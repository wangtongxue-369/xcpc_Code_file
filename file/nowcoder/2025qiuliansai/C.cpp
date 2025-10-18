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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
	ll a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	cin >> s;
	s = ' ' + s;
	vector<ll> dp(n + 10, 0);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		if (i >= 4 && s.substr(i - 3, 4) == "nico")
		{
			dp[i] = max(dp[i], dp[i - 4] + a);
		}

		if (i >= 6 && s.substr(i - 5, 6) == "niconi")
		{
			dp[i] = max(dp[i], dp[i - 6] + b);
		}

		if (i >= 10 && s.substr(i - 9, 10) == "niconiconi")
		{
			dp[i] = max(dp[i], dp[i - 10] + c);
		}
	}
	cout << dp[n] << '\n';
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
