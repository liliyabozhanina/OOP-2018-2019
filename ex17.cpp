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

int main()
{
    complex c1, c2; 

    // ��������� �� ������������ ����� c1
    double a, b;
    cout << "Re, Im? "; cin >> a >> b;
    c1.create(a, b);    

    // ��������� �� ������������ �����     c2
    cout << "Re, Im? "; cin >> a >> b;
    c2.create(a, b);         

    // �������� �� c1+c2 � ���������
    c1.sum(c2).print();    
    // �������� �� c1-c2 � ��������� 
    c1.sub(c2).print();
    // �������� �� c1*c2 � ���������
    c1.mult(c2).print();
    // �������� �� c1/c2 � ���������

    if(!c2.IsZero())
        c1.quot(c2).print();
    else 
        cout << "������������ ����� c2 � ����� �� 0.";
    return 0;
}
