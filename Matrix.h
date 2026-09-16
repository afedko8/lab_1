#pragma once
#include<vector>
#include<iostream>

template<typename T>
class Matrix
{
private:
    size_t coll;
    size_t rows;
    bool is_zero;
public:
    std::vector<std::vector<T>> matrix;
    Matrix(size_t n, size_t m);
    Matrix();
    ~Matrix();
    void print();
    void input();
    void add(Matrix &b);
    void mult(T val);
    void mult(Matrix &b);
    void power(size_t p);
    void pad_to_square();
};

template<typename T>
Matrix<T>::Matrix(){
    is_zero = 1;
    rows = 0;
    coll = 0;
}

template<typename T>
Matrix<T>::~Matrix() {}

template<typename T>
void Matrix<T>::print(){
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->coll; j++)
        {
            std::cout<<matrix[i][j]<< ' ';
        }
        std::cout<<std::endl;
    }
}

template<typename T>
void Matrix<T>::input(){
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->coll; j++)
        {
            std::cin>>matrix[i][j];
        }
    }
}

template<typename T>
Matrix<T>::Matrix(size_t n, size_t m) : rows(n), coll(m), matrix(n, std::vector<T>(m)) {}

template<typename T>
void Matrix<T>::add(Matrix &b){
    if (!((this->rows == b.rows) && (this->coll == b.coll)))
    {
        std::cout<<"Error: Matrix dimensions do not match for addition.";
        return;
    }
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->coll; j++)
        {
            matrix[i][j]+=b.matrix[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::mult(Matrix &b) {
    if (this->coll != b.rows) {
        std::cout << "Error: Matrix dimensions do not match for multiplication.\n";
        return;
    }

    std::vector<std::vector<T>> new_matrix(this->rows, std::vector<T>(b.coll, T(0)));
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < b.coll; j++) {
            T sum = T(0);
            for (size_t k = 0; k < this->coll; k++) {
                if (matrix[i][k] == T(0)) continue;
                sum += matrix[i][k] * b.matrix[k][j];
            }
            new_matrix[i][j] = sum;
        }
    }

    matrix = std::move(new_matrix);
    coll = b.coll;
}

template<typename T>
void Matrix<T>::pad_to_square(){
    if (rows!=coll)
    {
        size_t new_size = std::max(rows,coll);
        std::vector<std::vector<T>> new_matrix(new_size,std::vector<T>(new_size,0));
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < coll; j++)
            {
                new_matrix[i][j] = matrix[i][j];
            }
            
        }
        matrix = std::move(new_matrix);
        rows = new_size;
        coll = new_size;
    }
}

template<typename T>
void Matrix<T>::power(size_t p){
    pad_to_square();
    Matrix<T> result(rows,rows);
    for (size_t i = 0; i < rows; i++)
    {
      result.matrix[i][i] = T(1);   
    }
    if (p==0){ 
        matrix = std::move(result.matrix);
        return;
    }
    if (p == 1) return;
    
    Matrix<T> base(rows,rows);
    base.matrix = std::move(matrix);
    while (p>0)
    {
        if (p%2) result.mult(base);
        p/=2;            
        if(p>0) base.mult(base);
    }
    matrix = std::move(result.matrix);
}