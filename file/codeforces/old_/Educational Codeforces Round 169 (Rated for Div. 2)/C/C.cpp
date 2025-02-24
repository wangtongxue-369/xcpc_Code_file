#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
bool cmp(ll s1, ll s2)
{
	return s1 > s2;
}
void solve()
{
	ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	ll al = 0, bo = 0;
	ans = 0;
	ll res = 0;
	for (int i = 1; i <= n - 1; i += 2)
	{
		ll d = a[i] - a[i + 1];
		// ll d2 = max(0ll, d - k);
		//  res += max(0ll, (k - d));
		ans += d;
	}
	if (n % 2 == 1)
	{
		ans = max(ans - k, 0ll) + a[n];
	}
	else
	{
		ans = max(ans - k, 0ll);
	}
	cout << ans << '\n';
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
