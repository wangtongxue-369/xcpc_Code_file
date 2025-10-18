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
ll _ = 1, n, m; // a[MAXN], f[MAXN];
struct Point
{
	ld x;
	ld y;
};
void solve()
{
	ll x0, y0;
	cin >> x0 >> y0;
	ll k;
	cin >> n >> k;
	vector<Point> ve(n + 10);
	ll sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> ve[i].x >> ve[i].y;
		if (ve[i].x < 0 && ve[i].y > 0)
		{
			sum1++;
		}
		else if (ve[i].x < 0 && ve[i].y < 0)
		{
			sum3++;
		}
		else if (ve[i].x > 0 && ve[i].y > 0)
		{
			sum2++;
		}
		else if (ve[i].x > 0 && ve[i].y < 0)
		{
			sum4++;
		}
	}
	if (x0 < 0 && y0 > 0 && (sum1 > k || (sum1 + sum2 > k && sum1 + sum3 > k)))
	{
		cout << -1 << '\n';
		return;
	}
	else if (x0 < 0 && y0 < 0 && (sum3 > k || (sum3 + sum1 > k && sum3 + sum4 > k)))
	{
		cout << -1 << '\n';
		return;
	}
	else if (x0 > 0 && y0 > 0 && (sum2 > k || (sum2 + sum1 > k && sum2 + sum4 > k)))
	{
		cout << -1 << '\n';
		return;
	}
	else if (x0 > 0 && y0 < 0 && (sum4 > k || (sum4 + sum2 > k && sum4 + sum3 > k)))
	{
		cout << -1 << '\n';
		return;
	}
	vector<ld> xx, yy;
	for (int i = 1; i <= n; i++)
	{
		ld x1 = x0, y1 = y0, x2 = ve[i].x, y2 = ve[i].y;
		if ((ve[i].x < 0 && x0 > 0) || (ve[i].x > 0 && x0 < 0))
		{
			yy.push_back((-x2 * y1 + x1 * y2) / (x2 - x1));
		}
		if ((ve[i].y < 0 && y0 > 0) || (ve[i].y > 0 && y0 < 0))
		{
			xx.push_back((-x2 * y1 + x1 * y2) / (y2 - y1));
		}
	}
	sort(yy.begin(), yy.end());
	sort(xx.begin(), xx.end());
	ld ans = 1e18;
	if (n - xx.size() <= k)
	{
		// cerr << 9;
		for (int i = 0; i + (n - k) - 1 < xx.size(); i++)
		{
			ans = min(ans, xx[i + (n - k) - 1] - xx[i]);
		}
	}
	if (n - yy.size() <= k)
	{
		// cerr << 9;
		for (int i = 0; i + (n - k) - 1 < yy.size(); i++)
		{
			ans = min(ans, yy[i + (n - k) - 1] - yy[i]);
		}
	}
	if (ans == 1e18)
	{
		cout << -1 << '\n';
		return;
	}
	cout << fixed << setprecision(9) << ans << '\n';
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