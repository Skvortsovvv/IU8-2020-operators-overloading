#include "Vector.h"
#include <iostream>
#include <fstream>
Vector::Vector() // Пустоой конструктор
{
	n = 0;
	p = nullptr;
}


Vector::~Vector() // Диструктор
{
	if (p != nullptr) delete[]p;
}

Vector::Vector(int* p, int n) // Конструктор
{
	this->n = n;
	this->p = new int[n];
	for (int i = 0; i < n; i++) {
		this->p[i] = p[i];
	}
}

Vector::Vector(const Vector& V) //Копирование
{
	n = V.n;
	p = new int[n];
	for (int i = 0; i < n; i++) {
		p[i] = V.p[i];
	}
}

Vector::Vector(Vector&& V) //Перемещение
{
	n = V.n;
	p = V.p;
	V.n = 0;
	V.p = nullptr;
}

int& Vector::operator[](int index) // Обращение по индексу
{
	return p[index];
}

Vector& Vector::operator=(Vector&& V) //Копирование(Присваивание)
{
	n = V.n;
	p = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = V.p[i];
	}
	return *this;
}

Vector& operator^(int* p, Vector& V) { //  XOR
	int* pM = new int[V.n];
	for (int i = 0; i < V.n; i++)
	{
		pM[i] = p[i] ^ V.p[i];
	}
	Vector* pV = new Vector(pM, V.n);
	delete[]pM;
	return *pV;
}

std::ostream& operator<<(ostream& out, Vector& V) // Печать
{
	if (V.p == nullptr) {
		cout << "Vector is empty" << endl;
	}
	else {
		for (int i = 0; i < V.n; i++)
		{
			out << V.p[i] << ' ';
		}
		cout << endl;
	}
	return out;
}

std::istream& operator>>(istream& in, Vector& V) // Запись
{
	int m;
	in >> m;
	V.n = m;
	V.p = new int[m];
	for (int i = 0; i < V.n; i++) {
		in >> V.p[i];
	}
	return in;
}

std::ofstream& operator<<(ofstream& out, Vector& V) // Запись в файл
{
	out << " The result: ";
	for (int i = 0; i < V.n; i++) {
		out << V.p[i];
	}
	return out;
}


std::ifstream& operator>>(ifstream& in, Vector& V) // Чтение из файла
{
	in >> V.n;
	V.p = new int[V.n];
	for (int i = 0; i < V.n; i++) {
		in >> V.p[i];
	}
	return in;
}
