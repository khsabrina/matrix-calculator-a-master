#include "doctest.h"
#include "Matrix.hpp"

using namespace zich;
TEST_CASE ("Inputs in Constructor") {
    vector<double> test(30);
    for (double i = 0; i < 30; ++i) {
        test[(unsigned int)i] = i;
    }
    SUBCASE("Good Inputs"){
        //checking vaild inputs of col and row when col*row == test.size() and col,row when <=0
        CHECK_NOTHROW(Matrix m(test,3,10));
        CHECK_NOTHROW(Matrix m(test,5,6));
        CHECK_NOTHROW(Matrix m(test,1,30));
        CHECK_NOTHROW(Matrix m(test,15,2));
    }
    SUBCASE("Bad Inputs"){
        //checking invaild inputs of col and row when <=0
        for (double i = -10; i < 1; ++i) {
            CHECK_THROWS(Matrix m(test,i,1));
            CHECK_THROWS(Matrix m(test,1,i));
        }
        //checking invaild inputs of col and row when col*row != test.size() 
        for (double i = 31; i < 40; ++i) {
            CHECK_THROWS(Matrix m(test,i,1));
            CHECK_THROWS(Matrix m(test,1,i));
        }
    }
    
}
TEST_CASE ("Checking +,-") {
    vector<double> test_a = {1, 0, 0, 0, 1, 0, 0, 0, 1}; //3x3
    vector<double> test_b = {3, 0, 0, 0, 3, 0, 0, 0, 3};    //3x3
    vector<double> test_c = {2,3,4,5,6,7};  //2x3
    vector<double> test_d = {5,6,7,8}; //2x2
    vector<double> test_e = {1,2,3,4}; //2x2
    vector<double> ans_a = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    vector<double> ans_b = {6,8,10,12};
    vector<double> ans_c = {-2, 0, 0, 0, -2, 0, 0, 0, -2};
    vector<double> ans_d = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    vector<double> ans_e = {4,4,4,4};
    Matrix m(test_a,3,3);
    Matrix m9(test_c,2,3);
    Matrix m1(test_b,3,3);
    Matrix m2(test_d,2,2);
    Matrix m3(test_e,2,2);
    Matrix m4(ans_a,3,3);
    Matrix m5(ans_b,2,2);
    Matrix m6(ans_c,3,3);
    Matrix m7(ans_d,3,3);
    Matrix m8(ans_e,2,2);
    SUBCASE("Good Inputs"){
        CHECK_EQ((m+m1)==m4, true);
        CHECK_EQ((m2+m3)==m5, true);
        CHECK_EQ((m-m1)==m6, true);
        CHECK_EQ((m1-m)==m7, true);
        CHECK_EQ((m2-m3)==m8, true);
        m+=m1;
        m2+=m3;
        CHECK_EQ(m==m4, true);
        CHECK_EQ(m2==m5, true);
    }
    SUBCASE("Bad Inputs"){
            CHECK_THROWS(m1+=m2);
            CHECK_THROWS(m1+m2);
            CHECK_THROWS(m1-=m2);
            CHECK_THROWS(m1-m2);
            CHECK_THROWS(m+=m3);
            CHECK_THROWS(m+m3);
            CHECK_THROWS(m1+=m9);
            CHECK_THROWS(m5-m9);
            CHECK_THROWS(m4+=m2);
    }
    
}
TEST_CASE ("Checking *") {
    vector<double> test_a = {1, 0, 0, 0, 1, 0, 0, 0, 1}; //3x3
    vector<double> test_b = {3, 0, 0, 0, 3, 0, 0, 0, 3};    //3x3
    vector<double> test_c = {2,3,4,5,6,7};  //2x3
    vector<double> test_d = {5,6,7,8}; //2x2
    vector<double> test_e = {1,2,3,4}; //2x2
    vector<double> ans_a = {6,9,12,15,18,21};
    vector<double> ans_b = {23,34,31,46};
    Matrix m(test_a,3,3);
    Matrix m9(test_c,2,3);
    Matrix m1(test_b,3,3);
    Matrix m2(test_d,2,2);
    Matrix m3(test_e,2,2);
    Matrix m4(ans_a,2,3);
    Matrix m5(ans_b,2,2);
    SUBCASE("Good Inputs"){
        CHECK_EQ((m*m1)==m1, true);
        CHECK_EQ((m9*m)==m9, true);
        CHECK_EQ((m9*m1)==m4, true);
        CHECK_EQ((m2*m3)==m5, true);
        m*=m1;
        m9*=m1;
        CHECK_EQ(m==m1, true);
        CHECK_EQ(m9==m4, true);
    }
    SUBCASE("Bad Inputs"){
            CHECK_THROWS(m1*=m2);
            CHECK_THROWS(m1*m2);
            CHECK_THROWS(m1*=m2);
            CHECK_THROWS(m1*m2);
            CHECK_THROWS(m*=m3);
            CHECK_THROWS(m*m3);
            CHECK_THROWS(m1*=m9);
    }
    
}
TEST_CASE ("Checking >=,<=,==,!=,<,>") {
    vector<double> test_a = {1, 0, 0, 0, 1, 0, 0, 0, 1}; //3x3
    vector<double> test_b = {3, 0, 0, 0, 3, 0, 0, 0, 3};    //3x3
    vector<double> test_c = {2,3,4,5,6,7};  //2x3
    vector<double> test_d = {5,6,7,8}; //2x2
    vector<double> test_e = {1,2,3,4}; //2x2
    vector<double> ans_a = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    vector<double> ans_b = {6,8,10,12};
    vector<double> ans_c = {-2, 0, 0, 0, -2, 0, 0, 0, -2};
    vector<double> ans_d = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    vector<double> ans_e = {4,4,4,4};
    Matrix m(test_a,3,3);
    Matrix m9(test_c,2,3);
    Matrix m1(test_b,3,3);
    Matrix m2(test_d,2,2);
    Matrix m3(test_e,2,2);
    Matrix m4(ans_a,3,3);
    Matrix m5(ans_b,2,2);
    Matrix m6(ans_c,3,3);
    Matrix m7(ans_d,3,3);
    Matrix m8(ans_e,2,2);
    SUBCASE("Good Inputs"){
        CHECK_EQ((m+m1)==m4, true);
        CHECK_EQ((m2+m3)==m5, true);
        CHECK_EQ(m1>m, true);
        CHECK_EQ(m>m7, false);
        CHECK_EQ(m1>=m1, true);
        CHECK_EQ((m2+m3)==m5, true);
        CHECK_EQ(m1>m, true);
        CHECK_EQ(m>m7, false);
        CHECK_EQ(m3<m2, true);
        CHECK_EQ(m3>m2, false);
        CHECK_EQ((m1-m)!=m7, false);
        CHECK_EQ((m2-m3)!=m8, false);
    }
    
}
