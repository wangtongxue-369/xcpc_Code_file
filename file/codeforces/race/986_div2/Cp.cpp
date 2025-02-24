#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

bool can_divide(const std::vector<int> &arr, int m, int v, int alice_piece)
{
    int n = arr.size();
    for (int i = 0; i <= n; ++i)
    {
        int alice_sum = std::accumulate(arr.begin(), arr.begin() + i, 0);
        if (alice_sum == alice_piece)
        {
            int curr_sum = 0;
            int pieces = 0;
            for (int j = i; j < n; ++j)
            {
                curr_sum += arr[j];
                if (curr_sum >= v)
                {
                    pieces += 1;
                    curr_sum = 0;
                }
            }
            if (pieces >= m)
            {
                return true;
            }
        }

        alice_sum = std::accumulate(arr.begin() + n - i, arr.end(), 0);
        if (alice_sum == alice_piece)
        {
            int curr_sum = 0;
            int pieces = 0;
            for (int j = 0; j < n - i; ++j)
            {
                curr_sum += arr[j];
                if (curr_sum >= v)
                {
                    pieces += 1;
                    curr_sum = 0;
                }
            }
            if (pieces >= m)
            {
                return true;
            }
        }
    }
    return false;
}

int solve()
{
    int n, m, v;
    std::cin >> n >> m >> v;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int total_sum = std::accumulate(arr.begin(), arr.end(), 0);
    if (total_sum < m * v)
    {
        return -1;
    }

    int left = 0;
    int right = total_sum;
    int ans = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (can_divide(arr, m, v, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        std::cout << solve() << std::endl;
    }
    return 0;
}