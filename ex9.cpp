#include <iostream.h>
#include <iomanip.h>

struct Rectangle
{ 
    int length;            // �������
    int width;             // ��������
};

int main()
{
    //�)
    Rectangle r = {15, 20};
    Rectangle *p = &r;

    //�)
    cout << setw(10) << p->length
         << setw(10) << p->width << endl;

    return 0;
}
