#include "222200314_VeryLongInt1.h"

int main()
{
    try
    {
        // VeryLongInt v1("-11546165111q12");
        VeryLongInt v2("21546464884");
        VeryLongInt v3("1234567895615156165616514565646123456789");
        VeryLongInt v4("00001112");
        VeryLongInt v5("123456789");
        VeryLongInt v6("126");
        //cout << "v5= " << v5<<" ";
        //cout << "v6= " << v6 << endl;
        //v5 /= v6;
        //cout << "v5= " << v5<<" ";
        //cout << "v6= " << v6 << endl;
        //v5 /= v6;
        //cout << "v5= " << v5<<" ";
        //cout << "v6= " << v6 << endl;
        //v5 /= v6;
        //cout << "v5= " << v5<<" ";
        //cout << "v6= " << v6 << endl;
        //cout << "v5/v6= " << v5 / v6 << endl;

        cout << "v3=" << v3 << endl;
        cout << "v2=" << v2 << endl;
        cout << "v3/v2= " << v3 / v2 << endl;
        cout << "v3%v2= " << v3 % v2 << endl;
        v3%=v2;
        cout << "v3=" << v3 << endl;
        cout << "v2=" << v2 << endl;
        cout << "v3/v2= " << v3 / v2 << endl;
        cout << "v3%v2= " << v3 % v2 << endl;
        //if(v5<v6)
        //{
        //    cout << "v5 < v6" << endl;
        //}
        //if(v5<=v6)
        //{
        //    cout << "v5 <= v6" << endl;
        //}
        //if(v5>v6)
        //{
        //    cout << "v5 > v6" << endl;
        //}
        //if(v5>=v6)
        //{
        //    cout << "v5 >= v6" << endl;
        //}
        //if(v5==v6)
        //{
        //    cout << "v5 == v6" << endl;
        //}
        //if(v5!=v6)
        //{
        //    cout << "v5 != v6" << endl;
        //}

        //cout<<v2-v3<<endl;
    }
    catch (BigIntException e)
    {
        cout << e.what() << endl;
    }


    system("pause");
}
