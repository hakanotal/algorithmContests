#include <iostream>
#include <math.h>

using namespace std;

int digit_sum(int a)
{
    while (a > 9)
    {
        int sum = 0;
        int n = a;
        while (n != 0)
        {
            int digit = n % 10;
            sum = sum + digit;
            n = n / 10;
        }
        a = sum;
    }
    return a;
}

int calc(int a, int b)
{
    if (b == 1)
        return a;

    switch (a)
    {
    case 0:
    case 1:
        return a;

    case 2:
    case 5:
        b = b % 6;
        return digit_sum(pow(a, b));
    case 4:
        b = b % 3;
        return digit_sum(pow(a, b));
    case 7:
        b = b % 3;
        return digit_sum(pow(a, b));
    case 8:
        b = b % 2;
        return digit_sum(pow(a, b));

    case 3:
    case 6:
    case 9:
        return 9;
    }

    return -1;
}

int main()
{
    int a, b;
    cin >> a >> b;

    a = digit_sum(a);

    cout << calc(a, b);

    return 0;
}