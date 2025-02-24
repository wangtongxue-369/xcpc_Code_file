#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e5 + 5;
int a[N], l[N], r[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (st.empty() || a[i] < a[st.top()])
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && a[i] >= a[st.top()])
            {
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        r[st.top()] = n + 1;
        st.pop();
    }
    for (int i = n; i >= 1; i--)
    {
        if (st.empty() || a[i] < a[st.top()])
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && a[i] >= a[st.top()])
            {
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        l[st.top()] = 0;
        st.pop();
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!l[i] || a[l[i]] != a[i])
            ans += (r[i] - l[i] - 2);
        else
        {
            ans += (r[i] - 1 - i);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}