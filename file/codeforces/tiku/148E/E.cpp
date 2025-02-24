#include <bits/stdc++.h>
using namespace std;
const int N = 1919810;
typedef long long ll;
typedef pair<ll, ll> PII;
ll n, m, k;
ll a[N], b[N];
char s[N];
int dp[2010][2010];
void __()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int nw = dp[i - 1][j - 1];
            if (j == a[i])
                nw++;
            dp[i][j] = max(dp[i][j], nw);
        }
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j >= i; j--)
        {
            if (dp[j][i] >= k)
            {
                printf("%d\n", n - i);
                return;
            }
        }
    }
    puts("-1");
}
int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        __();
    }
}