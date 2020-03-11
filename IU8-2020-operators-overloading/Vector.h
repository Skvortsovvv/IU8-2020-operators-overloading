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
	Vector(const Vector& V); //�����������
	Vector(Vector&& V); //�����������
	~Vector();
	int& operator[](int index);
	Vector& operator=(Vector&& V); //�����������(������������)
	friend Vector& operator^(int* p, Vector& V); //XOR
	friend ostream& operator<<(ostream& out, Vector& V); // ������ cout
	friend istream& operator>>(istream& in, Vector& V); // ������ cin
	friend ofstream& operator<<(ofstream& out, Vector& V); // ������ � ����
	friend ifstream& operator>>(ifstream& in, Vector& V); // ������ �� �����
};
