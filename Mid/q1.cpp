#include <iostream>
#include <cmath>
using namespace std;

int isqrt(int num);

int main()
{
    int num, res;

    cout << "Enter number: ";
    cin >> num;

    res = isqrt(num);

    cout << res << endl;

    return 0;
}

int isqrt(int number)
{
    int c = 0;
    float num = number;

    if (num < 0)
    {
        return -1;
    }

    while (num >= 2)
    {
        num = sqrt(num);
        c++;
    }

    return c;
}