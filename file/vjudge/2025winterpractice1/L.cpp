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
ll _ = 1, n, m, a[MAXN], b[MAXN];
ll ans[MAXN];

void solve()
{
	memset(ans, 0, sizeof(ans));
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.length(); i++)
	{
		a[i] = s1[s1.length() - i] - '0';
	}
	for (int i = 1; i <= s2.length(); i++)
	{
		b[i] = s2[s2.length() - i] - '0';
	}
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			ans[i + j - 1] += a[i] * b[j];
		}
	}
	for (int i = 1; i <= s1.length() + s2.length(); i++)
	{
		if (ans[i] > 9)
		{
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
	}
	ll len = s1.length() + s2.length();
	while (len > 1 && ans[len] == 0)
	{
		len--;
	}
	for (int i = len; i >= 1; i--)
	{
		cout << ans[i];
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