import repo.Author;
import repo.Book;
import repo.Document;
import repo.Repo;

public class Main {
    public static void main(String[] args) {
        Repo repo1 = new Repo(20);
        Repo repo2 = new Repo(30, 5, 12);

        System.out.println(repo1);
        System.out.println(repo2);


        Document document1 = new Document(5, "txt", "Doc 1");
        Document document2 = new Document(8, "txt", "Doc 2");

        System.out.println(document1);
        System.out.println(document2);

        Author author = new Author("Ivanov");

        System.out.println(author);

        Book book1 = new Book(10, "pdf", "Book 1", author, "!@#$%");

        System.out.println(book1);

        System.out.println(repo1.uploadDocument(document1));
        System.out.println(repo1.uploadDocument(document2));
        System.out.println(repo1.uploadDocument(book1));
        System.out.println(repo1);

        Document docRef = document1;
        System.out.println(docRef.toString());
        docRef = book1;
        System.out.println(docRef);
    }
}