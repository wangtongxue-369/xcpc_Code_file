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
ll _ = 1; // n, m, ans = 0, a[MAXN], f[MAXN];
typedef int Elemtype;
void solve()
{
    Elemtype a[8];
    memset(a, 0, sizeof(a));
    char s[MAXN];
    printf("输入操作字符串");
    scanf("%s", s);
    int n = strlen(s), head = 0, tail = -1;
    for (int i = 0; i < n; i++)
    {
        if ('1' <= s[i] && s[i] <= '9')
        {
            if (tail - head + 1 > 8)
            {
                printf("输入数据有误！");
                return;
            }
            tail++;
            a[tail % n] = s[i] - '0';
        }
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            if (tail < head)
            {
                printf("输入数据有误！");
                return;
            }
            head++;
        }
        else
        {
            break;
        }
    }
    printf("操作后的队列为：\n");
    for (int i = head; i < tail; i++)
    {
        printf("%d ", a[i % n]);
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
