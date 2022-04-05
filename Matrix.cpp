#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "Matrix.hpp"

namespace zich{
    Matrix::Matrix(vector<double> m, int r, int c){
        if(r<=0 || c<=0 || c*r != m.size()){
            throw invalid_argument{"Can't do this shit"};
        }
        this->matrix = m;
        this->row =r;
        this->col =c;
    }
    Matrix Matrix::operator+(Matrix const &m){
        if(this->row != m.row || this->col != m.col){
            throw invalid_argument{"Can't do this shit"};
        }
        vector<double> mat((size_t)(this->col*this->row));
        for(int i= 0 ;i<this->col*this->row; i++){
           mat[(unsigned int)i] = this->matrix[(unsigned int)i] + m.matrix[(unsigned int)i]; 
        }
        return Matrix{mat,this->row,this->col};
    }
    Matrix Matrix::operator+(){
        return Matrix{this->matrix ,this->row ,this->col};  
    }
    void Matrix::operator+=(Matrix const &m){
        if(this->row != m.row || this->col != m.col){
            throw invalid_argument{"Can't do this shit"};
        }
        for(int i= 0 ;i<m.matrix.size(); i++){
            this->matrix[(unsigned int)i] = this->matrix[(unsigned int)i] +m.matrix[(unsigned int)i]; 
        }
    }
    Matrix Matrix::operator-(Matrix const &m){
        if(this->row != m.row || this->col != m.col){
            throw invalid_argument{"Can't do this shit"};
        }
        vector<double> mat((size_t)(this->col*this->row));
        for(int i= 0 ;i<this->col*this->row; i++){
           mat[(unsigned int)i] = this->matrix[(unsigned int)i] - m.matrix[(unsigned int)i]; 
        }
        return Matrix{mat,this->row,this->col};
    }
    Matrix Matrix::operator-(){
        vector<double> m((size_t)(this->col*this->row));
        for(int i= 0 ;i<this->col*this->row; i++){
           m[(unsigned int)i] = matrix[(unsigned int)i]*(-1); 
        }
        return Matrix{m,row,col};  
    }
    void Matrix::operator-=(Matrix const &m){
        if(this->row != m.row || this->col != m.col){
            throw invalid_argument{"Can't do this shit"};
        }
        for(int i= 0 ;i<this->col*this->row; i++){
            this->matrix[(unsigned int)i] = this->matrix[(unsigned int)i] -m.matrix[(unsigned int)i]; 
        }
    }
    bool Matrix::operator==(Matrix const &m){
        if(this->row != m.row ||this->col != m.col){
            throw invalid_argument{"Can't do this shit"};
        }
        for(int i= 0 ;i<this->matrix.size(); i++){
            if (this->matrix[(unsigned int)i] != m.matrix[(unsigned int)i]){
                return false;
            } 
        }
        return true;
    }
    bool Matrix::operator>=(Matrix const &m){
        return *this >m || *this ==m;
    }
    bool Matrix::operator<=(Matrix const &m){
        return *this <m || *this ==m;
    }
    bool Matrix::operator!=(Matrix const &m){
        return !(*this == m);
    }
    bool Matrix::operator>(Matrix const &m){
        if(this->row != m.row || this->col != m.col){
            throw invalid_argument{"Can't do this shit"};
        }
        int sum_matrix1=0;
        int sum_matrix2=0;
        for(int i= 0 ;i<this->matrix.size(); i++){
            sum_matrix1 = this->matrix[(unsigned int)i] + sum_matrix1;
            sum_matrix2 = m.matrix[(unsigned int)i] + sum_matrix2;
        }
        if(sum_matrix1 > sum_matrix2){
            return true;
        }
        return false;
    }
    bool Matrix::operator<(Matrix const &m){
        if(this->row != m.row || this->col != m.col){
            throw invalid_argument{"Can't do this shit"};
        }
        int sum_matrix1=0;
        int sum_matrix2=0;
        for(int i= 0 ;i<this->matrix.size(); i++){
            sum_matrix1 = this->matrix[(unsigned int)i] + sum_matrix1;
            sum_matrix2 = m.matrix[(unsigned int)i] + sum_matrix2;
        }
        if(sum_matrix1 < sum_matrix2){
            return true;
        }
        return false;
    }
    //postfix increment
    Matrix Matrix::operator++(int n){
        for(int i= 0 ;i<this->matrix.size(); i++){
          this->matrix[(unsigned int)i]++; 
        }
        return Matrix{matrix,row,col};
    }
    //Prefix Increment
    Matrix Matrix::operator++(){
        for(int i= 0 ;i<this->matrix.size(); i++){
          ++this->matrix[(unsigned int)i]; 
        }
        return Matrix{matrix,row,col};
    }
    //postfix increment
    Matrix Matrix::operator--(int){
        for(int i= 0 ;i<this->matrix.size(); i++){
          this->matrix[(unsigned int)i]--; 
        }
        return Matrix{matrix,row,col};
    }
    //Prefix Increment
    Matrix Matrix::operator--(){
        for(int i= 0 ;i<this->matrix.size(); i++){
          --this->matrix[(unsigned int)i]; 
        }
        return Matrix{matrix,row,col};
    }
    Matrix operator*(double num ,Matrix const &m){
        vector<double> mat((size_t)(m.col*m.row));
        for(int i=0; i<(m.col*m.row);i++){
            mat[(unsigned int)i] = m.matrix[(unsigned int)i]*num;
        }
        return Matrix{mat,m.row,m.col};
    }
    Matrix operator*(Matrix const &m,double num){
        vector<double> mat((size_t)(m.col*m.row));
        for(int i=0; i<m.col*m.row;i++){
            mat[(unsigned int)i] = m.matrix[(unsigned int)i]*num;
        }
        return Matrix{mat,m.row,m.col};
    }
    vector<vector<double>> Matrix::move_to_matrix(vector<double> m, int row, int col){
        vector<vector<double>> mat;
        mat.resize((uint)row);
        for(size_t i =0;i<row;i++){
            mat[i].resize((uint)col);
        }
        int index =0;
        for(int i= 0; i<row; i++){
            for(int j=0; j<col; j++){
                mat[(unsigned int)i][(unsigned int)j]= m[(unsigned int)index];
                index++;
            }
        }
        return mat;
    }
    vector<double> Matrix::move_to_arr(vector<vector<double>> m, int row, int col){
        vector<double> mat((size_t)(col*row));
        int index =0;
        for(int i= 0; i<row; i++){
            for(int j=0; j<col; j++){
                mat[(unsigned int)index]= m[(unsigned int)i][(unsigned int)j];
                index++;
            }
        }
        return mat;
    }
    Matrix Matrix::operator*(Matrix const &m){
        if(this->col != m.row){
            throw invalid_argument{"Can't do this shit"};
        }
        vector<vector<double>> mat1=move_to_matrix(this->matrix,this->row,this->col);
        vector<vector<double>> mat2=move_to_matrix(m.matrix,m.row,m.col);
        vector<vector<double>> result_mat;
        result_mat.resize((uint)this->row);
        for(size_t i =0;i<this->row;i++){
            result_mat[i].resize((uint)m.col);
        }
        for(int i = 0; i < this->row; ++i){
            for(int j = 0; j < m.col; ++j){
                for(int k = 0; k < this->col; ++k)
                {
                    result_mat[(unsigned int)i][(unsigned int)j] += mat1[(unsigned int)i][(unsigned int)k] * mat2[(unsigned int)k][(unsigned int)j];
                }
            }
        }
        vector<double> ans_mat = move_to_arr(result_mat,this->row,m.col);
        return Matrix{ans_mat,this->row,m.col};

    }
    void operator*=(double num,Matrix& m){
        for(int i=0; i<m.matrix.size();i++){
            m.matrix[(unsigned int)i] = m.matrix[(unsigned int)i]*num;
        }
    }
    void operator*=(Matrix& m,double num){
        for(int i=0; i<m.matrix.size();i++){
            m.matrix[(unsigned int)i] = m.matrix[(unsigned int)i]*num;
        }
    }
    void Matrix::operator*=(Matrix const &m){
        if(this->col != m.row){
            throw invalid_argument{"Can't do this shit"};
        }
        Matrix ans = *this*m;
        this->row = ans.row;
        this->col = ans.col;
        this->matrix = ans.matrix;
    }
    ostream& operator<< (ostream& output, Matrix const &m) {
        // vector<vector<double>> mat((size_t)m.row);
        // int index =0;
        // for(int i= 0; i<m.row; i++){
        //     for(int j=0; j<m.col; j++){
        //         mat[(unsigned int)i][(unsigned int)j]= m.matrix[(unsigned int)index];
        //         index++;
        //     }
        // }
        for(int i=0; i< m.row; i++){
            output << "[";
            for(int j=0; j<m.col;j++){
                double num =m.matrix.at((unsigned int)( i*m.col+ j));
                output << num << " ";
            }
            output << "]\n";
        }
        return output;
    }

}