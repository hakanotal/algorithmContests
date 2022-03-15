// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt
// Hakan Tuğrul Otal - 15.03.2022
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main()
{
    int size = 1;
    pair<int, int> answer;  // answer = <max_sum, depth>
    vector<vector<int>> dp; // dynamic prog solution

    // Read rows
    string s;
    while (getline(cin, s))
    {
        dp.push_back(vector<int>(size));

        stringstream ss(s); // To extract numbers

        if (size == 1) // First row
        {
            int num;
            ss >> num;
            if (!isPrime(num))
            {
                dp[0][0] = num;
                answer = make_pair(num, size);
            }
            else
            {
                cout << "No possible answer exists." << endl;
                return 0;
            }
        }
        else // Other rows
        {
            for (int i = 0; i < size; i++)
            {
                int num;
                ss >> num;

                if (!isPrime(num)) // is num prime?
                {
                    // Get the two values one step above (and check for boundaries)
                    int val1 = i == 0 ? INT_MIN : dp[size - 2][i - 1];
                    int val2 = i == size - 1 ? INT_MIN : dp[size - 2][i];

                    // Find max sum
                    int max_above = max(val1, val2);
                    dp[size - 1][i] = max_above;
                    if (max_above > 0)
                        dp[size - 1][i] = max_above + num;
                }
                else // not prime
                    dp[size - 1][i] = INT_MIN;

                // cout << dp[size - 1][i] << " "; // <-- to see solution vector

                // To reach end of the pyramid as much as possible
                if (size > answer.second && dp[size - 1][i] > INT_MIN)
                    answer = make_pair(dp[size - 1][i], size);
                else if (size == answer.second)
                    answer = make_pair(max(answer.first, dp[size - 1][i]), size);
            }
        }
        // cout << endl;
        size++;
    }

    cout << answer.first << endl;

    return 0;
}