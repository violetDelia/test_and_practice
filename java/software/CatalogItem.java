package software;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Objects;

/** the CatalogItem */
public abstract class CatalogItem {

    /** the flag to distinguish Book or Recording */
    private char flag;

    /** the code */
    public String code;
    /** the title */
    public String title;
    /** the publishDate */
    public Date publishDate;

    public CatalogItem(String code, String title, Date publishDate) {
        this.code = code;
        this.title = title;
        this.publishDate = publishDate;
    }

    public String getCode() {
        return this.code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getTitle() {
        return this.title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public char getFlag() {
        return this.flag;
    }

    public void setFlag(char flag) {
        this.flag = flag;
    }

    public Date getPublishDate() {
        return this.publishDate;
    }

    public void setPublishDate(Date publishDate) {
        this.publishDate = publishDate;
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof CatalogItem)) {
            return false;
        }
        CatalogItem catalogItem = (CatalogItem) o;
        return Objects.equals(code, catalogItem.code) && Objects.equals(title, catalogItem.title)
                && Objects.equals(publishDate, catalogItem.publishDate);
    }

    @Override
    public int hashCode() {
        return Objects.hash(code, title, publishDate);
    }

    @Override
    public String toString() {
        if (getFlag() == 'B')
            return "Book" + "_" + getCode() + "_" + getTitle() + "_" + dateToString(getPublishDate());
        if (getFlag() == 'R')
            return "Recording" + '_' + getCode() + "_" + getTitle() + "_" + dateToString(getPublishDate());
        return "";
    }

    /**
     * date to string
     * 
     * @param date the Date
     * @return the string of Date
     */
    private String dateToString(Date date) {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        String publishDate = new String();
        try {
            publishDate = simpleDateFormat.format(date);
        } catch (Exception e1) {
            e1.printStackTrace();
        }
        return publishDate;
    }
}
