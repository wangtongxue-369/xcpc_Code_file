#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> calculateMinAdjustments(int n, const vector<int> &weights, const vector<pair<int, int>> &queries)
{
    vector<long long> results;

    for (auto &query : queries)
    {
        int l = query.first - 1; // 转为 0-based 索引
        int r = query.second - 1;

        long long left_sum = 0;
        long long adjustments = 0;

        // 从左到右模拟骨牌倒下
        for (int i = l; i <= r; ++i)
        {
            if (left_sum < weights[i])
            {
                adjustments += weights[i] - left_sum;
                left_sum = weights[i];
            }
            left_sum += weights[i];
        }

        results.push_back(adjustments);
    }

    return results;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<long long> results = calculateMinAdjustments(n, weights, queries);

    for (long long result : results)
    {
        cout << result << endl;
    }

    return 0;
}
