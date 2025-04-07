#include <bits/stdc++.h>
using namespace std;

vector<int> post;

bool check(const vector<int> &pre, int start, int end, bool isMirror)
{
    if (start > end)
        return true;
    int root = pre[start];
    int i = start + 1;
    // 划分左子树和右子树
    if (!isMirror)
    {
        while (i <= end && pre[i] < root)
            i++;
        int j = i;
        while (j <= end)
        {
            if (pre[j] < root)
                return false;
            j++;
        }
    }
    else
    {
        while (i <= end && pre[i] >= root)
            i++;
        int j = i;
        while (j <= end)
        {
            if (pre[j] >= root)
                return false;
            j++;
        }
    }
    // 检查左右子树
    bool left = check(pre, start + 1, i - 1, isMirror);
    bool right = check(pre, i, end, isMirror);
    if (left && right)
    {
        post.push_back(root);
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    bool valid = check(pre, 0, n - 1, false);
    if (!valid)
    {
        post.clear();
        valid = check(pre, 0, n - 1, true);
    }
    if (valid)
    {
        cout << "YES" << endl;
        for (int i = 0; i < post.size(); i++)
        {
            if (i > 0)
                cout << " ";
            cout << post[i];
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}