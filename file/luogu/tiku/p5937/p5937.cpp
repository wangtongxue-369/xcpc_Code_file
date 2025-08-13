#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500500;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
	ll l, r;
	ll op;
	/* data */
} a[MAXN];
ll cnt = 0;
ll b[2 * MAXN];
ll fa[2 * MAXN];
ll find(ll x)
{
	if (fa[x] != x)
	{
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void unin(ll x, ll y)
{
	ll tx = find(x);
	ll ty = find(y);
	if (tx != ty)
	{
		fa[tx] = ty;
	}
}
void solve()
{
	cin >> n;
	cin >> m;
	string op;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].l >> a[i].r >> op;
		a[i].l--;
		if (op == "odd")
		{
			a[i].op = 1;
		}
		else
		{
			a[i].op = 0;
		}
		b[++cnt] = a[i].l;
		b[++cnt] = a[i].r;
	}
	sort(b + 1, b + 1 + cnt);
	cnt = unique(b + 1, b + 1 + cnt) - (b + 1);
	for (int i = 1; i <= cnt * 2; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		a[i].l = lower_bound(b + 1, b + 1 + cnt, a[i].l) - b;
		a[i].r = lower_bound(b + 1, b + 1 + cnt, a[i].r) - b;
		if (a[i].op == 1)
		{
			if (find(a[i].l) == find(a[i].r))
			{
				cout << i - 1 << '\n';
				return;
			}
			else
			{
				unin(a[i].l, a[i].r + cnt);
				unin(a[i].l + cnt, a[i].r);
			}
		}
		else
		{
			if (find(a[i].l) == find(a[i].r + cnt))
			{
				cout << i - 1 << '\n';
				return;
			}
			else
			{
				unin(a[i].l, a[i].r);
				unin(a[i].l + cnt, a[i].r + cnt);
			}
		}
	}
	cout << m << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}