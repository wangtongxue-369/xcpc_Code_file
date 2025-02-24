#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
	ll k;
	cin >> n >> k;
	ll ans = 0, su = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		su += a[i];
	}
	if (k == 1)
	{
		cout << su << '\n';
		return;
	}
	if (k == n)
	{
		if (a[n] < 0)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << a[n] << '\n';
		}

		return;
	}
	vector<ll> f(n + 100, 0);
	ll maxn = -1e18;
	for (int i = 1; i <= n; i++)
	{
		if (i >= k)
		{
			maxn = max(maxn, f[i - k]);
			f[i] = max(f[i - 1], maxn) + a[i];
		}
	}
	cout << *max_element(f.begin(), f.end()) << '\n';
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
