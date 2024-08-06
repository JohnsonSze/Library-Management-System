### Explanation

The provided C++ program implements a simple Library Management System. This system allows users to add books, delete books, borrow books, and return books. Each book's information includes the title, author, ISBN, and borrowing status.

#### Classes and Methods:

1. **Class `Book`**:
    - **Attributes**:
        - `title`: The title of the book.
        - `author`: The author of the book.
        - `isbn`: The International Standard Book Number (ISBN) of the book.
        - `isBorrowed`: Boolean value indicating whether the book is borrowed.
    - **Methods**:
        - `getTitle()`: Returns the title of the book.
        - `getAuthor()`: Returns the author of the book.
        - `getISBN()`: Returns the ISBN of the book.
        - `getBorrowedStatus()`: Returns the borrowing status of the book.
        - `borrowBook()`: Sets the borrowing status to true.
        - `returnBook()`: Sets the borrowing status to false.
        - `printBookDetails()`: Prints the details of the book.

2. **Class `Library`**:
    - **Attributes**:
        - `books`: A vector of `Book` objects.
    - **Methods**:
        - `addBook(const Book &book)`: Adds a new book to the library.
        - `removeBook(const std::string &isbn)`: Removes a book from the library using its ISBN.
        - `borrowBook(const std::string &isbn)`: Borrows a book from the library using its ISBN.
        - `returnBook(const std::string &isbn)`: Returns a borrowed book to the library using its ISBN.
        - `listBooks() const`: Lists all books in the library.

3. **Function `displayMenu`**:
    - Prints the menu options for the Library Management System.

4. **Function `main`**:
    - Provides an infinite loop to handle user input and calls the corresponding library functions.

### Usage Example

When the program starts, the user will see a menu with options to add a book, remove a book, borrow a book, return a book, list all books, or exit the system. The user can enter the corresponding option number to perform the desired action. The program will then execute the corresponding operation and prompt the user for further input.

### Complete Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

class Book {
public:
    Book(std::string title, std::string author, std::string isbn)
        : title(title), author(author), isbn(isbn), isBorrowed(false) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }
    bool getBorrowedStatus() const { return isBorrowed; }

    void borrowBook() { isBorrowed = true; }
    void returnBook() { isBorrowed = false; }

    void printBookDetails() const {
        std::cout << "Title: " << title << "\nAuthor: " << author
                  << "\nISBN: " << isbn << "\nBorrowed: "
                  << (isBorrowed ? "Yes" : "No") << std::endl;
    }

private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isBorrowed;
};

class Library {
public:
    void addBook(const Book &book) {
        books.push_back(book);
        std::cout << "Book added successfully!" << std::endl;
    }

    void removeBook(const std::string &isbn) {
        auto it = std::find_if(books.begin(), books.end(),
            [&isbn](const Book &book) { return book.getISBN() == isbn; });

        if (it != books.end()) {
            books.erase(it);
            std::cout << "Book removed successfully!" << std::endl;
        } else {
            std::cout << "Book not found!" << std::endl;
        }
    }

    void borrowBook(const std::string &isbn) {
        auto it = std::find_if(books.begin(), books.end(),
            [&isbn](const Book &book) { return book.getISBN() == isbn; });

        if (it != books.end()) {
            if (!it->getBorrowedStatus()) {
                it->borrowBook();
                std::cout << "Book borrowed successfully!" << std::endl;
            } else {
                std::cout << "Book is already borrowed!" << std::endl;
            }
        } else {
            std::cout << "Book not found!" << std::endl;
        }
    }

    void returnBook(const std::string &isbn) {
        auto it = std::find_if(books.begin(), books.end(),
            [&isbn](const Book &book) { return book.getISBN() == isbn; });

        if (it != books.end()) {
            if (it->getBorrowedStatus()) {
                it->returnBook();
                std::cout << "Book returned successfully!" << std::endl;
            } else {
                std::cout << "Book was not borrowed!" << std::endl;
            }
        } else {
            std::cout << "Book not found!" << std::endl;
        }
    }

    void listBooks() const {
        if (books.empty()) {
            std::cout << "No books available in the library." << std::endl;
            return;
        }

        for (const auto &book : books) {
            book.printBookDetails();
            std::cout << "-----------------------------" << std::endl;
        }
    }

private:
    std::vector<Book> books;
};

void displayMenu() {
    std::cout << "Library Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Remove Book\n";
    std::cout << "3. Borrow Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. List All Books\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 6) {
            break;
        }

        std::string title, author, isbn;

        switch (choice) {
            case 1:
                std::cin.ignore();
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, isbn);
                library.addBook(Book(title, author, isbn));
                break;
            case 2:
                std::cin.ignore();
                std::cout << "Enter ISBN of the book to remove: ";
                std::getline(std::cin, isbn);
                library.removeBook(isbn);
                break;
            case 3:
                std::cin.ignore();
                std::cout << "Enter ISBN of the book to borrow: ";
                std::getline(std::cin, isbn);
                library.borrowBook(isbn);
                break;
            case 4:
                std::cin.ignore();
                std::cout << "Enter ISBN of the book to return: ";
                std::getline(std::cin, isbn);
                library.returnBook(isbn);
                break;
            case 5:
                library.listBooks();
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
                break;
        }
    }

    return 0;
}
```

### Usage Example:

When you run the program, you will see the following menu:

```
Library Management System
1. Add Book
2. Remove Book
3. Borrow Book
4. Return Book
5. List All Books
6. Exit
Enter your choice:
```

#### Adding a Book:
```
Enter your choice: 1
Enter title: C++ Programming
Enter author: Bjarne Stroustrup
Enter ISBN: 9780321563842
Book added successfully!
```

#### Borrowing a Book:
```
Enter your choice: 3
Enter ISBN of the book to borrow: 9780321563842
Book borrowed successfully!
```

#### Listing All Books:
```
Enter your choice: 5
Title: C++ Programming
Author: Bjarne Stroustrup
ISBN: 9780321563842
Borrowed: Yes
-----------------------------
```
