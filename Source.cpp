#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

void quickSort(int* ar, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = ar[(i + j) / 2];

    while (i <= j)
    {
        while (ar[i] < pivot)
            i++;
        while (ar[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(ar, low, j);
    if (i < high)
        quickSort(ar, i, high);
}

void rand_ar(int*& ar, int n)
{
    srand(static_cast<int>(time(0)));
    for (int i = 0; i < n; i++)
    {
        int e = (rand() % 100);
        ar[i] = e;
    }
}

void rand_good_ar(int*& ar, int n)
{
    srand(static_cast<int>(time(0)));
    for (int i = 0; i < n; i++)
    {
        bool good = false;
        while (!good)
        {
            int e = (rand() % 1000);
            if (e >= ar[i - 1] || i == 1)
            {
                ar[i] = e;
                good = true;
            }
        }
    }
}

void printAr(int* ar, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << ar[i] << ' ';
    std::cout << std::endl;
}

bool check(int* ar, int n)
{
    bool res = true;
    int i = 1;
    while ((res) && (i < n))
    {
        if (ar[i - 1] > ar[i])
            res = false;
        i++;
    }
    return res;
}

bool ask()
{
    std::cout << "1. Случайный" << std::endl << "2. Упорядоченный" << std::endl << " -> ";
    int c;
    std::cin >> c;
    while (!std::cin.good() || c < 1 || c > 2)
    {
        std::cout << "Ошибка ввода. Выберите значение 1 или 2." << std::endl << " -> ";
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }
    if (c == 1)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    int* a;
    std::cin >> n;
    a = new int[n];
    if (ask())
    {
        rand_ar(a, n);
    }
    else
        rand_good_ar(a, n);
    printAr(a, n);
    quickSort(a, 0, n - 1);
    if (check(a, n))
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    printAr(a, n);
    delete[] a;
    return 0;
}