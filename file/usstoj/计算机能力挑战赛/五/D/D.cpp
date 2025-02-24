#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
bool check(ll s1)
{
    bool flag = 1;
    if (s1 == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(s1); i++)
    {
        if (s1 % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

const int maxn = 250;

int k;
int girl[maxn];       // girl[i]等于第i个女生匹配到的男生
int line[maxn][maxn]; // line[i][j]表示男生i喜欢女生j
bool used[maxn];

// 为男生x匹配一个女生，成功返回true，失败返回false
// 注意在调用这个函数之前每次都要used[]数组清零
bool match(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        if (line[x][i] && !used[i])
        {
            used[i] = true;
            if (girl[i] == 0 || match(girl[i]))
            {
                girl[i] = x;
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<pair<ll, ll>, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (check(a[i] + a[j]) == 1)
            {
                line[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(used, 0, sizeof(used));
        if (match(i))
        {
            ++ans;
        }
    }
    cout << ans / 2 << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
