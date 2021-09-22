package software;

import java.util.Iterator;

/** the catalogIterator of Catalog */
public class CatalogIterator implements Iterator<CatalogItem> {

    private Catalog catalog;
    private int size;
    private int cursor;

    CatalogIterator(Catalog catalog) {

        /** the size of catalog */
        this.size = catalog.getNumberOfItem();
        /** the catalog */
        this.catalog = catalog;
        /** the cursor */
        this.cursor = 0;
    }

    public Catalog getCatalog() {
        return this.catalog;
    }

    public void setCatalog(Catalog catalog) {
        this.catalog = catalog;
    }

    public int getSize() {
        return this.size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getCursor() {
        return this.cursor;
    }

    public void setCursor(int cursor) {
        this.cursor = cursor;
    }

    @Override
    public boolean hasNext() {
        if (getCursor() >= getSize() - 1)
            return false;
        return true;
    }

    @Override
    public CatalogItem next() {
        if (getCursor() < getCatalog().getBooks().size() - 1) {
            setCursor(getCursor() + 1);
            return getCatalog().getBooks().get(getCursor());
        } else if (getCursor() >= getCatalog().getBooks().size() - 1) {
            setCursor(getCursor() + 1);
            return getCatalog().getRecording().get(getCursor() - getCatalog().getBooks().size());
        }
        return null;
    }

}
