#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ShowArr(int* p, int N) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%03d %c", *(p + i * N + j), ' ');
            //cout << *(p + i*N + j) << ' ';
        }
        cout << '\n';
    }
    return 0;
}

int Spiral(int* p, int N, int time_sleep, int X_Coord = 0, int Y_Coord = 0) {

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    //int currentX, currentY;


    for (int num = 0; num < N / 2; num++) {
        for (int i = num; i < N - num; i++)
        {
            destCoord.X = i * 4 + X_Coord;
            destCoord.Y = num + Y_Coord;
            SetConsoleCursorPosition(hStdout, destCoord);

            //cout << *(p+num*N+i);
            *(p + num * N + i) = rand() % (N * N);
            printf("%03d", *(p + num * N + i));

            Sleep(time_sleep);
        }

        for (int i = num + 1; i < N - num; i++)
        {
            destCoord.X = (N - 1 - num) * 4 + X_Coord;
            destCoord.Y = i + Y_Coord;
            SetConsoleCursorPosition(hStdout, destCoord);

            //cout << *(p + (N - 1 - num)+N*i);
            *(p + (N - 1 - num) + N * i) = rand() % (N * N);
            printf("%03d", *(p + (N - 1 - num) + N * i));

            Sleep(time_sleep);
        }

        for (int i = N - 2 - num; i > num - 1; i--)
        {
            destCoord.X = i * 4 + X_Coord;
            destCoord.Y = N - 1 - num + Y_Coord;
            SetConsoleCursorPosition(hStdout, destCoord);

            //cout << *(p + N*(N-num-1) +  i);
            *(p + N * (N - num - 1) + i) = rand() % (N * N);
            printf("%03d", *(p + N * (N - num - 1) + i));

            Sleep(time_sleep);
        }

        for (int i = N - 2 - num; i > num; i--)
        {
            destCoord.X = num * 4 + X_Coord;
            destCoord.Y = i + Y_Coord;
            SetConsoleCursorPosition(hStdout, destCoord);

            //cout << *(p + N*(i-num)+num); //Тут получается неправильно (2 столбец, 3 и 4 элементы)
            *(p + N * (i - num) + num) = rand() % (N * N);
            printf("%03d", *(p + N * (i - num) + num));

            Sleep(time_sleep);
        }
    }

    return 0;
}

int Snake(int* p, int N, int time_sleep, int X_Coord = 0, int Y_Coord = 0) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int num = 0; num < N; num++) {
        if (!(num % 2)) {
            for (int i = N - 1; i >= 0; i--) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num
                *(p + N * i + num) = rand() % (N * N);
                printf("%03d", *(p + N * i + num));

                Sleep(time_sleep);
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num);
                *(p + N * i + num) = rand() % (N * N);
                printf("%03d", *(p + N * i + num));

                Sleep(time_sleep);
            }
        }
    }

    destCoord.Y += 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    return 0;
}

int Summ(int* p, int* q, int N, int time_sleep, int X_Coord = 0, int Y_Coord = 0) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int num = 0; num < N; num++) {
        if (!(num % 2)) {
            for (int i = N - 1; i >= 0; i--) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num
                printf("%03d", *(p + N * i + num) + *(q + N * i + num));

                Sleep(time_sleep);
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num);
                printf("%03d", *(p + N * i + num) + *(q + N * i + num));

                Sleep(time_sleep);
            }
        }
    }

    destCoord.Y += 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    return 0;
}

int ShiftedMatrix(int* p, int N, int X_Coord = 0, int Y_Coord = 0) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int num = 0; num < N; num++) {
        for (int i = 0; i < N / 2; i++) {
            swap(*(p + i + num * N), *(p + i + 3 + num * N));
        }
    }
    ShowArr(p, N);
    return 0;
}

int SummedMatrix(int* p, int N, int num4, int X_Coord = 0, int Y_Coord = 0) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int num = 0; num < N; num++) {
        if (!(num % 2)) {
            for (int i = N - 1; i >= 0; i--) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num
                *(p + N * i + num) += num4;
                printf("%03d", *(p + N * i + num));
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num);
                *(p + N * i + num) += num4;
                printf("%03d", *(p + N * i + num));
            }
        }
    }

    destCoord.Y += 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    return 0;
}

