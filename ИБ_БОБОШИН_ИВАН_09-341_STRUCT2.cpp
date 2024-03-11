//1. Описать структуру для точки в 3х - мерном пространстве.Объявить и заполнить массив точек 3х - мерного простраства.
//
//1.1 Записать массив точек 3х - мерного простраства в текстовый файл(сначала размер массива, потом сам массив).После записи считать массив точек из текстового файла.
//Вывести считанную информацию на экран.
//
//1.2 Записать массив точек 3х - мерного простраства в бинарный файл(сначала размер массива, потом сам массив).После записи считать массив точек из бинарного файла.
//Вывести считанную информацию на экран.
//
//2. Описать структуру для информации о студенте(ФИО, возраст, группа, институт, направление).Заполнить один экземпляр структуры о студенте.
//
//2.1 Записать его в текстовый файл.После записи считать информацию о студенте из текстового файла.Вывести считанную информацию на экран.
//
//2.2 Записать его в бинарный файл.После записи считать информацию о студенте из бинарного файла.Вывести считанную информацию на экран.
//
//3. Описать структуру для информации о группе студентов(поля: название группы, институт, направление, количество студентов, массив студентов).[Замечание:структура информации о студенте в этом случае не должна содержать поля : группа, институт, направление.Эти поля уже содержаться в структуре, описывающей группу.] Заполнить один экземпляр группы студентов(при этом в группе чтобы было хотя бы 2 студента).
//
//3.1 Записать его в текстовый файл.После записи считать информацию о группе из текстового файла.Вывести считанную информацию на экран.
//
//3.2 Записать его в бинарный файл.После записи считать информацию о группе из бинарного файла.Вывести считанную информацию на экран.


#include <iostream>
#include <ctime>
#include <Windows.h>
#include <fstream>

using namespace std;

struct Point3D
{
    double PointX;
    double PointY;
    double PointZ;
};

struct Vector
{
    int size;
    /*int* V = new int[size];*/
    int* V;
};

struct Student
{
    char SecondName[100];
    char FirstName[100];
    char FatherName[100];
    int Age;
    char Group[100];
    char Specialization[100];
    char Institute[100];
};

struct DataStudent
{
    char SecondName[100];
    char FirstName[100];
    char FatherName[100];
    int Age;
};

