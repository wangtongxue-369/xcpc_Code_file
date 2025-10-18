/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
								|______/
*/
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
struct DSU
{
	vector<array<ll, 3>> fa;
	vector<ll> sz;
	void init(ll n)
	{
		fa.resize(n + 10);
		for (int i = 1; i <= n + 1; i++)
		{
			fa[i][0] = i, fa[i][1] = 0, fa[i][2] = 1;
		}
		sz.assign(n + 10, 1);
	}
	ll leader(ll x)
	{
		if (x != fa[x][0])
		{
			fa[x][0] = find(fa[x][0]);
		}
		return fa[x][0];
	}
	ll find(ll x)
	{
		if (x != fa[x][0])
		{
			fa[x][0] = find(fa[x][0]);
		}
		return fa[x][0];
	}
	void join(ll x, ll y)
	{
		x = leader(x);
		y = leader(y);
		if (x != y)
		{
			if (sz[x] < sz[y])
			{
				swap(x, y);
			}
			sz[x] += sz[y];
			fa[y][0] = x;
			fa[x][1] += fa[y][1];
			fa[x][2] += fa[y][2];
		}
	}
};
void solve()
{
	ll q;
	cin >> n >> q;
	DSU dsu;
	dsu.init(n);
	ll op, u, v, x;
	vector<ll> col(n + 10, 1);
	while (q--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> u >> v;
			dsu.join(u, v);
		}
		else if (op == 2)
		{
			cin >> x;
			ll re = dsu.find(x);
			if (col[x] == 0)
			{
				dsu.fa[re][1]--;
				dsu.fa[re][2]++;
				col[x] = 1;
			}
			else if (col[x] == 1)
			{
				dsu.fa[re][1]++;
				dsu.fa[re][2]--;
				col[x] = 0;
			}
		}
		else if (op == 3)
		{
			cin >> x;
			x = dsu.find(x);
			if (dsu.fa[x][1] > 0)
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
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