int SubtractedMatrix(int* p, int N, int num4, int X_Coord = 0, int Y_Coord = 0) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int num = 0; num < N; num++) {
        if (!(num % 2)) {
            for (int i = N - 1; i >= 0; i--) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num
                *(p + N * i + num) -= num4;
                printf("%03d", *(p + N * i + num));
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num);
                *(p + N * i + num) -= num4;
                printf("%03d", *(p + N * i + num));
            }
        }
    }

    destCoord.Y += 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    return 0;
}

int DividedMatrix(int* p, int N, int num4, int X_Coord = 0, int Y_Coord = 0) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int num = 0; num < N; num++) {
        if (!(num % 2)) {
            for (int i = N - 1; i >= 0; i--) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num
                *(p + N * i + num) /= num4;
                printf("%03d", *(p + N * i + num));
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num);
                *(p + N * i + num) /= num4;
                printf("%03d", *(p + N * i + num));
            }
        }
    }

    destCoord.Y += 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    return 0;
}

int MultipliedMatrix(int* p, int N, int num4, int X_Coord = 0, int Y_Coord = 0) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int num = 0; num < N; num++) {
        if (!(num % 2)) {
            for (int i = N - 1; i >= 0; i--) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num
                *(p + N * i + num) *= num4;
                printf("%03d", *(p + N * i + num));
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                destCoord.X = num * 4 + X_Coord;
                destCoord.Y = i + Y_Coord;
                SetConsoleCursorPosition(hStdout, destCoord);

                //cout << *(p + N * i + num);
                *(p + N * i + num) *= num4;
                printf("%03d", *(p + N * i + num));
            }
        }
    }

    destCoord.Y += 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    return 0;
}

int InsertSort(int* p, int n) {
    int* Pos = p;
    for (int i = 1; i <= n; i++) {
        p = Pos;
        while (*p < *(p - 1)) {
            if (*p < *(p - 1)) {
                swap(*p, *(p - 1));
                p--;
            }
        }
        Pos++;
    }
    return 0;
}

int SuperInsertSort(int* p, int N) {
    for (int arr = 0; arr < N * N; arr += N) {
        InsertSort(p + arr, N);
    }
    return 0;
}



void Lab3()
{
    setlocale(0, "");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(NULL));
    const int N = 6;
    int a[N][N], num4, action;
    int* p = *a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 10;
            //cout << *(p + i*N + j) << ' ';
        }
        cout << '\n';
    }
    cout << "Спираль                       Змейка";
    Spiral(p, N, 30, 0, 8);
    Snake(p, N, 30, 30, 8);


    destCoord.X = 0;
    destCoord.Y = 18;
    SetConsoleCursorPosition(hStdout, destCoord);


    //2 (пункт d)

    cout << "Новая матрица:" << endl;
    ShiftedMatrix(p, N);

    //3

    destCoord.X = 0;
    destCoord.Y = 28;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Сортировка массива:" << endl;
    SuperInsertSort(p, N);
    ShowArr(p, N);

    //4

    cout << "Введите число: ";
    cin >> num4;

    cout << "Выберите действие:" << endl;
    cout << "1 - прибавление числа к элементам матрицы" << endl;
    cout << "2 - вычитание числа из элементов матрицы" << endl;
    cout << "3 - умножение матрицы на число" << endl;
    cout << "4 - деление матрицы на число" << endl;
    cout << "5 - ИДЗ" << endl;
    cout << "Ваш выбор: ";
    cin >> action;
    switch (action) {
    case 1: {
        SummedMatrix(p, N, num4, 0, 44);
        break;
    };
    case 2: {
        SubtractedMatrix(p, N, num4, 0, 44);
        break;
    };
    case 3: {
        MultipliedMatrix(p, N, num4, 0, 44);
        break;
    };
    case 4: {
        if (num4 == 0) {
            cout << "Так нельзя)";
            break;
        }
        DividedMatrix(p, N, num4, 0, 44);
        break;
    };
    case 5: {
        destCoord.X = 0;
        destCoord.Y = 44;
        SetConsoleCursorPosition(hStdout, destCoord);
        cout << "Матрица 1                     Матрица 2                     Сложение матриц" << endl;
        int M1[N][N], M2[N][N];
        Snake(*M1, N, 0, 0, 45);
        Snake(*M2, N, 0, 30, 45);
        Summ(*M1, *M2, N, 0, 60, 45);
    }
    default:
        cout << "Ошибка операции: не выбрано нужное число";
    }
}