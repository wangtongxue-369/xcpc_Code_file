#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
	cin >> n >> m;
	ll l, r;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		a[l]--;
		a[r + 1]++;
	}
	ans = 0;
	ll sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += a[i];
		if (sum == 0)
		{
			ans++;
		}
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
