/**
 * @brief <h3> 个人信息
 * <p>
 * 班级：软件工程三班                                                                              <br>
 * 学号：222200314                                                                               <br>
 * 姓名：吴荣榜                                                                                   <br>
 * 电话：18859522606                                                                             <br>
 * 邮件地址：1220045015\@qq.com                                                                   <br>
 *
 * <h3> 主要算法与数据结构
 * <p>
 * 主要算法：模拟 二分 双指针 滑动窗格 高精度                                                           <br>
 * 数据结构：vector容器 string类                                                                   <br>
 * 简要描述：我们采用vector进行对超大整数的存储和维护操作，在高精度的加、减和乘的部分，我们采用
 * 模拟竖式运算的方式，来进行结果的计算。而在除法方面，我们采用二分法，结合双指针的方式来进行商
 * 的确定，并利用滑动窗格进行竖式除法的模拟，将时间复杂度降了一个logn水平。而在进制转换方面，我
 * 们采用模拟短除法的形式进行操作。                      <br><br>
 *
 * <h3> 开发环境和运行环境
 * <p>
 * 操作系统信息：Windows 11                                                                        <br>
 * 开发环境：CLion 2022.3.2                                                                       <br>
 * 运行时版本： 17.0.5+1-b653.25 amd64                                                             <br>
 *             VM: OpenJDK 64-Bit Server VM，JetBrains s.r.o.                                    <br>
 *  C++编译器版本  g++ (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0                  <br><br>
 *
 * <h3> 输入限制和输出说明
 * <p>
 * 我们将关键数据的输出颜色设置为绿色，将提示设置为黄色，警告和报错设置为红色，这样子可以使得程
 * 序界面更加的清晰和美观，增强了交互性。并且将测试环节的输出进行分页处理，用户按任意键即可进入
 * 下一页。也很大程度上提高了程序的条理性和美观性。                                                       <br><br>
 *
 * <h3> 参考文献
 * <p>
 * 无                                                                                           <br><br>
 *
 * <h3> 版权
 * <p>
 * Copyright (c) 2023-2023 吴荣榜(222200314). All Rights Reserved.                              <br><br>
 *
 * <h3> 其他需说明的问题
 * <p>
 * 无                                                                                           <br>
 */

#ifndef THIRD_222200314_VERYLONGINT1_H
#define THIRD_222200314_VERYLONGINT1_H

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

/**
 * @brief 设置句柄，设置控制台输出的颜色
 */
#define setRed SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12)
#define setGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)
#define setYellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14)
#define setWhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)

/**
 * @brief 封装了两个输出和输入绿色数据的语句
 */
#define enter(x) setGreen;cin>>x;cin.clear();cin.ignore();setWhite
#define print(x) setGreen;cout<<x;setWhite

/**
 * @brief 封装清屏和每次分屏输出均需要的顶部文字
 */
#define prePrint                                                                                \
system("cls");                                                                                  \
cout << "Copyright (c) 2023-2023 吴荣榜(222200314). All Rights Reserved." << endl << endl;       \
cout << "欢迎进入MEWWW的超大整数类程序ヾ(≧▽≦*)o" << endl

/**
 * @brief 封装抛错的catch操作
 */
#define catchException                                                                          \
catch (VeryLongIntException &e)                                                                 \
{                                                                                               \
       cout<<VeryLongInt();                                                                     \
    setRed;                                                                                     \
    cout << e.what() << endl<<endl;                                                             \
    setWhite;                                                                                   \
}

/**
 * @brief  <h3>采用万进制进行超大整数类的构思，也就是一个单元格可以存储四位的数字
 *
 * 然后这个进制数目不能盲目增大，因为我们还需要进行高精度的乘和除，
 * 过大的话会导致溢出或者无法计算，考虑到int的最大达到2147483647，
 * 10000的平方为一亿，这个也差不多够了，能基本做到充分利用。
 * 否则的话如果开到30000进制也是可以的，但是就是不方便后续的各项操作了，
 * 效率也并没有什么显著提高，因此的话综合考量下采用万进制。<br/>
 *
 * 这样不仅可以减少运算次数，也能很大的便利于结果的输出。
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

    /**
     * @brief 大整数类的自定义抛错
     */
    explicit VeryLongIntException(string message);

    /**
     * @brief 自定义的抛错信息get方法
     */
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
     * @brief 处理超大整数的取负重载
     */
    VeryLongInt operator-();

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
    friend bool operator<(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的\<=重载
     */
    friend bool operator<=(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的>重载
     */
    friend bool operator>(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的>=重载
     */
    friend bool operator>=(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的!=重载
     */
    friend bool operator!=(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的==重载
     */
    friend bool operator==(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief <h3>处理两个超大整数的*重载
     * <p>时间复杂度为O((n/4)*(m/4))
     * <p>极端情况下为O(n^2)
     */
    friend VeryLongInt operator*(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief 处理两个超大整数的*=重载
     */
    VeryLongInt &operator*=(const VeryLongInt &other);

    /**
     * @brief <h3>处理两个超大整数的/重载
     * <p>利用模拟竖式的思想，并采用二分法确定商的每一位
     * <p>时间复杂度为O(nmlogm)
     * <p>可以近似看成O(n^2)
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

/**
 * @brief 判断串是否为全零串
 */
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