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
int a, b, c, d, e;
bool check(char s[])
{
	int t = sscanf(s, "%d.%d.%d.%d:%d", &a, &b, &c, &d, &e);
	if (t != 5)
	{
		return 0;
	}
	if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255 || e < 0 || e > 65535)
	{
		return 0;
	}
	char st[1005];
	sprintf(st, "%d.%d.%d.%d:%d", a, b, c, d, e);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != st[i])
		{
			return 0;
		}
	}
	return 1;
}
void solve()
{
	cin >> n;
	map<string, int> ma;
	for (int i = 1; i <= n; i++)
	{
		string op;
		char ad[1005];
		cin >> op >> ad;
		if (!check(ad))
		{
			cout << "ERR" << '\n';
			continue;
		}
		string s(ad);
		if (op == "Server")
		{
			if (ma.count(s) != 0)
			{
				cout << "FAIL" << '\n';
				continue;
			}
			else
			{
				cout << "OK" << '\n';
				ma[s] = i;
			}
		}
		else
		{
			if (!ma.contains(ad))
			{
				cout << "FAIL" << '\n';
				continue;
			}
			else
			{
				cout << ma[s] << '\n';
			}
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
