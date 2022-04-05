#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace zich{
    class Matrix{
        public:
            int row;
            int col;
            vector<double> matrix;
            Matrix();
            Matrix(vector<double> m, int r, int c);
            Matrix operator+(Matrix const &m);
            Matrix operator+();
            void operator+=(Matrix const &m);
            Matrix operator-(Matrix const &m);
            Matrix operator-();
            void operator-=(Matrix const &m);
            bool operator==(Matrix const &m);
            bool operator>=(Matrix const &m);
            bool operator<=(Matrix const &m);
            bool operator!=(Matrix const &m);
            bool operator>(Matrix const &m);
            bool operator<(Matrix const &m);
            //postfix increment
            Matrix operator++(int);
            //Prefix Increment
            Matrix operator++();
            //postfix increment
            Matrix operator--(int);
            //Prefix Increment
            Matrix operator--();
            friend Matrix operator*(double,Matrix const &m);
            friend Matrix operator*(Matrix const &m,double);
            Matrix operator*(Matrix const &m);
            friend void operator*=(double,Matrix&);
            friend void operator*=(Matrix&,double);
            void operator*=(Matrix const &m);
            friend ostream& operator<< (ostream& output,Matrix const &m);
            vector<double> move_to_arr(vector<vector<double>> m, int row, int col);
            vector<vector<double>> move_to_matrix(vector<double> m, int row, int col);



    };
}