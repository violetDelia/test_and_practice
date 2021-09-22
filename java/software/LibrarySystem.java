package software;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Objects;
import java.util.Scanner;

/** the system */
public class LibrarySystem implements Cloneable {

    public static void main(String[] args) {
        String datePath = "J:\\test\\java\\software\\Catalog.dat";
        String newDatePath = "J:\\test\\java\\software\\newCatalog.dat";
        LibrarySystem librarySystem = new LibrarySystem();
        librarySystem.loadCatalogFromFile(datePath);
        System.out.println("*****************************************");
        System.out.println("       a.display all catalogItems");
        System.out.println("       b.display detail info of one item by title user input");
        System.out.println("       c.add a new Book or Recording");
        System.out.println("       d.delete by index");
        System.out.println("       e.save");
        System.out.println("       q.close");
        System.out.println("*****************************************");
        try (Scanner in = new Scanner(System.in);) {

            while (librarySystem.Running()) {
                System.out.println("");
                System.out.println("input operate");
                String operate = in.next();
                switch (operate) {
                    case "a":
                        librarySystem.displayCatalogItems();
                        break;
                    case "b":
                        System.out.println("input the code");
                        String code = in.next();
                        CatalogItem item = librarySystem.getCatalog().getItem(code);
                        if (item == null) {
                            System.out.println("not find");
                        } else {
                            System.out.println(item.toString());
                        }
                        break;

                    case "c":
                        System.out.println("input info");
                        System.out.println("the template: Book_code_title_date(yyyy-MM-dd)_author_page");
                        System.out.println("please replace ^ with blank");
                        String info = in.next();
                        try {
                            CatalogItem newItem = librarySystem.createICatalogItem(info);
                            if (newItem == null) {
                                System.out.println("input error");
                                System.out.println("operate again");
                                break;
                            }
                            librarySystem.getCatalog().addItem(newItem);
                            System.out.println("add success");
                        } catch (ParseException e1) {
                            System.out.println("input error");
                            System.out.println("operate again");
                        }
                        break;
                    case "d":
                        System.out.println("input index");
                        String index = in.next();
                        librarySystem.getCatalog()
                                .removeItem(librarySystem.getCatalog().gItem(Integer.parseInt(index)));
                        break;
                    case "e":
                        librarySystem.saveCatalogToFile(newDatePath);
                        System.out.println("save success");
                        break;
                    case "q":
                        librarySystem.close();
                        System.out.println("system close");
                        break;
                    default:
                        break;
                }
            }
        } catch (Exception e) {
            System.out.println("error");
            librarySystem.close();
        }

    }

    /** Info of CatalogItems */
    private Catalog catalog;
    /** the state of system */
    private boolean isRunning = true;

    public LibrarySystem() {
        catalog = new Catalog();
    }

    public Catalog getCatalog() {
        return this.catalog;
    }

    public void setCatalog(Catalog Catalog) {
        this.catalog = Catalog;
    }

    public boolean getIsRunning() {
        return this.isRunning;
    }

    public void setIsRunning(boolean isRunning) {
        this.isRunning = isRunning;
    }

    /**
     * 
     * @return whether the system is running
     */
    public boolean Running() {
        return getIsRunning();
    }

