#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a1[MAXN], a2[MAXN];
void solve()
{
	ans = 0;
	cin >> n;
	string s1, s2, t1, t2;
	cin >> s1 >> s2 >> t1 >> t2;
	map<ll, ll> ma11, ma10, ma21, ma20;
	ll p = 0;
	for (int i = 0; i < t1.length(); i++)
	{
		if (i == 0)
		{
			a1[i] = ++p;
		}
		else
		{
			if (t1[i - 1] != t1[i])
			{
				a1[i] = ++p;
			}
			else
			{
				if (t1[i] == '0')
				{
					a1[i] = ++p;
				}
				else
				{
					a1[i] = p;
				}
			}
		}
	}
	p = 0;
	for (int i = 0; i < t2.length(); i++)
	{
		if (i == 0)
		{
			a2[i] = ++p;
		}
		else
		{
			if (t2[i - 1] != t2[i])
			{
				a2[i] = ++p;
			}
			else
			{
				if (t2[i] == '0')
				{
					a2[i] = ++p;
				}
				else
				{
					a2[i] = p;
				}
			}
		}
	}
	for (int i = 0; i < t1.length(); i++)
	{
		cout << a1[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < t1.length(); i++)
	{
		cout << a2[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < t1.length(); i++)
	{
		if (s1[i] == '0')
		{
			ma10[a1[i]]++;
		}
		else
		{
			ma11[a1[i]]++;
		}
		if (s2[i] == '0')
		{
			ma20[a2[i]]++;
		}
		else
		{
			ma21[a2[i]]++;
		}
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (ma10[a1[i]] && ma20[a2[i]])
		{
			ans++;
			ma10[a1[i]]--, ma20[a2[i]]--;
		}
		else if (ma11[a1[i]] && ma21[a2[i]])
		{
			ans++;
			ma11[a1[i]]--, ma21[a2[i]]--;
		}
		else if (ma10[a1[i]])
		{
			ma10[a1[i]]--;
			ma21[a2[i]]--;
		}
		else
		{
			ma11[a1[i]]--;
			ma20[a2[i]]--;
		}
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
