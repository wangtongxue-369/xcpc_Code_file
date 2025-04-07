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
	ll x, y;
	cin >> n >> x >> y;
	ll l = y, r = y, t = x, d = x;
	cout << "Yes\n";
	cout << n - 1 << '\n';
	while (!(l == 1 && r == n && t == 1 && d == n))
	{
		if (r + 1 <= n && t - 1 >= 1)
		{
			r++, t--;
			cout << t << ' ' << r << ' ' << d - t << ' ' << l - r << '\n';
			continue;
		}
		if (d + 1 <= n && r + 1 <= n)
		{
			d++, r++;
			cout << d << ' ' << r << ' ' << t - d << ' ' << ' ' << l - r << '\n';
			continue;
		}
		if (l - 1 >= 1 && t - 1 >= 1)
		{
			l--, t--;
			cout << t << ' ' << l << ' ' << d - t << ' ' << r - l << '\n';
			continue;
		}
		if (d + 1 <= n && l - 1 >= 1)
		{
			d++, l--;
			cout << d << ' ' << l << ' ' << t - d << ' ' << r - l << '\n';
			continue;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
