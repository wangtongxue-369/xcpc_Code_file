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
	cin >> n >> m;
	ans = 0;
	ans += 2 * (n) % mod * (n - 2) % mod * (m - 1) % mod;
	ans %= mod;
	ans += 2 * (m) % mod * (m - 2) % mod * (n - 1) % mod;
	ans %= mod;
	ans += 2 * (n) % mod * (n - 1) % mod * (m - 2) % mod;
	ans %= mod;
	ans += 2 * (m) % mod * (m - 1) % mod * (n - 2) % mod;
	ans %= mod;

	ans -= 4 * (n - 1) * (m - 2);
	ans = (ans % mod + mod) % mod;
	ans -= 4 * (n - 2) * (m - 1);
	ans = (ans % mod + mod) % mod;
	// ans -= (n - 1) * (m - 1);
	// cout << 7683984 - ans << '\n';
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