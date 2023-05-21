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
                << "第一个92位整数为(12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012): "
                << endl;
        VeryLongInt v1("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012");
        cout << v1 << endl;

        cout
                << "第二个92位整数为(11451456881145145688114514568811451456881145145688114514568811451456881145145688114514568811): "
                << endl;
        VeryLongInt v2("11451456881145145688114514568811451456881145145688114514568811451456881145145688114514568811");
        cout << v2 << endl;

        cout << "第一个92位整数 + 第二个92位整数" << endl << v1 + v2 << endl;
        cout << "第一个92位整数 - 第二个92位整数" << endl << v1 - v2 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================两个92位超长整数的四则运算====================" << endl;
        setWhite;

        cout << "第一个92位整数 * 第二个92位整数" << endl << v1 * v2 << endl;
        cout << "第一个92位整数 / 第二个92位整数" << endl << v1 / v2 << endl;
        cout << "第一个92位整数 % 第二个92位整数" << endl << v1 % v2 << endl;
        cout << "第二个92位整数 / 第一个92位整数" << endl << v2 / v1 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================两个92位超长整数的四则运算====================" << endl;
        setWhite;

        cout << "第二个92位整数 % 第一个92位整数" << endl << v2 % v1 << endl;
        v1 += v2;
        cout << "第一个92位整数 += 第二个92位整数" << endl << v1 << endl;
        v1 -= v2;
        cout << "第一个92位整数 -= 第二个92位整数" << endl << v1 << endl;
        v1 *= v2;
        cout << "第一个92位整数 *= 第二个92位整数" << endl << v1 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================两个92位超长整数的四则运算====================" << endl;
        setWhite;

        v1 /= v2;
        cout << "第一个92位整数 /= 第二个92位整数" << endl << v1 << endl;
        v1 %= v2;
        cout << "第一个92位整数 %= 第二个92位整数" << endl << v1 << endl;
        cout << "第一个92位整数 < 第二个92位整数: " << boolalpha << (v1 < v2) << endl << endl;
        cout << "第一个92位整数 <= 第二个92位整数: " << boolalpha << (v1 <= v2) << endl << endl;
        cout << "第一个92位整数 == 第二个92位整数: " << boolalpha << (v1 == v2) << endl << endl;
        cout << "第一个92位整数 > 第二个92位整数: " << boolalpha << (v1 > v2) << endl << endl;
        cout << "第一个92位整数 >= 第二个92位整数: " << boolalpha << (v1 >= v2) << endl << endl;
        cout << "第一个92位整数 != 第二个92位整数: " << boolalpha << (v1 != v2) << endl << endl;

    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================任意的数除以0的检验====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("1145612345678914654");
        VeryLongInt v2("0");
        cout << "第一个数为(1145612345678914654)" << endl << v1 << endl;
        cout << "第二个数为(0)" << endl << v2 << endl;
        cout << "第一个数 / 第二个数" << endl << v1 / v2 << endl;
    }
    catchException;

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================任意的数取模0的检验====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("1145612345678914654");
        VeryLongInt v2("0");
        cout << "第一个数为(1145612345678914654)" << endl << v1 << endl;
        cout << "第二个数为(0)" << endl << v2 << endl;
        cout << "第一个数 % 第二个数" << endl << v1 % v2 << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================任意的数加、减、乘0的检验====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("1145612345678914654");
        VeryLongInt v2("0");
        cout << "第一个数为(1145612345678914654)" << endl << v1 << endl;
        cout << "第二个数为(0)" << endl << v2 << endl;
        cout << "第一个数 + 第二个数" << endl << v1 + v2 << endl;
        cout << "第一个数 - 第二个数" << endl << v1 - v2 << endl;
        cout << "第一个数 * 第二个数" << endl << v1 * v2 << endl;
    }
    catchException;

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================某一92位超大整数混合自增自减====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012");
        VeryLongInt v2;
        cout
                << "第一个数为字符串构造(12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012)"
                << endl << v1 << endl;
        cout << "第二个数为默认构造" << endl << v2 << endl;

        v2 = ++v1;
        cout << "第二个数 = ++第一个数" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;

        v2 = v1++;
        cout << "第二个数 = 第一个数++" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;

        v2 = --v1;
        cout << "第二个数 = --第一个数" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;

        v2 = v1--;
        cout << "第二个数 = 第一个数--" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;
    }
    catchException;

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================某一92位超大整数赋值运算符测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012");
        VeryLongInt v2;
        VeryLongInt v3;
        cout
                << "第一个数为字符串构造(12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012)"
                << endl << v1 << endl;
        cout << "第二个数为默认构造" << endl << v2 << endl;
        cout << "第三个数为默认构造" << endl << v3 << endl;
        v3 = v2 = v1;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;
        cout << "第三个数现在的值为" << endl << v3 << endl;
    }
    catchException;

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================某一92位超大整数拷贝构造和求负测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012");
        VeryLongInt v2(v1);
        cout
                << "第一个数为字符串构造(12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012)"
                << endl << v1 << endl;
        cout << "第二个数为拷贝构造" << endl << v2 << endl;

        v2 = -v1;

        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================某一92位超大整数和长整型四则运算测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012");
        VeryLongInt v2(123456789);
        cout
                << "第一个数为字符串构造(12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012)"
                << endl << v1 << endl;
        cout << "第二个数为长整型构造(123456789)" << endl << v2 << endl;
        cout << "第一个数 + 第二个数" << endl << v1 + v2 << endl;
        cout << "第一个数 - 第二个数" << endl << v1 - v2 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================某一92位超大整数和长整型四则运算测试====================" << endl;
        setWhite;

        cout << "第一个数 * 第二个数" << endl << v1 * v2 << endl;
        cout << "第一个数 / 第二个数" << endl << v1 / v2 << endl;
        cout << "第一个数 % 第二个数" << endl << v1 % v2 << endl;

        cout << "第二个数 + 第一个数" << endl << v2 + v1 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================某一92位超大整数和长整型四则运算测试====================" << endl;
        setWhite;

        cout << "第二个数 - 第一个数" << endl << v2 - v1 << endl;
        cout << "第二个数 * 第一个数" << endl << v2 * v1 << endl;
        cout << "第二个数 / 第一个数" << endl << v2 / v1 << endl;
        cout << "第二个数 % 第一个数" << endl << v2 % v1 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================某一92位超大整数和长整型四则运算测试====================" << endl;
        setWhite;

        v1 += v2;
        cout << "第一个数 += 第二个数" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;

        v1 -= v2;
        cout << "第一个数 -= 第二个数" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================某一92位超大整数和长整型四则运算测试====================" << endl;
        setWhite;

        v1 *= v2;
        cout << "第一个数 *= 第二个数" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;

        v1 /= v2;
        cout << "第一个数 /= 第二个数" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;

        cout << "按任意键进入下一页..." << endl;
        getch();
        prePrint;
        setYellow;
        cout << endl << "====================某一92位超大整数和长整型四则运算测试====================" << endl;
        setWhite;

        v1 %= v2;
        cout << "第一个数 %= 第二个数" << endl;
        cout << "第一个数现在的值为" << endl << v1 << endl;
        cout << "第二个数现在的值为" << endl << v2 << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================某一任意字符串和任意长整型关系运算符测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("123456789");
        VeryLongInt v2(546321987);

        cout << "第一个数为字符串构造(123456789)" << endl << v1 << endl;
        cout << "第二个数为长整型构造(546321987)" << endl << v2 << endl;

        cout << "字符串整数 <=长整数: " << boolalpha << (v1 <= v2) << endl << endl;
        cout << "字符串整数 ==长整数: " << boolalpha << (v1 == v2) << endl << endl;
        cout << "字符串整数 > 长整数: " << boolalpha << (v1 > v2) << endl << endl;
        cout << "字符串整数 >=长整数: " << boolalpha << (v1 >= v2) << endl << endl;
        cout << "字符串整数 !=长整数: " << boolalpha << (v1 != v2) << endl << endl;
        cout << "字符串整数 < 长整数: " << boolalpha << (v1 < v2) << endl << endl;


    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================某一任意字符串和任意字符串关系运算符测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("4239367029101410");
        VeryLongInt v2("1231467789101410");

        cout << "第一个数为字符串构造(4239367029101410)" << endl << v1 << endl;
        cout << "第二个数为字符串构造(1231467789101410)" << endl << v2 << endl;

        cout << "第一个数 <= 第二个数: " << boolalpha << (v1 <= v2) << endl << endl;
        cout << "第一个数 == 第二个数: " << boolalpha << (v1 == v2) << endl << endl;
        cout << "第一个数 > 第二个数: " << boolalpha << (v1 > v2) << endl << endl;
        cout << "第一个数 >= 第二个数: " << boolalpha << (v1 >= v2) << endl << endl;
        cout << "第一个数 != 第二个数: " << boolalpha << (v1 != v2) << endl << endl;
        cout << "第一个数 < 第二个数: " << boolalpha << (v1 < v2) << endl << endl;


    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================超大整数输入重载运算符测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1;
        cin >> v1;
        cout << "你所输入的数字为" << endl << v1 << endl;

    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================自定义绝对值相加函数测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("-4239367029101410");
        VeryLongInt v2("1231467789101410");
        cout << "第一个数为字符串构造(-4239367029101410)" << endl << v1 << endl;
        cout << "第二个数为字符串构造(1231467789101410)" << endl << v2 << endl;
        cout << "两个数的绝对值之和" << endl << absAddUp(v1, v2) << endl;

    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================自定义绝对值相减(被减数绝对值大于等于减数)函数测试===================="
         << endl;
    setWhite;

    try
    {
        VeryLongInt v1("-4239367029101410");
        VeryLongInt v2("1231467789101410");
        cout << "第一个数为字符串构造(-4239367029101410)" << endl << v1 << endl;
        cout << "第二个数为字符串构造(1231467789101410)" << endl << v2 << endl;
        absAddUp(v1, v2);
        cout << "两个数的绝对值之差" << endl << absSubtractUp(v1, v2) << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================自定义取绝对值函数测试====================" << endl;
    setWhite;

    try
    {
        VeryLongInt v1("-4239367029101410");
        VeryLongInt v2("1231467789101410");
        cout << "第一个数为字符串构造(-4239367029101410)" << endl << v1 << endl;
        cout << "第二个数为字符串构造(1231467789101410)" << endl << v2 << endl;

        cout << "第一个数的绝对值为" << endl << abs(v1) << endl;
        cout << "第二个数的绝对值为" << endl << abs(v2) << endl;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================自定义任意进制转换(2-16进制)的函数测试====================" << endl;
    setWhite;

    try
    {
        string s1 = "5656161";
        string s2 = "75431";
        string s3 = "0x114514abc";
        string s4 = "0114514666";

        VeryLongInt v1 = s1;
        VeryLongInt v2 = s2;
        VeryLongInt v3 = s3;
        VeryLongInt v4 = s4;
        cout << "第一个数为十进制字符串(5656161)" << endl;
        cout << v1 << endl;
        cout << "第二个数为十进制字符串(75431)" << endl;
        cout << v2 << endl;
        cout << "第三个数为十六进制字符串(0x114514abc)" << endl;
        cout << v3 << endl;
        cout << "第四个数为八进制字符串(0114514666)" << endl;
        cout << v4 << endl;

        cout << "第一个数的二进制为: ";
        setGreen;
        cout << change(s1, 10, 2) << endl << endl;
        setWhite;

        cout << "第二个数的二进制为: ";
        setGreen;
        cout << change(s2, 10, 2) << endl << endl;
        setWhite;

        cout << "第一个数的六进制为: ";
        setGreen;
        cout << change(s1, 10, 6) << endl << endl;
        setWhite;

        cout << "第二个数的六进制为: ";
        setGreen;
        cout << change(s2, 10, 6) << endl << endl;
        setWhite;

        cout << "第三个数的二进制为: ";
        setGreen;
        cout << change(s3, 16, 2) << endl << endl;
        setWhite;

        cout << "第四个数的二进制为: ";
        setGreen;
        cout << change(s4, 8, 2) << endl << endl;
        setWhite;
    }
    catchException

    cout << "按任意键进入下一页..." << endl;
    getch();
    prePrint;
    setYellow;
    cout << endl << "====================自定义判断全0字符串测试====================" << endl;
    setWhite;

    try
    {
        string s1 = "000000";
        string s2 = "20000";
        VeryLongInt v1 = s1;
        VeryLongInt v2 = s2;
        cout << "第一个数为字符串(000000)" << endl << v1 << endl;
        cout << "第二个数为字符串(20000)" << endl << v2 << endl;

        cout << "第一个数是全0串吗? " << boolalpha << judge(s1) << endl << endl;
        cout << "第一个数是全0串吗? " << boolalpha << judge(s2) << endl << endl;

    }
    catchException

    cout << "拜拜ヾ(≧▽≦*)o 按任意键即可退出该系统:)";
    getch();
}