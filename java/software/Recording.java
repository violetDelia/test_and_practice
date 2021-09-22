package software;

import java.util.Objects;

/** the Recording */
public class Recording extends CatalogItem {

    /** the performer */
    public String performer;
    /** the format */
    public String format;

    public Recording(String code, String title, java.util.Date date, String performer, String format) {
        super(code, title, date);
        super.setFlag('R');
        this.performer = performer;
        this.format = format;
    }

    public String getPerformer() {
        return this.performer;
    }

    public void setPerformer(String performer) {
        this.performer = performer;
    }

    public String getFormat() {
        return this.format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof Recording)) {
            return false;
        }
        Recording recording = (Recording) o;
        return Objects.equals(performer, recording.performer) && Objects.equals(format, recording.format);
    }

    @Override
    public int hashCode() {
        return Objects.hash(performer, format);
    }

    @Override
    public String toString() {
        return super.toString() + "_" + getPerformer() + "_" + getFormat();
    }

}
