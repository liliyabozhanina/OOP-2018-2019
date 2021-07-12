#include <iostream.h>

const int SIZE = 16;
const int SIZEMAX = 20;

// ���������� �� ����������� Person
struct Person
{
    char f_name[SIZE];                        // ��������� ���
    char l_name[SIZE];                        // ������� ���
};

// ��������� �� ����� �� ����
void read_person(Person& P)
{
    cout << "��������� ���: ";
    cin >> P.f_name;
    cout << "������� ���: ";
    cin >> P.l_name;
}
// ��������� �� ������� �� ����
void print_person(const Person& P)
{
    cout << "��������� ���: " << P.f_name << endl
         << "������� ���: "   << P.l_name << endl;
}

// ���������� �� ����������� Client
struct Client
{
    Person name;                        // ����
    double amount;                      // ���� � ������� ������
};

// ��������� �� ����� �� ������
void read_client(Client& C)
{
    cout << "��� �� ������: \n"; 
    read_person(C.name);
    cout << "���� �� �������: "; 
    cin >> C.amount;
}

// ��������� �� ����� �� ������
void print_client(const Client& C)
{
    cout << "��� �� ������:\n";
    print_person(C.name);
    cout << "���� �� �������: " << C.amount << endl;
}

int main()
{
    // �)
    // ��������� �� ������� � ���������
    // ������ �� ��������� �� �������
    cout << "�������� �������� �� n �� 1 �� "
         << SIZEMAX << ": ";
    int n; cin >> n;
    Client a[SIZEMAX];
    int i;
    for(i = 0; i < n; i++)
        read_client(a[i]);

    // �)
    // ��������� �� ������� � ���������
    // ������ �� ��������� �� �����������
    cout << "������� �� �������: \n";
    for(i = 0; i < n; i++)
        print_client(a[i]);

    // �)
    // �������� �� ������ �� ������������
    // �� ��������� �� �����������
    double S = 0;
    for(i = 0; i < n; i++)
        if (a[i].amount < 0) S += a[i].amount;
    cout << "������ �� ������������ �� ��������� �: "
         << S << endl;
    return 0;
}
