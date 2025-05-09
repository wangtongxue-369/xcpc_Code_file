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
ll _ = 1, n, m, ans = 0, a[500], f[MAXN];
void solve()
{
	cin >> n >> m;
	map<ll, set<ll>> ma;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ma[a[i]].insert(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (ma[a[i]].size() - 1 == 0)
		{
			cout << "BeiJu\n";
		}
		else
		{
			cout << ma[a[i]].size() - 1 << '\n';
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
