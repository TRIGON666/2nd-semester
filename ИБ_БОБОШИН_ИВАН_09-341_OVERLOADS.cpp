/*
1. Определить класс для комплексных чисел. Переопределить операции:

1.1. оператор присвоения =,

1.2. бинарные операции +, -, *, /,

1.3. умножение всего числа на скаляр *,

1.4. операции +=, -=, *=, /=,

1.5. оперции сравнения ==, !=,

1.6. оперции ввода, вывода >>, <<.

Следующие операции с точки зрения комплексных чисел для переопределения бессмысленны, но стоит их попробовать для себя хоть как-то реализовать,
чтобы усвоить то, как они переопределяются: >, <, >=, <=, (постфиксные и префиксные) ++, --.

2. Описать класс для хранения полинома n-й степени (два свойства: n - степень полинома; массив из n+1 элемента,
хранящий коэффициенты при неизвестном в соответствующей степени).
Реализовать конструктор, в котором выделяется массив в зависимости от задаваемого размера.
Релизовать деструктор, в котором удаляется массив. Реализовать метод вычисления полинома для заданного значения x.
Переопределить следующие операции:

2.1. + для сложения двух полиномов,

2.2. - для вычитания двух полиномов,

2.3. * умножения полинома на скаляр,

2.4. * умножения двух полиномов,

2.5. << для вывода вида полинома в консоль.

Пример полинома 4-й степени: 5*x^4 + 3*x^2 - x - 7 (вывод << можно переопределить для такого вида).
Для него массив имеет следующий вид: -7 -1 3 0 5 (mas[0] = -7, mas[1]=-1, mas[2]=3, mas[3] = 0, mas[4] = 5)
*/

#include <iostream>
#include <Windows.h>


class complexNumb 
{
private:
	double real;
	double imaginary;

public:
	complexNumb(double real, double imaginary) {
		this->real = real;
		this->imaginary = imaginary;
	}

	//1.1. оператор присвоения =
	complexNumb operator=(const complexNumb& right_val) 
	{
		if (this == &right_val)
		{
			return *this;
		}
		real = right_val.real;
		imaginary = right_val.imaginary;
		return *this;
	}

	// 1.2. бинарные операции +, -, *, /
	friend complexNumb operator+(const complexNumb& left_val, const complexNumb& right_val) 
	{
		return complexNumb(left_val.real + left_val.real, left_val.imaginary + left_val.imaginary);
	}

	friend complexNumb operator-(const complexNumb& left_val, const complexNumb& right_val) 
	{
		return complexNumb(left_val.real - right_val.real, left_val.imaginary - right_val.imaginary);
	}

	friend complexNumb operator*(const complexNumb& left_val, const complexNumb& right_val) 
	{
		return complexNumb(left_val.real * right_val.real - left_val.imaginary * right_val.imaginary,
			left_val.real * right_val.imaginary + left_val.imaginary * right_val.real);
	}

	friend complexNumb operator/(const complexNumb& left_val, const complexNumb& right_val) 
	{
		double down_val = right_val.real * right_val.real + right_val.imaginary * right_val.imaginary;
		return complexNumb((left_val.real * right_val.real + left_val.imaginary * right_val.imaginary) / down_val,
			(left_val.imaginary * right_val.real - left_val.real * right_val.imaginary) / down_val);
	}

	// 1.3. умножение всего числа на скаляр *
	friend complexNumb operator*(const complexNumb& left_val, double scalar) 
	{
		return complexNumb(left_val.real * scalar, left_val.imaginary * scalar);
	}

	friend complexNumb operator*(double scalar, const complexNumb& left_val)
	{
		return left_val * scalar;
	}

	// 1.4. операции +=, -=, *=, /=
	friend complexNumb& operator+=(complexNumb& left_val, const complexNumb& right_val) 
	{
		left_val.real += right_val.real;
		left_val.imaginary += right_val.imaginary;
		return left_val;
	}

