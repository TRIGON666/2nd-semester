#include <iostream>
#include <time.h>
#include <Windows.h>

template<typename Bub>
void bubSort(Bub* mas, int n)
{
    Bub bub;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                bub = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = bub;
            }
        }
    }
}

template<typename Ins>
void insSort(Ins* mas, int n)
{
    Ins ins;
    for (int i = 1; i < n; i++)
    {
        ins = mas[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (mas[j] < ins) break;
            mas[j + 1] = mas[j];
            mas[j] = ins;
        }
    }
}

template<typename Choic>
void choicSort(Choic* mas, int n)
{
    int choic;
    Choic tmp;
    for (int i = 0; i < n; i++)
    {
        choic = 1;
        for (int j = i + 1; j < n; j++)
            if (mas[j] < mas[choic]) choic = j;
        tmp = mas[i];
        mas[i] = mas[choic];
        mas[choic] = tmp;
    }
}

template<class Vector>
class vector
{
private:
    size_t size;
    Vector* elm;
public:
    vector()
    {
        size = 0;
        elm = NULL;
    }

    vector(size_t size)
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
        elm = new Vector[size];
    }

    ~vector()
    {
        delete[] elm;
    }

    Vector get_element(int i)
    {
        if (i < 0 || i >= size)
            exit(-1);
        return elm[i];
    }

    void set_element(int i, Vector val)
    {
        if (i < 0 || i >= size)
            exit(-1);
        elm[i] = val;
    }

    //void print()
    //{
    //    for (int i = 0; i < size; i++)
    //        std::cout << elm[i] << " " << "<---";
    //    std::cout << '\n';
    //}
};

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int n;
    std::cin >> n;
    int* mas = new int[n];

    for (int i = 0; i < n; i++)
        mas[i] = rand();

    for (int i = 0; i < n; i++)
        std::cout << mas[i] << '\t';
    std::cout << '\n';

    
    std::cout << "Выберите сортировку(1 - Bubble, 2 - Insert, 3 - Select): ";
    int k;
    std::cin >> k;

    if (k == 1)
    {
        bubSort(mas, n);
        std::cout << "Пузырёк ;): \n";
        for (int i = 0; i < n; i++)
            std::cout << mas[i] << '\t';
        std::cout << '\n';
    }

    if (k == 2) 
    {
        insSort(mas, n);
        std::cout << "Вставка ;): \n";
        for (int i = 0; i < n; i++)
            std::cout << mas[i] << '\t';
        std::cout << '\n';
    }

    if (k == 3)
    {
        choicSort(mas, n);
        std::cout << "Выбором ;): \n";
        for (int i = 0; i < n; i++)
            std::cout << mas[i] << '\t';
        std::cout << '\n';
    }
    
    
    size_t size = 3;
    vector <int> p1(3);
    
    for (int i = 0; i < size; i++) 
    { 
        p1.set_element(i, rand());
    }

    for (int i = 0; i < size; i++) 
    { 
        std::cout << p1.get_element(i) << "[" << i+1 << "]" << " ";
    }
    //p1.print();
    /*
    Я немного не понял про вывод сделал get и сделал функцией print надеюсь что нормально
    */
}
