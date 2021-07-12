#include <iostream.h>
#include <math.h>

// ���������� �� ����������� triangle
struct triangle
{ 
    double a, b, c;				// ������ �� ����������
};

// ��������� �� ����������
void create_triangle(triangle& t)
{
    bool tri;
    do
    {
        cout << "a, b, c (������ �� ����������): ";
        cin >> t.a >> t.b >> t.c;
        tri = (t.a > 0) && (t.b > 0) && (t.c > 0) &&
              (t.a + t.b > t.c) && (t.a + t.c > t.b) &&
              (t.b + t.c > t.a);
    } while(!tri);
}

// ��������� �� ����������
void show_triangle(const triangle &t)
{
    cout << "triangle(" << t.a << ", " << t.b << ", "
         << t.c << ")\n";
}

// �������� �� ���������� �� ����������
double perimeter(const triangle &t)
{
    return t.a + t.b + t.c;
}

// �������� �� ������ �� ����������
double surface(const triangle &t)
{
    double p = perimeter(t)/2;
    return sqrt(p*(p - t.a)*(p - t.b)*(p - t.c));
}

int main()
{
    // ��������� �� ����������
    triangle t; create_triangle(t);
    // ��������� �� �����������
    show_triangle(t);
    // �������� � ��������� �� ���������� �� �����������
    cout << "���������: " << perimeter(t) << endl;
    // �������� � ��������� �� ������ �� �����������
    cout << "����: " << surface(t) << endl;
    return 0;
}


/*
///��������� create_triangle ���� �� ���� ���������� � �� ������� �����:

triangle create_triangle()
{ 
    triangle t;
    bool tri;
    do
    { 
        cout << "a, b, c (������ �� ����������): ";
        cin >> t.a >> t.b >> t.c;
        tri = (t.a > 0) && (t.b > 0) && (t.c > 0) &&
              (t.a + t.b > t.c) && (t.a + t.c > t.b) &&
              (t.b + t.c > t.a);
    } while(!tri);
    return t;
}

//������ ����������� �� ���������� �� ����������� ���� �����������
triangle t = create_triangle();
*/
