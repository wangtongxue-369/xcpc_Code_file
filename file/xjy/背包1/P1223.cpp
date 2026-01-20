#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
struct node
{
    int t;
    int i;
} a[1005];
bool cmp(node x, node y)
{
    return x.t < y.t;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].t;
        a[i].i = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i].t * (n - i);
    }

    // 第二种，类似前缀和累计
    // int cnt = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     sum += cnt;
    //     cnt += a[i].t;
    // }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].i << ' ';
    }
    cout << '\n';
    sum /= n;
    cout << fixed << setprecision(2) << sum << '\n';
    return 0;
}
