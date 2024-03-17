#include <iostream>
#include <Windows.h>
#include <fstream>

/*
﻿1. Описать класс для хранения вектора чисел (два свойства: размер вектора, сам вектор). Реализовать конструктор, в котором выделяется массив в зависимости от задаваемого размера. Релизовать деструктор, в котором удаляется массив. Реализовать методы сложения двух векторов (результат сохраняется в объекте, метод которого вызван), умножения вектора на скаляр.

2. Описать класс для хранения полинома n-й степени (два свойства: n - степень полинома; массив из n+1 элемента, хранящий коэффициенты при неизвестном в соответствующей степени). Реализовать конструктор, в котором выделяется массив в зависимости от задаваемого размера. Релизовать деструктор, в котором удаляется массив. Реализовать методы вычисления полинома для заданного значения, сложения двух полиномов (результат сохраняется в объекте, метод которого вызван), вычитания двух полиномов, умножения полинома на скаляр, умножения двух полиномов.

Пример полинома 4-й степени: 5*x^4 + 3*x^2 - x - 7. Для него массив имеет следующий вид: -7 -1 3 0 5 (mas[0] = -7, mas[1]=-1, mas[2]=3, mas[3]=0, mas[4]=5).

3*. Описать класс для информации о студенте (ФИО, возраст, группа, институт, направление). Реализовать конструктор и деструктор. На каждое свойство релизовать соответствующие методы типа set и get.

4*. Релизовать в классе о студенте (задача п.3) метод записи в текстовый файл и чтения из текстового файла свойств класса. Заполнить один объект класса о студенте. Используя реализованные методы записать этот объект в текстовый файл. После записи считать информацию о студенте из текстового файла в новый объект.

Замечание. В методы записи и чтения передается только один аргумент - строка с именем файла для записи или чтения, соответственно.
*/



class Vector {
private:
	int size;
	int* elm;
public:
	
	Vector()
	{
		size = 0;
		elm = NULL;
	}

	Vector(int size)
	{
		if (size == 0)
		{
			this->size = 0;
			elm = NULL;
			return;
		}
		if (size < 0)
		{
			exit(-1);
		}

		this->size = size;
		elm = new int[size];

		/*std::cout << "Vector is made!\n";*/
	}

	Vector(const Vector& other)
	{
		size = other.size;
		elm = new int[size];

		for (int i = 0; i < size; i++)
			elm[i] = other.elm[i];
	}

	~Vector()
	{
		delete[] elm;
		/*std::cout << "Vector is destroyed!\n";*/
	}


	int get_size()
	{
		return size;
	}

	int get_element(int i)
	{
		if (i < 0 || i >= size)
			exit(-1);
		return elm[i];
	}

	void set_element(int i, int val)
	{
		if (i < 0 || i >= size)
			exit(-1);
		elm[i] = val;
	}


	void fill_vector()
	{
		for (int i = 0; i < size; i++)
			std::cin >> elm[i];
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << elm[i] << " " << "<---";
		std::cout << '\n';
	}


	Vector add(Vector other)
	{
		if (this->size != other.size)
			exit(-1);

		Vector res(size);

		for (int i = 0; i < size; i++)
		{
			res.elm[i] = elm[i] + other.elm[i];
		}

		return res;
	}

	Vector mult(int k)
	{
		Vector res(size);

		for (int i = 0; i < size; i++)
			res.elm[i] = elm[i] * k;
		return res;
	}
};

class Poli {
private:
	int n;
	double* coeff;
public:

	Poli()
	{
		n = 0;
		coeff = NULL;
	}

	Poli(int n)
	{
		if (n <= 0)
		{
			this->n = 0;
			coeff = NULL;
			return;
		}
		if (n < 0)
		{
			exit(-1);
		}

		this->n = n;
		coeff = new double[n + 1];
	}

	Poli(const Poli& other)
	{
		n = other.n;
		coeff = new double[n + 1];

		for (int i = 0; i <= n; i++)
			coeff[i] = other.coeff[i];
	}

	~Poli()
	{
		delete[] coeff;
	}


	int get_n() const
	{
		return n;
	}

	double get_coeff(int i) const
	{
		if (i < 0 || i >= n + 1)
			exit(-1);
		return coeff[i];
	}

	void set_element(int i, double val)
	{
		if (i < 0 || i >= n + 1)
			exit(-1);
		coeff[i] = val;
	}


	void fill_poli()
	{
		for (int i = 0; i <= n; i++)
			std::cin >> coeff[i];
	}


	Poli add(const Poli& other)
	{
		if (this->n != other.n)
			exit(-1);

		Poli res(n);

		for (int i = 0; i <= n; i++)
			res.coeff[i] = coeff[i] + other.coeff[i];

		return res;
	}
	Poli sub(const Poli& other)
	{
		if (this->n != other.n)
			exit(-1);

		Poli res(n);

		for (int i = 0; i <= n; i++)
			res.coeff[i] = coeff[i] - other.coeff[i];

		return res;
	}

