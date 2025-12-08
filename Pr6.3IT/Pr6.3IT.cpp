#include <iostream>
#include <string>
using namespace std;

int Sum(int* a, const int size);       
template <typename T>
T Sum(T* a, const int size);         

int main()
{
    const int n = 10;

    int a[n] = { 1,2,3,4,5,6,7,8,9,10 };

    int s1 = Sum(a, n);
    cout << "Sum(a, n) = " << s1 << endl;

    int s2 = Sum<int>(a, n);
    cout << "Sum<int>(a, n) = " << s2 << endl;

    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    double s3 = Sum<double>(b, n); 
    cout << "Sum<double>(b, n) = " << s3 << endl;

    string c[n] = { "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 " };
    string s4 = Sum<string>(c, n);
    cout << "Sum<string>(c, n) = " << s4 << endl;

    return 0;
}

int Sum(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; ++i)
    {
        if (a[i] % 2 != 0)   // стало: беремо тільки непарні
            s += a[i];
    }
    return s;
}

template <typename T>
T Sum(T* a, const int size)
{
    T s = T();
    for (int i = 0; i < size; ++i)
    {
        if constexpr (std::is_same_v<T, int>)
        {
            if (a[i] % 2 != 0)
                s += a[i];
        }
        else if constexpr (std::is_same_v<T, double>)
        {
            long long whole = static_cast<long long>(a[i]);
            if (whole % 2 != 0)
                s += a[i];
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            int val = std::stoi(a[i]);
            if (val % 2 != 0)
                s += a[i];  
        }
    }
    return s;
}