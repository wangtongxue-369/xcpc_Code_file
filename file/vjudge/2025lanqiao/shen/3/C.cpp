#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, ans;
int main()
{
    cin >> a >> b;
    for (int i = 1; i <= a; i++) // zhengfangxin
    {
        for (int j = 1; j <= b; j++)
        {
            ans += min(i, j);
        }
    }
    cout << ans << " ";
    ll ans2 = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            ans2 += (i * j);
        }
    }
    cout << ans2 - ans;
}