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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN][2];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // f[i]]0
    for (int i = 1; i <= n; i++)
    {
    }
}
// 0 bugai
// 1 ji
// 2 ou
// f[i][0]=f[i][]
// 0 : a[i] -> ji   f[i-1][2],   (a[i]+a[i-1]).is  ->  f[i-1][0]
//     a[i] -> ou   f[i-1][1],   (a[i]+a[i-1]).is  ->  f[i-1][0]
// 1 : f[i-1][2]+1   a[i-1]%2==0  ->  f[i-1][0]
// 2 : f[i-1][1]+1   a[i-1]%2==1  ->  f[i-1][0]
//
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}