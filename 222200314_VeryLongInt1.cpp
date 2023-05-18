//
// Created by RUGAN on 2023-05-07.
//

#include "222200314_VeryLongInt1.h"


using namespace std;


/**
 * <h3>大整数类的自定义抛错
 */
VeryLongIntException::VeryLongIntException(string message) : message(std::move(message))
{
}

string VeryLongIntException::what()
{
    return message;
}

/**
 * <h3>超大十进制整数构造函数，转成vector存储
 */
VeryLongInt::VeryLongInt(string number)
{
    int type = check(number);

    if (type == ERROR)
    {
        cout << "0" << endl;
        throw VeryLongIntException("mewww!!!! 这不是合法的十进制/八进制/十六进制!");
    }

    //八进制的话先进行一波进制转换
    if (type == IS_OCT)
    {
        number = change(number, 8, 10);
    }

        //十六进制的话先进行一波进制转换
    else if (type == IS_HEX)
    {
        number = change(number.substr(2, number.size() - 2), 16, 10);
    }

    //十进制的构造初始化，上面已经把八进制和十六进制进行转换了
    //先记录一下原长度
    int originLength = number.length();

    //如果是十进制的话，要考虑到符号占位问题
    int signBlock = 0;

    //一个下标指针，用来分割整数的
    int i;

    //符号默认为+
    sign = '+';

    //如果首位是-号，那么设置，并且标记符号占位
    if (number[0] == '-')
    {
        sign = '-';
        signBlock = 1;
    }
        //一般情况下是不写+号，但是写了也不算错，同样也要标记符号占位
    else if (number[0] == '+')
    {
        sign = '+';
        signBlock = 1;
    }

    //最最尾巴开始分割，每次移动四位，直到移到边界
    //这个边界就是符号占位
    for (i = originLength - 4; i >= signBlock; i -= 4)
    {
        // cout << i << endl;  debug

        //然后就开始四位四位的计算，每四位数转成字符串
        //temp用来保存计算过程的值
        int temp = 0;
        for (int j = i; j <= i + 3; j++)
        {
            temp = temp * 10 + number[j] - '0';
        }

        //计算完了直接尾插
        this->number.emplace_back(temp);

        //计算完了看一下，如果再移的话越界了，也就是不满四位了，直接退出，
        //进行单独的特殊判断
        if (i - signBlock < 4)
        {
            break;
        }
    }

    //这里要注意一下，如果for循环一开始都进不去的话，i的值是负数，所以的话我们要还原i
    if (originLength < 4)
    {
        i = originLength;
    }

    //只要这个i不是0，说明进入了特殊判断环节
    if (i)
    {
        int temp = 0;

        //我们从符号位往后开始计算
        for (int j = signBlock; j <= i - 1; j++)
        {
            temp = temp * 10 + number[j] - '0';
        }
        this->number.emplace_back(temp);
    }
}

/**
 * <h3>默认值为零的无参构造函数
 */
VeryLongInt::VeryLongInt()
{
    sign = '+';
    this->number.emplace_back(0);
}

/**
 * <h3>检验是不是合法的10进制/16进制/8进制
 */
