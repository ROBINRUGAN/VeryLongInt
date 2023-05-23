/**
 * @brief <h3> ������Ϣ
 * <p>
 * �༶�������������                                                                              <br>
 * ѧ�ţ�222200314                                                                               <br>
 * ���������ٰ�                                                                                   <br>
 * �绰��18859522606                                                                             <br>
 * �ʼ���ַ��1220045015\@qq.com                                                                   <br>
 *
 * <h3> ��Ҫ�㷨�����ݽṹ
 * <p>
 * ��Ҫ�㷨��ģ�� ���� ˫ָ�� �������� �߾���                                                           <br>
 * ���ݽṹ��vector���� string��                                                                   <br>
 * ��Ҫ���������ǲ���vector���жԳ��������Ĵ洢��ά���������ڸ߾��ȵļӡ����ͳ˵Ĳ��֣����ǲ���
 * ģ����ʽ����ķ�ʽ�������н���ļ��㡣���ڳ������棬���ǲ��ö��ַ������˫ָ��ķ�ʽ��������
 * ��ȷ���������û������������ʽ������ģ�⣬��ʱ�临�ӶȽ���һ��lognˮƽ�����ڽ���ת�����棬��
 * �ǲ���ģ��̳�������ʽ���в�����                      <br><br>
 *
 * <h3> �������������л���
 * <p>
 * ����ϵͳ��Ϣ��Windows 11                                                                        <br>
 * ����������CLion 2022.3.2                                                                       <br>
 * ����ʱ�汾�� 17.0.5+1-b653.25 amd64                                                             <br>
 *             VM: OpenJDK 64-Bit Server VM��JetBrains s.r.o.                                    <br>
 *  C++�������汾  g++ (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0                  <br><br>
 *
 * <h3> �������ƺ����˵��
 * <p>
 * ���ǽ��ؼ����ݵ������ɫ����Ϊ��ɫ������ʾ����Ϊ��ɫ������ͱ�������Ϊ��ɫ�������ӿ���ʹ�ó�
 * �������ӵ����������ۣ���ǿ�˽����ԡ����ҽ����Ի��ڵ�������з�ҳ�����û�����������ɽ���
 * ��һҳ��Ҳ�ܴ�̶�������˳���������Ժ������ԡ�                                                       <br><br>
 *
 * <h3> �ο�����
 * <p>
 * ��                                                                                           <br><br>
 *
 * <h3> ��Ȩ
 * <p>
 * Copyright (c) 2023-2023 ���ٰ�(222200314). All Rights Reserved.                              <br><br>
 *
 * <h3> ������˵��������
 * <p>
 * ��                                                                                           <br>
 */

#ifndef THIRD_222200314_VERYLONGINT1_H
#define THIRD_222200314_VERYLONGINT1_H

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

/**
 * @brief ���þ�������ÿ���̨�������ɫ
 */
#define setRed SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12)
#define setGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)
#define setYellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14)
#define setWhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)

/**
 * @brief ��װ�����������������ɫ���ݵ����
 */
#define enter(x) setGreen;cin>>x;cin.clear();cin.ignore();setWhite
#define print(x) setGreen;cout<<x;setWhite

/**
 * @brief ��װ������ÿ�η����������Ҫ�Ķ�������
 */
#define prePrint                                                                                \
system("cls");                                                                                  \
cout << "Copyright (c) 2023-2023 ���ٰ�(222200314). All Rights Reserved." << endl << endl;       \
cout << "��ӭ����MEWWW�ĳ������������d(�R���Q*)o" << endl

/**
 * @brief ��װ�״��catch����
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
 * @brief  <h3>��������ƽ��г���������Ĺ�˼��Ҳ����һ����Ԫ����Դ洢��λ������
 *
 * Ȼ�����������Ŀ����äĿ������Ϊ���ǻ���Ҫ���и߾��ȵĳ˺ͳ���
 * ����Ļ��ᵼ����������޷����㣬���ǵ�int�����ﵽ2147483647��
 * 10000��ƽ��Ϊһ�ڣ����Ҳ��๻�ˣ��ܻ�������������á�
 * ����Ļ��������30000����Ҳ�ǿ��Եģ����Ǿ��ǲ���������ĸ�������ˣ�
 * Ч��Ҳ��û��ʲô������ߣ���˵Ļ��ۺϿ����²�������ơ�<br/>
 *
 * �����������Լ������������Ҳ�ܴܺ�ı����ڽ���������
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

    /**
     * @brief ����������Զ����״�
     */
    explicit VeryLongIntException(string message);

    /**
     * @brief �Զ�����״���Ϣget����
     */
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
     * @brief ������������ȡ������
     */
    VeryLongInt operator-();

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
    friend bool operator<(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������\<=����
     */
    friend bool operator<=(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������>����
     */
    friend bool operator>(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������>=����
     */
    friend bool operator>=(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������!=����
     */
    friend bool operator!=(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������==����
     */
    friend bool operator==(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief <h3>������������������*����
     * <p>ʱ�临�Ӷ�ΪO((n/4)*(m/4))
     * <p>���������ΪO(n^2)
     */
    friend VeryLongInt operator*(const VeryLongInt &self, const VeryLongInt &other);

    /**
     * @brief ������������������*=����
     */
    VeryLongInt &operator*=(const VeryLongInt &other);

    /**
     * @brief <h3>������������������/����
     * <p>����ģ����ʽ��˼�룬�����ö��ַ�ȷ���̵�ÿһλ
     * <p>ʱ�临�Ӷ�ΪO(nmlogm)
     * <p>���Խ��ƿ���O(n^2)
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

/**
 * @brief �жϴ��Ƿ�Ϊȫ�㴮
 */
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