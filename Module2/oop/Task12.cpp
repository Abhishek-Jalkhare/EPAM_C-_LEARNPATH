//
// Created by AbhishekJalkhare on 02-02-2026.
//

#include <iostream>
#include <vector>
using namespace std;

// Defines an abstract base class Item with private members: title (std::string),
// id (int) Implements protected/public accessors and mutators for title and id
// (including validation if necessary) Declares a pure virtual function display()
// in Item (making it abstract) Derives classes Book, Magazine, and DVD from Item,
// each with additional private members and their own display() implementation Uses
// accessors to enforce validation rules (e.g., pages > 0 for Book, duration > 0 for DVD)
// Demonstrates polymorphism by storing Item pointers to various objects and calling display()
// via the base pointer

class Item {
    string title;
    int id;

public:
    [[nodiscard]] string getTitle() const {
        return title;
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    [[nodiscard]] int getId() const {
        return id;
    }

    void setId(const int id) {
        this->id = id;
    }

    Item(const string& title, const int id)
        : title(title),
          id(id) {
    }

    virtual void display() const = 0;
    virtual ~Item() = default;
};

class Book : public Item {
    int pages;

public:
    Book(const string& title, const int id , int pages)
        : Item(title, id) {
        setPages(pages);
    }

    [[nodiscard]] int getPages() const {
        return pages;
    }

    void setPages(const int pages) {
        if (pages <= 0) {
            cout<<"Pages should always be greater than 0"<<endl;
            return;
        }
        this->pages = pages;
    }

    void display() const override {
        cout<< "----BOOK----"<<endl;
        cout << "Book Title   : " << getTitle() << endl;
        cout << "Pages        : " << getPages()<< endl;
    }

};

class Magazine : public Item {
    int issue;

public:
    Magazine(const string& title, const int id , const int issue)
        : Item(title, id) {
        setIssue(issue);
    }

    [[nodiscard]] int getIssue() const {
        return issue;
    }

    void setIssue(const int issue) {
        if (issue <= 0) {
            cout<<"Invalid issue it should be greater than 0"<<endl;
        }
        this->issue = issue;
    }

    void display() const override {
        cout<<"------MAGZINE------"<<endl;
        cout << "Magazine Title : " << getTitle() << endl;
        cout << "Issue Number   : " << issue << endl;

    }
};

class DVD : public Item {
    double duration ;

public:
    DVD(const string& title, const int id , const double duration)
        : Item(title, id) {
        setDuration(duration);
    }

    [[nodiscard]] double getDuration() const {
        return duration;
    }

    void setDuration(const double duration) {
        if (duration <= 0 ) {
            cout<<"Invalid duration it should be positive"<<endl;
        }
        this->duration = duration;
    }

    void display() const override {
        cout<< "-----D V D------"<<endl;
        cout << "DVD Title   : " << getTitle() << endl;
        cout << "Duration    : " << duration << " minutes" << endl;

    }

};


int main(int argc, char* argv[]) {
    vector<Item*> arr = {new Book("book1",12,200) ,
        new Magazine("magzine1" , 12  , 2),
        new DVD("DVD1" , 123 , 120)
    };

    for ( Item * it : arr ) {
        it->display();
    }
}
