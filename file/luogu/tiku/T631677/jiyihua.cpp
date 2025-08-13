#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int gcd(int a, int b)
{

    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
}