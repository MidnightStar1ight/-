#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;


void bubble_sort(int* p, int n) {
	int* StartPos = p;
	for (int i = 0; i < n - 1; i++) {
		p = StartPos;
		for (int j = 0; j < n - i - 1; j++, p++) {
			if (*p > *(p + 1)) {
				swap(*p, *(p + 1));
			}
		}
	}
}

void shaker_sort(int* p, int n) {
	int* StartPos = p;
	for (int i = 0; i < n / 2; i++) {
		p = StartPos;
		for (int j = i; j < n - i - 1; j++, p++) {
			if (*p > *(p + 1)) {
				swap(*p, *(p + 1));
			}
		}
		p -= 2;
		for (int j = n - 3 - i; j >= i; j--, p--) {
			if (*p > *(p + 1)) {
				swap(*p, *(p + 1));
			}
		}
		StartPos += 1;
	}

}

void comb_sort(int* p, int n) {
	int* StartPos = p;
	float k = 1.3;
	int cycle = 1, range = n - 1;
	do {
		p = StartPos;
		if (range == 1) {
			cycle = 0;
		}
		for (int i = 0; i < n - range; i++, p++) {
			if (*p > *(p + range)) {
				swap(*p, *(p + range));
				if (range == 1) {
					cycle += 1;
				}
			}
		}
		if (range > 1) {
			range = int(range / k);
		}
	} while (cycle > 0);
}

void insert_sort(int* p, int n) {
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
}

void quick_sort(int* p, int end, int begin) {
	int mid;
	int f = begin;
	int l = end;
	mid = *(p + ((f + l) / 2));
	while (f < l)
	{
		while (*(p + f) < mid) f++;
		while (*(p + l) > mid) l--;
		if (f <= l)
		{
			swap(*(p + f), *(p + l));
			f++;
			l--;
		}
	}
	if (begin < l) quick_sort(p, l, begin);
	if (f < end) quick_sort(p, end, f);
}

float bin_search(int num, int* p, int n) {
	if (num == *(p + n / 2)) return 1;
	if ((n == 1) and (num != *p)) return 0;

	if (n % 2 == 0) {
		if (num > *(p + n / 2)) {
			//cout << "�";
			return bin_search(num, p + n / 2, n / 2);
		}
		if (num < *(p + n / 2)) {
			//cout << "�";
			return bin_search(num, p, n / 2);
		}
	}
	else {
		if (num > *(p + n / 2 + 1)) {
			//cout << "�";
			return bin_search(num, p + n / 2 + 1, n / 2 + 1);
		}
		if (num < *(p + n / 2 + 1)) {
			//cout << "�";
			return bin_search(num, p, n / 2 + 1);
		}
	}
}


