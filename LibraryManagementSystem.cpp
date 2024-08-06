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
