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
	ll p;
	cin >> p >> m;
	ans = 0;
	ans += m / p;

	for (ll k = m / p; k <= (m + p - 2) / p; k++)
	{
		ll w = (p - 1) ^ (k * p + 1);
		if (w <= m)
		{
			ans++;
		}
		// if ((1 + (k - 1) * p + 1) <= (1 + (k + 1) * p - 1) && (1 + (k + 1) * p - 1) <= m)
		// {
		// 	ans++;
		// }
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
// x-y<=x^y<=x+y
//  g-(p-1)<=g^(p-1)==1(mod p)<=g+(p-1)
//
//  (1+k*p)=g^(p-1)
//  g-(p-1)<=(1+k*p)<=g+(p-1)
//  g<=(1+k*p+(p-1))
//  g<=(1+k*p+p-1)
//  g<=(1+(k+1)*p-1)<=m
//  g>=(1+k*p-p+1)
//  g>=(1+(k-1)*p+1)

// g-(p-1)-1<=k*p
//(g-(p-1)-1)/p<=k
//(g+(p-1)-1)/p>=k