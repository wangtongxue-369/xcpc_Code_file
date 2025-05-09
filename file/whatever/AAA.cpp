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

void prllVector(const vector<ll> &v)
{
    for (ll val : v)
        cout << val << " ";
}

bool isSafe(vector<ll> work, vector<vector<ll>> alloc, vector<vector<ll>> need, vector<ll> &safeSeq)
{
    vector<bool> finish(n, false);
    safeSeq.clear();

    cout << "\nName\tWork\t\tNeed\t\tAllocation\tWork+ Allocation\tFinish\n";
    for (ll cnt = 0; cnt < n; cnt++)
    {
        bool found = false;
        for (ll i = 0; i < n; i++)
        {
            if (!finish[i])
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
                    cout << process_names[i] << "\t";
                    prllVector(work);
                    cout << "\t";
                    prllVector(need[i]);
                    cout << "\t";
                    prllVector(alloc[i]);
                    cout << "\t";

                    vector<ll> new_work = work;
                    for (ll j = 0; j < m; j++)
                    {
                        new_work[j] += alloc[i][j];
                    }

                    prllVector(new_work);
                    cout << "\tT\n";

                    work = new_work;
                    finish[i] = true;
                    safeSeq.push_back(i);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            break;
    }

    if (safeSeq.size() == n)
    {
        cout << "\nSYSTEM SECURITY!!!\n";
        return true;
    }
    else
    {
        cout << "\nRESOURCE INSECURITY!!!\n";
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
    string line, pname;
    vector<ll> req(m);
    cout << "Please input the customer's name and request:\n";

    cin >> pname;
    for (ll j = 0; j < m; j++)
    {
        cin >> req[j];
    }

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
void slove()
{
    initData();

    while (true)
    {
        cout << "\n1、judge the system security\n";
        cout << "2、judge the request security\n";
        cout << "3、quit\n";
        ll choice;
        cin >> choice;
        cin.ignore();
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
        }
    }
}
signed main()
{
    ll _ = 1;
    // cin>>_;
    while (_--)
    {
        slove();
    }
    return 0;
}