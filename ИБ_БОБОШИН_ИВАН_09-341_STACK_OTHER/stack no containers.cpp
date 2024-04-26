#include <iostream>
#include <windows.h>

//#include "MyStack.h"
#include "OneLinkedList.h"

/*
1 Задание с использованием контейнеров(здесь на выбор 2 алгоритма)
Дан целочисленный массив. Реализовать функцию, которая перевернет порядок
элементов с помощью стека так, что первым элементом массива будет последний
элемент, вторым – предпоследний, и тд., последним – первый элемент.
*/

template<typename T>
class MyStack {
private:
	struct Node {
		T info;
		Node* next;

		Node(T info, Node* next) : info(info), next(next) {}
	};

	Node* head;

public:
	MyStack();
	~MyStack();
	void print();
	bool isEmpty();
	void push(T info);
	T top();
	T pop();
};

template<typename T>
MyStack<T>::MyStack()
{
	head = NULL;
}

template<typename T>
MyStack<T>::~MyStack()
{
	while (!isEmpty())
		pop();
}

template<typename T>
void MyStack<T>::print()
{
	std::cout << "(";
	for (Node* cur = head; cur != NULL; cur = cur->next)
		std::cout << cur->info << " ";
	std::cout << ")" << "\n";
}

template<typename T>
bool MyStack<T>::isEmpty()
{
	return head == NULL;
}

template<typename T>
void MyStack<T>::push(T info)
{
	head = new Node(info, head);
}

template<typename T>
T MyStack<T>::top()
{
	if (isEmpty())
		throw - 1;
	return head->info;
}

template<typename T>
T MyStack<T>::pop()
{
	if (isEmpty())
		throw - 1;
	T res = head->info;
	Node* help = head;
	head = head->next;

	delete help;

	return res;
}

////////////////////////////////////////////////////////////
void insertBot(MyStack<int>& info, int val) // 2 вариант(прописана отдельно функция вставки)
{
	if (info.isEmpty())
	{
		info.push(val);
		return;
	}

	int topval = info.top();
	info.pop();
	insertBot(info, val);
	info.push(topval);
}

void reverseStack(MyStack<int>& info)
{
	if (info.isEmpty())
		return;

	int val = info.top();
	info.pop();
	reverseStack(info);
	insertBot(info, val);
}

////////////////////////////////////////////////////////////////
const int max_size_word = 1000;
///////////////////////////////////////////////////////////////

/*
	3. Дан линейный список, содержащий целые числа. Реализовать функцию, которая
	перевернет порядок элементов с помощью стека так, что первым элементом списка
	будет последний элемент, вторым – предпоследний, и т.д., последним – первый
	элемент.
*/

void reverseList(OneLinkedList& list)
{
	Node* head = list.head;
	if (head == NULL || head->next == NULL)
		return;

	MyStack<Node*> transpose;
	Node* node = head;

	while (node) {
		transpose.push(node);
		node = node->next;
	}

	list.head = transpose.top();
	node = list.head;
	transpose.pop();

	while (!transpose.isEmpty())
	{
		node->next = transpose.top();
		transpose.pop();
		node = node->next;
	}
	node->next = NULL;
}


int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
		1. Дан целочисленный массив. Реализовать функцию, которая перевернет порядок
		элементов с помощью стека так, что первым элементом массива будет последний
		элемент, вторым – предпоследний, и тд., последним – первый элемент.
	*/

	MyStack<int> info;

	info.push(1);
	info.push(33);
	info.push(21);
	info.push(4);

	reverseStack(info); // Если закоментим выведет 4 21 33 1

	while (!info.isEmpty())
	{
		std::cout << info.top() << " ";
		info.pop();
	}
	std::cout << "\n";

	/*
		2. Дана строка. Инвертировать порядок расположения символов в строке с помощью стека.
	*/

	MyStack<char> word;
	char text[max_size_word];

	std::cout << "Введите предложение/слово: ";
	std::cin.getline(text, max_size_word);
	std::cout << "\n";

	for (int i = 0; text[i] != '\0'; i++)
	{
		word.push(text[i]);
	}

	while (!word.isEmpty())
	{
		std::cout << word.top();
		word.pop();
	}
	std::cout << "\n";

	/*
		3. Дан линейный список, содержащий целые числа. Реализовать функцию, которая
		перевернет порядок элементов с помощью стека так, что первым элементом списка
		будет последний элемент, вторым – предпоследний, и т.д., последним – первый
		элемент.
	*/

	OneLinkedList list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	std::cout << "Список:" << "\n";
	Node* node = list.head;
	while (node)
	{
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << "\n";

	reverseList(list);

	std::cout << "Список в обратном порядке:" << "\n";
	node = list.head;
	while (node)
	{
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << "\n";

}
