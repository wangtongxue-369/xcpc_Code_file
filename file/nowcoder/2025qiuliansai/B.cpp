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
	ll k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = ' ' + s;
	ll l = 1;
	ans = 0;
	ll sum0 = 0, sum1 = 0;
	for (ll r = 1; r <= n; r++)
	{ // 全1
		if (s[r] == '0')
		{
			sum0++;
		}
		while (l + 1 <= r && sum0 > k)
		{
			if (s[l] == '0')
			{
				sum0--;
			}
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	l = 1;
	for (ll r = 1; r <= n; r++)
	{ // 全0
		if (s[r] == '1')
		{
			sum1++;
		}
		while (l + 1 <= r && sum1 > k)
		{
			if (s[l] == '1')
			{
				sum1--;
			}
			l++;
		}
		ans = max(ans, r - l + 1);
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