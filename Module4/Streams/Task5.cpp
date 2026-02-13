//
// Created by AbhishekJalkhare on 10-02-2026.
//
#include <vector>
#include <iostream>
using namespace std;

class Book {
    string title;
    string author;
    double price;

public:
    Book(const string& title, const string& author, double price)
        : title(title),
          author(author),
          price(price) {
    }
    Book() = default;

    friend ostream& operator<<(ostream& os , const Book& b) {
        os<<"Book title : "<<b.title <<"\nAuthor Name : "<<b.author<<"\nPrice : "<<b.price<<endl;
        return os;
    }

    friend istream& operator>>(istream& is  ,Book& b) {
        cout<<"Enter book title : ";
        getline(is ,b.title);
        cout<<"\nEnter Author Name : ";
        getline(is , b.author);
        cout<<"\nEnter price : ";
        is>>b.price;

        return is;
    }
};

int main(int argc, char* argv[]) {
    vector<Book> vec(1 ,Book());
    for (auto& b : vec) {
        cin>>b;
    }

    for (auto & b: vec) {
        cout<<b;
    }
}
