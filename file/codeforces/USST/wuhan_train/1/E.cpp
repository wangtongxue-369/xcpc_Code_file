#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
#define lson p << 1
#define rson p << 1 | 1
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
#define int long long
int gcd(int a, int b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), erp(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
        erp[i] = gcd(erp[i + 1], a[i]);
    int gcdd = 0, ans = erp[1];
    for (int i = 1; i <= n; i++)
    {
        if (gcdd == gcd(gcdd, a[i]))
        {
            continue;
        }
        int tmp = gcdd;
        for (int j = i; j <= n; j++)
        {
            tmp = gcd(a[j] + k, tmp);
            ans = max(ans, gcd(tmp, erp[j + 1]));
        }
        gcdd = gcd(gcdd, a[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _{1};
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
