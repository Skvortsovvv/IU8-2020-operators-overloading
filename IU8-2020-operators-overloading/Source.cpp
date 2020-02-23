#include <iostream>
#include <fstream>
#include "Vector.h"

using namespace std;

void print(int* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}

int main() {
	int n;
	ifstream inf;
	inf.open("input.txt");
	if (!inf) {
		cout << "File not found!";
		return 0;
	}
	inf >> n;
	int* pM = new int[n]; // Создание одномеронго массива
	for (int i = 0; i < n; i++) {
		inf >> pM[i];
	}
	cout << "Array: ";
	print(pM, n);
	Vector V1;

	inf >> V1; // Создание Vector'а при чтении из файла
	inf.close();
	cout << "Vector V1: ";
	cout << V1;

	Vector V2 = pM ^ V1; // XOR и запись результата в файл
	ofstream outf;
	outf.open("output.txt");
	if (!outf) {
		cout << "File not found!";
		return 0;
	}
	outf << V2;
	outf.close();
	cout << "Vector V2: ";
	cout << V2;

	Vector V3(V1); // Копирование
	cout << "Vector V3(V1): ";
	cout << V3;

	Vector V6 = V2; // Копироание через присваивание
	cout << "Vector V6(V2): ";
	cout << V6;

	Vector V4 = move(V1); // Перемещение
	cout << "Vector V4: " << V4;
	cout << "Vector V1:" << V1;
	V3[1] = 9;

	Vector V5;
	cout << "Enter dimension and elements V5: ";
	cin >> V5;
	cout << "Vector V5: " << V5;

	return 0;

}
