#include <bits/stdc++.h>
using namespace std;
struct jb
{
	int m, v;
	double xjb;
};
jb a[105];
// 需要交换返回0，不需要交换返回1
bool cmp(jb x, jb y)
{
	if (x.xjb <= y.xjb)
	{
		return 0;
	}
	return 1;
}
// 第二种排序
bool cmp2(jb x, jb y)
{
	return x.xjb > y.xjb;
}
int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].m >> a[i].v;
		a[i].xjb = (double)a[i].v / a[i].m;
	}
	sort(a + 1, a + 1 + n, cmp);
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].m <= t)
		{
			sum += a[i].v;
			t -= a[i].m;
		}
		else
		{
			sum += a[i].xjb * t;
			t = 0;
		}
	}
	cout << fixed << setprecision(2) << sum << '\n';
}
