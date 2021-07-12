#include <iostream.h>
#include <math.h>

struct rat
{ 
private:
    int num;                          // ��������
    int den;                          // ����������

public:
    void makerat(int, int);           // ������� ���������� �����
    int numer()const;                 // ������ ��������� �� ���������� �����
    int denom()const;                 //������ ����������� �� ���������� �����
    void printrat() const;            // ������� ���������� �����
};

// �������� �� ���-������� ��� �������
// �� ��� ���������� �����
int gcd(int a, int b)
{
    while(a != b)
    {
        if (a > b) a = a-b; 
        else b = b-a;
    }
    return a;
}

void rat::makerat(int a, int b)
{
    // ���������� ��, �� b � �������� �� 0
    if(a == 0)
    {
        num = 0;
        den = 1;
    }
    else
    {
        int g = gcd(abs(a), abs(b));
        if(a > 0 && b > 0 || a < 0 && b < 0)
        {
            num = abs(a)/g;
            den = abs(b)/g;
        }
        else
        {
            num = - abs(a)/g;
            den = abs(b)/g;
        }
    }
}

int rat::numer() const
{
    return num;
}

int rat::denom() const
{
    return den;
}

void rat::printrat() const
{
    cout << num << "/" << den << endl;
}

////�) 
bool equal(const rat& x, const rat& y)
{
    return x.numer()*y.denom() ==
           x.denom()*y.numer();
}

////�) 
bool grthan(const rat& x, const rat& y)
{
    return x.numer()*y.denom() >
           x.denom()*y.numer();
}

////�) 
rat maxrat(int n, rat x[])
{
    rat max = x[0];
    for(int i = 1; i < n; i++)
        if(grthan(x[i], max))
            max = x[i];
    return max;
}

////�) 
void sortrat(int n, rat x[])
{
    for(int i = 0; i < n-1; i++)
    {
        int k = i; rat max = x[i];
        for(int j = i+1; j < n; j++)
        {
            if(grthan(x[j], max))
            {
                max = x[j];
                k = j;
            }
        }
        x[k] = x[i]; x[i] = max;
    }
}

int main()
{
    const int n = 5;
    rat arr[n];
    int i;
    for (i = 0; i < n; ++i)
    {
        arr[i].makerat(2*i, 5*(i+1));
    }
    sortrat(n, arr);
    for (i = 0; i < n; ++i)
    {
        arr[i].printrat();
    }
    return 0;
}
