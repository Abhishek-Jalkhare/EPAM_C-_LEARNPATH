#include <iostream>
#include <vector>
using namespace std;

class Matrix {
protected:
    int rows, cols;
    vector<vector<double>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c) ,
        data(vector(r , vector<double>(c, 0))){
    }

    virtual ~Matrix() = default;


    void setValue(int r, int c, int value) {
        data[r][c] = value;
    }

    void setValue(double r, double c, double value) {
        data[(int)r][(int)c] = value;
    }


    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }


    virtual void display() const {
        for (const auto& row : data) {
            for (const auto val : row)
                cout << val << " ";
            cout << "\n";
        }
    }
};




class SquareMatrix : public Matrix {
public:
    SquareMatrix(int n) : Matrix(n, n) {}

    void display() const override {
        cout << "Square Matrix:\n";
        Matrix::display();
    }
};



// ================= Derived: IdentityMatrix =================
class IdentityMatrix : public SquareMatrix {
public:
    IdentityMatrix(int n) : SquareMatrix(n) {
        for (int i = 0; i < n; ++i)
            data[i][i] = 1;
    }

    void display() const override {
        cout << "Identity Matrix:\n";
        Matrix::display();
    }
};




int main() {


    Matrix m1(2,2), m2(2,2);

    m1.setValue(0,0,5);          // int version
    m1.setValue(0.0,1.0,3.5);    // double version

    m2.setValue(0,0,2);
    m2.setValue(0,1,1);

    Matrix sum = m1 + m2;        // operator overloading

    cout << "Sum Matrix:\n";
    sum.display();


    cout << "\nRuntime Polymorphism \n";

    Matrix* arr[2];

    arr[0] = new SquareMatrix(3);
    arr[1] = new IdentityMatrix(3);

    for (int i = 0; i < 2; ++i) {
        arr[i]->display();   // dynamic dispatch
        cout << "\n";
        delete arr[i];
    }

    return 0;
}
