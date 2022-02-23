#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> answers;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int b = 100 - a;

        for (int i = 51; i > 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                a = a / i;
                b = b / i;
            }
        }
        answers.push_back(a + b);
    }

    for (auto it : answers)
        cout << it << endl;

    return 0;
}