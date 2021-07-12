#include <iostream.h>
#include <math.h>

const double PI = 3.14159265;

// ���������� �� ����������� polar
struct polar
{
    double mag;                       // ������
    double ang;                       // ����
};

// ���������� �� ����������� rect
struct rect
{
    double x;                         // �������
    double y;                         // ��������
};

// ������������� �� ������, ������� ����
// �����������, � ������� ����������
polar rect_to_polar(const rect& r)
{
    polar p;
    p.mag = sqrt(r.x * r.x + r.y * r.y);
    p.ang = atan2(r.y, r.x);
    return p;
}

// ������������� �� ������, ������� ����
// ������� � ����������� ����������
rect polar_to_rect(const polar& p)
{
    const double DEG_TO_RAD = PI/180;
    rect r;
    r.x = p.mag * cos(p.ang*DEG_TO_RAD);
    r.y = p.mag * sin(p.ang*DEG_TO_RAD);
    return r;
}

// ��������� �� ������, ������� ����
// ������� ����������
void show_polar(const polar& p)
{
    const double RAD_TO_DEG = 180/PI;
    cout << "������ = " << p.mag;
    cout << ", ���� = " << p.ang * RAD_TO_DEG;
    cout << " �������.\n";
}

// ��������� �� ������, ������� ����
// ����������� ����������
void show_rect(const rect& r)
{
    cout << "������� = " << r.x
         << ", �������� = " << r.y << "\n";
}

int main()
{
    rect r;
    polar p;
    cout << "�������� ����� �� ��������� �� ������������: \n";
    cout << "r - �� ����������� � "
            "p - �� ������� ����������. \n";
    char ch; cin >> ch;
    switch(ch)
    {
    case 'r':
        cout << "�������� ������������� ���������� x � y: ";
        while(cin >> r.x >> r.y)
        { 
            p = rect_to_polar(r);
            show_polar(p);
            cout << "�������� ����������� ����������, "
                    "�� ���� �������� ���� end ";
        }
        break;
    case 'p':
        cout << "�������� ��������� ���������� mag � ang: ";
        while(cin >> p.mag >> p.ang)
        { 
            r = polar_to_rect(p);
            show_rect(r);
            cout << "�������� ������� ����������, "
                    "�� ���� �������� ���� end ";
        }
    }
    return 0;
}
