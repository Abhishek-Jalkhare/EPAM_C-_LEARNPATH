//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include<iostream>
using namespace std;

void inputMatrix(int rows, int cols, int ** mat);
void addMatrices(int rows, int cols, int ** mat1, int ** mat2, int ** result);
void subtractMatrices(int rows, int cols, int ** mat1, int ** mat2, int ** result);
void multiplyMatrices(int r1, int c1, int r2, int c2, int **mat1, int **mat2, int **result);
void transposeMatrix(int rows, int cols, int **matrix, int **result);
void printMatrix(int rows, int cols, int **matrix);



int main(int argc, char const *argv[])
{
    int r1 , c1;
    cout<<"Enter rows and columns for first matrix: ";
    cin>>r1>>c1;
    int **mat1 = new int*[r1];
    int r2 , c2;
    cout<<"Enter rows and columns for second matrix: ";
    cin>>r2>>c2;
    int **mat2 = new int*[r2];

    inputMatrix(r1, c1, mat1);
    inputMatrix(r2, c2, mat2);

    int **result = new int*[r1];
    for(int i=0;i<r1;i++){
        result[i] = new int[c2];
    }

    if(r1 == r2 && c1 == c2){
        cout<<"Addition of matrices: "<<endl;
        addMatrices(r1, c1, mat1, mat2, result);
        printMatrix(r1, c1, result);

        cout<<"Subtraction of matrices: "<<endl;
        subtractMatrices(r1, c1, mat1, mat2, result);
        printMatrix(r1, c1, result);
    } else {
        cout<<"Addition and Subtraction not possible due to dimension mismatch."<<endl;
    }


    return 0;
}

void inputMatrix(int rows, int cols, int ** mat){
    for(int i=0;i<rows;i++){
        mat[i] = new int[cols];
        for(int j=0;j<cols;j++){
            cout<<"Enter element at position ("<<i<<","<<j<<"): ";
            cin>>mat[i][j];
        }
    }
}

void addMatrices(int rows, int cols, int ** mat1, int ** mat2, int ** result){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int ** mat1, int ** mat2, int ** result){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int r1 , int c1, int r2, int c2, int **mat1, int **mat2, int **result){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            result[i][j] = 0;
            for(int k=0;k<c1;k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}


void transposeMatrix(int rows, int cols, int **matrix, int **result){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[j][i] = matrix[i][j];
        }
    }
}


void printMatrix(int rows, int cols, int **matrix){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}