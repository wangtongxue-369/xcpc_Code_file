#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a = 1e9 + 1;
    for (int i = 1; i <= 10000; i++)
    {
        a += (1e9 + 1);
    }
    cout << fixed << setprecision(17);
    cout << "a: " << a << endl;
    return 0;
}
