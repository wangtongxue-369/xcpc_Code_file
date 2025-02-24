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
	ll h, k;
	cin >> n >> m >> h >> k;
	string s;
	cin >> s;
	map<PII, ll> ma;
	ll x, y;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		ma[{x, y}]++;
	}
	x = 0, y = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'R')
		{
			x++;
		}
		else if (s[i] == 'L')
		{
			x--;
		}
		else if (s[i] == 'U')
		{
			y++;
		}
		else if (s[i] == 'D')
		{
			y--;
		}
		h--;
		if (h < 0)
		{
			cout << "No\n";
			return;
		}
		if (h < k && ma[{x, y}] > 0)
		{
			h = k;
			ma[{x, y}]--;
		}
	}
	if (h >= 0)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "NO\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
