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
	string s;
	cin >> s;
	vector<ll> pre1(s.length() + 10, 0);
	vector<ll> pre0(s.length() + 10, 0);
	char c = s[0];
	ll p = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)
		{
			if (s[i - 1] != s[i - 2])
			{
				p++;
			}
		}
		if (s[i - 1] == '1')
		{
			pre1[i] = 1;
		}
		else
		{
			pre0[i] = 1;
		}
		pre1[i] += pre1[i - 1];
		pre0[i] += pre0[i - 1];
	}
	// cout << p << '\n';
	ans = 0;
	ll num0 = 0, num1 = 0;
	for (int w = 1; w <= n; w++)
	{
		ll sum = 1;
		for (ll i = 1; i <= n; i += w)
		{
			num0 = pre0[min(i + w - 1, n)] - pre0[i - 1];
			num1 = pre1[min(i + w - 1, n)] - pre1[i - 1];
			if (num0 != 0 && num1 != 0)
			{
				sum++;
			}
		}
		// cout << sum << '\n';
		ans ^= sum;
	}
	cout << ans << '\n';
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
