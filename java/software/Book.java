package software;

import java.util.Date;
import java.util.Objects;

/** the Book */
public class Book extends CatalogItem {

    /** the author */
    public String author;
    /** the page */
    public int numberOfPages;

    public Book(String code, String title, Date publishDate, String author, int numberOfPages) {
        super(code, title, publishDate);
        super.setFlag('B');
        this.author = author;
        this.numberOfPages = numberOfPages;
    }

    public String getAuthor() {
        return this.author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getNumberOfPages() {
        return this.numberOfPages;
    }

    public void setNumberOfPages(int numberOfPages) {
        this.numberOfPages = numberOfPages;
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof Book)) {
            return false;
        }
        Book book = (Book) o;
        return Objects.equals(author, book.author) && numberOfPages == book.numberOfPages;
    }

    @Override
    public int hashCode() {
        return Objects.hash(author, numberOfPages);
    }

    @Override
    public String toString() {
        return super.toString() + "_" + getAuthor() + "_" + getNumberOfPages();
    }
}
