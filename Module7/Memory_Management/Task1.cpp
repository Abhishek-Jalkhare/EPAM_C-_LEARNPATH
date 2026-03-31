//
// Created by AbhishekJalkhare on 18-03-2026.
//
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
using namespace std;

class Book {
public:
    std::string title;
    std::string author;
    Book()=default;
    Book(std::string  t, std::string  a) : title(std::move(t)), author(std::move(a)) {}
    void print() const {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};

class Library {
    std::vector<std::unique_ptr<Book>> books;
public:
    ~Library() = default; // Unique ptr follows  RAII Principle so deFAULT DETRUCTOR WORKS
        // Clean up all books



    void addBook(const std::string& title, const std::string& author) {
        books.push_back(make_unique<Book>(title, author));
    }

    Book* findBook(const std::string& title) {
        for (std::unique_ptr<Book>& book : books) {
            if (book->title == title) return book.get();
        }
        return nullptr;
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->title == title) {
                books.erase(it);
                // destructor of book called
                return;
            }
        }
    }
};




int main(int argc, char* argv[]) {
    Library lib;
    lib.addBook("1984", "George Orwell");
    lib.addBook("Brave New World", "Aldous Huxley");

    // Find a book and keep its pointer
    Book* bookPtr = lib.findBook("1984");
    if (bookPtr) {
        bookPtr->print();
    }

    // Remove the book from the library
    lib.removeBook("1984");
    bookPtr = nullptr; // now it will not crash the program

    // // Dangling pointer: bookPtr now points to deleted memory!
    // this will crash the program
     std::cout << "Trying to access deleted book:" << std::endl;
     if (bookPtr != nullptr) {
         bookPtr->print(); // Undefined behavior!(program crashes accessing dangling reference)
     }

    return 0;
}
