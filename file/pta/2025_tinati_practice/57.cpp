#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *build(int postStart, int postEnd, int inStart, int inEnd,
                unordered_map<int, int> &pos, vector<int> &post)
{
    if (postStart > postEnd)
        return nullptr;
    TreeNode *root = new TreeNode(post[postEnd]);
    int index = pos[post[postEnd]];
    int leftSize = index - inStart;
    root->left = build(postStart, postStart + leftSize - 1, inStart, index - 1, pos, post);
    root->right = build(postStart + leftSize, postEnd - 1, index + 1, inEnd, pos, post);
    return root;
}

vector<int> levelOrder(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        res.push_back(node->val);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> post(n), in(n);
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
        pos[in[i]] = i;

    TreeNode *root = build(0, n - 1, 0, n - 1, pos, post);
    vector<int> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
    return 0;
}