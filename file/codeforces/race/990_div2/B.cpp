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
	cin >> n;
	string s;
	cin >> s;
	map<char, ll> ma;
	for (int i = 0; i < n; i++)
	{
		ma[s[i]]++;
	}
	char maxn = s[0], minn = s[0];
	for (auto it : ma)
	{
		if (it.second > ma[maxn])
		{
			maxn = it.first;
		}
		if (it.second < ma[minn])
		{
			minn = it.first;
		}
	}
	if (maxn == minn)
	{
		bool flag = 0;
		for (auto it : s)
		{
			if (it != maxn && flag == 0)
			{
				cout << maxn;
				flag = 1;
			}
			else
			{
				cout << it;
			}
		}
		cout << '\n';
		return;
	}
	else
	{
		bool flag = 0;
		for (auto it : s)
		{
			if (it == minn && flag == 0)
			{
				cout << maxn;
				flag = 1;
			}
			else
			{
				cout << it;
			}
		}
		cout << '\n';
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
