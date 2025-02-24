#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], fa[MAXN];
bool ask(ll s1, ll s2)
{
	cout << "? " << s1 << ' ' << s2 << endl;
	bool op;
	cin >> op;
	return op;
}
void solve()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		fa[i] = 0;
	}
	ll now = 2;
	fa[1] = 0;
	queue<ll> q;
	q.push(1);
	while (now < n)
	{
		if (ask(now, 1))
		{
			fa[now] = 0;
			q.push(now);
			now++;
		}
		else
		{
			fa[now] = 1;
			q.pop();
			q.push(now);
			now++;
			break;
		}
	}
	while (now < n)
	{
		if (ask(q.front(), now))
		{
			q.pop();
		}
		else
		{
			fa[now] = q.front();
			q.push(now);
			now++;
			q.pop();
		}
	}
	cout << "! ";
	for (int i = 1; i < n; i++)
	{
		cout << fa[i] << ' ';
	}
	cout << endl;
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
