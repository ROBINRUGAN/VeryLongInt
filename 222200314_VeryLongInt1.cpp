//
// Created by RUGAN on 2023-05-07.
//

#include "222200314_VeryLongInt1.h"


using namespace std;


/**
 * ����������Զ����״�
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
 * <h3>����ʮ�����������캯����ת��vector�洢
 * @param number
 */
VeryLongInt::VeryLongInt(string number)
{
    if (check(number))
    {
        //TODO ���ֽ���

        //ʮ���ƵĹ����ʼ��
        int originLength = number.length();
        int signBlock = 0;
        //һ���±�ָ�룬�����ָ�������
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
        throw BigIntException("��ʽ����");
    }


}

/**
 * <h3>Ĭ��ֵΪ����޲ι��캯��
 */
VeryLongInt::VeryLongInt()
{
    sign = '+';
    this->number.emplace_back(0);
}

/**
 * <h3> �����ǲ��ǺϷ���10����/16����/8����
 * @param number
 * @return
 */
bool VeryLongInt::check(string number)
{
    //��һλ�Ȳ��ǼӼ��ţ��ֲ��Ǹ������ֵ�ֱ�Ӳ���
    if (number[0] != '+' && number[0] != '-' && (number[0] < '0' || number[0] > '9') &&
            (number[0] < 'A' || number[0] > 'F'))
    {

        return false;
    }
    if (number.length() > 1)
    {    //�ڶ�λ�Ȳ���ʮ�����Ƶ�x��X���ֲ��Ǹ������ֵ�ֱ�Ӳ���
        if (number[1] != 'x' && number[1] != 'X' && (number[1] < '0' || number[1] > '9') &&
                (number[1] < 'A' || number[1] > 'F'))
        {
            return false;
        }
    }
    if (number.length() > 2)
    {
        //���Ǹ������ֵ�ֱ�Ӳ���
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
    sign='+';
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

VeryLongInt &VeryLongInt::operator+=(const VeryLongInt &other)
{
    //carry��Ž�λ�����ִ�С��maxLength������ɵĳ�����������
    int carry = 0, maxLength = 0;

    // ���������ϳ���һ��Ϊ��׼�����а�λ�ӷ�������
    // ����������ڽ�λ�����Ҳ����˵�ᳬ�����е�λ������������λ��Ϊ��׼
    // ��ͬʱ�����������ĳ�����û�н�λ��ʱ����ֹѭ��
    while (maxLength < number.size() || maxLength < other.number.size() || carry)
    {
        // ��������λ�������ˣ����߿��ܴ��ڽ�λ�����������Ԥ��ǰ������м���
        // ��ʱ�����û�н�λ�����˵�0��ȥ���Ϳ�����
        if (maxLength == number.size())
        {
            number.push_back(0);
        }
        // ��������Ƚ�С����ô�����в�0
        number[maxLength] += carry + (maxLength < other.number.size() ? other.number[maxLength] : 0);
        carry = number[maxLength] / BASE;
        number[maxLength] %= BASE;
        maxLength++;
    }
    trimZero();
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
    //borrow��ŵ����Ƿ��1��maxLength��ŵ��������ɵĳ���������λ��
    int borrow = 0, maxLength = 0;
    while (maxLength < number.size() || maxLength < other.number.size())
    {
        //�����borrow��һ�ֳ�ǰ֧���ٻ���ĸо�
        number[maxLength] -= borrow + (maxLength < other.number.size() ? other.number[maxLength] : 0);
        borrow = number[maxLength] < 0;
        number[maxLength] += borrow * BASE;
        maxLength++;
    }
    trimZero();
    return *this;
}

/**
 * <h3>�߾��ȳ��ϸ߾���
 * <p>ʱ�临�Ӷ�ΪO((n/4)*(m/4))
 * <p>���������ΪO(n^2)
 * @param other
 * @return
 */
VeryLongInt operator*(const VeryLongInt &self,const VeryLongInt &other)
{
    VeryLongInt result;
    int selfLength = self.number.size();
    int otherLength = other.number.size();

    //ֱ�ӽ���Ԥ���С������֮����±�����
    result.number.resize(selfLength + otherLength);

    //��ʱ�Ȳ�����FFT��Karatsuba�㷨
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
    // ȥ��ǰ����
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
    this->number = other.number;
    return *this;
}

bool VeryLongInt::operator<(const VeryLongInt &other) const
{
    if (*this == other)
    {

        return false;
    }

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
            //cout << "this->number[i]="<<this->number[i]<<" "<< "other.number[i]="<<other.number[i]<<endl;
            return true;
        }
        if (this->number[i] > other.number[i])
        {
            //cout << "this->number[i]="<<this->number[i]<<" "<< "other.number[i]="<<other.number[i]<<endl;
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
    if (*this == other)
    {

        return false;
    }

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
            //cout << "this->number[i]="<<this->number[i]<<" "<< "other.number[i]="<<other.number[i]<<endl;
            return true;
        }
        if (this->number[i] < other.number[i])
        {
            //cout << "this->number[i]="<<this->number[i]<<" "<< "other.number[i]="<<other.number[i]<<endl;
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
 * <h3>�߾��ȳ��Ը߾��ȵ�����
 * <p>����ģ����ʽ��˼�룬�����ö��ַ�ȷ���̵�ÿһλ
 * <p>ʱ�临�Ӷ�ΪO(nmlogm)
 * <p>���Խ��ƿ���O(n^2)
 * @param other
 * @return
 */
VeryLongInt operator/(const VeryLongInt &self,const VeryLongInt &other)
{
    VeryLongInt result, temp;
    for (int i = self.number.size() - 1; i >= 0; i--)
    {
        temp.number.insert(temp.number.begin(), self.number[i]);
        //��Ϊ�ҵ��޲ι��캯��Ĭ����һ��Ԫ��0������ڽ��м����ʱ����Ҫ�����ǰ����ȥ��������������

            temp.trimZero();

        int left = 0, right = BASE - 1, ans = 0;

        //���ַ��Գ��̵�ÿһλ
        //����ȥ�������������ָ�뽻��
        //�ҵ�ans��ʵʱ�����������ޣ�С�ڻ���ڣ������Բ��õ���
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (other * mid <= temp)
            {
                //˫�˲��ϱƽ������������ܸ���ans����ô�ҵ�ansһ�����ţ�
                // ��ô���һ�ε�ans���Ǵ�
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        //ͷ�壬��������
        result.number.insert(result.number.begin(), ans);
        //cout << "temp=" << temp << " " << "other=" << other << " " << endl;
        //cout << "number[i]" << self.number[i] << " " << "ans=" << ans << endl;
        //ģ����ʽ�����еļ�������
        temp = temp - other * ans;
    }
    //ȥ��ǰ����
    result.trimZero();
    //���·���
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
    return self-self/other*other;
}

VeryLongInt &VeryLongInt::operator%=(const VeryLongInt &other)
{
    *this=(*this)%other;
    return *this;
}

VeryLongInt &VeryLongInt::operator++()
{
    *this+=1;
    return *this;
}

VeryLongInt VeryLongInt::operator++(int)
{
    VeryLongInt temp = *this;
    *this+=1;
    return temp;
}


//���س����������������
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

//���س������������빦��
istream &operator>>(istream &in, VeryLongInt &veryLongInt)
{
    string temp;
    in >> temp;
    veryLongInt = VeryLongInt(temp);
    return in;
}


