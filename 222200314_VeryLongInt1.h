#ifndef THIRD_222200314_VERYLONGINT1_H
#define THIRD_222200314_VERYLONGINT1_H

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#define setRed SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12)
#define setGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)
#define setYellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14)
#define setWhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
#define enter(x) setGreen;cin>>x;cin.clear();cin.ignore();setWhite
#define print(x) setGreen;cout<<x;setWhite

#define prePrint                                                                                \
system("cls");                                                                                  \
cout << "Copyright (c) 2023-2023 吴荣榜(222200314). All Rights Reserved." << endl << endl;       \
cout << "欢迎进入MEWWW的超大整数类程序ヾ(≧▽≦*)o" << endl

#define catchException                  \
catch (VeryLongIntException &e)         \
{                                       \
       cout<<VeryLongInt();             \
    setRed;                             \
    cout << e.what() << endl<<endl;     \
    setWhite;                           \
}

/**
 * @brief  <h3>采用万进制进行超大整数类的构思，也就是一个单元格可以存储四位的数字
 *
 * <p>
 * 然后这个进制数目不能盲目增大，因为我们还需要进行高精度的乘和除，
 * 过大的话会导致溢出或者无法计算，考虑到int的最大达到2147483647，
 * 10000的平方为一亿，这个也差不多够了，能基本做到充分利用。
 * 否则的话如果开到30000进制也是可以的，但是就是不方便后续的各项操作了，
 * 效率也并没有什么显著提高，因此的话综合考量下采用万进制。
 * <p/>
 *
 * <p>
 * 这样不仅可以减少运算次数，也能很大的便利于结果的输出。
 * <p/>
 */
#define BASE 10000

/**
 * @brief 错误的字符串
 */
#define ERROR 0

/**
 * @brief 这是十进制字符串
 */
#define IS_DEC 1

/**
 * @brief 这是八进制字符串
 */
#define IS_OCT 2

/**
 * @brief 这是十六进制字符串
 */
#define IS_HEX 3


using namespace std;

/**
 * @brief 自定义的抛错类，用来存放报错信息
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
 * @brief 超大整型类
 */
class VeryLongInt
{
public:

    /**
     * @brief 十进制正负符号
     */
    char sign;

    /**
     * @brief 超大整数，我们采用vector进行存放
     */
    vector<int> number;

    /**
     * @brief 字符串构造函数
     */
    VeryLongInt(string number);

    /**
     * @brief 默认构造函数
     */
    VeryLongInt();

    /**
     * @brief 长整型构造函数
     * <p>然后这个就直接走十进制/八进制/十六进制的低精度构造了，直接一步到位
     * 让代码变得简洁
     */
    VeryLongInt(long number);

    /**
     * @brief 字符串常量的构造函数
     * <p>这是为了重载运算之后方便隐式转换
     */
    VeryLongInt(const char *a);

    /**
     * @brief 拷贝构造函数
     */
    VeryLongInt(const VeryLongInt &other);

    /**
     * @brief 检验函数，可以检验字符串是 异常/十进制/八进制/十六进制
     */
    int check(string number);

    /**
     * @brief 去掉前导零
     */
    void trimZero();

    /**
     * @brief 处理两个超大整数的+=重载
     */
    VeryLongInt operator+=(const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的+重载
     */
    friend VeryLongInt operator+(const VeryLongInt &a, const VeryLongInt &b);

    /**
     * @brief 处理两个超大整数的-重载
     */
    friend VeryLongInt operator-(const VeryLongInt &a, const VeryLongInt &b);

    /**
    * @brief 处理两个超大整数的-=重载
    */
    VeryLongInt &operator-=(const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的=重载
     */
    VeryLongInt &operator=(const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的\<重载
     */
    bool operator<(const VeryLongInt &other) const;

    /**
     * @brief 处理两个超大整数的\<=重载
     */
    bool operator<=(const VeryLongInt &other) const;

    /**
     * @brief 处理两个超大整数的>重载
     */
    bool operator>(const VeryLongInt &other) const;

    /**
     * @brief 处理两个超大整数的>=重载
     */
    bool operator>=(const VeryLongInt &other) const;

    /**
     * @brief 处理两个超大整数的!=重载
     */
    bool operator!=(const VeryLongInt &other) const;

    /**
     * @brief 处理两个超大整数的==重载
     */
    bool operator==(const VeryLongInt &other) const;

    /**
     * @brief 处理两个超大整数的*重载
     */
    friend VeryLongInt operator*(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的*=重载
     */
    VeryLongInt &operator*=(const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的/重载
     */
    friend VeryLongInt operator/(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的/=重载
     */
    VeryLongInt &operator/=(const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的%重载
     */
    friend VeryLongInt operator%(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的%=重载
     */
    VeryLongInt &operator%=(const VeryLongInt &other);

    /**
     * @brief 处理超大整数的前++重载
     */
    VeryLongInt &operator++();

    /**
     * @brief 处理超大整数的后++重载
     */
    VeryLongInt operator++(int);

    /**
     * @brief 处理超大整数的前--重载
     */
    VeryLongInt &operator--();

    /**
     * @brief 处理超大整数的后--重载
     */
    VeryLongInt operator--(int);


};

/**
 * @brief 重载输出运算符，输出正确的超大整数
 */
ostream &operator<<(ostream &out, const VeryLongInt &veryLongInt);

/**
 * @brief 重载输入运算符，录入正确的超大整数
 */
istream &operator>>(istream &in, VeryLongInt &veryLongInt);

/**
 * @brief 绝对值的相加
 */
VeryLongInt absAddUp(VeryLongInt first, VeryLongInt second);

/**
 * @brief 绝对值的相减，要求是大数减小数
 */
VeryLongInt absSubtractUp(VeryLongInt first, VeryLongInt second);

/**
 * @brief 返回超大整数类的绝对值形式
 */
VeryLongInt abs(VeryLongInt number);

//判断串是否为全零串
bool judge(string s);

/**
 * @brief 进制转换函数
 * @param number 原来的n进制超大整数
 * @param n 原来的进制
 * @param m 要转的进制
 * @return 转换后的字符串
 */
string change(string number, int n, int m);

#endif //THIRD_222200314_VERYLONGINT1_H
