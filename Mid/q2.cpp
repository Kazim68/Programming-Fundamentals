#include <iostream>
using namespace std;

int main()
{
    int iterate, num;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int c1 = 1, c2 = 2, c3 = 3;

    cout << "Enter the numbers of integers: ";
    cin >> iterate;

    while (iterate < 0 || iterate > 1000)
    {
        cout << "Incorrect! Re-enter value: ";
        cin >> iterate;
    }

    for (int i = 1; i <= iterate; i++)
    {
        cout << "Enter number: ";
        cin >> num;

        if (i == c1)
        {
            sum1 += num;
            c1 += 3;
        }

        else if (i == c2)
        {
            sum2 += num;
            c2 += 3;
        }

        else if (i == c3)
        {
            sum3 += num;
            c3 += 3;
        }
    }

    cout << "Sum 1 is: " << sum1 << endl;
    cout << "Sum 2 is: " << sum2 << endl;
    cout << "Sum 3 is: " << sum3 << endl;

    return 0;
}