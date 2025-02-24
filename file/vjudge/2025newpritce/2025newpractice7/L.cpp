#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1;
ll n, m, ans = 0, a[MAXN];
ll getlin(ll x)
{
	ll res = 0;
	while (x)
	{
		x /= 10;
		res++;
	}
	return res;
}
ll ksm(ll a1, ll b1)
{
	ll res = 1;
	while (b1)
	{
		if (b1 & 1)
		{
			res = res * a1 % mod;
		}
		a1 = a1 * a1 % mod;
		b1 >>= 1;
	}
	return res;
}
void solve()
{

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	vector<ll> baca(n + 10, 0);
	map<ll, ll> ma;
	for (int i = n; i >= 1; i--)
	{
		ma[getlin(a[i])]++;
		baca[i] = (baca[i + 1] + a[i]) % mod;
	}
	for (int i = 1; i < n; i++)
	{
		ma[getlin(a[i])]--;
		for (auto it : ma)
		{
			ans = (ans + ((a[i] % mod * (ksm(10, it.first) % mod)) % mod * it.second % mod) % mod) % mod;
		}
		ans = (ans + baca[i + 1] % mod) % mod;
	}
	cout << ans % mod << '\n';
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