	Poli multk(double k)
	{
		Poli res(n);

		for (int i = 0; i <= n; i++)
			res.coeff[i] = coeff[i] * k;
		return res;
	}


	Poli mult(const Poli& other)
	{
		int res_size = n + other.n;
		Poli res(res_size);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= other.n; j++) {
				res.coeff[i + j] = coeff[i] * other.coeff[j];
			}
		}

		return res;
	}


	void print()
	{
		for (int i = n; i >= 0; i--)
		{
			if (i == 0)
				std::cout << coeff[i] << " ";
			else
				std::cout << coeff[i] << "x^" << i << " ";
		}
		std::cout << '\n';
	}


	void printM(const Poli& other)
	{
		for (int i = other.n; i >= 0; i--)
		{
			if ((i) == 0)
				std::cout << coeff[i] << " ";
			else
				std::cout << coeff[i] << "x^" << i << " ";
		}
		std::cout << '\n';

	}
};

class Student {
private:
	char* fullName;
	int age;
	char* group;
	char* institute;
	char* specialization;

public:
	Student(const char* name, int studentAge,
		const char* studentGroup,
		const char* studentInstitute,
		const char* studentSpecialization)
	{
		size_t sizeName = strlen(name) + 1;
		fullName = new char[sizeName];
		strcpy_s(fullName, sizeName, name);

		age = studentAge;

		size_t sizeGroup = strlen(studentGroup) + 1;
		group = new char[sizeGroup];
		strcpy_s(group, sizeGroup, studentGroup);

		size_t sizeInstitute = strlen(studentInstitute) + 1;
		institute = new char[sizeInstitute];
		strcpy_s(institute, sizeInstitute, studentInstitute);

		size_t sizeSpecialization = strlen(studentSpecialization) + 1;
		specialization = new char[sizeSpecialization];
		strcpy_s(specialization, sizeSpecialization, studentSpecialization);
	}

	~Student() {
		delete[] fullName;
		delete[] group;
		delete[] institute;
		delete[] specialization;
	}

	const char* getFullName() {
		return fullName;
	}

	int getAge() {
		return age;
	}

	const char* getGroup() {
		return group;
	}

	const char* getInstitute() {
		return institute;
	}

	const char* getSpecialization() {
		return specialization;
	}

	void setFullName(const char* name) {
		size_t size = strlen(name) + 1;
		fullName = new char[size];
		strcpy_s(fullName, size, name);
	}

	void setAge(int studentAge) {
		age = studentAge;
	}

	void setGroup(const char* studentGroup) {
		size_t size = strlen(studentGroup) + 1;
		group = new char[size];
		strcpy_s(group, size, studentGroup);
	}

	void setInstitute(const char* studentInstitute) {
		size_t size = strlen(studentInstitute) + 1;
		institute = new char[size];
		strcpy_s(institute, size, studentInstitute);
	}

	void setSpecialization(const char* studentSpecialization) {
		size_t size = strlen(studentSpecialization) + 1;
		specialization = new char[size];
		strcpy_s(specialization, size, studentSpecialization);
	}

	void print() {
		std::cout << "ФИО: " << fullName << "\n";
		std::cout << "Возраст: " << age << "\n";
		std::cout << "Группа: " << group << "\n";
		std::cout << "Институт: " << institute << "\n";
		std::cout << "Направление: " << specialization << "\n";
	}


	void writeS() {
		std::ofstream fout("out.txt");
		if (!fout.is_open()) {
			return;
		}
		fout << fullName << "\n";
		fout << age << "\n";
		fout << group << "\n";
		fout << institute << "\n";
		fout << specialization << "\n";
		fout.close();
	}

	void readS() {
		std::ifstream fin("out.txt");
		if (!fin.is_open()) {
			return;
		}
		char buf[100];
		fin.getline(buf, 100);
		setFullName(buf);
		fin >> age;
		fin.ignore(); // небольшой фикс проблемы пустой строчки
		fin.getline(buf, 100);
		setGroup(buf);
		fin.getline(buf, 100);
		setInstitute(buf);
		fin.getline(buf, 100);
		setSpecialization(buf);
		fin.close();
	}
};


int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Задание 1 \n";

	Vector p1(3), p2(3);

	p1.fill_vector();
	p2.fill_vector();

	Vector p3 = p1.add(p2);

	p3.print();

	(p3.mult(4)).print();

	std::cout << "Задание 2 \n";

	Poli x1(4);
	x1.fill_poli();

	Poli x2(4);
	x2.fill_poli();

	Poli x3 = x1.add(x2);
	x3.print();

	Poli x4 = x1.sub(x2);
	x4.print();

	(x3.multk(4)).print();

	Poli tmp = x1.mult(x2);
	tmp.printM(tmp);

	std::cout << "Задание 3 \n";

	Student student("Бобошин Иван Сергеевич", 18, "09-341", "ICMIT", "Информационная Безопасность");
	student.print();
	std::cout << "\n";
	student.writeS();
	Student newStudent("", 0, "", "", "");
	newStudent.readS();
	newStudent.print();


	return 0;
}

