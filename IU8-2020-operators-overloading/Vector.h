#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Vector {
public:
	int* p;
	int n;
public:
	Vector();
	Vector(int* p, int n);
	Vector(const Vector& V); //Копирование
	Vector(Vector&& V); //Перемещение
	~Vector();
	int& operator[](int index);
	Vector& operator=(Vector&& V); //Копирование(Присваивание)
	friend Vector& operator^(int* p, Vector& V); //XOR
	friend ostream& operator<<(ostream& out, Vector& V); // Печать cout
	friend istream& operator>>(istream& in, Vector& V); // Запись cin
	friend ofstream& operator<<(ofstream& out, Vector& V); // Запись в файл
	friend ifstream& operator>>(ifstream& in, Vector& V); // Чтение из файла
};
