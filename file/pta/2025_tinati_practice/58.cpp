#include <bits/stdc++.h>
using namespace std;
struct info
{
    int id, cnt;
    double avg1, avg2;
};
void solve()
{
    int n;
    cin >> n;
    vector<set<int>> e(10000);
    vector<pair<int, int>> v(10000, {0, 0});

    for (int i = 0; i < n; ++i)
    {
        int me, fa, mo, k, kid;
        cin >> me >> fa >> mo >> k;

        if (fa != -1)
        {
            e[fa].insert(me);
            e[me].insert(fa);
        }
        if (mo != -1)
        {
            e[mo].insert(me);
            e[me].insert(mo);
        }

        for (int j = 0; j < k; ++j)
        {
            cin >> kid;
            e[me].insert(kid);
            e[kid].insert(me);
        }

        int x, y;
        cin >> x >> y;
        v[me].first += x;
        v[me].second += y;
    }

    vector<bool> vis(10000);
    vector<info> ans;

    for (int i = 0; i < 10000; ++i)
    {
        if (!vis[i])
        {
            if (e[i].empty() && v[i].first == 0)
                continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;
            int c = 0, cnt = 0, sum = 0, mn = 10000;

            while (!q.empty())
            {
                auto u = q.front();
                q.pop();
                c++;
                cnt += v[u].first;
                sum += v[u].second;
                mn = min(mn, u);
                for (auto vv : e[u])
                {
                    if (!vis[vv])
                    {
                        vis[vv] = true;
                        q.push(vv);
                    }
                }
            }
            ans.push_back({mn, c, 1.0 * cnt / c, 1.0 * sum / c});
        }
    }
    sort(ans.begin(), ans.end(), [](info x, info y)
         { return x.avg2 > y.avg2 ||
                  (fabs(x.avg2 - y.avg2) < 1e-6 && x.id < y.id); });

    cout << ans.size() << endl;
    for (auto [id, x, y, z] : ans)
    {
        cout << setw(4) << setfill('0') << id << " ";
        printf("%d %.3lf %.3lf\n", x, y, z);
    }
}
int main()
{
    solve();
    return 0;
}