#include <iostream>
#include <Windows.h>
#include <ctime>

	class Node
	{
	public:
		double data;
		Node* prev, * next;

	public:
		Node(double data)
		{
			this->data = data;
			this->prev = this->next = NULL;
		}
	};

	class OneLinkedList {
	public:
		Node* head, * tail;
	public:
		OneLinkedList()
		{
			this->head = this->tail = NULL;
		}

		OneLinkedList(const OneLinkedList& other) // конструктор копирования
		{
			head = tail = NULL;
			Node* node = other.head;
			while (node)
			{
				push_back(node->data);
				node = node->next;
			}
		}

		~OneLinkedList()
		{
			while (head != NULL) pop_front(); // удаление всех объектов
		}

		void pop_front() // удаление с начала
		{
			if (head == NULL) return;
			if (head == tail)
			{
				delete tail;
				head = tail = NULL;
				return;
			}

			Node* node = head;
			head = node->next;
			delete node;
		}

		void push_back(double data) // добавление в конец
		{
			Node* node = new Node(data);
			//if (head == NULL) head = node;
			//if (tail != NULL) tail->next = node;
			//tail = node;
			if (head == NULL)
			{
				head = node;
				tail = node;
			}
			else
			{
				tail->next = node;
				tail = node;
			}
		}

		void push_front(double data) // добавление в начало
		{
			Node* node = new Node(data);
			node->next = head;
			head = node;
			if (tail == NULL) tail = node;
		}

		void pop_back() // удаление с конца
		{
			if (tail == NULL) return;
			if (head == tail)
			{
				delete tail;
				head = tail = NULL;
				return;
			}

			Node* node = head;
			for (; node->next != tail; node = node->next);
			node->next = NULL;
			delete tail;
			tail = node;
		}

		Node* getAt(int k) // доступ к элементу
		{
			if (k < 0) return NULL;

			Node* node = head;
			int n = 0;
			/*while (node && n != k && node->next)
			{
				node = node->next;
				n++;
			}*/
			while (node && n != k)
			{
				node = node->next;
				n++;
			}
			return (n == k) ? node : NULL;
		}

		void insert(int k, double data) // вставка элемента
		{
			Node* left = getAt(k);
			if (left == NULL) return;

			Node* right = left->next;
			Node* node = new Node(data);

			left->next = node;
			node->next = right;
			if (right == NULL) tail = node;
		}

		void earse(int k) // удаление промежуточного
		{
			if (k < 0) return;

			if (k == 0)
			{
				pop_front();
				return;
			}

			Node* left = getAt(k - 1);

			if (left == NULL) return;

			Node* node = left->next;

			if (node == NULL) return;

			Node* right = node->next;

			left->next = right;
			if (node == tail) tail = left;
			delete node;
		}

		int FindElem(double data) // поиск первого попавшегося элемента
		{
			int k = 0;
			Node* node = head;
			while (node)
			{
				if (node->data == data) return k;
				node = node->next;
				k++;
			}
			return -1;
		}

		int GetElemData(int k, bool& ok) // получение элемента
		{
			/*if (k < 0 || head == NULL)
			{
				ok = false;
				return INT_MIN;
			}
			Node* node = head;
			int n = 0;
			while (node && n != k)
			{
				node = node->next;
				n++;
			}
			if (node)
			{
				ok = true;
				return node->data;
			}

			ok = false;
			return INT_MIN;*/
			Node* node = getAt(k);
			if (node)
			{
				ok = true;
				return node->data;
			}
			ok = false;
			return INT_MIN;
		}

		int GetListSize() // размер списка
		{
			Node* node = head;
			int n = 0;
			while (node)
			{
				node = node->next;
				n++;
			}
			return n;
		}

		bool remElm(double data) // удаление элемента
		{
			bool del = false;
			Node* node = head;
			Node* prev = NULL;

			while (node != NULL)
			{
				if (node->data == data)
				{
					Node* tmp = node;
					if (prev != NULL)
						prev->next = node->next;
					else
						head = node->next;
					node = node->next;
					delete tmp;
					del = true;
				}
				else
				{
					prev = node;
					node = node->next;
				}
			}

			return del;
		}

		void sort() // сортировка по возрастанию
		{
			if (!head || !head->next) return;

			Node* sorted = NULL;
			Node* unsorted = head;

			while (unsorted)
			{
				Node* node = unsorted;
				unsorted = unsorted->next;

				if (!sorted || sorted->data >= node->data)
				{
					node->next = sorted;
					sorted = node;
				}
				else
				{
					Node* prev = NULL;
					Node* tmp = sorted;
					while (tmp && tmp->data < node->data)
					{
						prev = tmp;
						tmp = tmp->next;
					}

					if (!prev)
					{
						node->next = sorted;
						sorted = node;
					}
					else
					{
						node->next = prev->next;
						prev->next = node;
					}
				}
			}

			head = sorted;

			Node* lastNode = sorted;
			while (lastNode->next)
			{
				lastNode = lastNode->next;
			}
			tail = lastNode;
		}

		void transpose() // обратный порядок
		{
			if (!head || !head->next) return;

			Node* node = head;
			Node* prev = NULL;
			Node* ptr;

			while (node) {
				ptr = node->next;
				node->next = prev;
				prev = node;
				node = ptr;
			}

			head = prev;
			tail = head;
		}

		void fill_size(int size)
		{
			double data;
			for (int i = 0; i < size; ++i)
			{
				std::cin >> data;
				push_back(data);
			}
		}

		void fillRandom(int size)
		{
			srand(time(0));
			for (int i = 0; i < size; ++i)
			{
				double data = rand();
				push_back(data);
			}
		}

		OneLinkedList sortedLists(const OneLinkedList& other)
		{
			OneLinkedList result;
			Node* node1 = head;
			Node* nodeOther = other.head;

			while (node1 != NULL && nodeOther != NULL)
			{
				if (node1->data <= nodeOther->data)
				{
					result.push_back(node1->data);
					node1 = node1->next;
				}
				else
				{
					result.push_back(nodeOther->data);
					nodeOther = nodeOther->next;
				}
			}

			while (node1 != NULL)
			{
				result.push_back(node1->data);
				node1 = node1->next;
			}

			while (nodeOther != NULL)
			{
				result.push_back(nodeOther->data);
				nodeOther = nodeOther->next;
			}
			return result;
		}
	};

