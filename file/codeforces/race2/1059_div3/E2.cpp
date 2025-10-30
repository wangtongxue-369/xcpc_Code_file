#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i]; // num a[n] num1 num2 num3
    int num = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] != a[n])
        {
            num = a[i];
            break;
        }
    }
    int num1 = 0, num2 = 0, num3 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != a[n] && i != num)
        {
            num1 = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != num && i != num1)
        {
            num2 = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != num1 && i != num2)
        {
            num3 = i;
            break;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (i % 3 == 1)
            cout << num1 << ' ';
        else if (i % 3 == 2)
            cout << num2 << " ";
        else
            cout << num3 << " ";
    }
    cout << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int __ = 1;
    cin >> __;
    while (__--)
    {
        solve();
    }
    return 0;
}