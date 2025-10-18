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
ll ksm(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}
void solve()
{
	ll c, d;
	cin >> c >> d;
	ll p = c;
	ll ws = 0;
	while (p)
	{
		p /= 10;
		ws++;
	}
	ans = 0;
	ll s1 = 1, s2 = 10;
	// cout << ksm(10, 5) << '\n';
	while (s1 <= c + d)
	{
		ll l = max(s1, c + 1);
		ll r = min(s2 - 1, c + d);
		if (l <= r)
		{
			ans += (ll)sqrt((ld)1.0 * c * s2 + r) - (ll)sqrt((ld)1.0 * c * s2 + l - 1);
		}

		s1 *= 10, s2 *= 10;
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