class LinkedList // двусвязный список
{
public:
	Node* head, * tail;
public:
	LinkedList()
	{
		this->head = this->tail = NULL;
	}

	LinkedList(const LinkedList& other) // конструктор копирования
	{
		head = tail = NULL;
		Node* ptr = other.head;
		while (ptr)
		{
			push_back(ptr->data);
			ptr = ptr->next;
		}

	}

	~LinkedList()
	{
		while (head != NULL) pop_front(); // удаление всех объектов
	}

	void pop_front() // удаление с начала
	{
		if (head == NULL) return;
		Node* ptr = head->next;
		if (ptr != NULL) ptr->prev = NULL;
		else tail = NULL;

		delete head;
		head = ptr;
	}

	Node* push_back(double data) // добавление в конец
	{
		Node* ptr = new Node(data);
		ptr->prev = tail;
		if (tail != NULL) tail->next = ptr;
		if (head == NULL) head = ptr;
		tail = ptr;
		return ptr;
	}

	Node* push_front(double data) // добавление в начало
	{
		Node* ptr = new Node(data);
		ptr->next = head;
		if (head != NULL) head->prev = ptr;
		if (tail == NULL) tail = ptr;
		head = ptr;
		return ptr;
	}

	void pop_back() // удаление с конца
	{
		if (tail == NULL) return;
		Node* ptr = tail->prev;
		if (ptr != NULL) ptr->next = NULL;
		else head = NULL;

		delete tail;
		tail = ptr;
	}

	Node* getAt(int k) // доступ к элементу
	{
		Node* ptr = head;
		int n = 0;

		while (n != k)
		{
			if (ptr == NULL) return ptr;
			ptr = ptr->next;
			n++;
		}

		return ptr;
	}

	Node* insert(int k, double data) // вставка элемента
	{
		Node* right = getAt(k);
		if (right == NULL) return push_back(data);

		Node* left = right->prev;
		if (left == NULL) return push_front(data);

		Node* ptr = new Node(data);

		ptr->prev = left;
		ptr->next = right;
		left->next = ptr;
		right->prev = ptr;
		
		return ptr;
	}

