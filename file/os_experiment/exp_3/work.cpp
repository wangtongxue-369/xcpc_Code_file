#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 32766;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    ll s = 0, e = 0;
};
bool cmpz(node s1, node s2)
{
    return s1.s < s2.s;
}
bool cmpzl(node s1, node s2)
{
    ll l1 = (s1.e - s1.s + 1), l2 = (s2.e - s2.s + 1);
    if (l1 == l2)
    {
        return s1.s < s2.s;
    }
    return l1 < l2;
}
vector<node> a;
bool checkchongfu(ll adr, ll siz)
{
    ll st = adr, en = adr + siz - 1;
    for (auto [s, e] : a)
    {
        if ((st <= s && s <= en) || (st <= e && e <= en) || (s <= st && st <= e) || (s <= en && en <= e))
        {
            return 0;
        }
    }
    return 1;
}
void output()
{
    sort(a.begin(), a.end(), cmpzl);
    ll p = 1;
    cout << "Index\tadr\tend\tsize" << endl;
    for (auto it : a)
    {
        cout << p << "       " << it.s << "    " << it.e << "    " << it.e - it.s + 1 << endl;
        p++;
    }
    sort(a.begin(), a.end(), cmpz);
}
void output2()
{
    sort(a.begin(), a.end(), cmpz);
    ll p = 1;
    cout << "Index\tadr\tend\tsize" << endl;
    for (auto it : a)
    {
        cout << p << "       " << it.s << "    " << it.e << "    " << it.e - it.s + 1 << endl;
        p++;
    }
    sort(a.begin(), a.end(), cmpz);
}
void ins(ll adr, ll size)
{
    ll end = adr + size - 1;
    a.push_back({adr, end});
    sort(a.begin(), a.end(), cmpz);
    while (1)
    {
        ll p = -1;
        bool flag = 1;
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i - 1].e + 1 == a[i].s)
            {
                flag = 0;
                p = i;
                break;
            }
        }
        if (p == -1)
        {
            break;
        }
        auto it1 = a[p - 1];
        auto it2 = a[p];
        a.erase(a.begin() + p);
        a[p - 1].e = it2.e;
        sort(a.begin(), a.end(), cmpz);
        if (flag)
        {
            break;
        }
    }
}
void best()
{
    while (1)
    {
        output();
        cout << "Assign or Accept:" << endl;
        string op;
        cin >> op;
        if (op == "as")
        {
            ll si;
            cout << "input APPLACATION:" << endl;
            cin >> si;
            ll p = -1, minn = 1e18;
            for (int i = 0; i < a.size(); i++)
            {
                auto it = a[i];
                ll len = it.e - it.s + 1;
                if (len >= si && minn > len)
                {
                    p = i;
                    minn = min(minn, len);
                }
            }
            if (p == -1)
            {
                cout << "Too large application!" << endl;
                continue;
            }
            cout << "SUCCESS!!!     ADDRESS=";
            auto it = a[p];
            a.erase(a.begin() + p);
            ll len = it.e - it.s + 1;
            // a.push_back({it.e - si + 1, it.e});
            cout << it.e - si + 1 << endl;
            it.e = it.e - si;
            if (it.e - it.s + 1 >= 1)
            {
                a.push_back(it);
            }
            sort(a.begin(), a.end(), cmpz);
        }
        else
        {
            ll adr, size;
            cout << "nput adr and size:" << endl;
            cin >> adr >> size;
            if (!checkchongfu(adr, size))
            {
                cout << "数据重复" << endl;
                continue;
            }
            if ((adr + size - 1 > MAXN) || adr < 0)
            {
                cout << "数据范围出错" << endl;
                continue;
            }
            if (size <= 0)
            {
                cout << "Invalid size" << endl;
                continue;
            }
            ll end = adr + size - 1;
            ins(adr, size);
        }
    }
}
void frist()
{
    while (1)
    {
        output2();
        cout << "Assign or Accept:" << endl;
        string op;
        cin >> op;
        if (op == "as")
        {
            ll si;
            cout << "input APPLACATION:" << endl;
            cin >> si;
            ll p = -1, minn = 1e18;
            for (int i = 0; i < a.size(); i++)
            {
                auto it = a[i];
                ll len = it.e - it.s + 1;
                if (len >= si)
                {
                    p = i;
                    break;
                }
            }
            if (p == -1)
            {
                cout << "Too large application!" << endl;
                continue;
            }
            cout << "SUCCESS!!!     ADDRESS=";
            auto it = a[p];
            a.erase(a.begin() + p);
            ll len = it.e - it.s + 1;
            // a.push_back({it.e - si + 1, it.e});
            cout << it.e - si + 1 << endl;
            it.e = it.e - si;
            if (it.e - it.s + 1 >= 1)
            {
                a.push_back(it);
            }
            sort(a.begin(), a.end(), cmpz);
        }
        else
        {
            ll adr, size;
            cout << "nput adr and size:" << endl;
            cin >> adr >> size;
            if (!checkchongfu(adr, size))
            {
                cout << "数据重复" << endl;
                continue;
            }
            if ((adr + size - 1 > MAXN) || adr < 0)
            {
                cout << "数据范围出错" << endl;
                continue;
            }
            if (size <= 0)
            {
                cout << "Invalid size" << endl;
                continue;
            }
            ll end = adr + size - 1;
            ins(adr, size);
        }
    }
}
void solve()
{
    cout << "input the way (best or first):" << endl;
    string op;
    cin >> op;
    a.push_back({0, MAXN});
    if (op == "best")
    {
        best();
    }
    else
    {
        frist();
    }
    return;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}