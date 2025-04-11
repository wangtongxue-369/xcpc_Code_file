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
    int n, sum = 0;
    char c;
    scanf("%d", &sum);
    scanf("%c", &c);
    while (c != '=')
    {
        if (c == '+')
        {
            scanf("%d", &n);
            sum += n;
        }
        else if (c == '-')
        {
            scanf("%d", &n);
            sum -= n;
        }
        else if (c == '*')
        {
            scanf("%d", &n);
            sum *= n;
        }
        else if (c == '/')
        {
            scanf("%d", &n);
            if (n == 0)
            {
                printf("ERROR");
                return;
            }
            sum /= n;
        }
        else
        {
            printf("ERROR");
            return;
        }
        scanf("%c", &c);
    }
    printf("%d\n", sum);
    return;
}
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