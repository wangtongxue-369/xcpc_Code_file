#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;
const int N = 25;
i64 a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    i64 ans = 0;
    for (int i = 1; i <= ((1 << (n + 1)) - 1); i++)
    {
        int f = 0;
        for (int j = 0; j <= 22; j++)
        {
            if (i & (1 << j))
            {
                f += a[n - j];
                f %= mod;
                break;
            }
        }
        ans += ((f * i) % mod);
    }
    cout << (ans + mod) % mod << "\n";
    return 0;
}