void Lab2() {

	srand(time(NULL));
	setlocale(0, "ru");
	int num_min, num_max;
	int mid_num, mid_num_count = 0, less_num, less_num_count = 0, more_num, more_num_count = 0, index1, index2, find_num;
	int a_max, a_min, a_NotSorted_max, a_NotSorted_min, max = 1 << (sizeof(int) - 1), min = -max;
	const int n = 10;
	int a[n], b[n], type, * p = a, * p_NotSorted = b;
	int task;
	auto
		s_start = high_resolution_clock::now(),
		s_end = high_resolution_clock::now();
	duration<double> Duration;

	// ������� �������

	do {
		cout << "�������� �����: ";
		cin >> num_min >> num_max;
		p = a;
		p_NotSorted = b;
		bool error = 0;
		cout << "�������� ������: ";
		for (int i = 0; i < n; i++, p++, p_NotSorted++) {
			*p = *p_NotSorted = rand() % (num_max - num_min + 1) + num_min;
			cout << *p << ' ';
		}


		p_NotSorted = b;
		cout << endl;

		do {
			cout << "\n\n";
			cout << "�������:" << '\n' <<
				"1. ����������" << '\n' <<
				"2. ���������� max/min ���������" << '\n' <<
				"3. ������� �������� � ��� ���������� � �������" << '\n' <<
				"4. ���������� � ������� ����� ������� ���������" << '\n' <<
				"5. ���������� � ������� ����� ������ ���������" << '\n' <<
				"6. �������� �����" << '\n' <<
				"7. ������������ ��������� �������" << '\n' <<
				"8. ���" << '\n' <<

				"0. ������ ����� ������ / �����" << "\n\n" <<

				"�������� ������� (������� 2-6 �������� ������ ����� ����������): ";

			cin >> task;
			switch (task) {
			case (1):
				cout << "\n\n";

				cout << "���� ����������:" << '\n' <<
					"1: Bubble sort" << '\n' <<
					"2: Shaker sort" << '\n' <<
					"3: Comb sort" << '\n' <<
					"4: Insert sort" << '\n' <<
					"5: Quick sort" << '\n';
				cout << "�������� ��� ����������: ";
				cin >> type;


				switch (type)
				{
				case (1):
					s_start = high_resolution_clock::now();
					bubble_sort(a, n);
					s_end = high_resolution_clock::now();
					duration<double> b_s_duration = s_end - s_start;
					cout << "\n" "����� ����������: " << b_s_duration.count() << " ������";
					break;
				case (2):
					s_start = high_resolution_clock::now();
					shaker_sort(a, n);
					s_end = high_resolution_clock::now();
					duration<double> s_s_duration = s_end - s_start;
					cout << "\n" "����� ����������: " << s_s_duration.count() << " ������";
					break;
				case (3):
					s_start = high_resolution_clock::now();
					comb_sort(a, n);
					s_end = high_resolution_clock::now();
					duration<double> c_s_duration = s_end - s_start;
					cout << "\n" "����� ����������: " << c_s_duration.count() << " ������";
					break;
				case (4):
					s_start = high_resolution_clock::now();
					insert_sort(a, n);
					s_end = high_resolution_clock::now();
					duration<double> i_s_duration = s_end - s_start;
					cout << "\n" "����� ����������: " << i_s_duration.count() << " ������";
					break;
				case (5):
					s_start = high_resolution_clock::now();
					quick_sort(a, n - 1, 0);
					s_end = high_resolution_clock::now();
					duration<double> q_s_duration = s_end - s_start;
					cout << "\n" "����� ����������: " << s_s_duration.count() << " ������";
					break;

				default:
					cout << "������ �����: ������� ����� �� 1 �� 5";
					error = 1;
					task = 0;
					break;
				}
				if (!error) {
					cout << "\n\n" << "��������������� ������:" << endl;
					p = a;
					for (int i = 0; i < n; i++, p++) {
						cout << *p << ' ';
					}
				}

				cout << "\n\n";
				break;
			case (2): {
				p = a;
				p_NotSorted = b;
				s_start = high_resolution_clock::now();
				a_max = *(p + n - 1);
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "����� ���������� ����. �������� ���������������� �������: " << Duration.count() << " ������" << endl;

				s_start = high_resolution_clock::now();
				a_min = *p;
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "����� ���������� ���. �������� ���������������� �������: " << Duration.count() << " ������" << endl;

				//cout << "!!    " << * p_NotSorted << endl;
				a_NotSorted_min = 1 << (sizeof(int) - 1);
				a_NotSorted_max = -a_NotSorted_min;
				s_start = high_resolution_clock::now();
				for (int i = 1; i < n; i++, p_NotSorted++) {
					//cout << '|' << i << ' ' << *p_NotSorted << '|' << ' ';
					if (*p_NotSorted > a_NotSorted_max) a_NotSorted_max = *p_NotSorted;
				}
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "����� ���������� ����. �������� ������������������ �������: " << Duration.count() << " ������" << endl;

				p_NotSorted--;
				s_start = high_resolution_clock::now();
				for (int i = n - 1; i >= 0; i--, p_NotSorted--) {
					if (*p_NotSorted < a_NotSorted_min) a_NotSorted_min = *p;
				}
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "����� ���������� ���. �������� ������������������ �������: " << Duration.count() << " ������" << endl;

				cout << "\n" "������������ ������� : " << a_NotSorted_max << "\n" "����������� ������� : " << a_NotSorted_min << endl;
				break;
			}
			case (3): {
				p = a;
				a_max = *(p + n - 1);
				a_min = *p;
				cout << "\n\n";
				mid_num = (a_max + a_min) / 2;
				cout << "������� ��������: " << mid_num << endl;
				cout << "������� ���������: ";
				s_start = high_resolution_clock::now();
				for (int i = 0; i < n; i++, p++) {
					if (*p == mid_num) {
						cout << i << ' ';
						mid_num_count++;
					}
				}
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "\n" "����� ���������� ���������, ������ �������� ��������: " << Duration.count() << " ������" << endl;

				cout << "���������� ���������, ������ �������� ��������: " << mid_num_count << endl;

				break;
			}
			case (4): {
				p = a;
				cout << "\n" "������� ����� ��� ������ � ������� ��������� ������ �������: ";
				cin >> less_num;
				s_start = high_resolution_clock::now();
				for (int i = 0; i < n; i++, p++) {
					if (*p < less_num) less_num_count++;
				}
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "\n" "���������� ��������� ������ ������� ��������: " << less_num_count;
				cout << "\n" "����� ���������� ���������� ��������� ������ ��������� ��������: " << Duration.count() << " ������" << endl;
				break;
			}
			case (5): {
				p = a;
				cout << "\n" "������� ����� ��� ������ � ������� ��������� ������ �������: ";
				cin >> more_num;
				s_start = high_resolution_clock::now();
				for (int i = 0; i < n; i++, p++) {
					if (*p > more_num) more_num_count++;
				}
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "\n" "���������� ��������� ������ ������� ��������: " << more_num_count;
				cout << "\n" "����� ���������� ���������� ��������� ������ ������� ��������: " << Duration.count() << " ������" << endl;
				break;
			}
			case (6): {
				p = a;
				cout << "\n" "������� �����, ������� ���������� �����: ";
				cin >> find_num;
				s_start = high_resolution_clock::now();
				bin_search(find_num, p, n);
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;

				p = a;
				int is_true = 0;
				s_start = high_resolution_clock::now();
				for (int i = 0; i < n; i++, p++) {
					if (*p == find_num) {
						is_true = 1;
						break;
					}
				}
				s_end = high_resolution_clock::now();
				duration<double> Duration_2 = s_end - s_start;

				if (bin_search(find_num, p, n)) cout << "�������� ����� ���� � �������" << endl;
				else cout << "��������� ����� ��� � �������" << endl;
				cout << "\n" "����� ���������� �������� � ������� ���������: " << Duration_2.count() << " ������" << endl;
				cout << "����� ���������� �������� � ������� �������� �������: " << Duration.count() << " ������" << endl;
				break;
			}
			case (7): {
				p = a;
				cout << "\n" "������� ������� ��������� ��� �� ������������: ";
				cin >> index1 >> index2;
				s_start = high_resolution_clock::now();
				swap(*(p + index1), *(p + index2));
				s_end = high_resolution_clock::now();
				Duration = s_end - s_start;
				cout << "\n" "����� ������������ ���������: " << Duration.count() << " ������" << endl;
				break;
			}
			case (8): {
				p = b;
				int idz_num, idz_count = 0;
				cout << "������� ��������, ������� ����� ������� �� ������ ��������� �������: ";
				cin >> idz_num;
				for (int i = 1; i < n; i += 2) *(p + i) = (*(p + i) - idz_num) * (rand() % 10);
				cout << "\n" "���������� ������:" << endl;
				for (int i = 0; i < n; i++) cout << *(p + i) << ' ';

				for (int i = 1; i < n; i += 2) {
					if (*(p + i) % 2 == 0) idz_count++;
				}
				cout << "\n" "���������� ������ ��������� � ������� ����������: " << idz_count << endl;
				idz_count = 0;

				cout << "���������� �������� ��������� � ��������� ����������: " << idz_count << endl;
				cout << "���������� ���������, ��������� ������ �� 1: " << ' ' << n << endl;
				for (int i = 0; i < n; i++) {
					if (*(p + i) % 2 == 0) idz_count++;
				}
				cout << "���������� ���������, ��������� ������ �� 2: " << ' ' << idz_count << endl;
				idz_count = 0;
				for (int i = 0; i < n; i++) {
					if (*(p + i) % 3 == 0) idz_count++;
				}
				cout << "���������� ���������, ��������� ������ �� 3: " << ' ' << idz_count << endl;
			}
			case (0):
				//
				break;
			default:
				cout << "����������� ������ ����� �������";
				break;
			}
		} while (task);

		//1. ����������
		//2. max/min ��������
		//3. ��. �������� � ��� ����������
		//4. ������ a
		//5. ������ b
		//6. �������� �����
		//7. ������������� ���������
		//8. ���


		cout << "\n\n" << "������ ����� ������?" << '\n' << "1 - ��" << '\n' << "0 - ���" << endl;
		cin >> task;
	} while (task);
}