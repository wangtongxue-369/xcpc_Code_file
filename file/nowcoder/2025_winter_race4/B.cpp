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
ll ksm(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
void solve()
{
	// cout << ksm(2, 0) << '\n';
	cin >> n;
	string s;
	cin >> s;
	if (n == 1)
	{
		if (s[0] == '?')
		{
			cout << 2 << '\n';
			return;
		}
		cout << 1 << '\n';
		return;
	}
	// 第一个和最后一个得相同才可以平衡
	// 其实满足上面条件，无论内部怎么摆都是平衡的，
	//  那么只需要考虑第一个和最后一个
	// 1.。。。1   2p*(n-2)          中间的
	// 0.。。。0   2p*(n-2)
	// 1.。。。0   2p*2
	// 0.。。。1   2p*2
	ans = 0;
	ll p = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (s[i] == '?')
		{
			p++;
		}
	}
	ll p2 = ksm(2, p);
	// ans = (2 * p2 * (n - 2) + 4 * p2) % mod;
	// cout << ans << '\n';

	if (s[0] != '?' && s[n - 1] != '?')
	{
		if (s[0] == s[n - 1])
		{
			ans = (p2 * (n - 2)) % mod;
		}
		else
		{
			ans = (p2 * 2) % mod;
		}
	}
	else
	{
		// ans = p2 * 2;
		if (((int)(s[0] == '?') + (int)(s[n - 1] == '?')) == 2)
		{
			ans = (2 * p2 * (n - 2) + 4 * p2) % mod;
		}
		else
		{
			ans = (p2 * (n - 2) + 2 * p2) % mod;
		}
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
