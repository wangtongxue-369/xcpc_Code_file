#include <bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> q;
ll a[300];
ll vis[300];
ll n, x, y, ans = 0;
int main()
{
    cin >> n >> x >> y;
    q.push(x);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (!q.empty())
    {

        ll f = q.front();
        if (f == y)
        {
            break;
        }
        q.pop();
        ans++;
        ll fd = f - a[f];
        ll fu = f + a[f];
        if (fd >= 1 && vis[fd] == 0)
        {
            vis[fd] = 1;
            q.push(fd);
        }
        if (fu <= n && vis[fu] == 0)
        {
            vis[fu] = 1;
            q.push(fu);
        }
    }
    cout << ans;
}