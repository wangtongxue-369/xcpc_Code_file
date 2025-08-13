#include <bits/stdc++.h>
#define rep(i, j, k) for (ll i = (j), LEN = (k); i < LEN; ++i)
#define per(i, j, k) for (ll i = (j), LEN = (k); i > LEN; --i)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
ll const mod{998244353}, inf{0x3f3f3f3f3f3f3f3f};
void debug() { cerr << endl; }
template <typename T, typename... Ts>
void debug(T t, Ts... ts)
{
    cerr << t << " ";
    debug(ts...);
}

void solve()
{
    int n;
    cin >> n;
    vii e(n + 1);
    rep(i, 1, n + 1)
    {
        int d;
        cin >> d;
        e[i].resize(d);
        rep(j, 0, d) cin >> e[i][j];
    }
    vi ans(n + 1, 0);
    auto f = [&](int s) -> void
    {
        vi ssr;
        ssr.pb(s);
        set<pii> sss;
        pii lst{s, 0}, nxt;
        while (nxt != pii{s, 0})
        {
            auto [u, idx] = lst;
            int v{e[u][idx]}, d{e[v].size()};
            rep(i, 0, d)
            {
                if (e[v][i] == u)
                {
                    nxt = {v, (i + 1) % d};
                    break;
                }
            }
            pii edge{min(u, v), max(u, v)};
            sss.insert(edge);
            if (!nxt.se)
                ssr.pb(v);
            lst = nxt;
        }
        for (int x : ssr)
            ans[x] = sss.size();
    };
    rep(i, 1, n + 1) if (!ans[i]) f(i);
    rep(i, 1, n + 1) cout << ans[i] << '\n';
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