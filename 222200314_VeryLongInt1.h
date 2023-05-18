#ifndef THIRD_222200314_VERYLONGINT1_H
#define THIRD_222200314_VERYLONGINT1_H

/**
 * <p> 采用万进制进行超大整数类的构思，也就是一个单元格可以存储四位的数字
 * <p> 然后这个进制数目不能盲目增大，因为我们还需要进行高精度的乘和除，
 * 过大的话会导致溢出或者无法计算，考虑到int的最大达到2147483647，
 * 10000的平方为一亿，这个也差不多够了，能基本做到充分利用。
 * 否则的话如果开到30000进制也是可以的，但是就是不方便后续的各项操作了，
 * 效率也并没有什么显著提高，因此的话综合考量下采用万进制。
 * <p> 这样不仅可以减少运算次数，也能很大的便利于结果的输出。
 */
#define BASE 10000

/**
 * 错误的字符串
 */
#define ERROR 0

/**
 * 这是十进制字符串
 */
#define IS_DEC 1

/**
 * 这是八进制字符串
 */
#define IS_OCT 2

/**
 * 这是十六进制字符串
 */
#define IS_HEX 3

#include <bits/stdc++.h>

using namespace std;

/**
 * 自定义的抛错类，用来存放报错信息
 */
class VeryLongIntException : exception
{
public:
    explicit VeryLongIntException(string message);

    string what();

private:
    string message;
};

/**
 * 超大整型类
 */
class VeryLongInt
{
public:

    /**
     * 十进制正负符号
     */
    char sign;

    /**
     * 超大整数，我们采用vector进行存放
     */
    vector<int> number;

    /**
     * 字符串构造函数
     */
    VeryLongInt(string number);

    /**
     * 默认构造函数
     */
    VeryLongInt();

    /**
     * 长整型构造函数，然后这个就直接走十进制/八进制/十六进制的低精度构造了，直接一步到位
     * 让代码变得简洁
     */
    VeryLongInt(long long number);

    /**
     * 字符串常量的构造函数，这是为了重载运算之后方便隐式转换
     */
    VeryLongInt(const char* a);

    /**
     * 拷贝构造函数
     */
    VeryLongInt(const VeryLongInt &other);

    /**
     * 检验函数，可以检验字符串是 异常/十进制/八进制/十六进制
     */
    int check(string number);

    /**
     * 去掉前导零
     */
    void trimZero();

    /**
     * 处理两个超大整数的+=重载
     */
    VeryLongInt operator+=(const VeryLongInt &other);

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
    friend VeryLongInt operator*(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * 处理两个超大整数的*=重载
     */
    VeryLongInt &operator*=(const VeryLongInt &other);

    /**
     * 处理两个超大整数的/重载
     */
    friend VeryLongInt operator/(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * 处理两个超大整数的/=重载
     */
    VeryLongInt &operator/=(const VeryLongInt &other);

    /**
     * 处理两个超大整数的%重载
     */
    friend VeryLongInt operator%(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * 处理两个超大整数的%=重载
     */
    VeryLongInt &operator%=(const VeryLongInt &other);

    /**
     * 处理超大整数的前++重载
     */
    VeryLongInt &operator++();

    /**
     * 处理超大整数的后++重载
     */
    VeryLongInt operator++(int);

    /**
     * 处理超大整数的前--重载
     */
    VeryLongInt &operator--();

    /**
     * 处理超大整数的后--重载
     */
    VeryLongInt operator--(int);


};

/**
 * 重载输出运算符，输出正确的超大整数
 */
ostream &operator<<(ostream &out, const VeryLongInt &veryLongInt);

/**
 * 重载输入运算符，录入正确的超大整数
 */
istream &operator>>(istream &in, VeryLongInt &veryLongInt);

/**
 * 绝对值的相加
 */
VeryLongInt absAddUp(VeryLongInt first, VeryLongInt second);

/**
 * 绝对值的相减，要求是大数减小数
 */
VeryLongInt absSubtractUp(VeryLongInt first, VeryLongInt second);

/**
 * 返回超大整数类的绝对值形式
 */
VeryLongInt abs(VeryLongInt number);

#endif //THIRD_222200314_VERYLONGINT1_H