	void earse(int k) // удаление промежуточного
	{
		Node* ptr = getAt(k);
		if (ptr == NULL) return;

		if (ptr->prev == NULL)
		{
			pop_front();
			return;
		}

		if (ptr->next == NULL)
		{
			pop_back();
			return;
		}

		Node* left = ptr->prev;
		Node* right = ptr->next;

		left->next = right;
		right->prev = left;

		delete ptr;
	}

	int FindElem(double data) // поиск первого попавшегося элемента
	{
		int k = 0;
		Node* ptr = head;
		while (ptr)
		{
			if (ptr->data == data) return k;
			ptr = ptr->next;
			k++;
		}
		return -1;
	}

	int GetElemData(int k, bool& ok) // получение элемента
	{
		if (k < 0 || head == NULL)
		{
			ok = false;
			return INT_MIN;
		}
		Node* ptr = head;
		int n = 0;
		while (ptr && n < k)
		{
			ptr = ptr->next;
			n++;
		}
		if (ptr)
		{
			ok = true;
			return ptr->data;
		}

		ok = false;
		return INT_MIN;
	}

	int GetListSize() // размер списка
	{
		Node* ptr = head;
		int n = 0;
		while (ptr)
		{
			ptr = ptr->next;
			n++;
		}
		return n;
	}
};

class Poly 
{
public:
	struct Monom 
	{
		double coef;
		int n;
		Monom* next;
	};
public:
	Monom* head;
	Poly() 
	{
		head = NULL;
	}

	void addMonom(double coef, int n) 
	{
		Monom* newMonom = new Monom;
		newMonom->coef = coef;
		newMonom->n = n;
		newMonom->next = NULL;

		if (head == NULL) 
		{
			head = newMonom;
			return;
		}

		Monom* monom = head;
		Monom* prev = NULL;

		while (monom && monom->n < n) 
		{
			prev = monom;
			monom = monom->next;
		}

		if (monom && monom->n == n) 
		{
			monom->coef += coef;
			delete newMonom;
			return;
		}

		if (prev == NULL) 
		{
			newMonom->next = head;
			head = newMonom;
			return;
		}

		prev->next = newMonom;
		newMonom->next = monom;
	}

	double preobrz(double x) 
	{
		double result = 0.0;
		Monom* monom = head;

		while (monom) 
		{
			result += monom->coef * pow(x, monom->n);
			monom = monom->next;
		}
		return result;
	}

	void print() 
	{
		Monom* monom = head;
		bool one = true;
		if (monom == NULL) return;

		while (monom) 
		{
			if (monom->coef > 0 && !one)  std::cout << " + ";
			if (monom->n == 0) std::cout << monom->coef;
			else std::cout << monom->coef << "x^" << monom->n;
			monom = monom->next;
			one = false;
		}
		std::cout << "\n";
	}

	// не стал заморачиваться и делать friend операторы
	Poly operator+(const Poly& other) const 
	{
		Poly result;
		Monom* monom1 = head;
		Monom* monom2 = other.head;
		while (monom1 || monom2) 
		{
			if (!monom1) 
			{
				result.addMonom(monom2->coef, monom2->n);
				monom2 = monom2->next;
				continue;
			}

			if (!monom2) 
			{
				result.addMonom(monom1->coef, monom1->n);
				monom1 = monom1->next;
				continue;
			}

			if (monom1->n == monom2->n) 
			{
				result.addMonom(monom1->coef + monom2->coef, monom1->n);
				monom1 = monom1->next;
				monom2 = monom2->next;
			}
			else if (monom1->n < monom2->n) 
			{
				result.addMonom(monom1->coef, monom1->n);
				monom1 = monom1->next;
			}
			else 
			{
				result.addMonom(monom2->coef, monom2->n);
				monom2 = monom2->next;
			}
		}

		return result;
	}

