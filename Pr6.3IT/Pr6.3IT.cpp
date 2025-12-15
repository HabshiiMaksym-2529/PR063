#include <iostream>
#include <iomanip>
#include <time.h>
#include <type_traits>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void CreateTemplate(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
    {
        if constexpr (std::is_integral_v<T>)
            a[i] = Low + rand() % (High - Low + 1);
        else
            a[i] = Low + (T)(rand() % (int)((High - Low) * 10.)) / 10.0; 
    }
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

template <typename T>
void PrintTemplate(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

int Sum(int* a, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)  
            sum += a[i];
    }
    return sum;
}

template <typename T>
T SumTemplate(T* a, const int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
            sum += a[i];
    }
    return sum;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    const int Low = -20;
    const int High = 20;

    int a[n];
    Create(a, n, Low, High);
    cout << "Array : ";
    Print(a, n);

    int s1 = Sum(a, n);
    cout << "Sum: " << s1 << endl;
    cout << endl;

    long b[n];
    CreateTemplate<long>(b, n, Low, High);
    cout << "Array Template: ";
    PrintTemplate(b, n);

    long s2 = SumTemplate<long>(b, n);
    cout << "Sum template: " << s2 << endl;

    return 0;
}