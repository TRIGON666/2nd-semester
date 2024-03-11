
/*
1. Описать структуру для точки в 3х-мерном пространстве. Объявить и заполнить массив точек 3х-мерного простраства.

2. Описать структуру для хранения вектора чисел (два поля: размер вектора, сам вектор - массив, размер которого равен полю "размер вектора").
Реализовать функции сложения двух векторов, умножения вектора на скаляр.
-
3. Описать структуру для информации о студенте (ФИО, возраст, группа, институт, направление). Заполнить один экземпляр структуры о студенте.

4. Описать структуру для информации о группе студентов (поля: название группы, институт, направление, количество студентов, массив студентов).

Замечание: структура информации о студенте в этом случае не должна содержать поля: группа, институт, направление. Эти поля уже содержаться в структуре, описывающей группу.
Заполнить один экземпляр группы студентов (при этом в группе чтобы было хотя бы 2 студента).

*/

#include <iostream>
#include <ctime>
#include <Windows.h>


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
    cout << "\t ЗАДАЧА 1  \n ";
    int CountPoint3D;
    cin >> CountPoint3D;
    Point3D* PointsArray3D = new Point3D[CountPoint3D];
    for (int i = 0; i < CountPoint3D; i++) {
        PointsArray3D[i].PointX = 1 + rand() % 10;
        PointsArray3D[i].PointY = 1 + rand() % 10;
        PointsArray3D[i].PointZ = 1 + rand() % 10;
    }

    cout << "X Y Z \n";
    for (int i = 0; i < CountPoint3D; i++) {
        cout << "[" << PointsArray3D[i].PointX << ", " << PointsArray3D[i].PointY << ", " << PointsArray3D[i].PointZ << "]\n";
    }
    delete[] PointsArray3D;

    cout << "\t ЗАДАЧА 2  \n";
    Vector size;
    cout << "Размер: ";
    cin >> size.size;

    Vector a;
    Vector b;
    a.size = size.size;
    b.size = size.size;
    if (a.size == b.size) {
        a.V = new int[size.size];
        b.V = new int[size.size];
        
        int scalar;
        cout << "Скаляр: ";
        cin >> scalar;

        for (int i = 0; i < size.size; i++) {
            a.V[i] = 1 + rand() % 10;
        }
        for (int i = 0; i < size.size; i++) {
            b.V[i] = 1 + rand() % 10;
        }
        Vector sum;
        sum.V = new int[size.size];
        for (int i = 0; i < size.size; i++) {
            sum.V[i] = a.V[i] + b.V[i];
        }
        Vector proiz_1;
        Vector proiz_2;
        proiz_1.V = new int[size.size];
        proiz_2.V = new int[size.size];
        for (int i = 0; i < size.size; i++) {
            proiz_1.V[i] = a.V[i] * scalar;
        }
        for (int i = 0; i < size.size; i++) {
            proiz_2.V[i] = b.V[i] * scalar;
        }
        cout << "Сумма векторов A и B равна: ";
        for (int i = 0; i < size.size; i++) {
            cout << sum.V[i] <<" ";
        }
        cout << endl;
        cout << "Произведение вектора A на скаляр равен: ";
        for (int i = 0; i < size.size; i++) {
            cout << proiz_1.V[i] << " ";
        }
        cout << endl;
        cout << "Произведение вектора B на скаляр равен: ";
        for (int i = 0; i < size.size; i++) {
            cout << proiz_2.V[i] << " ";
        }
        delete[] sum.V;
        delete[] proiz_1.V;
        delete[] proiz_2.V;
        cout << endl;
    }
    cout << "\t ЗАДАЧА 3  \n";
    Student down{"Бобошин",
            "Иван",
        "Сергеевич",
        228,
        "09-341",
        "Информационная безопасность",
        "ICMIT"};
    cout << down.SecondName << " " << down.FirstName << " " << down.FatherName << " " << down.Age << " " << down.Group << " " << down.Specialization << " " << down.Institute;

    cout << "\n\t ЗАДАЧА 4  \n";

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


    
    cout << Groups.Group << "\t" << Groups.Institute << "\t" << Groups.Specialization << "\n";

    for (int i = 0; i < Groups.countstudents; i++) {
        cout << Groups.Stud[i].SecondName << "\n" << Groups.Stud[i].FirstName << "\n" << Groups.Stud[i].FatherName << "\n" << Groups.Stud[i].Age << "\n";
    }

    


}