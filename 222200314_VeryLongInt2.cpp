#include "222200314_VeryLongInt1.h"

int main()
{
    prePrint;

    setYellow;
    cout << endl << "====================���캯���Ĳ���====================" << endl;
    setWhite;

    cout << "Ĭ�Ϲ���: " << endl;
    VeryLongInt v1;
    cout << v1 << endl;

    cout << "�ַ������죬���ַ���Ϊ(0): " << endl;
    VeryLongInt v2("0");
    cout << v2 << endl;

    cout << "�ַ������죬���ַ���Ϊ(+00): " << endl;
    VeryLongInt v3("+00");
    cout << v3 << endl;

    cout << "�ַ������죬���ַ���Ϊ(-0): " << endl;
    VeryLongInt v4("-0");
    cout << v4 << endl;

    cout << "�ַ������죬���ַ���Ϊ(-000): " << endl;
    VeryLongInt v5("-000");
    cout << v5 << endl;

    cout << "�ַ������죬���ַ���Ϊ(-00001): " << endl;
    VeryLongInt v6("-00001");
    cout << v6 << endl;

    cout << "�ַ������죬���ַ���Ϊ(187647121166609): " << endl;
    VeryLongInt v7("187647121166609");
    cout << v7 << endl;
    system("pause");
}
