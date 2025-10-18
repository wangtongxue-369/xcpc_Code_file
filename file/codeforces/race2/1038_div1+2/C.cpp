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
#define ld long double
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
	ll i;
	ll x, y;
	ll u, v;
};
struct v
{
	ll i;
	ll v;
};
struct u
{
	ll i;
	ll u;
};
bool cmp(node s1, node s2)
{
	return s1.x < s2.x;
}
bool cmp2(node s1, node s2)
{
	return s1.y < s2.y;
}
void sola()
{
	cin >> n;
	node a[n + 10];
	vector<u> uu;
	vector<v> vv;
	for (int i = 1; i <= n; i++)
	{
		a[i].i = i;
		cin >> a[i].x >> a[i].y;
		a[i].u = a[i].x + a[i].y;
		a[i].v = a[i].x - a[i].y;
		uu.push_back({i, a[i].u});
		vv.push_back({i, a[i].v});
	}
	sort(a + 1, a + 1 + n, cmp);
	sort(a + 1, a + 1 + n / 2, cmp2);
	sort(a + 1 + n / 2, a + 1 + n, cmp2);
	for (int i = 1; i <= n / 2; i++)
	{
		cout << a[i].i << ' ' << a[n - i + 1].i << '\n';
		ans += abs(a[i].x - a[i + n / 2].x) + abs(a[i].y - a[i + n / 2].y);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> _;
	while (_--)
	{
		sola();
	}
	return 0;
}