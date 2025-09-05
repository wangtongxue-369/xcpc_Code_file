#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

void slove()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        a[i] -= i;
    }
    int l = 1, r = n + 1;
    auto check = [&](int len) -> bool
    {
        multiset<int> s1, s2;
        int sum1 = 0, sum2 = 0;
        auto f = [&]() -> void
        {
            while (s1.size() > s2.size())
            {
                int x = *s1.rbegin();
                s2.insert(x);
                sum1 -= x;
                sum2 += x;
                s1.erase(*s1.rbegin());
            }
            while (s2.size() > s1.size())
            {
                int x = *s2.begin();
                s1.insert(x);
                sum2 -= x;
                sum1 += x;
                s2.erase(*s2.begin());
            }
        };
        for (int i = 1; i <= len; i++)
        {
            s1.insert(a[i]);
            sum1 += a[i];
        }
        f();
        int md = *s1.rbegin();
        int sum = sum2 - s2.size() * md + s1.size() * md - sum1;
        if (sum <= k)
        {
            return 1;
        }
        for (int i = len + 1, j = 1; i <= n; i++, j++)
        {
            if (s1.count(a[j]))
            {
                s1.erase(a[j]);
                sum1 -= a[j];
                f();
            }
            else
            {
                s2.erase(a[j]);
                sum2 -= a[j];
                f();
            }
            s1.insert(a[i]);
            sum1 += a[i];
            f();
            cout << "!!!";
            for (auto it : s1)
            {
                cout << it << " ";
            }
            for (auto it : s2)
            {
                cout << it << " ";
            }
            cout << "\n";
            md = *s1.rbegin();
            sum = sum2 - s2.size() * md + s1.size() * md - sum1;
            cout << j + 1 << " " << sum << " " << len << " " << md << "\n";
            if (sum <= k)
            {
                return 1;
            }
        }
        return 0;
    };
    while (l + 1 != r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll _{1};
    cin >> _;
    while (_--)
    {
        slove();
    }
    return 0;
}