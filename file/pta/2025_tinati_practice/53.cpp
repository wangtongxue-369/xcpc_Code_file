#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
struct Node
{
    string address;
    int value;
    string next;
};
void solve()
{
    string startAddress;
    int N;
    cin >> startAddress >> N;

    unordered_map<string, Node> nodes;
    for (int i = 0; i < N; i++)
    {
        Node tempNode;
        cin >> tempNode.address >> tempNode.value >> tempNode.next;
        nodes[tempNode.address] = tempNode;
    }

    vector<Node> uniqueNodes, duplicateNodes;
    unordered_set<int> seenValues;
    for (string currAddress = startAddress; currAddress != "-1"; currAddress = nodes[currAddress].next)
    {
        Node &currNode = nodes[currAddress];
        if (seenValues.insert(abs(currNode.value)).second)
        {
            uniqueNodes.push_back(currNode);
        }
        else
        {
            duplicateNodes.push_back(currNode);
        }
    }

    auto printNodes = [](const vector<Node> &nodes)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i].address << " " << nodes[i].value << " " << ((i == nodes.size() - 1) ? "-1" : nodes[i + 1].address) << "\n";
        }
    };

    printNodes(uniqueNodes);
    printNodes(duplicateNodes);

    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
