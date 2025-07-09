#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = (j), LEN = (k); i < LEN; ++i)
#define per(i, j, k) for (int i = (j), LEN = (k); i > LEN; --i)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lson (p << 1)
#define rson (p << 1 | 1)
#define pb push_back
#define yes "YES"
#define no "NO"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
ll const mod{998244353}, inf{0x3f3f3f3f3f3f3f3f};

struct pick
{
    int a, b, c;
    bool operator<(const pick &p) const
    {
        return a < p.a || (a == p.a && b < p.b) || (a == p.a && b == p.b && c < p.c);
    }
};

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<array<int, 3>> v(n);
    ll ans{0};
    for (auto &p : v)
    {
        cin >> p[0] >> p[1] >> p[2];
    }
    map<pick, ll> dp;
    dp[pick{0, 0, 0}] = 0;
    rep(i, 0, n)
    {
        map<pick, ll> tmp;
        for (auto &[x, y] : dp)
        {
            if (x.a < a)
                tmp[pick{x.a + 1, x.b, x.c}] = max(tmp[pick{x.a + 1, x.b, x.c}], y + v[i][0]);
            if (x.b < b)
                tmp[pick{x.a, x.b + 1, x.c}] = max(tmp[pick{x.a, x.b + 1, x.c}], y + v[i][1]);
            if (x.c < c)
                tmp[pick{x.a, x.b, x.c + 1}] = max(tmp[pick{x.a, x.b, x.c + 1}], y + v[i][2]);
        }
        dp = tmp;
    }
    cout << dp[pick{a, b, c}];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t{1};
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}