int VeryLongInt::check(string number)
{
    //一开始默认是错的
    int type = ERROR;

    //首先我们先判断第一位到底是什么，并且先初步区分
    //第一位是加号、或者减号、或者是数字0-9，可能是合法十进制数
    //因为第一位是0的话还可能是八进制数和十进制数
    if (number[0] == '+' || number[0] == '-' || (number[0] >= '0' && number[0] <= '9'))
    {
        type = IS_DEC;
    }

    //如果长度只有一位，那么要保证这是0-9的东西，单单正负号不合法，然后就可以返回了，判断完毕
    if (number.length() == 1)
    {
        if (number[0] < '0' || number[0] > '9')
        {
            type = ERROR;
        }
        return type;
    }

    //接下来进行第二位的判断，既然不是一位数，那么至少两位数
    //如果第一位是0，那么就只可能是八进制和十六进制了
    if (number[0] == '0')
    {
        //第二位如果是x或者X的话，那么就可能是正确的十六进制了
        if (number[1] == 'x' || number[1] == 'X')
        {
            type = IS_HEX;
        }

            //不然的话第二位就只能是数字了,而且只能是0-7，不能超过八进制
        else if (number[1] >= '0' && number[1] <= '7')
        {
            type = IS_OCT;
        }

            //其他的就是错的了，包括非法字符，以及8，9等等
        else
        {
            type = ERROR;
        }
    }

    //如果这个的长度只有2，那么要保证是个正确的数，比如普普通通的十进制数，如12，
    //比较短的八进制数，如05这样，
    //然后不可能是十六进制数，前面已经初步判断过了，所以只需要把十六进制的干掉就行
    //判断完了就可以直接return了
    if (number.length() == 2)
    {
        //如果可能是十六进制的话
        if (number[0] == '0' && type == IS_HEX)
        {
            type = ERROR;
        }
        return type;
    }

    //接下来就是多于两位的情况了，我们已经对三种进制做了区分，现在只需要分三类遍历即可
    //我们从第三位开始比较
    for (int i = 2; i < number.length(); i++)
    {
        //初筛后是十进制
        if (type == IS_DEC)
        {
            if (number[i] < '0' || number[i] > '9')
            {

                type = ERROR;
            }
        }
            //初筛后是八进制
        else if (type == IS_OCT)
        {
            if (number[i] < '0' || number[i] > '7')
            {
                type = ERROR;
            }
        }
            //初筛后是十六进制
        else if (type == IS_HEX)
        {
            //正难则反，采用补集思想
            if (number[i] >= '0' && number[i] <= '9' || number[i] >= 'A' && number[i] <= 'F' ||
                    number[i] >= 'a' && number[i] <= 'f')
            {
                type = IS_HEX;
            }
            else
            {
                type = ERROR;
            }
        }
        //一个独立于他们之外的if，判断是否error
        //如果都已经是错的了，然后就直接出去
        //可能是一开始就是ERROR，或者是上面导致变成了ERROR
        //这样的话上面就不需要写break了，非常方便，也不会浪费时间
        if (type == ERROR)
        {
            break;
        }
    }
    return type;
}

VeryLongInt::VeryLongInt(long long int number)
{
    sign = '+';
    if (number < 0)
    {
        sign = '-';
        number = -number;
    }
    while (number)
    {
        this->number.emplace_back(number % BASE);
        number /= BASE;
    }
}

VeryLongInt::VeryLongInt(const VeryLongInt &other)
{
    this->number = other.number;
    this->sign = other.sign;
}

void VeryLongInt::trimZero()
{
    while (number.size() > 1 && number.back() == 0)
    {
        number.pop_back();
    }
}

VeryLongInt VeryLongInt::operator+=(const VeryLongInt &other)
{
    if (sign == '+' && other.sign == '+')
    {
        *this = absAddUp(*this, other);
        this->sign = '+';
    }
    if (sign == '-' && other.sign == '-')
    {
        *this = absAddUp(*this, other);
        this->sign = '-';
    }
    if (sign == '+' && other.sign == '-')
    {
        if (abs(*this) < abs(other))
        {
            *this = absSubtractUp(other, *this);
            this->sign = '-';
        }
        if (abs(*this) >= abs(other))
        {
            *this = absSubtractUp(*this, other);
            this->sign = '+';
        }
    }
    if (sign == '-' && other.sign == '+')
    {
        if (abs(*this) <= abs(other))
        {
            *this = absSubtractUp(other, *this);
            this->sign = '+';
        }
        if (abs(*this) > abs(other))
        {
            *this = absSubtractUp(*this, other);
            this->sign = '-';
        }
    }
    return *this;
}

VeryLongInt operator+(const VeryLongInt &a, const VeryLongInt &b)
{
    VeryLongInt res = a;
    res += b;
    return res;
}

VeryLongInt operator-(const VeryLongInt &a, const VeryLongInt &b)
{
    VeryLongInt res = a;
    res -= b;
    return res;
}

VeryLongInt &VeryLongInt::operator-=(const VeryLongInt &other)
{
    if (sign == '+' && other.sign == '+')
    {
        if (abs(*this) < abs(other))
        {
            *this = absSubtractUp(other, *this);
            this->sign = '-';
        }
        if (abs(*this) >= abs(other))
        {
            *this = absSubtractUp(*this, other);
            this->sign = '+';
        }
    }
    if (sign == '-' && other.sign == '-')
    {
        if (abs(*this) <= abs(other))
        {
            *this = absSubtractUp(other, *this);
            this->sign = '+';
        }
        if (abs(*this) > abs(other))
        {
            *this = absSubtractUp(*this, other);
            this->sign = '-';
        }
    }
    if (sign == '+' && other.sign == '-')
    {
        *this = absAddUp(other, *this);
        this->sign = '+';
    }
    if (sign == '-' && other.sign == '+')
    {
        *this = absAddUp(other, *this);
        this->sign = '-';
    }
    return *this;
}

