#include <stdio.h>
#include <stdlib.h>

struct data
{
    char name[9];
    int gender;
    int flag;
};

typedef struct data dat;

int main()
{
    int n;
    scanf("%d", &n);

    dat store[n];

    int girl_count = 0, boy_count = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &(store[i].gender), store[i].name);
        store[i].flag = 0;
    }

    for (int i = 0; i < n / 2; i++)
    {
        printf("%s ", store[i].name);
        store[i].flag = 1;

        for (int j = n - 1; j != -1; j--)
        {
            if (store[i].gender != store[j].gender && !store[j].flag)
            {
                printf("%s\n", store[j].name);
                store[j].flag = 1;
                break;
            }
        }
    }

    return 0;
}