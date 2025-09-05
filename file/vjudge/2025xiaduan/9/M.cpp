#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
struct Point;
ll cross(Point a, Point b);
struct Point
{
    ll x, y, nb = 0;
    Point friend operator-(const Point &a, const Point &b)
    {
        return {a.x - b.x, a.y - b.y, 0};
    }
};

ll cross(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

auto gethull(vector<Point> P)
{
    sort(P.begin(), P.end(), [&](auto a, auto b)
         { return a.x < b.x || (a.x == b.x && a.y < b.y); });

    vector<Point> hi, lo;
    for (auto p : P)
    {
        while (hi.size() > 1 && cross(hi.back() - hi[hi.size() - 2], p - hi.back()) >= 0)
        {
            hi.pop_back();
        }
        while (!hi.empty() && hi.back().x == p.x)
            hi.pop_back();
        hi.push_back(p);
        while (lo.size() > 1 && cross(lo.back() - lo[lo.size() - 2], p - lo.back()) <= 0)
        {
            lo.pop_back();
        }
        if (lo.empty() || lo.back().x < p.x)
            lo.push_back(p);
    }
    return make_pair(hi, lo);
}

void slove()
{
    int n;
    cin >> n;
    vector<Point> po(n);
    for (int i = 0; i < n; i++)
    {
        cin >> po[i].x >> po[i].y;
    }
    auto [hi, lo] = gethull(po);

    ll p = 1;
    vector<Point> ve, re;
    for (auto it : hi)
    {
        ve.push_back({it.x, it.y, p});
        p++;
    }
    for (int i = lo.size() - 1; i >= 0; i--)
    {
        bool flag = 0;
        for (auto it : ve)
        {
            if (it.x == lo[i].x && it.y == lo[i].y)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            ve.push_back({lo[i].x, lo[i].y, p});
            p++;
        }
    }
    ll m = p - 1;
    for (auto it : po)
    {
        bool flag = 0;
        for (auto jk : ve)
        {
            if (jk.x == it.x && jk.y == it.y)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        re.push_back(it);
    }
    for (auto &it : po)
    {
        for (auto jk : ve)
        {
            if (jk.x == it.x && jk.y == it.y)
            {
                it.nb = jk.nb;
                break;
            }
        }
    }
    ll ans = 0;
    for (auto it : re)
    {
        Point base = it;
        ll p = 0;
        for (int i = 0; i < po.size(); i++)
        {
            if (po[i].x == it.x && po[i].y == it.y)
            {
                p = i;
                break;
            }
        }
        swap(po[0], po[p]);

        // base为极点Point
        auto norm2 = [&](const Point &v)
        { return v.x * v.x + v.y * v.y; };
        auto half = [&](const Point &v)
        { return v.y > 0 || (v.y == 0 && v.x >= 0); };

        sort(po.begin(), po.end(), [&](Point ia, Point ib)
             {
                Point va = ia - base, vb = ib - base;
                bool ha = half(va), hb = half(vb);
                if (ha != hb) return ha > hb;
                ll cp = cross(va, vb);
                if (cp != 0) return cp > 0;
                return norm2(va) < norm2(vb); });

        if ((po[1].nb != 0 && po[po.size() - 1].nb != 0) && (abs(po[1].nb - po[po.size() - 1].nb) == 1 || (po[1].nb == 1 && po[po.size() - 1].nb == m) || (po[1].nb == m && po[po.size() - 1].nb == 1)))
        {
            ans++;
        }
        for (int i = 1; i < po.size() - 1; i++)
        {
            if (po[i].nb != 0 && po[i + 1].nb != 0 && (abs(po[i].nb - po[i + 1].nb) == 1 || (po[i].nb == 1 && po[i + 1].nb == m) || (po[i].nb == m && po[i + 1].nb == 1)))
            {
                ans++;
            }
        }
    }
    cout << ans + 1 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll _{1};
    // cin >> _;
    while (_--)
    {
        slove();
    }
    return 0;
}