	Poly operator-(const Poly& other) const 
	{
		Poly result;
		Monom* monom1 = head;
		Monom* monom2 = other.head;
		while (monom1 || monom2) 
		{
			if (!monom1) 
			{
				result.addMonom(-monom2->coef, monom2->n);
				monom2 = monom2->next;
				continue;
			}

			if (!monom2) 
			{
				result.addMonom(monom1->coef, monom1->n);
				monom1 = monom1->next;
				continue;
			}

			if (monom1->n == monom2->n) 
			{
				result.addMonom(monom1->coef - monom2->coef, monom1->n);
				monom1 = monom1->next;
				monom2 = monom2->next;
			}
			else if (monom1->n < monom2->n) 
			{
				result.addMonom(monom1->coef, monom1->n);
				monom1 = monom1->next;
			}
			else 
			{
				result.addMonom(-monom2->coef, monom2->n);
				monom2 = monom2->next;
			}
		}

		return result;
	}

	Poly operator*(const Poly& other) const {
		Poly result;
		Monom* monom1 = head;
		while (monom1) {
			Monom* monom2 = other.head;
			while (monom2) 
			{
				int newN = monom1->n + monom2->n;
				double newCoef = monom1->coef * monom2->coef;
				result.addMonom(newCoef, newN);
				monom2 = monom2->next;
			}
			monom1 = monom1->next;
		}
		return result;
	}
	//деление выдавало ошибку - убрал
};



int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	OneLinkedList lst;
	lst.push_front(1);
	lst.push_back(0);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(2);

	int size = lst.GetListSize();
	std::cout << "Размер списка: " << size << "\n";

	OneLinkedList copyList(lst);
	

	Node* n = lst.getAt(0);
	double d = (n != NULL) ? n->data : 0;
	std::cout << d << "\n";


	int k = lst.FindElem(2);
	std::cout << "Найден элемент 2 индексом: " << k << "\n";

	bool ok;
	int elm = lst.GetElemData(k, ok);
	if (ok) std::cout << "Найден элемент 2 индексом: " << k << " " << elm << "\n";


	k = -1;
	elm = lst.GetElemData(k, ok);
	if (ok) std::cout << "Найден элемент -1 индексом: " << k << " " << elm << "\n";

	// обычный
	for (Node* node = lst.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	lst.earse(1);
	lst.insert(0, 5);
	lst.insert(0, 2);

	std::cout << "До удаления:  \n";
	for (Node* node = lst.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	lst.remElm(3);

	std::cout << "После удаления:  \n";
	for (Node* node = lst.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	// копирование
	for (Node* node = copyList.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	lst.sort();

	std::cout << "Отсортированный список:  \n";
	for (Node* node = lst.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	lst.transpose();

	std::cout << "Список в обратном порядке:  \n";
	for (Node* node = lst.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	int size_lst1, size_lst2;
	std::cin >> size_lst1 >> size_lst2;

	OneLinkedList l1;
	OneLinkedList l2;

	l1.fillRandom(size_lst1);
	l2.fillRandom(size_lst2);

	l1.sort();
	for (Node* node = l1.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";


	l2.sort();
	for (Node* node = l2.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	OneLinkedList res = l1.sortedLists(l2);

	for (Node* node = res.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	std::cout << "\n";

	//////////////////////////////////////////

	std::cout << "\n" << "Двусвязный список: \n";

	LinkedList list;

	list.push_back(5);
	list.push_back(4);
	list.push_back(2);

	std::cout << "Размер списка: " << list.GetListSize() << "\n";

	std::cout << "Элементы: ";
	Node* ptr = list.head;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << "\n";

	list.insert(1, 10);

	std::cout << "После вставки: ";
	ptr = list.head;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << "\n";

	list.earse(2);

	std::cout << "После удаления: ";
	ptr = list.head;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << "\n\n";



	///////////////////////////////

	Poly p1;


	p1.addMonom(1, 2);
	p1.addMonom(3, 3); 
	p1.addMonom(-1, 5);

	p1.print();

	Poly p2;

	p2.addMonom(1, 2);
	p2.addMonom(3, 3);
	p2.addMonom(-1, 5);

	p2.print();

	(p1 + p2).print();
	(p1 * p2).print();
	(p1 - p2).print();
	double x = 1;
	//double result = p1.preobrz(x);

	//std::cout << "Результат, если x = 1: " << result << "\n";


}