#include <iostream.h>

struct complex
{
private:
    double Re, Im;  // ������ � ���������� �����
public:

    // ��������� �� ���������� �����
    void create(double x, double y)
    {
        Re = x;
        Im = y;
    }

    // ��������� �� ���������� �����
    void print() const
    {
        cout << Re << (Im < 0 ? "" : "+") << Im << "i\n";
    }

    // �������� �� �������� ���� �� ���������� �����
    double get_Re() const
    {
        return Re;
    }

    // �������� �� ������������ ���� �� ���������� �����
    double get_Im() const
    {
        return Im;
    }

    // �������� ���� ���������� ����� � ����� �� 0
    bool IsZero() const
    {
        return (Re == 0) && (Im == 0);
    }

    // �������� �� ���������� �����
    complex sum(const complex& c) const
    {
        complex p;
        p.create(Re + c.Re, Im + c.Im);
        return p;
    }

    // ��������� �� ���������� �����
    complex sub(const complex& c) const
    {
        complex p;
        p.create(Re - c.Re, Im - c.Im);
        return p;
    }

    // ��������� �� ���������� �����
    complex mult(const complex& c) const
    {
        complex p;
        p.create(Re*c.Re - Im*c.Im, Re*c.Im + Im*c.Re);
        return p;
    }

    // ������� �� ���������� �����
    // ���������� ��, �� ��������� c
    // � �������� �� 0 ���������� �����
    complex quot(const complex& c) const
    {
        complex p;
        double den = c.Re*c.Re + c.Im*c.Im;
        p.create((Re*c.Re + Im*c.Im)/den, (Im*c.Re - Re*c.Im)/den);
        return p;
    }
};

// �������� �� ���������� �� ��������
complex Horner(int n, complex a[], complex x)
{ 
    complex s = a[0];
    for(int i = 1; i <= n; i++)
        s = s.mult(x).sum(a[i]);
    return s;
}

int main()
{
    complex x, a[10]; 

    // ��������� �� ������������ ����� x
    double p, q;
    cout << "Re, Im? ";
    cin >> p >> q;
    x.create(p, q);    

    // ��������� �� �������� �� ��������
    cout << "n= "; int n; cin >> n;

    // ��������� �� ������������� �� ��������
    for(int i = 0; i <= n; i++)
    { 
        cout << "Re, Im? ";
        cin >> p >> q;
        a[i].create(p, q);
    }

    // �������� � ��������� �� ���������� �� ��������
    Horner(n, a, x).print();
    return 0;
}
