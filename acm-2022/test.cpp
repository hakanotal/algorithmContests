#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    /*
    24089 269592
    */
    int n = 24089, k = 269592;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 269592;

    // sort(arr.begin(), arr.end());

    ofstream file("out.txt");
    file << n << " " << k << "\n";
    for (int i = 0; i < n; i++)
        file << arr[i] << " ";
    file.close();

    return 0;
}