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
ll _ = 1, n, m, ans = 0;
struct node
{
	ll i, a, h;
};
struct Compare
{
	bool operator()(const node &lhs, const node &rhs) const
	{
		if (lhs.h != rhs.h)
			return lhs.h > rhs.h; // h 降序
		if (lhs.a != rhs.a)
			return lhs.a > rhs.a; // a 降序
		return lhs.i > rhs.i;	  // i 降序
	}
};
struct Compare2
{
	bool operator()(const node &lhs, const node &rhs) const
	{
		if (lhs.a == rhs.a)
		{
			return lhs.i > rhs.i;
		}
		return lhs.a < rhs.a;
	}
};
void solve()
{
	ll a, k, h;
	cin >> n >> a >> k >> h;
	std::priority_queue<node, std::vector<node>, Compare> q;
	std::priority_queue<node, std::vector<node>, Compare2> q2;
	ll a1, h1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a1 >> h1;
		q.push({i, a1, k});
		q2.push({i, a1, k});
	}
	set<ll> se;
	while (h > 0)
	{
		node p = q.top();
		q.pop();
		cout << p.i << '\n';
		if (p.h > 1)
		{
			p.h--;
			q.push(p);
		}
		else
		{
			se.insert(p.i);
		}
		if (q.size() == 0)
		{
			break;
		}
		ll s = -1;
		while (se.contains(q2.top().i))
		{
			q2.pop();
		}
		s = q2.top().a;
		h -= s;
	}
	cout << n - q.size() << '\n';
	// cout << q.top().i << q.top().a << q.top().h << '\n';
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
