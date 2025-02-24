#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], b[MAXN];
struct node
{
    ll a, b;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.a < s2.a;
}
void solve()
{
    ll A, B;
    cin >> A >> B >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].b;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        // if (a[i].b == 1000)
        // {
        //     cout << "!" << B - a[i].a * (ceil(1.0 * a[i].b / A) - 1) << '\n';
        // }
        if (B - a[i].a * (ceil(1.0 * a[i].b / A) - 1) <= 0)
        {
            cout << "NO\n";
            return;
        }
        B -= a[i].a * ceil(1.0 * a[i].b / A);
        if (B <= 0)
        {
            if (i == n)
            {
                continue;
            }
            else
            {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    return;
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
