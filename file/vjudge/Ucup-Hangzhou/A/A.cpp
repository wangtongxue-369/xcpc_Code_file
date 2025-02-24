#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int now = 0, ago = 0;
    for (int i = 1; i <= min(n, 20); i++)
    {
        cout << "?" << " " << i << endl;
        cin >> now;
        if (now == ago)
        {
            cout << "!" << " " << i << endl;
            return 0;
        }
        ago = now;
    }
    int lo = 21, hi = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        cout << "?" << " " << mid << endl;
        cin >> now;
        if (now == ago)
        {
            cout << "!" << " " << mid << endl;
            break;
        }
        else
        {
            if (now > ago)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        ago = now;
    }
    return 0;
}