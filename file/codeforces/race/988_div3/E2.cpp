#include <iostream>
#include <string>
using namespace std;

// Function to query the interactor
int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush(); // Ensure the query is flushed immediately
    int y;
    cin >> y;
    return y;
}

// Main logic to determine the binary string or output "IMPOSSIBLE"
void theProgram()
{
    int n;
    cin >> n;
    string ans;
    int prev = 0;
    int cnt0 = 0;

    for (int i = 1; i < n; i++)
    {
        int x = query(1, i + 1);

        if (prev == 0)
        {
            if (x == 0)
            {
                continue; // No 01 subsequences yet
            }
            else
            {
                if (x > i)
                {
                    cout << "! IMPOSSIBLE" << endl;
                    return;
                }
                else
                {
                    for (int j = 0; j < i - x; j++)
                    {
                        ans.push_back('1');
                    }
                    for (int j = 0; j < x; j++)
                    {
                        ans.push_back('0');
                    }
                }
            }
            ans.push_back('1'); // Append the next character
            cnt0 = x;
            prev = x;
        }
        else
        {
            if (x > prev)
            {
                if (x - prev == cnt0)
                {
                    ans.push_back('1');
                    prev = x;
                }
                else
                {
                    cout << "! IMPOSSIBLE" << endl;
                    return;
                }
            }
            else if (x == prev)
            {
                ans.push_back('0');
                cnt0++;
            }
            else
            {
                cout << "! IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    // Ensure the string is of correct length
    if (ans.size() < n)
    {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    cout << "! " << ans << endl;
    cout.flush();
}

// Driver function to handle multiple test cases
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        theProgram();
    }

    return 0;
}