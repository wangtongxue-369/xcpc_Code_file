#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005]; // f[500005];
void solve()
{
    ll op;
    cin >> n;
    bool flag = 0;
    string s;
    while (n--)
    {
        string s1 = "01";
        if (flag == 0)
        {
            cout << "? " << s << '0' << endl;
            cin >> op;
            if (op == 1)
            {
                s += '0';
                continue;
            }
            else
            {
                cout << "? " << s << '1' << endl;
                cin >> op;
                if (op == 1)
                {
                    s += '1';
                    continue;
                }
                else
                {
                    flag = 1;
                    n++;
                    continue;
                }
            }
        }
        else
        {
            cout << "? " << '0' << s << endl;
            cin >> op;
            if (op == 1)
            {
                s = '0' + s;
            }
            else
            {
                s = '1' + s;
            }
        }
    }
    cout << "!" << ' ' << s << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
