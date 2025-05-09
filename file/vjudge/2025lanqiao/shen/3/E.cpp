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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    ll a;
    ll i;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.a < s2.a;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
        a[i].i = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i].a * (n - i);
        cout << a[i].i << ' ';
    }
    cout << '\n';
    sum /= n;
    printf("%.2lf", sum);
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
