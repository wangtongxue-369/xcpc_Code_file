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
	ll k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	s = 'L' + s + 'L';
	// s += 'L';
	vector<ll> pre(n + 10, 0);
	vector<ll> sc(n + 10, 0);
	pre[n + 1] = n;
	for (int i = n; i >= 0; i--)
	{
		if (s[i + 1] == 'L')
		{
			pre[i] = i + 1;
		}
		else
		{
			pre[i] = pre[i + 1];
		}
	}
	for (int i = 1; i <= n + 1; i++)
	{
		sc[i] = sc[i - 1] + (s[i] == 'C' ? 1 : 0);
	}
	// for (int i = 0; i <= n + 1; i++)
	// {
	// 	cout << pre[i] << ' ';
	// }
	// cout << '\n';
	// for (int i = 0; i <= n + 1; i++)
	// {
	// 	cout << sc[i] << ' ';
	// }
	// cout << '\n';
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, k});
	vector<bool> f(n + 10, 0);
	while (!q.empty())
	{
		auto [it, k1] = q.top();
		q.pop();
		if (f[it] == 1)
		{
			continue;
		}
		f[it] = 1;
		if (it == n + 1)
		{
			break;
		}

		ll d = pre[it] - it;
		// cout << it << '\n';
		// cout << "! " << d << '\n';
		if (d <= m)
		{
			// cout << "IN1 " << pre[it] << '\n';
			q.push({pre[it], k1});
		}
		else
		{
			// cout << "!*@#&()" << '\n';
			// cout << pre[it] << ' ' << it + m << '\n';
			// cout << sc[pre[it]] - sc[it + m] << '\n';
			if (sc[pre[it]] - sc[it + m] == 0 && s[it + m] != 'C' && d - m <= k1)
			{
				// k -= d - m;
				q.push({pre[it], k1 - (d - m)});
			}
		}
		// if ((sc[pre[it]] - sc[it] == 0 && d <= k))
		// {
		// 	cout << "IN1 " << pre[it] << '\n';
		// 	k -= d;
		// 	q.push(pre[it]);
		// }
	}
	if (f[n + 1] == 1)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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
