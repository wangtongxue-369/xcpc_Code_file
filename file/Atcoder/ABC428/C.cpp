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
void solve()
{
	cin >> n;
	string s;
	ll sum = 0;
	ll ew = 0;
	ll op = 1;
	ll pd = 0;
	bool flag = 0;
	vector<PII> ve;
	ll minn = 1e18;
	for (int i = 1; i <= n; i++)
	{
		ll op;
		char c;
		cin >> op;
		if (op == 1)
		{
			cin >> c;
			if (c == '(')
			{
				sum++;
			}
			else
			{
				sum--;
			}
			if (sum < 0)
			{
				flag = 1;
			}
			ve.push_back({sum, flag});
		}
		else
		{
			ve.pop_back();
			if (ve.size())
			{
				sum = ve.back().first;
				flag = ve.back().second;
			}
			else
			{
				sum = 0, flag = 0;
			}
		}
		if (flag == 0 && sum == 0)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
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