	friend complexNumb& operator-=(complexNumb& left_val, const complexNumb& right_val) 
	{
		left_val.real -= right_val.real;
		left_val.imaginary -= right_val.imaginary;
		return left_val;
	}

	friend complexNumb& operator*=(complexNumb& left_val, const complexNumb& right_val) 
	{
		double tmp_r = left_val.real * right_val.real - left_val.imaginary * right_val.imaginary;
		double tmp_i = left_val.real * right_val.imaginary + left_val.imaginary * right_val.real;
		left_val.real = tmp_r;
		left_val.imaginary = tmp_i;
		return left_val;
	}

	friend complexNumb& operator/=(complexNumb& left_val, const complexNumb& right_val) 
	{
		double down_val = right_val.real * right_val.real + right_val.imaginary * right_val.imaginary;
		double tmp_r = (left_val.real * right_val.real + left_val.imaginary * right_val.imaginary) / down_val;
		double tmp_i = (left_val.imaginary * right_val.real - left_val.real * right_val.imaginary) / down_val;
		left_val.real = tmp_r;
		left_val.imaginary = tmp_i;
		return left_val;
	}

	// 1.5. оперции сравнения ==, !=
	friend bool operator==(const complexNumb& left_val, const complexNumb& right_val) 
	{
		return (left_val.real == right_val.real) && (left_val.imaginary == right_val.imaginary);

	}

	friend bool operator!=(const complexNumb& left_val, const complexNumb& right_val) 
	{
		return !(left_val == right_val);
	}

	// 1.6. оперции ввода, вывода >>, <<
	friend std::ostream& operator<<(std::ostream& out, const complexNumb& res) 
	{
		out << res.real;
		if (res.imaginary >= 0)
			out << " + " << res.imaginary << "i";
		else
			out << res.imaginary << "i";
		return out;
	}

