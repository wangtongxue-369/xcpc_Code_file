#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500500;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m; // ans = 0;
ll fa[MAXN];
ll ans[MAXN];	// 颜色为x的数量
ll color[MAXN]; // i位置的颜色
ll cnt[MAXN];	// i的块的大小
ll find(ll x)
{
	if (fa[x] != x)
	{
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void nuio(ll x, ll y)
{
	ll tx = find(x);
	ll ty = find(y);
	if (tx != ty)
	{
		if (ty > tx)
		{
			swap(ty, tx);
		}
		fa[tx] = ty;
		cnt[ty] += cnt[tx];
	}
}
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
		color[i] = i;
		ans[i] = 1;
		cnt[i] = 1;
	}
	// cin >> n >> m;
	ll op, x, c;
	for (int i = 1; i <= m; i++)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> x >> c;
			x = find(x);
			ans[color[x]] -= cnt[x];
			ans[c] += cnt[x];
			color[x] = c;
			if (color[find(x + cnt[x])] == c)
			{
				nuio(x, x + cnt[x]);
			}
			if (color[find(x - 1)] == c)
			{
				nuio(x - 1, x);
			}
		}
		else
		{
			cin >> c;
			cout << ans[c] << '\n';
		}
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
