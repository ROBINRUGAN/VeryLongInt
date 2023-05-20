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
cout << "Copyright (c) 2023-2023 ���ٰ�(222200314). All Rights Reserved." << endl << endl;       \
cout << "��ӭ����MEWWW�ĳ������������d(�R���Q*)o" << endl

#define catchException                  \
catch (VeryLongIntException &e)         \
{                                       \
       cout<<VeryLongInt();             \
    setRed;                             \
    cout << e.what() << endl<<endl;     \
    setWhite;                           \
}

/**
 * @brief  <h3>��������ƽ��г���������Ĺ�˼��Ҳ����һ����Ԫ����Դ洢��λ������
 *
 * <p>
 * Ȼ�����������Ŀ����äĿ������Ϊ���ǻ���Ҫ���и߾��ȵĳ˺ͳ���
 * ����Ļ��ᵼ����������޷����㣬���ǵ�int�����ﵽ2147483647��
 * 10000��ƽ��Ϊһ�ڣ����Ҳ��๻�ˣ��ܻ�������������á�
 * ����Ļ��������30000����Ҳ�ǿ��Եģ����Ǿ��ǲ���������ĸ�������ˣ�
 * Ч��Ҳ��û��ʲô������ߣ���˵Ļ��ۺϿ����²�������ơ�
 * <p/>
 *
 * <p>
 * �����������Լ������������Ҳ�ܴܺ�ı����ڽ���������
 * <p/>
 */
#define BASE 10000

/**
 * @brief ������ַ���
 */
#define ERROR 0

/**
 * @brief ����ʮ�����ַ���
 */
#define IS_DEC 1

/**
 * @brief ���ǰ˽����ַ���
 */
#define IS_OCT 2

/**
 * @brief ����ʮ�������ַ���
 */
#define IS_HEX 3


using namespace std;

/**
 * @brief �Զ�����״��࣬������ű�����Ϣ
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
 * @brief ����������
 */
class VeryLongInt
{
public:

    /**
     * @brief ʮ������������
     */
    char sign;

    /**
     * @brief �������������ǲ���vector���д��
     */
    vector<int> number;

    /**
     * @brief �ַ������캯��
     */
    VeryLongInt(string number);

    /**
     * @brief Ĭ�Ϲ��캯��
     */
    VeryLongInt();

    /**
     * @brief �����͹��캯��
     * <p>Ȼ�������ֱ����ʮ����/�˽���/ʮ�����Ƶĵ;��ȹ����ˣ�ֱ��һ����λ
     * �ô����ü��
     */
    VeryLongInt(long number);

    /**
     * @brief �ַ��������Ĺ��캯��
     * <p>����Ϊ����������֮�󷽱���ʽת��
     */
    VeryLongInt(const char *a);

    /**
     * @brief �������캯��
     */
    VeryLongInt(const VeryLongInt &other);

    /**
     * @brief ���麯�������Լ����ַ����� �쳣/ʮ����/�˽���/ʮ������
     */
    int check(string number);

    /**
     * @brief ȥ��ǰ����
     */
    void trimZero();

    /**
     * @brief ������������������+=����
     */
    VeryLongInt operator+=(const VeryLongInt &other);

    /**
     * @brief ������������������+����
     */
    friend VeryLongInt operator+(const VeryLongInt &a, const VeryLongInt &b);

    /**
     * @brief ������������������-����
     */
    friend VeryLongInt operator-(const VeryLongInt &a, const VeryLongInt &b);

    /**
    * @brief ������������������-=����
    */
    VeryLongInt &operator-=(const VeryLongInt &other);

    /**
     * @brief ������������������=����
     */
    VeryLongInt &operator=(const VeryLongInt &other);

    /**
     * @brief ������������������\<����
     */
    bool operator<(const VeryLongInt &other) const;

    /**
     * @brief ������������������\<=����
     */
    bool operator<=(const VeryLongInt &other) const;

    /**
     * @brief ������������������>����
     */
    bool operator>(const VeryLongInt &other) const;

    /**
     * @brief ������������������>=����
     */
    bool operator>=(const VeryLongInt &other) const;

    /**
     * @brief ������������������!=����
     */
    bool operator!=(const VeryLongInt &other) const;

    /**
     * @brief ������������������==����
     */
    bool operator==(const VeryLongInt &other) const;

    /**
     * @brief ������������������*����
     */
    friend VeryLongInt operator*(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������*=����
     */
    VeryLongInt &operator*=(const VeryLongInt &other);

    /**
     * @brief ������������������/����
     */
    friend VeryLongInt operator/(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������/=����
     */
    VeryLongInt &operator/=(const VeryLongInt &other);

    /**
     * @brief ������������������%����
     */
    friend VeryLongInt operator%(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������%=����
     */
    VeryLongInt &operator%=(const VeryLongInt &other);

    /**
     * @brief ������������ǰ++����
     */
    VeryLongInt &operator++();

    /**
     * @brief �����������ĺ�++����
     */
    VeryLongInt operator++(int);

    /**
     * @brief ������������ǰ--����
     */
    VeryLongInt &operator--();

    /**
     * @brief �����������ĺ�--����
     */
    VeryLongInt operator--(int);


};

/**
 * @brief �������������������ȷ�ĳ�������
 */
ostream &operator<<(ostream &out, const VeryLongInt &veryLongInt);

/**
 * @brief ���������������¼����ȷ�ĳ�������
 */
istream &operator>>(istream &in, VeryLongInt &veryLongInt);

/**
 * @brief ����ֵ�����
 */
VeryLongInt absAddUp(VeryLongInt first, VeryLongInt second);

/**
 * @brief ����ֵ�������Ҫ���Ǵ�����С��
 */
VeryLongInt absSubtractUp(VeryLongInt first, VeryLongInt second);

/**
 * @brief ���س���������ľ���ֵ��ʽ
 */
VeryLongInt abs(VeryLongInt number);

//�жϴ��Ƿ�Ϊȫ�㴮
bool judge(string s);

/**
 * @brief ����ת������
 * @param number ԭ����n���Ƴ�������
 * @param n ԭ���Ľ���
 * @param m Ҫת�Ľ���
 * @return ת������ַ���
 */
string change(string number, int n, int m);

#endif //THIRD_222200314_VERYLONGINT1_H
