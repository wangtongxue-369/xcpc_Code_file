#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll id, v;
    bool operator<(const node &n1) const
    {
        return n1.v < v;
    }
};
void slove()
{
    ll ans = 0;
    int n;
    cin >> n;
    priority_queue<node> a;
    node x;
    x.id = 0;
    x.v = 1e18;
    a.push(x);
    vector<ll> ve;
    ll maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        ll s;
        cin >> s;
        ve.push_back(s);
        maxn = max(maxn, s);
    }
    for (int i = 0; i < n; i++)
    {
        x.v = ve[i];
        x.id = i + 1;
        if (x.v < a.top().v)
        {
            a.push(x);
        }
        if (x.v == a.top().v)
        {
            continue;
        }
        while (a.top().v < x.v)
        {
            // cout << "<=" << ((x.id - 1) - (a.top().id) + 1) << ' ' << i << endl;
            ans += ((x.id - 1) - (a.top().id) + 1);
            a.pop();
        }
        if (x.v == a.top().v)
        {
            continue;
        }
        else
        {
            a.push(x);
        }
    }

    if (a.top().v == maxn && a.top().id == n)
    {
        ans += n - 1;
        cout << ans << '\n';
        return;
    }
    if (a.top().v != maxn)
    {
        while (a.size() > 1)
        {
            ans += (n - a.top().id);
            a.pop();
        }
    }

    // while (a.size() > 1)
    // {
    //     if (a.top().v == maxn)
    //     {
    //         break;
    //     }
    //     ans += (n - a.top().id + 1);
    //     a.pop();
    // }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll _ = 1;
    cin >> _;
    while (_--)
    {
        slove();
    }
    return 0;
}