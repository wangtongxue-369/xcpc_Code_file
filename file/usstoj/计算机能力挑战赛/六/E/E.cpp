#include <bits/stdc++.h>
using namespace std;
int n, k;
int ans = 0;
void dfs(int x, int sum, int pre)
{
    if (x == k && sum == n)
    {
        if (sum == n)
            ans++;
        return;
    }
    for (int i = pre; i <= n - sum - (k - x - 1) * pre; i++)
    {
        dfs(x + 1, sum + i, i);
    }
}
int main()
{
    cin >> n >> k;
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}