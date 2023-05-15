//
// Created by RUGAN on 2023-05-07.
//

#ifndef THIRD_222200314_VERYLONGINT1_H
#define THIRD_222200314_VERYLONGINT1_H
#define BASE 10000

#include <bits/stdc++.h>

using namespace std;

//抛错类
class BigIntException : exception
{
public:
    explicit BigIntException(string message);

    string what();

private:
    string message;
};

//超大整型类
class VeryLongInt
{
public:

    //十进制正负符号
    char sign;

    //超大整数
    vector<int> number;

    //字符串构造函数
    VeryLongInt(string number);

    //默认构造函数
    VeryLongInt();

    VeryLongInt(long long number);

    VeryLongInt(const VeryLongInt &other);

    bool check(string number);

    void trimZero();

    /**
     * 处理两个超大整数的+=重载
     */
    VeryLongInt &operator+=(const VeryLongInt &other);

    /**
     * 处理两个超大整数的+重载
     */
    friend VeryLongInt operator+(const VeryLongInt &a, const VeryLongInt &b);

    /**
     * 处理两个超大整数的-重载
     */
    friend VeryLongInt operator-(const VeryLongInt &a, const VeryLongInt &b);

    /**
    * 处理两个超大整数的-=重载
    */
    VeryLongInt &operator-=(const VeryLongInt &other);

    /**
     * 处理两个超大整数的=重载
     */
    VeryLongInt &operator=(const VeryLongInt &other);

    /**
     * 处理两个超大整数的\<重载
     */
    bool operator<(const VeryLongInt &other) const;

    /**
     * 处理两个超大整数的\<=重载
     */
    bool operator<=(const VeryLongInt &other) const;

    /**
     * 处理两个超大整数的>重载
     */
    bool operator>(const VeryLongInt &other) const;

    /**
     * 处理两个超大整数的>=重载
     */
    bool operator>=(const VeryLongInt &other) const;

    /**
     * 处理两个超大整数的!=重载
     */
    bool operator!=(const VeryLongInt &other) const;

    /**
     * 处理两个超大整数的==重载
     */
    bool operator==(const VeryLongInt &other) const;

    /**
     * 处理两个超大整数的*重载
     */
    friend VeryLongInt operator*(const VeryLongInt &self,const VeryLongInt &other);

    /**
     * 处理两个超大整数的*=重载
     */
    VeryLongInt &operator*=(const VeryLongInt &other);

    /**
     * 处理两个超大整数的/重载
     */
    friend VeryLongInt operator/(const VeryLongInt &self,const VeryLongInt &other);

    /**
     * 处理两个超大整数的%重载
     */
    friend VeryLongInt operator%(const VeryLongInt &self,const VeryLongInt &other);

    /**
     * 处理两个超大整数的%=重载
     */
    VeryLongInt &operator%=(const VeryLongInt &other);

    /**
     * 处理两个超大整数的/=重载
     */
    VeryLongInt &operator/=(const VeryLongInt &other);

};

ostream &operator<<(ostream &out, const VeryLongInt &veryLongInt);

istream &operator>>(istream &in, VeryLongInt &veryLongInt);


#endif //THIRD_222200314_VERYLONGINT1_H