struct InfoStudent
{
    int countstudents;
    char Group[100];
    char Specialization[100];
    char Institute[100];
    DataStudent Stud[1000];
};
int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");
    cout << "\t ЗАДАЧА 1.1  \n ";
    ofstream fout("1.1.txt");
    int CountPoint3D;
    cin >> CountPoint3D;
    Point3D* PointsArray3D = new Point3D[CountPoint3D];
    fout << CountPoint3D << endl;
    for (int i = 0; i < CountPoint3D; i++) {
        PointsArray3D[i].PointX = 1 + rand() % 10;
        PointsArray3D[i].PointY = 1 + rand() % 10;
        PointsArray3D[i].PointZ = 1 + rand() % 10;
    }
    for (int i = 0; i < CountPoint3D; i++) {
        fout << PointsArray3D[i].PointX << " ";
        fout << PointsArray3D[i].PointY << " ";
        fout << PointsArray3D[i].PointZ << " " << "\n";

    }

    ifstream fin("1.1.txt");
    int size;
    fin >> size;


    Point3D* outpo = new Point3D[size];
    for (int i = 0; i < size; ++i) {
        fin >> outpo[i].PointX >> outpo[i].PointY >> outpo[i].PointZ;
    }

    for (int i = 0; i < size; i++) {
        cout << outpo[i].PointX << " ";
        cout << outpo[i].PointY << " ";
        cout << outpo[i].PointZ << " " << endl;
    }
    fin.close();
    fout.close();
    cout << "\n\t ЗАДАЧА 1.2  \n";
    ofstream ffout("1.2.bin", ios::binary);
    for (int i = 0; i < CountPoint3D; i++) {
        ffout.write((char*)&PointsArray3D[i].PointX, sizeof(PointsArray3D));
        ffout.write((char*)&PointsArray3D[i].PointY, sizeof(PointsArray3D));
        ffout.write((char*)&PointsArray3D[i].PointZ, sizeof(PointsArray3D));
    }

    ifstream ffin("1.2.bin", ios::binary);
    while (ffin.read((char*)&PointsArray3D, sizeof(PointsArray3D)))
    {
        cout << PointsArray3D << "\t";
    }
    ffin.close();
    ffout.close();
    delete[] PointsArray3D;
    cout << "\n\t ЗАДАЧА 2  \n";
    Student down{ "Бобошин",
            "Иван",
        "Сергеевич",
        228,
        "09-341",
        "Информационная безопасность",
        "ICMIT" };
    cout << down.SecondName << " " << down.FirstName << " " << down.FatherName << " " << down.Age << " " << down.Group << " " << down.Specialization << " " << down.Institute;
    ofstream fffout("2.1.txt");
    fffout << down.SecondName << " " << down.FirstName << " " << down.FatherName << " " << down.Age << " " << down.Group << " " << down.Specialization << " " << down.Institute << "\n";

    char stud[256];
    ifstream fffin("2.1.txt");
    while (!fffin.eof()) {
        fffin >> stud;
        cout << stud << endl;
    }
    fffin.close();
    fffout.close();
    cout << "\n\t ЗАДАЧА 2.2  \n";
    ofstream ffffout("2.2.bin", ios::binary);
    ffffout.write(reinterpret_cast<char*>(&down), sizeof(down));
    ffffout.close();

    Student stua;
    ifstream ffffin("2.2.bin", ios::binary);
    ffffin.read(reinterpret_cast<char*>(&stua), sizeof(stua));
    ffffin.close();

    cout << "ФИО: " << stua.SecondName << " " << stua.FirstName << " " << stua.FatherName << endl;
    cout << "Возраст: " << stua.Age << endl;
    cout << "Группа: " << stua.Group << endl;
    cout << "Направление: " << stua.Specialization << endl;
    cout << "Институт: " << stua.Institute << endl;
    ffffin.close();

    ffffout.close();
    cout << "\n\t ЗАДАЧА 3.1  \n";

    InfoStudent Groups;

    strcpy_s(Groups.Group, "09-341");
    strcpy_s(Groups.Institute, "ICMIT");
    strcpy_s(Groups.Specialization, "Информационная безопасность");
    Groups.countstudents = 2;

    strcpy_s(Groups.Stud[0].SecondName, "Бобошин");
    strcpy_s(Groups.Stud[0].FirstName, "Иван");
    strcpy_s(Groups.Stud[0].FatherName, "Сергеевич");
    Groups.Stud[0].Age = 18;

    strcpy_s(Groups.Stud[1].SecondName, "Сотруддинов");
    strcpy_s(Groups.Stud[1].FirstName, "Нияз");
    strcpy_s(Groups.Stud[1].FatherName, "Ильнарович");
    Groups.Stud[1].Age = 19;

    //ofstream pout("group.txt");
    //pout.write(Groups.Group, sizeof(Groups.Group));
    //pout.write(Groups.Institute, sizeof(Groups.Institute));
    //pout.write(Groups.Specialization, sizeof(Groups.Specialization));
    //pout.write((char*)&Groups.countstudents, sizeof(Groups.countstudents));
    //for (int i = 0; i < Groups.countstudents; i++) {
    //    pout.write(Groups.Stud[i].SecondName, sizeof(Groups.Stud[i].SecondName));
    //    pout.write(Groups.Stud[i].FirstName, sizeof(Groups.Stud[i].FirstName));
    //    pout.write(Groups.Stud[i].FatherName, sizeof(Groups.Stud[i].FatherName));
    //    pout.write((char*)&Groups.Stud[i].Age, sizeof(Groups.Stud[i].Age));
    //}



    /*ifstream pin("group.txt");


    InfoStudent group;
    pin.read(group.Group, sizeof(group.Group));
    pin.read(group.Institute, sizeof(group.Institute));
    pin.read(group.Specialization, sizeof(group.Specialization));
    pin.read((char*)&group.countstudents, sizeof(group.countstudents));
    for (int i = 0; i < group.countstudents; i++) {
        pin.read(Groups.Stud[i].SecondName, sizeof(Groups.Stud[i].SecondName));
        pin.read(Groups.Stud[i].FirstName, sizeof(Groups.Stud[i].FirstName));
        pin.read(Groups.Stud[i].FatherName, sizeof(Groups.Stud[i].FatherName));
        pin.read((char*)&Groups.Stud[i].Age, sizeof(Groups.Stud[i].Age));
    }



    cout << "Название группы: " << group.Group <<endl;
    cout << "Институт: " << group.Institute << endl;
    cout << "Направление: " << group.Specialization << endl;
    cout << "Количество студентов: " << group.countstudents << endl;

    for (int i = 0; i < group.countstudents; i++) {
        cout << "  ФИО: " << group.Stud[i].SecondName  << " " << group.Stud[i].FirstName << group.Stud[i].FatherName << endl;
        cout << "  Возраст: " << group.Stud[i].Age << endl;
    }
    pin.close();
    pout.close();*/
}
