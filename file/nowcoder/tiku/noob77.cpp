class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求序列a中的峰、谷点的个数
     * @param a int整型vector 序列a
     * @return int整型
     */
    int countPeakPoint(vector<int> &a)
    {
        int ans = 0;
        for (int i = 1; i < a.size() - 1; i++)
        {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
            {
                ans++;
            }
            else if (a[i - 1] > a[i] && a[i] < a[i + 1])
            {
                ans++;
            }
        }
        return ans;
    }
};