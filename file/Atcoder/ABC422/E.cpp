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
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
	cin >> n;
	vector<PII> ve;
	ll x, y;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		ve.push_back({x, y});
	}
	// sort(ve.begin(), ve.end());

	ll t = 100;
	srand(time(0));
	while (t--)
	{

		ll s1 = rand() % n, s2 = rand() % n;
		while (s2 == s1)
		{
			s2 = rand() % n;
		}
		__int128_t x1 = ve[s1].first, x2 = ve[s2].first, y1 = ve[s1].second, y2 = ve[s2].second;
		__int128_t A = (y2 - y1), B = -(x2 - x1), C = (x2 - x1) * y1 - (y2 - y1) * x1;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (A * (__int128_t)ve[i].first + B * (__int128_t)ve[i].second + C == 0)
			{
				sum++;
			}
		}
		if (sum >= n / 2 + 1)
		{
			cout << "Yes\n";
			cout << (ll)A << ' ' << (ll)B << ' ' << (ll)C << '\n';
			return;
		}
	}
	cout << "No\n";
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