#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }

    vector<pair<pair<int, int>, int>> b(n);
    for (int i = 0; i < n; ++i)
    {
        b[i].first = a[i];
        b[i].second = i;
    }

    sort(b.begin(), b.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
         { return a.first.first < b.first.first; });

    set<int> se;
    for (int i = 1; i <= n; ++i)
    {
        se.insert(i);
    }

    vector<int> result(n, -1);

    for (int i = 0; i < n; ++i)
    {
        int l = b[i].first.first;
        int r = b[i].first.second;
        int idx = b[i].second;

        auto it = se.lower_bound(l);
        if (it == se.end() || *it > r)
        {
            cout << -1 << endl;
            return 0;
        }

        int chosen_number = *it;
        result[idx] = chosen_number;
        se.erase(it);
    }

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
