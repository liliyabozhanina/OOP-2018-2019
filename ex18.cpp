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

// ��������� ���� ��� ���������� ����� �� �����
bool equal(const complex& x, const complex& y)
{ 
    return x.get_Re() == y.get_Re() &&
           x.get_Im() == y.get_Im();
}

// �������� �� ���������
void complex_system(const complex& a, const complex& b,
                    const complex& c, const complex& d,
                    const complex& e, const complex& f )
{
    complex det = a.mult(d).sub(c.mult(b)), zero;
    zero.create(0, 0);
    if(equal(det, zero))
    {
        if(equal(b.mult(f), d.mult(e)))
            cout << "��������� ��� ������� ����� �������.\n";
        else 
            cout << "��������� ���� �������.\n";
    }
    else
    { 
        complex x, y;
        x = e.mult(d).sub(b.mult(f)).quot(det);
        y = a.mult(f).sub(c.mult(e)).quot(det);
        x.print();
        y.print();
    }
}

int main()
{
    // ���������� �� ������������� �� ���������
    complex a, b, c, d, e, f;
    // ��������� �� ������������ �����,
    // ������� �� ����������� �� ���������
    a.create(1,2); b.create(-1,4);
    c.create(1,3); d.create(1,4);
    e.create(3,6); f.create(3,6);
    // �������� �� ���������
    complex_system(a, b, c, d, e, f);
    return 0;
}
