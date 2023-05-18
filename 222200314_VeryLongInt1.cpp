//
// Created by RUGAN on 2023-05-07.
//

#include "222200314_VeryLongInt1.h"


using namespace std;


/**
 * ����������Զ����״�
 * @param message
 */
VeryLongIntException::VeryLongIntException(string message) : message(std::move(message))
{
}

string VeryLongIntException::what()
{
    return message;
}

/**
 * <h3>����ʮ�����������캯����ת��vector�洢
 * @param number
 */
VeryLongInt::VeryLongInt(string number)
{
    int type= check(number);

    //�˽��ƵĻ��Ƚ���һ������ת��
    if(type==IS_OCT)
    {
        //TODO
    }

    //ʮ�����ƵĻ��Ƚ���һ������ת��
    else if(type==IS_HEX)
    {
        //TODO
    }

    //ʮ���ƵĹ����ʼ��
    else if (type==IS_DEC)
    {
        //�ȼ�¼һ��ԭ����
        int originLength = number.length();

        //�����ʮ���ƵĻ���Ҫ���ǵ�����ռλ����
        int signBlock = 0;

        //һ���±�ָ�룬�����ָ�������
        int i;

        //����Ĭ��Ϊ+
        sign = '+';

        //�����λ��-�ţ���ô���ã����ұ�Ƿ���ռλ
        if (number[0] == '-')
        {
            sign = '-';
            signBlock = 1;
        }
        //һ��������ǲ�д+�ţ�����д��Ҳ�����ͬ��ҲҪ��Ƿ���ռλ
        else if (number[0] == '+')
        {
            sign = '+';
            signBlock = 1;
        }

        //����β�Ϳ�ʼ�ָÿ���ƶ���λ��ֱ���Ƶ��߽�
        //����߽���Ƿ���ռλ
        for (i = originLength - 4; i >= signBlock; i -= 4)
        {
            // cout << i << endl;  debug

            //Ȼ��Ϳ�ʼ��λ��λ�ļ��㣬ÿ��λ��ת���ַ���
            //temp�������������̵�ֵ
            int temp = 0;
            for (int j = i; j <= i + 3; j++)
            {
                temp = temp * 10 + number[j] - '0';
            }

            //��������ֱ��β��
            this->number.emplace_back(temp);

            //�������˿�һ�£�������ƵĻ�Խ���ˣ�Ҳ���ǲ�����λ�ˣ�ֱ���˳���
            //���е����������ж�
            if (i - signBlock < 4)
            {
                break;
            }
        }

        //����Ҫע��һ�£����forѭ��һ��ʼ������ȥ�Ļ���i��ֵ�Ǹ��������ԵĻ�����Ҫ��ԭi
        if (originLength < 4)
        {
            i = originLength;
        }

        //ֻҪ���i����0��˵�������������жϻ���
        if (i)
        {
            int temp = 0;

            //���Ǵӷ���λ����ʼ����
            for (int j = signBlock; j <= i - 1; j++)
            {
                temp = temp * 10 + number[j] - '0';
            }
            this->number.emplace_back(temp);
        }

    }

    else if(type==ERROR)
    {
        throw VeryLongIntException("mewww!!!! �ⲻ�ǺϷ���ʮ����/�˽���/ʮ������!");
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
int VeryLongInt::check(string number)
{
    //һ��ʼĬ���Ǵ��
    int type = ERROR;

    //�����������жϵ�һλ������ʲô�������ȳ�������
    //��һλ�ǼӺš����߼��š�����������0-9�������ǺϷ�ʮ������
    //��Ϊ��һλ��0�Ļ��������ǰ˽�������ʮ������
    if (number[0] == '+' || number[0] == '-' || (number[0] >= '0' && number[0] <= '9'))
    {
        type = IS_DEC;
    }

    //�������ֻ��һλ����ôҪ��֤����0-9�Ķ��������������Ų��Ϸ���Ȼ��Ϳ��Է����ˣ��ж����
    if (number.length() == 1)
    {
        if (number[0] < '0' || number[0] > '9')
        {
            type = ERROR;
        }
        return type;
    }

    //���������еڶ�λ���жϣ���Ȼ����һλ������ô������λ��
    //�����һλ��0����ô��ֻ�����ǰ˽��ƺ�ʮ��������
    if (number[0] == '0')
    {
        //�ڶ�λ�����x����X�Ļ�����ô�Ϳ�������ȷ��ʮ��������
        if (number[1] == 'x' || number[1] == 'X')
        {
            type = IS_HEX;
        }

            //��Ȼ�Ļ��ڶ�λ��ֻ����������,����ֻ����0-7�����ܳ����˽���
        else if (number[1] >= '0' && number[1] <= '7')
        {
            type = IS_OCT;
        }

            //�����ľ��Ǵ���ˣ������Ƿ��ַ����Լ�8��9�ȵ�
        else
        {
            type = ERROR;
        }
    }

    //�������ĳ���ֻ��2����ôҪ��֤�Ǹ���ȷ��������������ͨͨ��ʮ����������12��
    //�Ƚ϶̵İ˽���������05������
    //Ȼ�󲻿�����ʮ����������ǰ���Ѿ������жϹ��ˣ�����ֻ��Ҫ��ʮ�����Ƶĸɵ�����
    //�ж����˾Ϳ���ֱ��return��
    if (number.length() == 2)
    {
        //���������ʮ�����ƵĻ�
        if (number[0] == '0' && type == IS_HEX)
        {
            type = ERROR;
        }
        return type;
    }

    //���������Ƕ�����λ������ˣ������Ѿ������ֽ����������֣�����ֻ��Ҫ�������������
    //���Ǵӵ���λ��ʼ�Ƚ�
    for(int i=2;i<number.length();i++)
    {
        //��ɸ����ʮ����
        if(type==IS_DEC)
        {
            if(number[i]<'0'||number[i]>'9')
            {

                type=ERROR;
            }
        }
        //��ɸ���ǰ˽���
        else if(type==IS_OCT)
        {
            if(number[i]<'0'||number[i]>'7')
            {
                type=ERROR;
            }
        }
        //��ɸ����ʮ������
        else if(type==IS_HEX)
        {
            //�����򷴣����ò���˼��
            if(number[i]>='0'&&number[i]<='9'||number[i]>='A'&&number[i]<='F')
            {
                type=IS_HEX;
            }
            else
            {
                type=ERROR;
            }
        }
        //һ������������֮���if���ж��Ƿ�error
        //������Ѿ��Ǵ���ˣ�Ȼ���ֱ�ӳ�ȥ
        //������һ��ʼ����ERROR�����������浼�±����ERROR
        //�����Ļ�����Ͳ���Ҫдbreak�ˣ��ǳ����㣬Ҳ�����˷�ʱ��
        if(type==ERROR)
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
 * <h3>�߾��ȳ��ϸ߾���
 * <p>ʱ�临�Ӷ�ΪO((n/4)*(m/4))
 * <p>���������ΪO(n^2)
 * @param other
 * @return
 */
VeryLongInt operator*(const VeryLongInt &self, const VeryLongInt &other)
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
    this->sign = other.sign;
    this->number = other.number;
    return *this;
}


bool VeryLongInt::operator<(const VeryLongInt &other) const
{
    //����һ��С��������ֱ�ӷ���true
    if (this->sign == '-' && other.sign == '+')
    {
        return true;
    }
    //����һ�����ڸ�����ֱ�ӷ���false
    if (this->sign == '+' && other.sign == '-')
    {
        return false;
    }
    //���������ȣ�ֱ�ӳ�ȥ
    if (*this == other)
    {
        return false;
    }
    //���������Ƕ��Ǹ��ţ�������������ȵ����
    if (this->sign == '-' && other.sign == '-')
    {
        return !(abs(*this) < abs(other));
    }

    //���������Ƕ������ţ�������������ȵ����
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
    //����һ��С��������ֱ�ӷ���false
    if (this->sign == '-' && other.sign == '+')
    {
        return false;
    }
    //����һ�����ڸ�����ֱ�ӷ���true
    if (this->sign == '+' && other.sign == '-')
    {
        return true;
    }
    //���������ȣ�ֱ�ӳ�ȥ
    if (*this == other)
    {
        return false;
    }
    //���������Ƕ��Ǹ��ţ�������������ȵ����
    if (this->sign == '-' && other.sign == '-')
    {
        return !(abs(*this) > abs(other));
    }

    //���������Ƕ������ţ�������������ȵ����
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
 * <h3>�߾��ȳ��Ը߾��ȵ�����
 * <p>����ģ����ʽ��˼�룬�����ö��ַ�ȷ���̵�ÿһλ
 * <p>ʱ�临�Ӷ�ΪO(nmlogm)
 * <p>���Խ��ƿ���O(n^2)
 * @param other
 * @return
 */
VeryLongInt operator/(const VeryLongInt &self, const VeryLongInt &other)
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

VeryLongInt abs(VeryLongInt number)
{
    number.sign = '+';
    return number;
}

VeryLongInt absAddUp(VeryLongInt first, VeryLongInt second)
{
    //carry��Ž�λ�����ִ�С��maxLength������ɵĳ�����������
    int carry = 0, maxLength = 0;

    // ���������ϳ���һ��Ϊ��׼�����а�λ�ӷ�������
    // ����������ڽ�λ�����Ҳ����˵�ᳬ�����е�λ������������λ��Ϊ��׼
    // ��ͬʱ�����������ĳ�����û�н�λ��ʱ����ֹѭ��
    while (maxLength < first.number.size() || maxLength < second.number.size() || carry)
    {
        // ��������λ�������ˣ����߿��ܴ��ڽ�λ�����������Ԥ��ǰ������м���
        // ��ʱ�����û�н�λ�����˵�0��ȥ���Ϳ�����
        if (maxLength == first.number.size())
        {
            first.number.push_back(0);
        }
        // ��������Ƚ�С����ô�����в�0
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
    //borrow��ŵ����Ƿ��1��maxLength��ŵ��������ɵĳ���������λ��
    int borrow = 0, maxLength = 0;
    while (maxLength < first.number.size() || maxLength < second.number.size())
    {
        //�����borrow��һ�ֳ�ǰ֧���ٻ���ĸо�
        first.number[maxLength] -= borrow + (maxLength < second.number.size() ? second.number[maxLength] : 0);
        borrow = first.number[maxLength] < 0;
        first.number[maxLength] += borrow * BASE;
        maxLength++;
    }
    first.trimZero();
    return first;
}


