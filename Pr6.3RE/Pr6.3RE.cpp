#include <iostream>
#include <iomanip>
#include <time.h>
#include <type_traits>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

template <typename T>
void CreateTemplate(T* a, const int size, const T Low, const T High, int i)
{
    if constexpr (std::is_integral_v<T>)
        a[i] = Low + rand() % (High - Low + 1);
    else
        a[i] = Low + (T)(rand() % (int)((High - Low) * 10.)) / 10.0;

    if (i < size - 1)
        CreateTemplate(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

template <typename T>
void PrintTemplate(T* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        PrintTemplate(a, size, i + 1);
    else
        cout << endl;
}

int Sum(int* a, const int size, int i)
{
    if (i >= size)
        return 0;

    int current = (a[i] % 2 != 0) ? a[i] : 0; 
    return current + Sum(a, size, i + 1);
}

template <typename T>
T SumTemplate(T* a, const int size, int i)
{
    if (i >= size)
        return 0;

    T current = (a[i] % 2 != 0) ? a[i] : 0;
    return current + SumTemplate(a, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    const int Low = -20;
    const int High = 20;

    int a[n];
    Create(a, n, Low, High, 0);

    cout << "1. Array:";
    Print(a, n, 0);

    int s1 = Sum(a, n, 0);
    cout << "Sum: " << s1 << endl;
    cout << endl;

    long b[n];
    CreateTemplate<long>(b, n, Low, High, 0);

    cout << "2. ArrayTemplate:";
    PrintTemplate<long>(b, n, 0);

    long s2 = SumTemplate<long>(b, n, 0);
    cout << "Sum Template: " << s2 << endl;

    return 0;
}