/**
 * <h3>高精度乘上高精度
 * <p>时间复杂度为O((n/4)*(m/4))
 * <p>极端情况下为O(n^2)
 */
VeryLongInt operator*(const VeryLongInt &self, const VeryLongInt &other)
{
    VeryLongInt result;
    int selfLength = self.number.size();
    int otherLength = other.number.size();

    //直接进行预存大小，方便之后的下标索引
    result.number.resize(selfLength + otherLength);

    //暂时先不考虑FFT和Karatsuba算法
    for (int i = 0; i < selfLength; ++i)
    {
        int carry = 0;
        for (int j = 0; j < otherLength; ++j)
        {
            int prod = self.number[i] * other.number[j] + carry + result.number[i + j];
            carry = prod / BASE;
            result.number[i + j] = prod % BASE;
        }
        if (carry > 0)
        {
            result.number[i + otherLength] += carry;
        }
    }
    // 去掉前导零
    result.trimZero();
    return result;
}

VeryLongInt &VeryLongInt::operator*=(const VeryLongInt &other)
{
    *this = ((*this) * other);
    return *this;
}

VeryLongInt &VeryLongInt::operator=(const VeryLongInt &other)
{
    this->sign = other.sign;
    this->number = other.number;
    return *this;
}


bool VeryLongInt::operator<(const VeryLongInt &other) const
{
    //负数一定小于正数，直接返回true
    if (this->sign == '-' && other.sign == '+')
    {
        return true;
    }
    //正数一定大于负数，直接返回false
    if (this->sign == '+' && other.sign == '-')
    {
        return false;
    }
    //如果两数相等，直接出去
    if (*this == other)
    {
        return false;
    }
    //接下来就是都是负号，而且两数不相等的情况
    if (this->sign == '-' && other.sign == '-')
    {
        return !(abs(*this) < abs(other));
    }

    //接下来就是都是正号，而且两数不相等的情况
    if (this->number.size() < other.number.size())
    {
        return true;
    }
    if (this->number.size() > other.number.size())
    {
        return false;
    }
    for (int i = this->number.size() - 1; i >= 0; i--)
    {
        if (this->number[i] < other.number[i])
        {
            return true;
        }
        if (this->number[i] > other.number[i])
        {
            return false;
        }
    }
}

bool VeryLongInt::operator<=(const VeryLongInt &other) const
{
    if (*this < other || *this == other)
    {
        return true;
    }
    return false;
}

bool VeryLongInt::operator>=(const VeryLongInt &other) const
{

    if (*this > other || *this == other)
    {
        return true;
    }
    return false;
}

bool VeryLongInt::operator>(const VeryLongInt &other) const
{
    //负数一定小于正数，直接返回false
    if (this->sign == '-' && other.sign == '+')
    {
        return false;
    }
    //正数一定大于负数，直接返回true
    if (this->sign == '+' && other.sign == '-')
    {
        return true;
    }
    //如果两数相等，直接出去
    if (*this == other)
    {
        return false;
    }
    //接下来就是都是负号，而且两数不相等的情况
    if (this->sign == '-' && other.sign == '-')
    {
        return !(abs(*this) > abs(other));
    }

    //接下来就是都是正号，而且两数不相等的情况
    if (this->number.size() > other.number.size())
    {
        return true;
    }
    if (this->number.size() < other.number.size())
    {
        return false;
    }
    for (int i = this->number.size() - 1; i >= 0; i--)
    {
        if (this->number[i] > other.number[i])
        {
            return true;
        }
        if (this->number[i] < other.number[i])
        {
            return false;
        }
    }
}

bool VeryLongInt::operator!=(const VeryLongInt &other) const
{
    return !(*this == other);
}

bool VeryLongInt::operator==(const VeryLongInt &other) const
{
    if (this->sign != other.sign)
    {
        return false;
    }
    if (this->number.size() != other.number.size())
    {
        return false;
    }
    for (int i = this->number.size() - 1; i >= 0; i--)
    {
        if (this->number[i] != other.number[i])
        {
            return false;
        }
    }
    return true;
}

/**
 * <h3>高精度除以高精度的重载
 * <p>利用模拟竖式的思想，并采用二分法确定商的每一位
 * <p>时间复杂度为O(nmlogm)
 * <p>可以近似看成O(n^2)
 */
