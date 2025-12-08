#include <iostream>
#include <string>
#include <type_traits>
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

    double b[n] =
    { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    double s3 = Sum<double>(b, n);
    cout << "Sum<double>(b, n) = " << s3 << endl;

    string c[n] =
    { "1 ", "2 ", "3 ", "4 ", "5 ",
      "6 ", "7 ", "8 ", "9 ", "10 " };
    string s4 = Sum<string>(c, n);
    cout << "Sum<string>(c, n) = " << s4 << endl;

    return 0;
}

int Sum(int* a, const int size)
{
    if (size <= 0)
        return 0;

    int add = 0;
    if (a[0] % 2 != 0)
        add = a[0];

    return add + Sum(a + 1, size - 1);
}

template <typename T>
T Sum(T* a, const int size)
{
    if (size <= 0)
        return T();  

    T add = T();

    if constexpr (is_same_v<T, int>)
    {
        if (a[0] % 2 != 0)
            add = a[0];
    }
    else if constexpr (is_same_v<T, double>)
    {
        long long whole = static_cast<long long>(a[0]); 
        if (whole % 2 != 0)
            add = a[0];
    }
    else if constexpr (is_same_v<T, std::string>)
    {
        int val = stoi(a[0]);
        if (val % 2 != 0)
            add = a[0];  
    }
    return add + Sum<T>(a + 1, size - 1);
}