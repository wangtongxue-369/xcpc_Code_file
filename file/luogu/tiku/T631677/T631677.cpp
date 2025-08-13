#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a, b;
int f(int n)
{
    if (n == 1)
    {
        return a;
    }
    if (n == 2)
    {
        return b;
    }
    return f(n - 1) + f(n - 2);
}
int main()
{
    int n;
    cin >> a >> b >> n;
    cout << f(n) << '\n';
}