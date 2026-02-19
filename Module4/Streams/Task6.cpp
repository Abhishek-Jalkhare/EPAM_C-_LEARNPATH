//
// Created by AbhishekJalkhare on 10-02-2026.
//
//
// Created by AbhishekJalkhare on 10-02-2026.
//

#include <fstream>
#include <iostream>

using namespace std;

class c;

class Book {
    string title;
    string author;
    double price{};

public:
    Book(const string& title, const string& author, double price)
        : title(title),
          author(author),
          price(price) {
    }
    Book() = default;

    friend void saveFile(ofstream& file , const Book& b) {
        file<<b.title<<"\n"<<b.author<<"\n"<<b.price<<"\n";
    }

    friend ostream& operator<<(ostream& os , const Book& b) {
        os<<"Book title : "<<b.title <<"\nAuthor Name : "<<b.author<<"\nPrice : "<<b.price<<endl;
        return os;
    }

    friend Book loadFile(ifstream& file  ) ;



};




 Book loadFile(ifstream& file  ){
     string title ;
     string author;
     double price;
     if(!getline(file >> std::ws,title)) {
         file.close();
         throw runtime_error("EOF Reached");
     }
     getline(file , author);
     file>>price;
     file.ignore();
     Book b{title , author , price};
     return b;
}


int main(int argc, char* argv[]) {
    const Book b{"abc" , "a" , 123.443};
     ofstream ofs("Task6_Output_file.txt" , ios::app);
     if (!ofs.is_open()) {
         cout<<"can't open file"<<endl;
         return 1;
     }
     saveFile(ofs , b);
     ofs.close();
     ifstream ifs("Task6_Input_file.txt");
     Book c = loadFile(ifs);
     cout<<c<<endl;
     Book d = loadFile(ifs);
     cout<<d;
     ifs.close();

}