    /**
     * close the system
     */
    public void close() {
        setIsRunning(false);
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof LibrarySystem)) {
            return false;
        }
        LibrarySystem librarySystem = (LibrarySystem) o;
        return Objects.equals(catalog, librarySystem.catalog);
    }

    @Override
    public int hashCode() {
        return Objects.hash(catalog);
    }

    @Override
    public String toString() {
        return "{" + " Catalog='" + getCatalog() + "'" + "}";
    }

    /**
     * load the info from the fileName
     * 
     * @param fileName the path of the file with info
     */
    public void loadCatalogFromFile(String fileName) {
        try {
            BufferedReader readIn = new BufferedReader(new FileReader(fileName));
            String item = new String();
            while ((item = readIn.readLine()) != null) {
                try {
                    getCatalog().addItem(createICatalogItem(item));
                } catch (ParseException e) {
                    e.printStackTrace();
                }
            }
            readIn.close();
        } catch (EOFException e) {
            System.err.println("End of stream");
        } catch (FileNotFoundException e) {
            System.err.println("File " + fileName + " Not Found");
        } catch (IOException e) {
            e.printStackTrace();
        } catch (StringIndexOutOfBoundsException e) {
            System.err.println("file wrong");
            e.printStackTrace();
        }
    }

    /**
     * save the info to the fileName
     * 
     * @param fileName the path of file
     */
    public void saveCatalogToFile(String fileName) {
        FileWriter writeFile = null;
        try {
            BufferedWriter writeIn = new BufferedWriter(new FileWriter(fileName));
            CatalogIterator it = getCatalog().getIterator();
            while (it.hasNext()) {
                writeIn.write(it.next().toString());
                writeIn.newLine();
            }
            writeIn.flush();
            writeIn.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (writeFile != null) {
                try {
                    writeFile.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    /**
     * print the info in the catalog
     */
    public void displayCatalogItems() {
        CatalogIterator it = getCatalog().getIterator();
        while (it.hasNext()) {
            System.out.println(it.next().toString());
        }
    }

    /**
     * create a CatalogItem object
     * 
     * @param item the string about CatalogItem
     * @return the new CatalogItem
     * @throws ParseException string is not match the template
     */
    private CatalogItem createICatalogItem(String item) throws ParseException {
        if (item.charAt(0) == 'B') {
            return createBook(item);
        }
        if (item.charAt(0) == 'R') {
            return createRecording(item);
        }
        return null;
    }

    /**
     * string to date
     * 
     * @param publishDate the string about date
     * @return new date
     * @throws ParseException string is not match the template
     */
    private Date stringToDate(String publishDate) throws ParseException {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        Date date = new Date();
        try {
            date = simpleDateFormat.parse(publishDate);
        } catch (ParseException e1) {
            e1.printStackTrace();
            throw e1;
        }
        return date;
    }

    /**
     * create a Recording object
     * 
     * @param item the string about Recording
     * @return the new Recording
     * @throws ParseException string is not match the template
     */
    private CatalogItem createRecording(String item) throws ParseException {
        int indexLeft = item.indexOf(95, 0) + 1;
        int indexRight = item.indexOf(95, indexLeft);
        String code = new String(item.substring(indexLeft, indexRight));
        indexLeft = ++indexRight;
        indexRight = item.indexOf(95, indexLeft);
        String title = new String(item.substring(indexLeft, indexRight));
        indexLeft = ++indexRight;
        indexRight = item.indexOf(95, indexLeft);
        String publishDate = new String(item.substring(indexLeft, indexRight));
        indexLeft = ++indexRight;
        indexRight = item.indexOf(95, indexLeft);
        String performer = new String(item.substring(indexLeft, indexRight));
        indexLeft = ++indexRight;
        indexRight = item.indexOf(95, indexLeft);
        String format = new String(item.substring(indexLeft));
        return new Recording(code, title, stringToDate(publishDate), performer, format);
    }

    /**
     * create a Book object
     * 
     * @param item the string about Book
     * @return the new Book
     * @throws ParseException string is not match the template
     */
    private CatalogItem createBook(String item) throws StringIndexOutOfBoundsException, ParseException {
        try {
            int indexLeft = item.indexOf(95, 0) + 1;
            int indexRight = item.indexOf(95, indexLeft);
            String code = new String(item.substring(indexLeft, indexRight));
            indexLeft = ++indexRight;
            indexRight = item.indexOf(95, indexLeft);
            String title = new String(item.substring(indexLeft, indexRight));
            indexLeft = ++indexRight;
            indexRight = item.indexOf(95, indexLeft);
            String publishDate = new String(item.substring(indexLeft, indexRight));
            indexLeft = ++indexRight;
            indexRight = item.indexOf(95, indexLeft);
            String author = new String(item.substring(indexLeft, indexRight));
            indexLeft = ++indexRight;
            indexRight = item.indexOf(95, indexLeft);
            String numberOfPages = new String(item.substring(indexLeft));
            return new Book(code, title, stringToDate(publishDate), author, Integer.parseInt(numberOfPages));
        } catch (StringIndexOutOfBoundsException e) {
            e.printStackTrace();
            throw e;
        }
    }

}
