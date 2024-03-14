package repo;

public class Document {
    private double docSize;
    private String format;
    private String title;
    private Repo repo;

    public Document(double docSize, String format, String title) {
        this.docSize = docSize;
        this.format = format;
        this.title = title;
    }

    public void setDocSize(double docSize) {
        this.docSize = docSize;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setRepo(Repo repo) {
        this.repo = repo;
    }

    public double getDocSize() {
        return docSize;
    }

    public String getFormat() {
        return format;
    }

    public String getTitle() {
        return title;
    }

    @Override
    public String toString() {
        return "Document{" +
                "docSize=" + docSize +
                ", format='" + format + '\'' +
                ", title='" + title + '\'' +
                '}';
    }
}
