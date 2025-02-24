#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll op1, op2;
    for (int i = 1; i <= n - 1; i += 2)
    {
        cout << '?' << ' ' << i << ' ' << i + 1 << endl;
        cin >> op1;
        cout << "?" << ' ' << i + 1 << ' ' << i << endl;
        cin >> op2;
        if (op1 == op2)
        {
            continue;
        }
        else
        {
            if (i == 1)
            {
                cout << '?' << ' ' << i << ' ' << n << endl;
                cin >> op1;
                cout << "?" << ' ' << n << ' ' << i << endl;
                cin >> op2;
            }
            else
            {
                cout << '?' << ' ' << i << ' ' << i - 1 << endl;
                cin >> op1;
                cout << "?" << ' ' << i - 1 << ' ' << i << endl;
                cin >> op2;
            }
            if (op1 == op2)
            {
                cout << "! " << i + 1 << endl;
            }
            else
            {
                cout << "! " << i << endl;
            }
            return;
        }
    }
    cout << '!' << ' ' << n << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
