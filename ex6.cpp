#include <iostream.h>
#include <math.h>

// ���������� �� ����������� Point
struct Point
{
    double x,                          // ������� �� �����
           y;                          // �������� �� �����
};

// ��������� �� ����� �� ���������
void create_point(Point& t)
{
    cout << "�������: "; cin >> t.x;
    cout << "��������: "; cin >> t.y;
}

// ��������� �� ����� �� ���������
void show_point(const Point& p)
{
    cout << "Point(" << p.x << ", " << p.y << ")";
}

// �������� �� ��������� �� ������� � ������ ������
double segment(const Point& p1, const Point& p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) +
                (p2.y - p1.y)*(p2.y - p1.y));
}

// ���������� �� ����������� Triangle
struct Triangle
{
    Point A, B, C;        // ������� �� �����������
};

// ��������� �� ����������
void create_triangle(Triangle& t)
{
    cout << "�������� ��� ����� � ���������, ����� "
         << "����� �� �� ������� �� ����������!\n";
    create_point(t.A);
    create_point(t.B);
    create_point(t.C);
}

// ��������� �� ����������
void show_triangle(const Triangle &t)
{
    cout << "triangle("; show_point(t.A);
    cout << ", "; show_point(t.B);
    cout << ", "; show_point(t.C);
    cout << ")\n";
}

// �������� �� ���������� �� ����������
double perimeter(const Triangle &t)
{
    double a = segment(t.B, t.C),
           b = segment(t.A, t.C),
           c = segment(t.A, t.B);
    return a + b + c;
}

// �������� �� ������ �� ����������
double surface(const Triangle &t)
{
    double a = segment(t.B, t.C),
           b = segment(t.A, t.C),
           c = segment(t.A, t.B);
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
    // ��������� �� ����������
    Triangle t; 
    create_triangle(t);
    // ��������� �� �����������
    show_triangle(t);
    // �������� � ��������� �� ���������� �� �����������
    cout << "���������: " << perimeter(t) << endl;
    // �������� � ��������� �� ������ �� �����������
    cout << "����: " << surface(t) << endl;
    return 0;
}
