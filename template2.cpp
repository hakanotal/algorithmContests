#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

class Object
{
public:
    int A;

    void read(FILE *fp)
    {
        fscanf(fp, "%d", &A);
        for (int i = 0; i < A; i++)
        {
            int x;
            fscanf(fp, "%d", &x);
        }
    }
};

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    FILE *fp = fopen("a.txt", "r"); // FILE *fp=stdin;
    int C;
    fscanf(fp, "%d", &C);
    for (int i = 0; i < C; i++)
    {
        Object o;
        o.read(fp);
    }
    fclose(fp);

    // Algorithm
    vector<int> answer;

    //  Output
    FILE *fp2 = fopen("a.out.txt", "w");
    for (auto &a : answer)
    {
        fprintf(fp2, "%d ", a);
    }
    fclose(fp);

    return 0;
}