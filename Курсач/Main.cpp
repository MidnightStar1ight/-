#include <iostream>
#include "labs.h"

using namespace std;


int main() {
	setlocale(0, "");
	int lab;
	cout << "Выберите номер работы (1-4): ";
	cin >> lab;
	switch (lab) {
	case 1:
		Lab1();
		break;
	case 2:
		Lab2();
		break;
	case 3:
		Lab3();
		break;
	case 4:
		Lab4();
		break;
	default:
		cout << "Ошибка введения";
	}

	return 0;
}