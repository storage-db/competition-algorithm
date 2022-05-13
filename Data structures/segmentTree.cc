#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e+5;
int t[N * 2];

void build()
{ // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int value)
{ // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r)
{ // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", t + n + i);//arr
    build();
    for (int i = 0; i < n * 2; i++)
    {
        cout << t[i] << " ";//Output the line segment tree array corresponding to the original array
    }
    cout << endl;
    cout << query(2, 5) << endl;
    modify(4, 8);
    cout << query(2, 5) << endl;
    for (int i = 0; i < n * 2; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}