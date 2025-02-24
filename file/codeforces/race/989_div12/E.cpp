#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m; // ans = 0, a[MAXN], f[MAXN];
void solve()
{
	ll k;
	cin >> n >> k;
	if (n % 2 == 0 && k % 2 == 1)
	{
		cout << "NO\n";
		return;
	}
	if (n == 1)
	{
		if (k == 1)
		{
			cout << "YES\n";
			cout << 1 << '\n';
			return;
		}
		cout << "NO\n";
		return;
	}
	if (k % 2 == 0)
	{
		set<vector<ll>> ans;
		vector<ll> c(n), d(n);
		for (int i = 0; i < n; i++)
		{
			c[i] = i + 1;
		}
		while (1)
		{
			if (ans.size() >= k)
			{
				break;
			}
			for (int i = 0; i < n; i++)
			{
				d[i] = n + 1 - c[i];
			}
			if (c >= d)
			{
				break;
			}
			ans.emplace(c);
			ans.emplace(d);
			next_permutation(c.begin(), c.end());
		}
		if (ans.size() < k)
		{
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for (auto it : ans)
		{
			for (auto i : it)
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
		return;
	}
	if (k == 1)
	{
		cout << "NO\n";
		return;
	}
	set<vector<ll>> vis;
	vector<ll> p(n, 0), a(n, 0), b(n, 0);
	for (int i = 0; i < n; i++)
	{
		p[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = (i + n / 2) % n + 1;
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = (n + 1) * 3 / 2 - a[i] - p[i];
	}
	vis.emplace(p);
	vis.emplace(a);
	vis.emplace(b);
	auto ans = vis;
	vector<int> c(n), d(n);
	for (int i = 0; i < n; i++)
	{
		c[i] = i + 1;
	}
	while (1)
	{
		if (ans.size() >= k)
			break;
		for (int i = 0; i < n; i++)
			d[i] = n + 1 - c[i];
		if (c >= d)
			break;
		if (vis.contains(c) || vis.contains(d))
		{
		}
		else
		{
			ans.emplace(c);
			ans.emplace(d);
		}
		next_permutation(c.begin(), c.end());
	}
	if (ans.size() < k)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (auto it : ans)
	{
		for (auto i : it)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}
// k%2==0
//  构造1 2 3 4 5 6
//  第二行对面的数
//  下一个全排列
//  k%2==1
//
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
