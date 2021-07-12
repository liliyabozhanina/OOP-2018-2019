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

bool equal(const rat& x, const rat& y)
{
    return x.numer()*y.denom() ==
           x.denom()*y.numer();
}

bool grthen(const rat& x, const rat& y)
{
    return x.numer()*y.denom() >
           x.denom()*y.numer();
}

rat maxrat(int n, rat x[])
{
    rat max = x[0];
    for(int i = 1; i < n; i++)
        if(grthen(x[i], max))
            max = x[i];
    return max;
}

// �������� �� ������ �� ������������ ����� r1 � r2
rat sumrat(const rat& r1, const rat& r2)
{ 
    rat r; 
    r.makerat(r1.numer() * r2.denom() + r2.numer() * r1.denom(),
              r1.denom() * r2.denom());
    return r;
}

// �������� �� ��������� �� ������������ ����� r1 � r2
rat subrat(const rat& r1, const rat& r2)
{ 
    rat r;
    r.makerat(r1.numer() * r2.denom() - r2.numer() * r1.denom(),
              r1.denom() * r2.denom());
    return r;
}

// �������� �� �������������� �� ������������ ����� r1 � r2
rat multrat(const rat& r1, const rat& r2)
{ 
    rat r; 
    r.makerat(r1.numer()*r2.numer(),
              r1.denom()*r2.denom());
    return r;
}

// �������� �� �������� �� ������������ ����� r1 � r2
rat quotrat(const rat& r1, const rat& r2)
{
    rat r;
    r.makerat(r1.numer()*r2.denom(),
              r1.denom()*r2.numer());
    return r;
}

// �������� �� ���������
void rat_system(const rat& a, const rat& b,
                const rat& c, const rat& d,
                const rat& e, const rat& f)
{ 
    rat det = subrat(multrat(a, d), multrat(c, b)), zero;
    zero.makerat(0, 1);
    if(equal(det, zero))
    {
        if(equal(multrat(b, f), multrat(d, e)))
            cout << "��������� ��� ������� ����� �������.\n";
        else cout << "��������� ���� �������.\n";
    }
    else
    { 
        rat x, y;
        x = quotrat(subrat(multrat(e, d), multrat(b, f)), det);
        y = quotrat(subrat(multrat(a, f), multrat(c, e)), det);
        x.printrat();
        y.printrat();
    }
}

int main()
{ 
    // ���������� �� ������������� �� ���������
    rat a, b, c, d, e, f;
    // ��������� �� ������������� �� ���������
    // ��� ���������
    a.makerat(1,2); b.makerat(-1,4);
    c.makerat(3,2); d.makerat(1,4);
    e.makerat(3,6); f.makerat(0,4);
    // �������� �� ���������
    rat_system(a, b, c, d, e, f);
    return 0;
}
