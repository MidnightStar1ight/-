#include <iostream>
#include <cstring>
#include <fstream>
#include<array>


char puncts[] = { '!', '@', '#', '$', '%', '^', '&', '(',')', '-', '_', '"', '№', ';', ':', '?', '/' };

bool isPunc(char symbol) {
    for (int i = 0; i < 17; i++) {
        if (symbol == puncts[i]) {
            return true;
        }
    }
    return false;
}


int searchSubstring(char text[], char pattern[]) {
    int sizeText = strlen(text); int sizePattern = strlen(pattern);
    for (int i = 0; i <= sizeText - sizePattern; i++) {
        int j;
        for (j = 0; j < sizePattern - 1; j++) {
            if (text[i + j] != pattern[j + 1])
                break;
        }

        if (j == sizePattern - 1)
            return i;
    }
    return -1;
}

void Lab4() {
    setlocale(0, "");

    const int size_str = 10000;
    char str[size_str];
    char formattedStr[size_str] = "";

    std::cout <<
        "Введите строку:\n";
    std::cin.getline(str, size_str);

    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    for (i; i < strlen(str); i++) {
        if (str[i] != ' ') {
            strncat_s(formattedStr, str + i, 1);
        }
        else {
            if (str[i] == ' ' && str[i + 1] != ' ' && !isPunc(str[i + 1])) {
                strncat_s(formattedStr, str + i, 1);
            }
        }
    }for (int i = 1; i < strlen(formattedStr); i++) {
        formattedStr[i] = tolower(formattedStr[i]);
    }


    std::cout <<
        "Выберите действие:\n"
        "1 - Вывести отформатированную строку.\n"
        "2 - Вывести слова в строке в обратном порядке\n"
        "3 - Заменить первую букву на заглавную во всех словах.\n"
        "4 - Найти количество подстрок\n";

    int task;
    for (int stop = 0; stop < 1; stop) {
        std::cout << "Введите номер действия: ";
        std::cin >> task;

        switch (task) {
        case 1: {
            std::cout <<
                "Отформатированная строка:\n" <<
                formattedStr << "\n\n";
            break;
        }

        case 2: {
            int wordlen = 0;
            for (int i = strlen(formattedStr) - 1; i >= 0; i--) {
                if (formattedStr[i] != ' ') {
                    ++wordlen;
                }
                else {
                    for (int j = i; j <= i + wordlen; j++) {
                        std::cout << formattedStr[j];
                    }
                    std::cout << ' ';
                    wordlen = 0;
                }
            }
            break;
        }
        case 3: {
            for (int i = 1; i < strlen(formattedStr); i++) {
                if (formattedStr[i - 1] == ' ') {
                    formattedStr[i] = toupper(formattedStr[i]);
                }
            }
            std::cout << formattedStr << "\n\n";
            break;
        }

        case 4:
            std::cout << "Введите искомую подстроку:\n";
            char pattern[size_str] = "";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(pattern, size_str);

            if (searchSubstring(formattedStr, pattern) < 0) {
                std::cout << "Такой подстроки нет\n\n";
            }
            else {
                std::cout << "Индекс массива, с которого начинается строка: " << searchSubstring(formattedStr, pattern); "\n\n";
            }

            break;
        }
    }
}




/*
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int main() {
    setlocale(0, "");

    //1

    const unsigned int N = 1001;
    char words[1000];
    char signs[] = ",. ;:-?!";

    cin.getline(words, N, '.');

    //2

    int Cstart, Cfinish;
    for (int i = 0; i < N; i++) {
        for (int s; s < 9; s++) {
            if (words[i] == signs[i]) {

            }
        }
    }




    return 0;
}




    const int N = 4;
    char word[N-1][N];
    for (int i = 0; i < N-1; i++) {
        cin.getline(word[i], N, ' ');
    }

    for (int i = 0; i < N - 1; i++) {
        cout << word[i];
    }
    */
