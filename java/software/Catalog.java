package software;

import java.util.ArrayList;
import java.util.List;

/** the catalog */
public class Catalog {

    /** list of Book */
    private List<CatalogItem> books = new ArrayList<>();
    /** list of Recording */
    private List<CatalogItem> recording = new ArrayList<>();

    public Catalog() {
    }

    public List<CatalogItem> getBooks() {
        return this.books;
    }

    public void setBooks(List<CatalogItem> books) {
        this.books = books;
    }

    public List<CatalogItem> getRecording() {
        return this.recording;
    }

    public void setRecording(List<CatalogItem> recording) {
        this.recording = recording;
    }

    /**
     * 
     * @return the iterator of this catalog
     */
    public CatalogIterator getIterator() {
        return new CatalogIterator(this);
    }

    /**
     * add item in list
     * 
     * @param item the item want to add
     */
    public void addItem(CatalogItem item) {
        if (item == null)
            return;
        else if (item.getFlag() == 'R') {
            recording.add(item);
            return;
        } else if (item.getFlag() == 'B') {
            books.add(item);
            return;
        }

    }

    /**
     * remove item form list
     * 
     * @param item the item want to remove
     */
    public void removeItem(CatalogItem item) {
        if (item.getFlag() == 'R')
            recording.remove(item);
        else if (item.getFlag() == 'B')
            recording.remove(item);
    }

    /**
     * search item by code
     * 
     * @param code info about item
     * @return if find,return the item.if not find ,return null point
     */
    public CatalogItem getItem(String code) {
        CatalogIterator it = this.getIterator();
        while (it.hasNext()) {
            CatalogItem item = it.next();
            if (item.getCode().equals(code))
                return item;
        }
        return null;
    }

    /**
     * get item by index
     * 
     * @param index the position of item in list
     * @return if find,return the item.if not find ,return null point
     */
    public CatalogItem gItem(int index) {
        if (index < this.getBooks().size()) {
            return this.getBooks().get(index);
        } else if ((index -= this.getBooks().size()) > 0) {
            return this.getRecording().get(index);
        }
        return null;

    }

    /**
     * @return total of items
     */
    public int getNumberOfItem() {
        return getBooks().size() + getRecording().size();
    }

}