#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll sum1, sum10, sum11;
    cin >> n;
    cout << "1 1" << endl;
    cin >> sum1;
    cout << "1 11" << endl;
    cin >> sum11;
    cout << "1 10" << endl;
    cin >> sum10;
    if (sum1 != sum11 + sum10)
    {
        cout << "0 " << n << " 1" << endl;
    }
    else
    {
        cout << "0 " << n << " 0" << endl;
    }
    cin >> sum1;
    // 1110110
}
signed main()
{
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
