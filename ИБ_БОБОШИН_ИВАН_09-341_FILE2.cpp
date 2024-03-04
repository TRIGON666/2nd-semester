#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	//1 ARRAY
	/*srand(time(0));

	ofstream fout;
	char OutName[100];
	cin >> OutName;
	fout.open(OutName);
	if (!fout.is_open())
	{
		cout << "This file \"" << OutName << "\" is not found";
		return -1;
	}

	int n;
	cin >> n;
	fout << n << "\n";

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (10 - 100 + 1) + 10;
		fout << arr[i] << " ";
	}*/
	//delete[] arr;
	//fout.close();
	//2 MATRIX ARRAY

	//srand(time(0));

	//ofstream fout;
	//char OutName[100];
	//cin >> OutName;
	//fout.open(OutName);
	//if (!fout.is_open())
	//{
	//	cout << "This file \"" << OutName << "\" is not found";
	//	return -1;
	//}

	//int n, m;
	//cin >> n >> m;
	//fout << n << " " << m << "\n";

	//int** arr = new int*[n];
	//for (int i = 0; i < n; i++) arr[i] = new int[m];

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		arr[i][j] = rand() % (10 - 100 + 1) + 10;
	//		fout << arr[i][j] << " ";
	//	}
	//	fout << "\n";
	// 
	//}
	//fout.close();

	//3
	//srand(time(0));

	//ofstream fout;
	//char OutName[100];
	//cin >> OutName;
	//fout.open(OutName, ios::binary);
	//if (!fout.is_open())
	//{
	//	cout << "This file \"" << OutName << "\" is not found";
	//	return -1;
	//}

	//int n;
	//cin >> n;
	//fout.write(reinterpret_cast<char*>(&n), sizeof(n));
	//int size = sizeof(int) * n;
	//for (int i = 0; i < n; i++) {
	//	int m;
	//	cin >> m;
	//	fout.write((char*)&m, sizeof(int));
	//}
	//fout.close();

	//4

	//srand(time(0));

	//ofstream fout;
	//char OutName[100];
	//cin >> OutName;
	//fout.open(OutName, ios::binary);
	//if (!fout.is_open())
	//{
	//	cout << "This file \"" << OutName << "\" is not found";
	//	return -1;
	//}

	//int n, m;
	//cin >> n >> m;
	//fout.write((char*)&n, sizeof(int));
	//fout.write((char*)&m, sizeof(int));
	//int** arr = new int*[n];
	//for (int i = 0; i < n; i++) arr[i] = new int[m];

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		arr[i][j] = rand() % (10 - 100 + 1) + 10;
	//		
	//	}
	//}
	//for (int i = 0; i < n; i++) fout.write((char*)arr[i], sizeof(int)*m);
	//fout.close();
//5

	//ifstream fin;
	//ofstream fout;

	//char InName[1000];
	//char OutName[1000];

	//cin >> InName;
	//fin.open(InName);
	//if (!fin.is_open()) {
	//	cout << "This file \"" << InName << "\" is not found!";
	//	return -1;
	//}

	//cin >> OutName;
	//fout.open(OutName);
	//if (!fin.is_open()) {
	//	cout << "This file \"" << OutName << "\" is not found!";
	//	return -1;
	//}
	//char curr;
	//char prev = '\0';
	//bool comm = false;
	//while (fin.get(curr)) {
	//	if (prev == '/' && curr == '/') {
	//		comm = true;
	//	}
	//	if (comm && curr == '\n') {
	//		comm = false;
	//		prev = '\0';
	//		continue;
	//	}
	//	if (!comm) {
	//		fout.put(prev);
	//	}
	//	prev = curr;
	//}
	//if (prev != '\n') {
	//	fout.put(prev);
	//}
	//fin.close();
	//fout.close();

 //6

	//srand(time(0));

	//ifstream fin;
	//char InName[100];
	//cin >> InName;
	//fin.open(InName);
	//if (!fin.is_open())
	//{
	//	cout << "This file \"" << InName << "\" is not found";
	//	return -1;
	//}

	//int n;
	//fin >> n;
	//cout << n << "\n";

	//int* arr = new int[n];
	//for (int i = 0; i < n; ++i) {
	//	fin >> arr[i];
	//	cout << arr[i] << " ";
	//}
	//delete[] arr;
	//fin.close();
	//7 MATRIX ARRAY


	//srand(time(0));

	//ifstream fin;
	//char InName[100];
	//cin >> InName;
	//fin.open(InName);
	//if (!fin.is_open())
	//{
	//	cout << "This file \"" << InName << "\" is not found";
	//	return -1;
	//}



	//int n, m;
	//fin >> n  >> m ;
	//cout << n << " " << m << endl;
	//int** arr = new int*[n];
	//for (int i = 0; i < n; i++) arr[i] = new int[m];

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		fin >> arr[i][j];
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	// 
	//}
	//fin.close();

//8
	//ifstream fin;
	//char InName[100];
	//cin >> InName;
	//fin.open(InName, ios::binary);
	//if (!fin.is_open())
	//{
	//	cout << "This file \"" << InName << "\" is not found";
	//	return -1;
	//}

	//int n;
	//fin.read((char*)&n,sizeof(n));
	//cout << n << "\n";
	//
	//int* arr = new int[n];
	//
	//for (int i = 0; i < n; ++i) {
	//	fin.read((char*)&arr[i], sizeof(int));
	//	cout << arr[i]<<" ";
	//}
	//
	//fin.close();
//9
//ifstream fin;
//char InName[100];
//cin >> InName;
//fin.open(InName, ios::binary);
//if (!fin.is_open())
//{
//	cout << "This file \"" << InName << "\" is not found";
//	return -1;
//}
//
//int n, m;
//fin.read((char*)&n, sizeof(int));
//fin.read((char*)&m, sizeof(int));
//cout << n << " " << m << "\n";
//
//int** arr = new int*[n];
//
//for (int i = 0; i < n; ++i) {
//	arr[i] = new int[m];
//	fin.read((char*)arr[i], sizeof(int)*m);
//}
//
//for (int i = 0; i < n; ++i) {
//	for (int j = 0; j < m; ++j) {
//		cout << arr[i][j] << " ";
//	}
//	cout << endl;
//}
//fin.close();
}