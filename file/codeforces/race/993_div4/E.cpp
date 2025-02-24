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
	ll k, l1, r1, l2, r2;
	cin >> k >> l1 >> r1 >> l2 >> r2;
	ll p = 1;
	ans = 0;
	while (p <= 1e9)
	{
		// cout << p << endl;
		ll l = ceil(1.0 * l2 / p);
		l = max(l, l1);
		ll r = floor(1.0 * r2 / p);
		r = min(r, r1);
		if (!(r < l))
		{
			ans += r - l + 1;
		}
		p = p * k;
	}
	cout << ans << '\n';
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
