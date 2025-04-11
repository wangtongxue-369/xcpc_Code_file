#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll ck = 10;

class PCB
{
public:
    string name;
    int cputime;
    int needtime;
    int count;
    int round;
    int state;
    PCB(string name, int cputime, int needtime, int count, int round, int state)
    {
        this->name = name;
        this->cputime = cputime;
        this->needtime = needtime;
        this->count = count;
        this->round = round;
        this->state = state;
    }
    string getName() const { return name; }
    void setName(string name) { this->name = name; }
    int getCpuTime() const { return cputime; }
    void setCpuTime(int cputime) { this->cputime = cputime; }
    int getNeedTime() const { return needtime; }
    void setNeedTime(int needtime) { this->needtime = needtime; }
    int getCount() const { return count; }
    void setCount(int count) { this->count = count; }
    int getRound() const { return round; }
    void setRound(int round) { this->round = round; }
    int getState() const { return state; }
    void setState(int state) { this->state = state; }
    void output() { cout << setw(ck) << name << setw(ck) << cputime << setw(ck) << needtime << setw(ck) << count << setw(ck) << round << setw(ck) << "WRF"[(int)state] << endl; }
};
void solve()
{
    cout << "      input name and needtime:" << endl;
    string s1;
    int nt;
    deque<PCB> wdq;
    deque<PCB> sdq;
    while (cin >> s1 >> nt)
    {
        PCB p(s1, 0, nt, 0, 2, 0);
        wdq.push_back(p);
    }
    n = wdq.size();
    while (sdq.size() != n)
    {
        cout << setw(ck) << "Name" << setw(ck) << "cputime" << setw(ck) << "needtime" << setw(ck) << "count" << setw(ck) << "round" << setw(ck) << "state" << endl;
        wdq.front().setState(1);
        for (auto it : wdq)
        {
            it.output();
        }
        for (auto it : sdq)
        {
            it.output();
        }
        auto it = wdq.front();
        wdq.pop_front();
        cout << "      就绪队列：";
        for (auto it = wdq.begin(); it != wdq.end(); ++it)
        {
            cout << it->getName();
            if (next(it) != wdq.end())
            {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "      完成队列：";
        for (auto it = sdq.begin(); it != sdq.end(); ++it)
        {
            cout << it->getName();
            if (next(it) != sdq.end())
            {
                cout << ", ";
            }
        }
        cout << endl;
        if (it.needtime <= 2)
        {
            it.setCpuTime(it.getCpuTime() + it.getNeedTime());
            it.setNeedTime(0);
            it.setCount(it.getCount() + 1);
            it.setState(2);
            sdq.push_back(it);
        }
        else
        {
            it.setCpuTime(it.getCpuTime() + it.getRound());
            it.setNeedTime(it.getNeedTime() - it.getRound());
            it.setCount(it.getCount() + 1);
            it.setState(0);
            wdq.push_back(it);
        }
    }
    cout << setw(ck) << "Name" << setw(ck) << "cputime" << setw(ck) << "needtime" << setw(ck) << "count" << setw(ck) << "round" << setw(ck) << "state" << endl;
    for (auto it : sdq)
    {
        it.output();
    }
    cout << "      就绪队列：";
    for (auto it = wdq.begin(); it != wdq.end(); ++it)
    {
        cout << it->getName();
        if (next(it) != wdq.end())
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "      完成队列：";
    for (auto it = sdq.begin(); it != sdq.end(); ++it)
    {
        cout << it->getName();
        if (next(it) != sdq.end())
        {
            cout << ", ";
        }
    }
    cout << endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    //  cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}