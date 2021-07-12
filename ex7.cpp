#include <iostream.h>
#include <math.h>

const int SIZEMAX = 100;

// ���������� �� ����������� Point
struct Point
{
    double x, y;    // ��������� ���������� �� ����� �� ���������
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
    cout << "Point(" << p.x << ", " << p.y << ")\n";
}

// �������� �� ������������ ����� ��� ����� �� ���������
double segment(const Point& p1, const Point& p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) +
                (p2.y - p1.y)*(p2.y - p1.y));
}

// ��������� �� ����� �� �����
void read_points(int n, Point *P)
{
    for(int i = 0; i < n; i++)
    {
        cout << "x, y= ";
        cin >> P[i].x >> P[i].y; 
        // ��� create_point(P[i]);
    }
}

// ��������� �� ����� �� �����
void show_points(int n, Point *P)
{
    for(int i = 0; i < n; i++)
        cout << "Point(" << P[i].x << ", " << P[i].y << ")\n";
    // ��� show_point(P[i]);
}

// �������� �� ���-�������� ���������� ����� �������
double max_distance(int n, Point *P)
{
    double max = 0;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
        {
            double temp = segment(P[i], P[j]);
            if (temp > max) max = temp;
        }
        return max;
}

int main()
{
    // ��������� �� ���� �� �������
    int n;
    do
    {
        cout << "�������� �������� �� n � �� 2 �� "
             << SIZEMAX << ": ";
        cin >> n;
    } while (n < 2 || n > SIZEMAX);

    // ����������� �� ����� �� ����� � ���������
    Point P[SIZEMAX];

    // ��������� �� ������� �� ������
    read_points(n, P);

    // ��������� �� ������� �� ������
    show_points(n, P);

    // ��������� �� ���-�������� ���������� ����� �������
    cout << "������������ ���������� ����� ������� � "
         << max_distance(n, P) << endl;
    return 0;
}
