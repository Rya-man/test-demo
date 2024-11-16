/*
 Practice program-Write a Java program to create a book database to hold various information of the books such as, book_ title,year of publication ,author, publisher_name,status 
 (issued or available\). Write  functions: to display the details of the books written by same author.
Display the details of all the books published by "Mcgrahil publisher" in the year 2000.
Display the details of all the books issued in between 1/10/2023 to 15/10/2023.
Use the concepts of object-oriented programming such as Encapsulation, and constructors to implement the above scenario.
 */


import java.util.ArrayList;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;

class Book {
  private String title;
  private int publicationYear;
  private String author;
  private String publisherName;
  private String status;
  private Date issueDate;

  public Book(String title, int publicationYear, String author, String publisherName, String status, String issueDate) {
    this.title = title;
    this.publicationYear = publicationYear;
    this.author = author;
    this.publisherName = publisherName;
    this.status = status;
    try {
      this.issueDate = new SimpleDateFormat("dd/MM/yyyy").parse(issueDate);
    } catch (ParseException e) {
      this.issueDate = null;
    }
  }

  public String getAuthor() {
    return author;
  }

  public String getPublisherName() {
    return publisherName;
  }

  public int getPublicationYear() {
    return publicationYear;
  }

  public String getStatus() {
    return status;
  }

  public Date getIssueDate() {
    return issueDate;
  }

  public void displayDetails() {
    System.out.println("Title: " + title);
    System.out.println("Author: " + author);
    System.out.println("Publication Year: " + publicationYear);
    System.out.println("Publisher: " + publisherName);
    System.out.println("Status: " + status);
    if (issueDate != null) {
      System.out.println("Issue Date: " + new SimpleDateFormat("dd/MM/yyyy").format(issueDate));
    }
    System.out.println();
  }
}

class BookDatabase {
  private ArrayList<Book> books;

  public BookDatabase() {
    books = new ArrayList<>();
  }

  public void addBook(Book book) {
    books.add(book);
  }

  public void displayBooksByAuthor(String author) {
    System.out.println("Books by Author: " + author);
    for (Book book : books) {
      if (book.getAuthor().equalsIgnoreCase(author)) {
        book.displayDetails();
      }
    }
  }

  public void displayBooksByPublisherAndYear(String publisher, int year) {
    System.out.println("Books published by " + publisher + " in " + year + ":");
    for (Book book : books) {
      if (book.getPublisherName().equalsIgnoreCase(publisher) && book.getPublicationYear() == year) {
        book.displayDetails();
      }
    }
  }

  public void displayBooksIssuedBetween(String startDate, String endDate) {
    SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
    Date start, end;
    try {
      start = sdf.parse(startDate);
      end = sdf.parse(endDate);
      System.out.println("Books issued between " + startDate + " and " + endDate + ":");
      for (Book book : books) {
        Date issueDate = book.getIssueDate();
        if (issueDate != null && issueDate.compareTo(start) >= 0 && issueDate.compareTo(end) <= 0) {
          book.displayDetails();
        }
      }
    } catch (ParseException e) {
      System.out.println("Invalid date format");
    }
  }
}

public class Library {
  public static void main(String[] args) {
    BookDatabase db = new BookDatabase();

    db.addBook(new Book("Java Programming", 2000, "James Gosling", "Mcgrahil publisher", "issued", "05/10/2023"));
    db.addBook(new Book("Advanced Java", 2000, "James Gosling", "Mcgrahil publisher", "available", ""));
    db.addBook(new Book("Data Structures", 2005, "Mark Weiss", "Pearson", "issued", "12/10/2023"));
    db.addBook(new Book("Operating Systems", 2010, "Abraham Silberschatz", "Wiley", "available", ""));
    
    // Display books by author
    db.displayBooksByAuthor("James Gosling");

    // Display books by publisher and year
    db.displayBooksByPublisherAndYear("Mcgrahil publisher", 2000);

    // Display books issued between specific dates
    db.displayBooksIssuedBetween("01/10/2023", "15/10/2023");
  }
}
