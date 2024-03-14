package repo;

import javax.print.Doc;

public class Book extends Document {
    private Author author;
    private String isbn;

    public Book(double docSize, String format, String title, Author author, String isbn) {
        super(docSize, format, title);
        this.author = author;
        this.isbn = isbn;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }
    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public void getSize() {

    }
    @Override
    public String toString() {
        return super.toString() + "Book{" +
                "author=" + author +
                ", isbn='" + isbn + '\'' +
                '}';
    }
}
