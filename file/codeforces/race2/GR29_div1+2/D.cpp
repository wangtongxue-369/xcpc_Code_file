#include <bits/stdc++.h>
#define rep(i, j, k) for (i64 i = (j), LEN = (k); i < LEN; ++i)
#define per(i, j, k) for (i64 i = (j), LEN = (k); i > LEN; --i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define A(x) array<i64, x>
using namespace std;
using i64 = long long;
using u64 = unsigned i64;
using vi = vector<int>;
i64 const mod{998244353}, inf{0x3f3f3f3f3f3f3f3f};
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
    map<int, int> cnt;
    i64 a{0}, b{0};
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    map<i64, i64> ncnt;
    for (auto &[x, y] : cnt)
        ncnt[y] = x;
    int who{0};
    for (auto &[y, x] : ncnt)
    {
        if (who)
        {
            b += (x + 1) / 2 * y;
            a += x / 2 * y;
        }
        else
        {
            a += (x + 1) / 2 * y;
            b += x / 2 * y;
        }
        who ^= x & 1;
    }
    if (a < b)
        swap(a, b);
    cout << a << ' ' << b << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t{1};
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}