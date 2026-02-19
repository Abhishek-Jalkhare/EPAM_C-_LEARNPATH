
//
// Created by AbhishekJalkhare on 13-02-2026.
//
#include <stdexcept>
#include <iostream>
#include <limits>
using namespace std;

class InvalidPriceException : public std::runtime_error{
public:
    explicit InvalidPriceException(const char* msg) :runtime_error(msg) {
    }

    explicit InvalidPriceException(const string& msg):runtime_error(msg) {

    }
};

class InvalidProductException : public runtime_error {
public:
    explicit InvalidProductException(const string& msg):runtime_error(msg){}
};

class Product {
    string name;
    double price;
    int stock;

    static bool hasTwoDigits(double d) {
        const double temp = d * 100;
        int t = temp;
        double f = t;

        bool res = (temp == f);
        return res;
    }
public:
    Product(const string& name, const double price, const int stock)
        : name(name),
          price(price),
          stock(stock) {
    }

    [[nodiscard]] string getName() const {
        return name;
    }

    [[nodiscard]] double getPrice() const {
        return price;
    }

    [[nodiscard]] int getStock() const {
        return stock;
    }

    void setPrice(const double price) {
        this->price = price;
    }

    void display() const{
        cout<<"Name : "<<this->name<<endl;
        cout<<"Price : "<<this->price<<endl;
        cout<<"Stock : "<<this->stock<<endl;
        cout<<"-------------------"<<endl;
    }

    static double getNewPrice() {
        double price ;
        cout<<"Enter New Price : " <<endl;
        cin>>price;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw InvalidPriceException("Non Numeric value entered");
        }
        if (price <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw InvalidPriceException("Price can only be positive");
        }

        if (price > 10000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw InvalidPriceException("Price exceeds maximum allowed value (Rs. 10,000) ");
        }

        if (!hasTwoDigits(price)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw InvalidPriceException("Price has more than two decimal digits");
        }

        return price;
    }

    static void updateProductPrice( Product& p) {
        while (true) {
            try{
                p.setPrice(getNewPrice());
                break;
            }catch (const InvalidPriceException& e ) {
                cout<<"Invalid Price Exception Occurred : "<<e.what()<<endl;
            }
        }
    }


};

void displayInventory(const Product* arr , const int n) {
    for (int i = 0 ; i < n ; i++) {
        Product p = arr[i];
        cout<<"Product Detail of "<<i+1<<" product : "<<endl;
        p.display();
    }
}

int main(int argc, char* argv[]) {
    cout<<"Welcome to Product Management System : select a Product to upadate : "<<endl;
    const Product arr[] {
        Product{"a" ,123,2} ,
        Product{"b" ,23,1},
        Product{"c" ,123,2}
    };
    constexpr int n = sizeof(arr)/sizeof(Product);
    int k = 1;
        while (k == 1) {
            try{
                displayInventory(arr, n);
                int i = 0;
                cout<<"Select a product to update"<<endl;
                cin>>i;
                if (i < 1 || i > n) {
                    throw InvalidProductException("out of bounds Product");
                }

                Product p = arr[i-1];
                Product::updateProductPrice(p);
            }catch (const InvalidPriceException& e) {
                cout<<"Invalid price exception : "<<e.what()<<endl;
            }
            catch (const InvalidProductException& e) {
                cout<<"Invalid Product exception : "<<e.what()<<endl;
            }
            cout<<"Enter 1 to continue program press eny other key to exit"<<endl;
            cin>>k;
        }
    }




