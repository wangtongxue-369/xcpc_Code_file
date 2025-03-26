#include <string.h>
#include <stdio.h>
void solve()
{
    char a[1000], b[1000];
    int i = 0, j, flag = 0, flag2 = 0;
    int number1 = 0, number2 = 0;
    while (((a[i]) = getchar()) != ' ')
    {
        i++;
    }
    gets(b);
    for (j = 0; j < i; j++)
    {
        if (a[j] < '0' || a[j] > '9')
        {
            flag = 1;
        }

        else
        {
            number1 = number1 * 10 + a[j] - '0';
        }
    }
    if (number1 > 1000 || number1 < 1)
    {
        flag = 1;
    }

    if (flag == 1)
    {
        printf("? + ");
    }

    else
    {
        printf("%d + ", number1);
    }

    for (i = 0; i < strlen(b); i++)
    {
        if (b[i] < '0' || b[i] > '9')
        {
            flag2 = 1;
        }

        else
        {
            number2 = number2 * 10 + b[i] - '0';
        }
    }
    if (number2 > 1000 || number2 < 1)
    {
        flag2 = 1;
    }
    if (flag2 == 1)
    {
        printf("? = ?");
    }
    else if (flag == 0 && flag2 == 0)
    {
        printf("%d = %d", number2, number1 + number2);
    }
    else if (flag2 == 0 && flag == 1)
    {
        printf("%d = ?", number2);
    }
}
int main()
{

    solve();

    return 0;
}
