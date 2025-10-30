/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
								|______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
struct node
{
	ll x;
	ll s;
};
void solve()
{
	ll c;
	cin >> n >> m >> c;
	map<ll, ll> ma;
	ll x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		ma[x]++;
	}
	vector<node> a;
	for (auto it : ma)
	{
		a.push_back({it.first, it.second});
	}
	for (int i = 0; i < ma.size(); i++)
	{
		a.push_back({a[i].x + m, a[i].s});
	}
	for (int i = 0; i < 2 * ma.size(); i++)
	{
		a[i].s = a[i].s + a[i - 1].s;
	}
	for (int i = 0; i < ma.size(); i++)
	{
		ll l = i + 1, r = 2 * ma.size() - 1;
		while (l < r)
		{
			ll mid = (l + r) >> 1;
			if ((a[mid].s - a[i].s) >= c)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		// cout << i << ' ' << l << '\n';
		ans += (a[i + 1].x - a[i].x) * (a[l].s - a[i].s);
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cin >> _;
	while (_--)
	{
		solve();
	}
	return 0;
}