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

ll m, n;
vector<ll> Available;
vector<vector<ll>> Max;
vector<vector<ll>> Allocation;
vector<vector<ll>> Need;
vector<string> process_names;

string vectorToString(const vector<ll> &v)
{
    string s;
    for (size_t i = 0; i < v.size(); ++i)
    {
        s += to_string(v[i]);
        if (i != v.size() - 1)
            s += " ";
    }
    return s;
}

void initData()
{
    cout << "Input the type of resource and number of customer:\n";
    cin >> m >> n;
    cin.ignore();

    Max.resize(n, vector<ll>(m));
    Allocation.resize(n, vector<ll>(m));
    process_names.resize(n);
    Need.resize(n, vector<ll>(m));

    cout << "Input the amount of resource (maximum , allocated) of each customer:\n";
    for (ll i = 0; i < n; i++)
    {
        cin >> process_names[i];
        for (ll j = 0; j < m; j++)
        {
            cin >> Max[i][j];
        }
        for (ll j = 0; j < m; j++)
        {
            cin >> Allocation[i][j];
        }
    }

    cout << "Input the amount of resources(available):\n";
    Available.resize(m);
    for (ll j = 0; j < m; j++)
    {
        cin >> Available[j];
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

bool isSafe(vector<ll> work, vector<vector<ll>> alloc, vector<vector<ll>> need, vector<ll> &safeSeq)
{
    vector<bool> vis(n, false);
    safeSeq.clear();
    vector<string> outline;
    outline.push_back("Name\tWork\t\tNeed\t\tAllocation\tWork+Allocation\tFinish\n");

    for (ll cnt = 0; cnt < n; cnt++)
    {
        bool found = false;
        for (ll i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bool flag = true;
                for (ll j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    string line;
                    line += process_names[i] + "   ";
                    line += vectorToString(work) + "   ";
                    line += vectorToString(need[i]) + "   ";
                    line += vectorToString(alloc[i]) + "   ";

                    vector<ll> new_work = work;
                    for (ll j = 0; j < m; j++)
                        new_work[j] += alloc[i][j];

                    line += vectorToString(new_work) + "   T\n";
                    outline.push_back(line);

                    work = new_work;
                    vis[i] = true;
                    safeSeq.push_back(i);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            break;
        }
    }
    if (safeSeq.size() == n)
    {
        for (const auto &line : outline)
            cout << line;
        cout << "\nSYSTEM SECURITY!!!\n";
        return true;
    }
    else
    {
        // cout << "\nRESOURCE INSECURITY!!!\n";
        return false;
    }
}

void securityCheck()
{
    vector<ll> safeSeq;
    isSafe(Available, Allocation, Need, safeSeq);
}

void requestCheck()
{
    string pname;
    vector<ll> req(m);
    cout << "Please input the customer's name and request:\n";
    cin >> pname;
    for (ll j = 0; j < m; j++)
        cin >> req[j];

    ll pid = -1;
    for (ll i = 0; i < n; i++)
    {
        if (process_names[i] == pname)
        {
            pid = i;
            break;
        }
    }
    if (pid == -1)
    {
        cout << "Error: Invalid process!\n";
        return;
    }

    for (ll j = 0; j < m; j++)
    {
        if (req[j] > Need[pid][j])
        {
            cout << "Error: Request exceeds need! Denied.\n";
            return;
        }
    }

    for (ll j = 0; j < m; j++)
    {
        if (req[j] > Available[j])
        {
            cout << "SYSTEM INSUFFICIENT!!!\n";
            cout << "CUSTOMER " << pname << " CAN NOT OBTAIN RESOURCES IMMEDIATELY\n";
            return;
        }
    }

    vector<ll> oldAvail = Available;
    vector<vector<ll>> oldAlloc = Allocation;
    vector<vector<ll>> oldNeed = Need;

    for (ll j = 0; j < m; j++)
    {
        Available[j] -= req[j];
        Allocation[pid][j] += req[j];
        Need[pid][j] -= req[j];
    }

    vector<ll> safeSeq;
    if (isSafe(Available, Allocation, Need, safeSeq))
    {
        Available = oldAvail;
        Allocation = oldAlloc;
        Need = oldNeed;
        cout << "CUSTOMER " << pname << " CAN GET RESOURCES IMMEDIATELY\n";
    }
    else
    {
        Available = oldAvail;
        Allocation = oldAlloc;
        Need = oldNeed;
        cout << "RESOURCE INSECURITY!!!\n";
        cout << "CUSTOMER " << pname << " CAN NOT OBTAIN RESOURCES IMMEDIATELY\n";
    }
}

void solve()
{
    initData();
    while (true)
    {
        cout << "\n1. Check system security\n";
        cout << "2. Check request security\n";
        cout << "3. Quit\n";
        ll choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            securityCheck();
            break;
        case 2:
            requestCheck();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}