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
ll _ = 1, n; // m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
	string s;
	cin >> s;
	cin >> n;
	ll p = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '?')
		{
			p = p * 2;
		}
		else
		{
			p = p * 2 + s[i] - '0';
		}
	}
	// cout << (1 << 58) << '\n';
	if (p > n)
	{
		cout << -1 << '\n';
		return;
	}
	// cout << p << '\n';
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '?')
		{
			if ((p + (1ll << (s.length() - i - 1))) <= n)
			{
				p = p + (1ll << (s.length() - i - 1));
			}
		}
	}
	if (p > n)
	{
		cout << -1 << '\n';
		return;
	}
	cout << p << '\n';
}
// 1 2 4 8 16 32
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
