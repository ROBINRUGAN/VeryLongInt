//
// Created by RUGAN on 2023-05-07.
//

#include "222200314_VeryLongInt1.h"


using namespace std;


/**
 * 大整数类的自定义抛错
 * @param message
 */
BigIntException::BigIntException(string message) : message(std::move(message))
{
}

string BigIntException::what()
{
    return message;
}

/**
 * <h3>超大十进制整数构造函数，转成vector存储
 * @param number
 */
VeryLongInt::VeryLongInt(string number)
{
    if (check(number))
    {
        //TODO 区分进制

        //十进制的构造初始化
        int originLength = number.length();
        int signBlock = 0;
        //一个下标指针，用来分割整数的
        int i;
        sign = '+';

        if (number[0] == '-')
        {
            sign = '-';
            signBlock = 1;
        }
        else if (number[0] == '+')
        {
            sign = '+';
            signBlock = 1;
        }

        for (i = originLength - 4; i >= signBlock; i -= 4)
        {
            // cout << i << endl;  debug
            int temp = 0;
            for (int j = i; j <= i + 3; j++)
            {
                temp = temp * 10 + number[j] - '0';
            }
            this->number.emplace_back(temp);
            if (i - signBlock < 4)
            {
                break;
            }
        }

        if (originLength < 4)
        {
            i = originLength;
        }
        if (i)
        {
            int temp = 0;
            for (int j = signBlock; j <= i - 1; j++)
            {
                temp = temp * 10 + number[j] - '0';
            }
            this->number.emplace_back(temp);
        }

    }
    else
    {
        throw BigIntException("格式错误");
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
 * <h3> 检验是不是合法的10进制/16进制/8进制
 * @param number
 * @return
 */
bool VeryLongInt::check(string number)
{
    //第一位既不是加减号，又不是各种数字的直接驳回
    if (number[0] != '+' && number[0] != '-' && (number[0] < '0' || number[0] > '9') &&
            (number[0] < 'A' || number[0] > 'F'))
    {

        return false;
    }
    if (number.length() > 1)
    {    //第二位既不是十六进制的x或X，又不是各种数字的直接驳回
        if (number[1] != 'x' && number[1] != 'X' && (number[1] < '0' || number[1] > '9') &&
                (number[1] < 'A' || number[1] > 'F'))
        {
            return false;
        }
    }
    if (number.length() > 2)
    {
        //不是各种数字的直接驳回
        for (int i = 2; i < number.length(); i++)
        {
            if ((number[i] < '0' || number[i] > '9') && (number[i] < 'A' || number[i] > 'F'))
            {
                return false;
            }
        }
    }
    return true;
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
        if (abs(*this) > abs(other))
        {
            *this = absSubtractUp(*this, other);
            this->sign = '+';
        }
    }
    if (sign == '-' && other.sign == '+')
    {
        if (abs(*this) < abs(other))
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

}

/**
 * <h3>高精度乘上高精度
 * <p>时间复杂度为O((n/4)*(m/4))
 * <p>极端情况下为O(n^2)
 * @param other
 * @return
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
 * @param other
 * @return
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
    if (veryLongInt.sign == '-')
    {
        out << veryLongInt.sign;
    }
    for (int i = veryLongInt.number.size() - 1; i >= 0; i--)
    {
        out << veryLongInt.number[i];
        if (i > 0)
        {
            cout << ",";
        }
    }
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


