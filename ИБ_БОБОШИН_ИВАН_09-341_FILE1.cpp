//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//	1
//	/*ifstream fin;
//	ofstream fout;
//
//	char inName[100];
//	char outName[100];
//
//	char c;
//	int n;
//
//	cin >> inName;
//	fin.open(inName);
//	if (!fin.is_open())
//	{
//		cout << "This file \"" << inName << "\" is not found";
//		return -1;
//	}
//
//	cin >> outName;
//	fout.open(outName);
//	if (!fout.is_open())
//	{
//		cout << "This file \"" << outName << "\" is not found";
//		return -1;
//	}
//
//	cin >> n;
//
//
//	int lineCount = 0;
//
//	while (!fin.eof())
//	{
//		c = fin.get();
//
//		if ((lineCount == 0 && c == '\n') || c == EOF)
//			continue;
//
//		if (lineCount >= n)
//		{
//			fout << '\n';
//			lineCount = 0;
//		}
//
//		fout << c;
//
//		lineCount++;
//
//		if (c == '\n')
//			lineCount = 0;
//	}
//
//
//	fin.close();
//	fout.close();*/
//	2
//	ifstream fin;
//	ofstream fout;
//
//	char inName[100];
//	char outName[100];
//
//	char c;
//
//	cin >> inName;
//	fin.open(inName);
//	if (!fin.is_open())
//	{
//		cout << "This file \"" << inName << "\" is not found";
//		return -1;
//	}
//
//	cin >> outName;
//	fout.open(outName);
//	if (!fout.is_open())
//	{
//		cout << "This file \"" << outName << "\" is not found";
//		return -1;
//	}
//
//	while (!fin.eof())
//	{
//		c = fin.get();
//		if (c == EOF)
//			continue;
//		fout << c;
//
//	}
//
//
//	fin.close();
//	fout.close();
//	3
//	ifstream fin;
//	ofstream fout;
//
//	char InName[1000];
//	char OutName[1000];
//
//	cin >> InName;
//	fin.open(InName);
//	if (!fin.is_open()) {
//		cout << "This file \"" << InName << "\" is not found!";
//		return -1;
//	}
//
//	cin >> OutName;
//	fout.open(OutName);
//	if (!fin.is_open()) {
//		cout << "This file \"" << OutName << "\" is not found!";
//		return -1;
//	}
//
//	int CountFiles;
//	fin >> CountFiles; // считывание 1 числа т.е. кол-ва файлов
//	char Files[1000];
//
//	for (int i = 0; i < CountFiles && fin >> Files; i++) {
//		ifstream FFiles;
//		FFiles.open(Files);
//		if (!FFiles.is_open()) {
//			cout << "This file \"" << Files << "\" is not found!";
//			return -1;
//		}
//		char simbols;
//		while (!FFiles.eof())
//		{
//			simbols = FFiles.get();
//			if (simbols == EOF)
//				continue;
//			fout << simbols;
//		}
//		FFiles.close();
//	}
//
//	fin.close();
//	fout.close();
//
//4
//ifstream fin;
//ofstream fout;
//
//char InName[1000];
//char OutName[1000];
//
//cin >> InName;
//fin.open(InName);
//if (!fin.is_open()) {
//	cout << "This file \"" << InName << "\" is not found!";
//	return -1;
//}
//
//cin >> OutName;
//fout.open(OutName, ios::binary);
//if (!fin.is_open()) {
//	cout << "This file \"" << OutName << "\" is not found!";
//	return -1;
//}
//
//int CountFiles;
//fin >> CountFiles; // считывание 1 числа т.е. кол-ва файлов
//char Files[1000];
//
//
//for (int i = 0; i < CountFiles && fin >> Files; i++) {
//	//int size = 0;
//	ifstream FFiles;
//	FFiles.open(Files, ios::binary);
//	if (!FFiles.is_open()) {
//		cout << "This file \"" << Files << "\" is not found!";
//		return -1;
//	}
//	char simbols[1000];
//	/*while (FFiles.read(simbols, sizeof(simbols))) {
//		fout.write(simbols, FFiles.gcount());
//	}*/
//	FFiles.read(simbols, sizeof(int) * 1000);
//	fout.write(simbols, FFiles.gcount());
//	//size = FFiles.tellg();
//	//char *simbols;
//	//simbols = new char[size];
//	//FFiles.clear();
//	//FFiles.seekg(0, ios::beg);
//	//FFiles.read(simbols, size*sizeof(char));
//	//cout << simbols;
//	//fout.write(simbols, size*sizeof(char));
//	FFiles.close();
//}
//
//fin.close();
//fout.close();
//5
//	ifstream fin;
//	ofstream fout;
//
//	char InName[1000];
//
//	cin >> InName;
//	fin.open(InName);
//	if (!fin.is_open()) {
//		cout << "This file \"" << InName << "\" is not found!";
//		return -1;
//	}
//
//	int CountFiles;
//	fin >> CountFiles; // считывание 1 числа т.е. кол-ва файлов
//	char Files[1000];
//
//	for (int i = 0; i < CountFiles && fin >> Files; i++) {
//		ifstream FFiles;
//		FFiles.open(Files);
//		if (!FFiles.is_open()) {
//			cout << "This file \"" << Files << "\" is not found!";
//			return -1;
//		}
//		
//		int sizeFile = 0;
//		FFiles.seekg(0, ios::end);
//
//		cout << "IT REALLY EXISTS!!!!! --> \"" << Files << "\" \n";
//		cout << "FILE SIZE  --> \"" << Files << "\" --> " << FFiles.tellg() <<" BYTE" << endl;
//
//		FFiles.close();
//	}
//
//	fin.close();
//
//6
//	ifstream fin;
//	ofstream fout;
//
//	char InName[1000];
//	char OutName[1000];
//
//	cin >> InName;
//	fin.open(InName, ios::binary);
//	if (!fin.is_open()) {
//		cout << "This file \"" << InName << "\" is not found!";
//		return -1;
//	}
//
//	cin >> OutName;
//	fout.open(OutName, ios::binary);
//	if (!fin.is_open()) {
//		cout << "This file \"" << OutName << "\" is not found!";
//		return -1;
//	}
//	char simbols[1000];
//
//	fin.seekg(0, ios::end); // переносимся в конец файла
//	int size = fin.tellg(); // считываем размер
//	fin.seekg(0, ios::beg); // обратно в начало
//	fin.read(simbols, size);
//	
//
//	for (int i = 0; i < size - 1 ; i+=2) {
//		swap(simbols[i], simbols[i + 1]);
//		
//	}
//	fout.write(simbols, size);
//	
//	fin.close();
//	fout.close();
//}