	friend std::istream& operator>>(std::istream& in, complexNumb& res) 
	{
		in >> res.real;
		in >> res.imaginary;
		return in;
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


	Poli operator+(const Poli& other)
	{
		if (this->n != other.n)
			exit(-1);

		Poli res(n);

		for (int i = 0; i <= n; i++)
			res.coeff[i] = coeff[i] + other.coeff[i];

		return res;
	}

	Poli operator-(const Poli& other)
	{
		if (this->n != other.n)
			exit(-1);

		Poli res(n);

		for (int i = 0; i <= n; i++)
			res.coeff[i] = coeff[i] - other.coeff[i];

		return res;
	}

	Poli operator*(double k)
	{
		Poli res(n);

		for (int i = 0; i <= n; i++)
			res.coeff[i] = coeff[i] * k;
		return res;
	}


	Poli operator*(const Poli& other)
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

	friend std::ostream& operator<<(std::ostream& out, const Poli& res)
	{
		out << res.n << "\n";
		for (int i = res.n; i >= 0; i--) {
			if (res.coeff[i] >= 0 && i!=res.n) out << "+";
			if (i == 0)
				out << res.coeff[i] << " ";
			else
				out << res.coeff[i] << "x^" << i << " ";
		}
		out << '\n';
		return out;
	}
};

//
//class complexNumb {
//private:
//	double val;
//public:
//	complexNumb(double val)
//	{
//		this->val = val;
//	}
//
//	//1.1.оператор присвоения =
//	complexNumb operator=(const complexNumb& val_right)
//	{
//		if (this == &val_right)
//		{
//			return *this;
//		}
//		val = val_right.val;
//		return *this;
//	}
//
//	//1.2.бинарные операции + , -, *, /
//	friend complexNumb operator+(const complexNumb& val_left,const complexNumb& val_right)
//	{
//		return complexNumb(val_left.val + val_right.val);
//	}
//
//
//	friend complexNumb operator-(const complexNumb& val_left, const complexNumb& val_right)
//	{
//		return complexNumb(val_left.val - val_right.val);
//	}
//
//	friend complexNumb operator*(const complexNumb& val_left, const complexNumb& val_right)
//	{
//		return complexNumb(val_left.val * val_right.val);
//	}
//
//	friend complexNumb operator/(const complexNumb& val_left, const complexNumb& val_right)
//	{
//		return complexNumb(val_left.val / val_right.val);
//	}
//
//	//1.3. умножение всего числа на скаляр *
//	complexNumb operator*(double scalar)
//	{
//		return complexNumb(val * scalar);
//	}
//	
//	//1.4. операции +=, -=, *=, /=
//	friend complexNumb operator+=(complexNumb& val_left,complexNumb& val_right)
//	{
//		val_left.val += val_right.val;
//		return complexNumb(val_left);
//	}
//
//
//	friend complexNumb operator-=(complexNumb& val_left, complexNumb& val_right)
//	{
//		val_left.val -= val_right.val;
//		return complexNumb(val_left);
//	}
//
//	//complexNumb operator-=(complexNumb& val_right)
//	//{
//	//	this->val -= val_right.val;
//	//	return *this;
//	//}
//
//	friend complexNumb operator*=(complexNumb& val_left, complexNumb& val_right)
//	{
//		val_left.val *= val_right.val;
//		return complexNumb(val_left);
//	}
//
//	friend complexNumb operator/=(complexNumb& val_left, complexNumb& val_right)
//	{
//		val_left.val /= val_right.val;
//		return complexNumb(val_left);
//	}
//
//	//complexNumb operator/=(complexNumb& val_right)
//	//{
//	//	this->val /= val_right.val;
//	//	return *this;
//	//}
//	
//	//1.5. оперции сравнения ==, !=
//	friend complexNumb operator==(complexNumb& val_left, complexNumb& val_right)
//	{
//		return val_left.val == val_right.val;
//	}
//
//	friend complexNumb operator!=(complexNumb& val_left, complexNumb& val_right)
//	{
//		return val_left.val != val_right.val;
//	}
//
//	//
//	void print() 
//	{
//		std::cout << "Число = " << val << "i\n";
//	}
//};

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//complexNumb a(10);
	//complexNumb b(5);
	//a.print();
	//b.print();
	//complexNumb c = a + b;
	//c.print();
	//complexNumb c1 = a - b;
	//c1.print();
	//complexNumb c2 = a * b;
	//c2.print();
	//complexNumb c3 = a / b;
	//c3.print();
	//complexNumb c4 = a * 4;
	//c4.print();
	//complexNumb c5 = b * 5;
	//c5.print();
	//(a += b).print();
	//(a -= b).print();
	//(a *= b).print();
	//(a /= b).print();
	//(a == b).print();
	
	std::cout << "Задача 1" << "\n"; 

	complexNumb a(99, 5);
	complexNumb b(31, -12);

	std::cout << "Число =  " << (a + b) << "\n";

	a += complexNumb(23, 36);

	std::cout << "Число = " << a << "\n";
	std::cout << "Число = " << (b *= a) << "\n";
	std::cout << "Число = " << (a * 52) << "\n";

	std::cout << "Число (a==b) = ";
	if (a == b) std::cout << "True" << "\n";
	else std::cout << "False" << "\n";

	std::cout << "Число (a!=b) = " ;
	if (a != b) std::cout << "True" << "\n";
	else std::cout << "False" << "\n";

	complexNumb input_infoValue(0,0);
	std::cin >> input_infoValue;
	std::cout << input_infoValue << "\n";
	
	std::cout << "Задача 2" << "\n";

	Poli p1(3);
	p1.fill_poli();

	Poli p2(3);
	p2.fill_poli();

	std::cout << "Сложение полиномов p1+p2 размера = " << (p1 + p2) << "\n";
	std::cout << "Вычитание полиномов p1-p2 размера = " << (p1 - p2) << "\n";
	std::cout << "Умножение полиномов p1*p2 размера = " << (p1 * p2) << "\n";
	std::cout << "Умножение на вектор полиномов p1*3 = размера = " << (p1 * 3) << "\n";
}

