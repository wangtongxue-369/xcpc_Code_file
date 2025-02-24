#include <bits/stdc++.h>
using namespace std;
#define ull long long
#define ll unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1;
ll f(ll n)
{
	if (n % 4 == 0)
	{
		return n;
	}
	if (n % 4 == 1)
	{
		return 1;
	}
	if (n % 4 == 2)
	{
		return n + 1;
	}
	if (n % 4 == 3)
	{
		return 0;
	}
}
ll g(ll n, ll i, ll k)
{
	if (i == 0)
	{
		if (k == 0)
			return f(n);
		else
			return 0;
	}
	if (n < k)
	{
		return 0;
	}
	ll p = 1ll << i;
	ll m = (n - k) / p;
	ll cntx = m + 1;
	ll res = f(m) << i;
	if (cntx % 2 == 1)
	{
		res ^= k;
	}
	return res;
}
void solve()
{
	ll l, r, k;
	int i;
	cin >> l >> r >> i >> k;
	ll sumql = f(l - 1), sumqr = f(r);
	ll sum = sumql ^ sumqr;
	ll s1 = g(l - 1, i, k), s2 = g(r, i, k);
	ll s = s1 ^ s2;
	ll ans = sum ^ s;
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> _;
	while (_--)
	{
		solve();
	}
	return 0;
}
