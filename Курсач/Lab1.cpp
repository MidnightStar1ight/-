#include <iostream>
using namespace std;

void Lab1()
{
    setlocale(0, "");



    cout << "1. ����� ������, ���������� ���������� ������ ������:" << '\n' << '\n';
    // int, short int, long int, float, double, long double, char � bool.
    cout <<
        "int: " << sizeof(int) << endl <<
        "short int: " << sizeof(short int) << endl <<
        "long int: " << sizeof(long int) << endl <<
        "float: " << sizeof(float) << endl <<
        "double: " << sizeof(double) << endl <<
        "long double: " << sizeof(long double) << endl <<
        "char: " << sizeof(char) << endl <<
        "bool: " << sizeof(bool) << endl;

    system("pause");



    int cycle = true;
    while (cycle)
    {
        bool idz;
        int order = sizeof(int) * 8 - 1;
        unsigned int mask = 1 << order;
        union {
            int integerA;
            float floatB;
        };
        char type;
        //int idzA = integerA;
        //float idzB = floatB
        do
        {
            cout << "�������� ��� ������: ��� ���� int �������� 'i', ��� float �������� 'f', ��� ���� double �������� 'd': ";
            cin >> type;
        } while ((type != 'i') and (type != 'f') and (type != 'd'));
        switch (type)
        {
        case 'i':
        {
            cout << "������� ����� �����: ";
            cin >> integerA;
            int idzA = integerA;
            for (int i = 0; i <= order; i++) {
                cout << ((integerA & mask) ? 1 : 0);
                mask = mask >> 1;
                if (!i or (i + 1) % 8 == 0)
                    cout << ' ';
            }
            cout << "\n�������� ��� ����, ������ �������, �����? \n 1 - �� \n 0 - ��� \n";
            cin >> idz;
            if (idz) {
                idzA = idzA << 1;
                cout << "������������ �����: " << idzA << '\n';
                cout << "�������� �������������:";
                for (int i = 0; i <= order; i++) {
                    cout << ((idzA & mask) ? 1 : 0);
                    idzA = idzA << 1;
                    if (!i or (i + 1) % 8 == 0)
                        cout << ' ';

                }
            }
            break;
        };
        case 'f':
        {
            union {
                int idzB;
                float GG;
            };
            cout << "������� ������������ �����: ";
            cin >> floatB;
            idzB = integerA;
            for (int i = 0; i <= order; i++) {
                cout << ((integerA & mask) ? 1 : 0);
                integerA = integerA << 1;
                if (!i or (i == 8))
                    cout << ' ';
            }
            cout << "\n�������� ��� ����, ������ �������, �����? \n 1 - �� \n 0 - ��� \n";
            cin >> idz;
            if (idz) {
                idzB = idzB << 1;
                cout << "������������ �����: " << GG << '\n';
                cout << "�������� �������������:";
                for (int i = 0; i <= order; i++) {
                    cout << ((idzB & mask) ? 1 : 0);
                    idzB = idzB << 1;
                    if (!i or (i == 8))
                        cout << ' ';
                }
            }
            break;
        };

        case 'd':
        {
            const int DOrder = sizeof(int) * 8;
            int DNum[DOrder];

            union {
                int a[2];
                double doubleD = 1;
            };

            cout << "������� ������������ �����: ";
            cin >> doubleD;

            for (int i = 0; i < DOrder; i++)
            {
                cout << ((a[1] & mask) ? 1 : 0);
                a[1] = a[1] << 1;
                if (!i or (i == 11))
                    cout << ' ';
            }

            for (int i = 0; i < DOrder; i++)
            {
                cout << ((a[0] & mask) ? 1 : 0);
                a[0] = a[0] << 1;
            }
            break;
        }



        }
        cout << "\n\n" "���������?" "\n" "1 - ��" "\n" "0 - ���" "\n";
        cin >> cycle;
    }
}