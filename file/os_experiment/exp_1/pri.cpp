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
    int pri;
    PCB(string name, int cputime, int needtime, int count, int round, int pri, int state)
    {
        this->name = name;
        this->cputime = cputime;
        this->needtime = needtime;
        this->count = count;
        this->round = round;
        this->pri = pri;
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
    int getPri() const { return pri; }
    void setpri(int pri) { this->pri = pri; }
    int getState() const { return state; }
    void setState(int state) { this->state = state; }
    void output() { cout << setw(ck) << name << setw(ck) << cputime << setw(ck) << needtime << setw(ck) << count << setw(ck) << pri << setw(ck) << "WRF"[(int)state] << endl; }
    bool operator<(const PCB &other) const
    {
        if (this->pri == other.pri)
        {
            return this->name < other.name;
        }
        return this->pri < other.pri;
    }
};
void solve()
{
    cout << "      input name and needtime:" << endl;
    string s1;
    int nt;
    priority_queue<PCB> q;
    deque<PCB> sdq;
    while (cin >> s1 >> nt)
    {
        PCB p(s1, 0, nt, 0, 2, 50 - nt, 0);
        q.push(p);
    }
    n = q.size();
    while (sdq.size() != n)
    {
        cout << setw(ck) << "Name" << setw(ck) << "cputime" << setw(ck) << "needtime" << setw(ck) << "count" << setw(ck) << "pri" << setw(ck) << "state" << endl;
        PCB topPCB = q.top();
        q.pop();
        topPCB.setState(1);
        q.push(topPCB);
        priority_queue<PCB> tempQueue = q;
        while (!tempQueue.empty())
        {
            PCB it = tempQueue.top();
            tempQueue.pop();
            it.output();
        }
        for (auto it : sdq)
        {
            it.output();
        }
        auto it = q.top();
        q.pop();
        cout << "      就绪队列：";
        tempQueue = q;
        while (!tempQueue.empty())
        {
            PCB i = tempQueue.top();
            tempQueue.pop();
            cout << i.getName();
            if (!tempQueue.empty())
            {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "      完成队列：";
        for (auto i = sdq.begin(); i != sdq.end(); ++i)
        {
            cout << i->getName();
            if (next(i) != sdq.end())
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
            it.setpri(it.getPri() - 3);
            it.setState(0);
            q.push(it);
        }
    }
    cout << setw(ck) << "Name" << setw(ck) << "cputime" << setw(ck) << "needtime" << setw(ck) << "count" << setw(ck) << "round" << setw(ck) << "state" << endl;
    priority_queue<PCB> tempQueue = q;
    while (!tempQueue.empty())
    {
        PCB it = tempQueue.top();
        tempQueue.pop();
        it.output();
    }
    for (auto it : sdq)
    {
        it.output();
    }
    cout << "      就绪队列：";
    tempQueue = q;
    while (!tempQueue.empty())
    {
        PCB i = tempQueue.top();
        tempQueue.pop();
        cout << i.getName();
        if (!tempQueue.empty())
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "      完成队列：";
    for (auto i = sdq.begin(); i != sdq.end(); ++i)
    {
        cout << i->getName();
        if (next(i) != sdq.end())
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