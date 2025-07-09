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
using vi = vector<ll>;
using vii = vector<vi>;
ll const mod{998244353}, inf{0x3f3f3f3f3f3f3f3f};
// -100 1 2
// 3 4 5
// -100 2 4
// 1 3 5
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a), greater<int>());
    int A{0}, B{0};
    rep(i, 0, n)
    {
        if (i & 1)
            B += a[i];
        else
            A += a[i];
    }
    int ans = abs(A) - abs(B);
    if (n % 2 == 0)
        ans = abs(ans);
    cout << ans << '\n';
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