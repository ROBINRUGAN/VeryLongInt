#include "222200314_VeryLongInt1.h"

int main()
{
    cout << "Copyright (c) 2023-2023 ÎâÈÙ°ñ(222200314). All Rights Reserved." << endl << endl;
    try
    {
        // VeryLongInt v1("-11546165111q12");
        VeryLongInt v2("21546464884");
        cout << v2 << endl;

        VeryLongInt v3("1234567895615156165616514565646123456789");
        cout<<v3<<endl;
        //VeryLongInt v4("00001112");
        //cout<<v4<<endl;
        VeryLongInt v5("123456789");
        cout<<v5<<endl;
        VeryLongInt v6("126");
        cout<<v6<<endl;
        cout << "v5= " << v5<<" ";
        cout << "v6= " << v6 << endl;
        v5 /= v6;
        cout << "v5= " << v5<<" ";
        cout << "v6= " << v6 << endl;
        v5 /= v6;
        cout << "v5= " << v5<<" ";
        cout << "v6= " << v6 << endl;
        v5 /= v6;
        cout << "v5= " << v5<<" ";
        cout << "v6= " << v6 << endl;
        cout << "v5/v6= " << v5 / v6 << endl;

        cout << "v3= " << v3 << endl;
        cout << "v2= " << v2 << endl;
        cout << "v3/v2= " << v3 / v2 << endl;
        cout << "v3%v2= " << v3 % v2 << endl;
        v3%=v2;
        cout << "v3= " << v3 << endl;
        cout << "v2= " << v2 << endl;
        cout << "v3/v2= " << v3 / v2 << endl;
        cout << "v3%v2= " << v3 % v2 << endl;

        cout << "v2= " << v2 << endl;
        cout << "v2++ " << v2++ << endl;
        cout << "v2= " << v2 << endl;
        cout << "++v2= " << ++v2 << endl;
        cout << "v2= " << v2 << endl;

        v3 = -0x12345;
        v2 = 145;
        cout << "v3= " << v3 << endl;
        cout << "v2= " << v2 << endl;
        cout << "v3+v2 " << (v3 += v2) << endl;

        v3 = "125465456468498989345";
        v2 = "12345";
        cout << "v3= " << v3 << endl;
        cout << "v2= " << v2 << endl;
        cout << "v3+v2 " << (v3 + v2) << endl;

        v3 = "-456655151";
        v2 = "12345";
        cout << "v3= " << v3 << endl;
        cout << "v2= " << v2 << endl;
        cout << "v3+v2 " << (v3 + v2) << endl;

        v3 = "-1255456345";
        v2 = "-12345";
        cout << "v3= " << v3 << endl;
        cout << "v2= " << v2 << endl;
        cout << "v3+v2 " << (v3 + v2) << endl;
        if(v5<v6)
        {
            cout << "v5 < v6" << endl;
        }
        if(v5<=v6)
        {
            cout << "v5 <= v6" << endl;
        }
        if(v5>v6)
        {
            cout << "v5 > v6" << endl;
        }
        if(v5>=v6)
        {
            cout << "v5 >= v6" << endl;
        }
        if(v5==v6)
        {
            cout << "v5 == v6" << endl;
        }
        if(v5!=v6)
        {
            cout << "v5 != v6" << endl;
        }

        cout<<v2-v3<<endl;

    }
    catch (VeryLongIntException e)
    {
        cout << e.what() << endl;
    }


    system("pause");
}
