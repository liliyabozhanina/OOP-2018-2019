#include <iostream>
#include <iomanip>

struct Rectangle
{
    int length;			// �������
    int width;			// ��������
};

////�)
void print_rectangle(Rectangle r)
{
    cout << setw(10) << r.length
         << setw(10) << r.width << endl;
}

////�)
void init_rectangle(Rectangle& r)
{
    do
    {
        cout << "length: ";
        cin >> r.length;
        cout << "width: ";
        cin >> r.width;
    } while(r.length <= 0 || r.width <= 0);
}

////�)
Rectangle init_rectangle()
{
    Rectangle r;
    do
    {
        cout << "length: ";
        cin >> r.length;
        cout << "width: ";
        cin >> r.width;
    } while(r.length <= 0 || r.width <= 0);
    return r;
}


int main()
{
    Rectangle r;
    r = init_rectangle();
    print_rectangle(r);
    init_rectangle(r);
    print_rectangle(r);
    return 0;
}
