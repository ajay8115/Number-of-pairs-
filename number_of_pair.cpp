#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

long long count(int x, int Y[], int n, int NoOfy[])
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return NoOfy[0]; // no of zeroes in y array;
    }

    int *idx = upper_bound(Y, Y + n, x);

    int ans = (Y + n) - idx;

    // if we reach here then definitely value of x should be greater than x so inc no of pair for y =0 and y=1;
    ans += (NoOfy[0] + NoOfy[1]);

    if (x == 2)
    {
        ans -= (NoOfy[3] + NoOfy[4]);
    }
    if (x == 3)
    {
        ans += NoOfy[2];
    }
    return ans;
}

long long countPairs(int x[], int y[], int m, int n)
{
    int NoOfy[5] = {0};
    for (int i = 0; i < n; i++)
    {
        if (y[i] < 5)
        {
            NoOfy[y[i]]++;
        }
    }

    sort(y, y + n);
    long long cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += count(x[i], y, n, NoOfy);
    }

    return cnt;
}