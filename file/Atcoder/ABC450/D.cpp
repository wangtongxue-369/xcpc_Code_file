#include <bits/stdc++.h>
using namespace std;
long long max_n = 0, k, ans = 1e9 + 7;
long long a[100005];
int n;
bool cmp(long long a1, long long b)
{
    return a1 > b;
}
int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        max_n = max(max_n, a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        int t1 = (max_n - a[i]) / k;
        a[i] = t1 * k + a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    //	for(int i = 1;i <= n;i++){
    //		cout<<a[i]<<" ";
    //	}
    for (int i = 1; i <= n - 1; i++)
    {
        ans = min(ans, k - (a[i] - a[i + 1]));
    }

    ans = min(ans, (a[n] + k - a[1]));
    ans = min(ans, a[1] - a[n]);
    cout << ans;

    return 0;
}
