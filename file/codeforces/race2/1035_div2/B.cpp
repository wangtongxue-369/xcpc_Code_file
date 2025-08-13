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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    double sum = 0;
    vector<double> a(n + 10);
    double jl = sqrt(1.0 * (px - qx) * (px - qx) + 1.0 * (py - qy) * (py - qy));
    double maxn = jl;
    a[1] = jl;
    sum = jl;
    n++;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }
    if (maxn > sum - maxn)
    {
        cout << "No\n";
        return;
    }
    if (n == 2)
    {
        if (a[1] == a[2])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    cout << "Yes\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}