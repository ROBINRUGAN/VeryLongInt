#include "222200314_VeryLongInt1.h"

int main()
{
    prePrint;

    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "默认构造: " << endl;
        VeryLongInt v;
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0): " << endl;
        VeryLongInt v("0");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0000): " << endl;
        VeryLongInt v("0000");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(+0): " << endl;
        VeryLongInt v("+0");
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "字符串构造，且字符串为(-00): " << endl;
        VeryLongInt v("-00");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(-000): " << endl;
        VeryLongInt v("-000");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0000): " << endl;
        VeryLongInt v("0000");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0x0000): " << endl;
        VeryLongInt v("0x0000");
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "字符串构造，且字符串为(4462626487878623219106144894949): " << endl;
        VeryLongInt v("4462626487878623219106144894949");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(-1241232447523442152123524): " << endl;
        VeryLongInt v("-1241232447523442152123524");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(00012345676543210): " << endl;
        VeryLongInt v("00012345676543210");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0x0123456789abcdef): " << endl;
        VeryLongInt v("0x0123456789abcdef");
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "字符串构造，且字符串为(0XFEDCBA9876543210): " << endl;
        VeryLongInt v("0XFEDCBA9876543210");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0a): " << endl;
        VeryLongInt v("0a");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0x): " << endl;
        VeryLongInt v("0x");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0X): " << endl;
        VeryLongInt v("0X");
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;


    try
    {
        cout << "字符串构造，且字符串为(12345678q): " << endl;
        VeryLongInt v("12345678q");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(-12345678q): " << endl;
        VeryLongInt v("-12345678q");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(000008): " << endl;
        VeryLongInt v("000008");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(000009): " << endl;
        VeryLongInt v("000009");
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "字符串构造，且字符串为(0544926): " << endl;
        VeryLongInt v("0544926");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(00000qwq2): " << endl;
        VeryLongInt v("00000qwq2");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0xABCDG): " << endl;
        VeryLongInt v("0xABCDG");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "字符串构造，且字符串为(0xABcDx): " << endl;
        VeryLongInt v("0xABcDx");
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "字符串构造，且字符串为(ABCD): " << endl;
        VeryLongInt v("ABCD");
        cout << v << endl;
    }
    catchException

    try
    {
        cout
                << "字符串构造，且字符串长度为2000位，为(12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890): "
                << endl;
        VeryLongInt v(
                "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
        cout << v << endl;
    }
    catchException

    try
    {
        cout
                << "字符串构造，且字符串长度为2000位，为(-12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890): "
                << endl;
        VeryLongInt v(
                "-12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "长整型构造，且该长整型为(0L): " << endl;
        VeryLongInt v(0L);
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "长整型构造，且该长整型为(LONG_MAX): " << endl;
        VeryLongInt v(LONG_MAX);
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "长整型构造，且该长整型为(LONG_MIN): " << endl;
        VeryLongInt v(LONG_MIN);
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "长整型构造，且该长整型为(123456): " << endl;
        VeryLongInt v(123456);
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "长整型构造，且该长整型为(-12345): " << endl;
        VeryLongInt v(-12345);
        cout << v << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================构造函数的测试====================" << endl;
    setWhite;

    try
    {
        cout << "长整型构造，且该长整型为(07777777777): " << endl;
        VeryLongInt v(017777777777);
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "长整型构造，且该长整型为(0x3f3f3f3f): " << endl;
        VeryLongInt v(0x3f3f3f3f);
        cout << v << endl;
    }
    catchException

    try
    {
        cout << "长整型构造，且该长整型为(0X3F3f3f3F): " << endl;
        VeryLongInt v(0X3F3f3f3F);
        cout << v << endl;
    }
    catchException


    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================学号和身份证号的四则运算====================" << endl;
    setWhite;

    try
    {
        cout << "身份证号为(350581200310192733): " << endl;
        VeryLongInt v1("350581200310192733");
        cout << v1 << endl;

        cout << "学号为(222200314): " << endl;
        VeryLongInt v2("222200314");
        cout << v2 << endl;

        cout << "身份证号(350581200310192733) + 学号(222200314)" << endl << v1 + v2 << endl;
        cout << "身份证号(350581200310192733) - 学号(222200314)" << endl << v1 - v2 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================学号和身份证号的四则运算====================" << endl;
        setWhite;

        cout << "身份证号(350581200310192733) * 学号(222200314)" << endl << v1 * v2 << endl;
        cout << "身份证号(350581200310192733) / 学号(222200314)" << endl << v1 / v2 << endl;
        cout << "身份证号(350581200310192733) % 学号(222200314)" << endl << v1 % v2 << endl;
        v1 += v2;
        cout << "身份证号(350581200310192733) += 学号(222200314)" << endl << v1 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================学号和身份证号的四则运算====================" << endl;
        setWhite;

        v1 -= v2;
        cout << "身份证号(350581200310192733) -= 学号(222200314)" << endl << v1 << endl;
        v1 *= v2;
        cout << "身份证号(350581200310192733) *= 学号(222200314)" << endl << v1 << endl;
        v1 /= v2;
        cout << "身份证号(350581200310192733) /= 学号(222200314)" << endl << v1 << endl;
        v1 %= v2;
        cout << "身份证号(350581200310192733) %= 学号(222200314)" << endl << v1 << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();

    prePrint;
    setYellow;
    cout << endl << "====================两个92位超长整数的四则运算====================" << endl;
    setWhite;
    try
    {
        cout
                << "第一个超长整数为(12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012): "
                << endl;
        VeryLongInt v1("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012");
        cout << v1 << endl;

        cout
                << "第二个超长整数为(11451456881145145688114514568811451456881145145688114514568811451456881145145688114514568811): "
                << endl;
        VeryLongInt v2("11451456881145145688114514568811451456881145145688114514568811451456881145145688114514568811");
        cout << v2 << endl;

        cout << "第一个超长整数 + 第二个超长整数" << endl << v1 + v2 << endl;
        cout << "第一个超长整数 - 第二个超长整数" << endl << v1 - v2 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================两个92位超长整数的四则运算====================" << endl;
        setWhite;

        cout << "第一个超长整数 * 第二个超长整数" << endl << v1 * v2 << endl;
        cout << "第一个超长整数 / 第二个超长整数" << endl << v1 / v2 << endl;
        cout << "第一个超长整数 % 第二个超长整数" << endl << v1 % v2 << endl;
        v1 += v2;
        cout << "第一个超长整数 += 第二个超长整数" << endl << v1 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================两个92位超长整数的四则运算====================" << endl;
        setWhite;

        v1 -= v2;
        cout << "第一个超长整数 -= 第二个超长整数" << endl << v1 << endl;
        v1 *= v2;
        cout << "第一个超长整数 *= 第二个超长整数" << endl << v1 << endl;
        v1 /= v2;
        cout << "第一个超长整数 /= 第二个超长整数" << endl << v1 << endl;
        v1 %= v2;
        cout << "第一个超长整数 %= 第二个超长整数" << endl << v1 << endl;
    }
    catchException


    cout << "拜拜ヾ(≧▽≦*)o 按任意键即可退出该系统:)";
    getch();
}
