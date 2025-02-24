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
            ll f = 0;
            for (int i = 0; i <= 1; i++)
            {
                cout << '?' << ' ' << s << s1[i] << endl;
                cin >> op;
                if (op == 1)
                {
                    s += s1[i];
                    break;
                }
                f++;
            }
            if (f == 2)
            {
                flag = 1;
                n++;
            }
        }
        else
        {
            ll f = 0;
            for (int i = 0; i <= 1; i++)
            {

                cout << "?" << ' ' << s1[i] << s << endl;
                cin >> op;
                if (op == 1)
                {
                    s = s1[i] + s;
                    break;
                }
                f++;
            }
            if (f == 2)
            {
                flag = 1;
                n++;
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