VeryLongInt operator/(const VeryLongInt &self, const VeryLongInt &other)
{
    VeryLongInt result, temp;
    for (int i = self.number.size() - 1; i >= 0; i--)
    {
        temp.number.insert(temp.number.begin(), self.number[i]);
        //因为我的无参构造函数默认有一个元素0，因此在进行计算的时候需要把这个前导零去掉，否则会出问题

        temp.trimZero();

        int left = 0, right = BASE - 1, ans = 0;

        //二分法试出商的每一位
        //最后出去的情况就是两个指针交错
        //我的ans会实时更新最大的上限（小于或等于），所以不用担心
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (other * mid <= temp)
            {
                //双端不断逼近，因此如果我能更新ans，那么我的ans一定更优，
                // 那么最后一次的ans就是答案
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        //头插，方便运算
        result.number.insert(result.number.begin(), ans);
        //cout << "temp=" << temp << " " << "other=" << other << " " << endl;
        //cout << "number[i]" << self.number[i] << " " << "ans=" << ans << endl;
        //模拟竖式除法中的减法操作
        temp = temp - other * ans;
    }
    //去掉前导零
    result.trimZero();
    //更新符号
    if (self.sign == other.sign && other.sign == '+')
    {
        result.sign = '+';
    }
    else if (self.sign == other.sign && other.sign == '-')
    {
        result.sign = '+';
    }
    else
    {
        result.sign = '-';
    }
    return result;
}

VeryLongInt &VeryLongInt::operator/=(const VeryLongInt &other)
{
    *this = ((*this) / other);
    return *this;
}

VeryLongInt operator%(const VeryLongInt &self, const VeryLongInt &other)
{
    return self - self / other * other;
}

VeryLongInt &VeryLongInt::operator%=(const VeryLongInt &other)
{
    *this = (*this) % other;
    return *this;
}

VeryLongInt &VeryLongInt::operator++()
{
    *this += 1;
    return *this;
}

VeryLongInt VeryLongInt::operator++(int)
{
    VeryLongInt temp = *this;
    *this += 1;
    return temp;
}

VeryLongInt &VeryLongInt::operator--()
{
    *this -= 1;
    return *this;
}

VeryLongInt VeryLongInt::operator--(int)
{
    VeryLongInt temp = *this;
    *this -= 1;
    return temp;
}

VeryLongInt::VeryLongInt(const char *a)
{
    VeryLongInt v1((string(a)));
    *this = v1;
}


//重载超大整数的输出功能
ostream &operator<<(ostream &out, const VeryLongInt &veryLongInt)
{
    string number = "";
    for (int i = veryLongInt.number.size() - 1; i >= 0; i--)
    {

        if (veryLongInt.number[i] < 1000)
        {
            number += "0";
        }
        if (veryLongInt.number[i] < 100)
        {
            number += "0";
        }
        if (veryLongInt.number[i] < 10)
        {
            number += "0";
        }
        number += to_string(veryLongInt.number[i]);
    }
    out << "十进制数为：";
    if (veryLongInt.sign == '-')
    {
        out << veryLongInt.sign;
    }
    for (int i = veryLongInt.number.size() - 1; i >= 0; i--)
    {
        if (i != veryLongInt.number.size() - 1)
        {
            if (veryLongInt.number[i] < 1000)
            {
                out << "0";
            }
            if (veryLongInt.number[i] < 100)
            {
                out << "0";
            }
            if (veryLongInt.number[i] < 10)
            {
                out << "0";
            }
        }
        out << veryLongInt.number[i];
        if (i > 0)
        {
            out << ",";
        }
    }

    string octNumber = change(number, 10, 8);
    string hexNumber = change(number, 10, 16);

    //计算出来第一个空格的位置
    int octBlank = (octNumber.length() - 1) % 4;
    int hexBlank = (hexNumber.length() - 1) % 4;

    out << endl << "八进制数为：";
    if (veryLongInt.sign == '-')
    {
        out << veryLongInt.sign;
    }
    for (int i = 0; i < octNumber.length(); i++)
    {
        cout << octNumber[i];
        if (i == octBlank && octBlank != octNumber.length())
        {
            cout << " ";
            octBlank += 4;
        }
    }


    out << endl << "十六进制数为：";
    if (veryLongInt.sign == '-')
    {
        out << veryLongInt.sign;
    }
    for (int i = 0; i < hexNumber.length(); i++)
    {
        cout << hexNumber[i];
        if (i == hexBlank && hexBlank != hexNumber.length())
        {
            cout << " ";
            hexBlank += 4;
        }
    }
    out << endl;
    return out;
}

//重载超大整数的输入功能
istream &operator>>(istream &in, VeryLongInt &veryLongInt)
{
    string temp;
    in >> temp;
    veryLongInt = VeryLongInt(temp);
    return in;
}

VeryLongInt abs(VeryLongInt number)
{
    number.sign = '+';
    return number;
}

VeryLongInt absAddUp(VeryLongInt first, VeryLongInt second)
{
    //carry存放进位的数字大小，maxLength存放生成的超大整数长度
    int carry = 0, maxLength = 0;

    // 以两个数较长的一个为基准，进行按位加法操作，
    // 并且如果存在进位情况，也就是说会超过已有的位数，则按新增的位数为基准
    // 当同时超过两个数的长度且没有进位的时候终止循环
    while (maxLength < first.number.size() || maxLength < second.number.size() || carry)
    {
        // 被加数的位数不够了，或者可能存在进位操作，因此先预留前导零进行计算
        // 到时候如果没有进位，多了的0再去掉就可以了
        if (maxLength == first.number.size())
        {
            first.number.push_back(0);
        }
        // 如果加数比较小，那么就自行补0
        first.number[maxLength] += carry + (maxLength < second.number.size() ? second.number[maxLength] : 0);
        carry = first.number[maxLength] / BASE;
        first.number[maxLength] %= BASE;
        maxLength++;
    }
    first.trimZero();
    return first;
}

VeryLongInt absSubtractUp(VeryLongInt first, VeryLongInt second)
{
    //borrow存放的是是否借1，maxLength存放的是所生成的超大整数的位数
    int borrow = 0, maxLength = 0;
    while (maxLength < first.number.size() || maxLength < second.number.size())
    {
        //这里的borrow有一种超前支付再还款的感觉
        first.number[maxLength] -= borrow + (maxLength < second.number.size() ? second.number[maxLength] : 0);
        borrow = first.number[maxLength] < 0;
        first.number[maxLength] += borrow * BASE;
        maxLength++;
    }
    first.trimZero();
    return first;
}

string change(string number, int n, int m)   //n进制转m进制只限0-9进制，若涉及带字母的进制，稍作修改即可
{
    //这个是用来处理十六进制数时候的string无法直接转换的问题的
    int num = 0;

    //这个是每次短除法的商
    string quotient;

    //这个是最终的转完进制后的结果
    string ans;

    //这个是余数
    int remain = 0;

    //如果是0的话，那就直接结束了
    if (!judge(number))
    {
        return "0";
    }

    //被除数不为0则继续
    while (judge(number))
    {
        for (char i: number)
        {
            num = i - '0';
            if (i == 'A' || i == 'a')
            {
                num = 10;
            }
            if (i == 'B' || i == 'b')
            {
                num = 11;
            }
            if (i == 'C' || i == 'c')
            {
                num = 12;
            }
            if (i == 'D' || i == 'd')
            {
                num = 13;
            }
            if (i == 'E' || i == 'e')
            {
                num = 14;
            }
            if (i == 'F' || i == 'f')
            {
                num = 15;
            }
            int temp = remain * n + num;

            //求出商
            if (temp / m <= 9)
            {
                quotient += temp / m + '0';
            }
            else
            {
                if (temp / m == 10)
                {
                    quotient += 'A';
                }
                if (temp / m == 11)
                {
                    quotient += 'B';
                }
                if (temp / m == 12)
                {
                    quotient += 'C';
                }
                if (temp / m == 13)
                {
                    quotient += 'D';
                }
                if (temp / m == 14)
                {
                    quotient += 'E';
                }
                if (temp / m == 15)
                {
                    quotient += 'F';
                }
            }

            //求出余数
            remain = temp % m;
        }

        //把商赋给下一次的被除数
        number = quotient;

        //把商清空
        quotient = "";

        //加上进制转换后数字
        if (remain <= 9)
        {
            ans += remain + '0';
        }
        else
        {
            if (remain == 10)
            {
                ans += 'A';
            }
            if (remain == 11)
            {
                ans += 'B';
            }
            if (remain == 12)
            {
                ans += 'C';
            }
            if (remain == 13)
            {
                ans += 'D';
            }
            if (remain == 14)
            {
                ans += 'E';
            }
            if (remain == 15)
            {
                ans += 'F';
            }
        }

        //清空余数
        remain = 0;
    }

    //倒置ans，这个才是真正的转换后的新进制数
    reverse(ans.begin(), ans.end());
    return ans;
}

bool judge(string s)
{
    for (char i: s)
    {
        if (i != '0')
        {
            return true;
        }
    }
    return false;
}


