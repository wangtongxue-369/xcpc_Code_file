/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
#define MAXN 1050
const ll base1 = 131;
const ll base2 = 127;

#define RATE_PER_HOUR 2 // 收费标准

typedef struct
{
    int year, month, day, hour, minute;
} DateTime;

typedef struct Car // 汽车节点
{
    char plate[32];
    DateTime time;
    struct Car *next;
} Car;

// 停车场栈top节点
Car *parking_top = NULL;
int parking_count = 0;
int car_v = 0;

// 便道队列首尾节点
Car *queue_front = NULL, *queue_rear = NULL;
int queue_count = 0;

int isLeapYear(int year)
{
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}
ll datetimeToMinutes(DateTime dt)
{
    int daysInMonth[12] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long long days = 0;

    for (int y = 1; y < dt.year; y++)
    {
        days += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < dt.month; m++)
    {
        days += daysInMonth[m - 1];
        if (m == 2 && isLeapYear(dt.year))
        {
            days += 1;
        }
    }

    days += (dt.day - 1);

    long long minutes = days * 24LL * 60LL;
    minutes += dt.hour * 60LL;
    minutes += dt.minute;

    return minutes;
}
// 打印时间
void print_datetime(DateTime dt)
{
    printf("%04d-%02d-%02d %02d:%02d", dt.year, dt.month, dt.day, dt.hour, dt.minute);
}

// 计算停车hour数
int calc_full_hours(DateTime entry, DateTime exit)
{
    ll t1 = datetimeToMinutes(entry);
    ll t2 = datetimeToMinutes(exit);
    double diff_min = t2 - t1;
    if (diff_min < 0)
        return -1;
    int hours = (int)(diff_min / 60.0);
    return hours;
}

// 新建节点
Car *new_car_node(const char *plate, DateTime dt)
{
    Car *c = (Car *)malloc(sizeof(Car));
    strncpy(c->plate, plate, 32 - 1);
    c->plate[32 - 1] = '\0';
    c->time = dt;
    c->next = NULL;
    return c;
}

// 停车场入栈
void push_parking(Car *node)
{
    node->next = parking_top;
    parking_top = node;
    parking_count++;
    printf("操作：车辆 %s 入栈（进入停车场），入场时间：", node->plate);
    print_datetime(node->time);
    printf("\n");
}

// 停车场出栈
Car *pop_parking()
{
    if (!parking_top)
        return NULL;
    Car *node = parking_top;
    parking_top = node->next;
    node->next = NULL;
    parking_count--;
    return node;
}

// 便道入队
void enqueue_wait(Car *node)
{
    node->next = NULL;
    if (!queue_rear)
    {
        queue_front = queue_rear = node;
    }
    else
    {
        queue_rear->next = node;
        queue_rear = node;
    }
    queue_count++;
    printf("操作：车辆 %s 入队（进入便道），到达时间：", node->plate);
    print_datetime(node->time);
    printf("\n");
}

// 便道出队
Car *dequeue_wait()
{
    if (!queue_front)
        return NULL;
    Car *node = queue_front;
    queue_front = node->next;
    if (!queue_front)
        queue_rear = NULL;
    node->next = NULL;
    queue_count--;
    return node;
}

// 便道查找对应车牌，如有则删除
Car *remove_from_waiting_by_plate(const char *plate)
{
    Car *prev = NULL, *cur = queue_front;
    while (cur)
    {
        if (strcmp(cur->plate, plate) == 0)
        {
            if (prev)
                prev->next = cur->next;
            else
                queue_front = cur->next;
            if (cur == queue_rear)
                queue_rear = prev;
            cur->next = NULL;
            queue_count--;
            return cur;
        }
        prev = cur;
        cur = cur->next;
    }
    return NULL;
}

// 停车场查找对应车牌
int exists_in_parking(const char *plate)
{
    Car *cur = parking_top;
    while (cur)
    {
        if (strcmp(cur->plate, plate) == 0)
            return 1;
        cur = cur->next;
    }
    return 0;
}

// 在便道中查找车牌是否存在
int exists_in_waiting(const char *plate)
{
    Car *cur = queue_front;
    while (cur)
    {
        if (strcmp(cur->plate, plate) == 0)
            return 1;
        cur = cur->next;
    }
    return 0;
}

// 显示停车场
void show_parking()
{
    if (!parking_top)
    {
        printf("停车场为空。\n");
        return;
    }

    Car *arr[1024];
    int cnt = 0;
    Car *cur = parking_top;
    while (cur && cnt < 1024)
    {
        arr[cnt++] = cur;
        cur = cur->next;
    }
    printf("停车场（从最里面->门口）：\n");
    if (cnt == 0)
    {
        printf("  （空）\n");
        return;
    }
    for (int i = cnt - 1; i >= 0; --i)
    {
        printf("  %s  入场：", arr[i]->plate);
        print_datetime(arr[i]->time);
        printf("\n");
    }
}

// 显示便道
void show_waiting()
{
    if (!queue_front)
    {
        printf("便道为空。\n");
        return;
    }
    printf("便道（从队首->队尾）：\n");
    Car *cur = queue_front;
    while (cur)
    {
        printf("  %s  到达：", cur->plate);
        print_datetime(cur->time);
        printf("\n");
        cur = cur->next;
    }
}

// 车辆到达
void car_arrival()
{
    char plate[32];
    DateTime dt;
    printf("请输入车牌（不含空格）：");
    if (scanf("%15s", plate) != 1)
    {
        while (getchar() != '\n')
            ;
        return;
    }
    printf("请输入到达时间（年 月 日 时 分）：");
    if (scanf("%d %d %d %d %d", &dt.year, &dt.month, &dt.day, &dt.hour, &dt.minute) != 5)
    {
        printf("时间输入错误，取消操作。\n");
        while (getchar() != '\n')
            ;
        return;
    }

    // 检查是否重复
    if (exists_in_parking(plate) || exists_in_waiting(plate))
    {
        printf("错误：车牌 %s 已存在于系统中（停车场或便道）。\n", plate);
        return;
    }

    Car *node = new_car_node(plate, dt);
    if (parking_count < car_v)
    {
        push_parking(node);
    }
    else
    {
        enqueue_wait(node);
    }
    printf("当前停车场占用：%d/%d，便道车辆：%d\n", parking_count, car_v, queue_count);
}

// 车辆离开
void car_departure()
{
    char plate[32];
    DateTime exit_dt;
    printf("请输入离开车辆车牌：");
    if (scanf("%15s", plate) != 1)
    {
        while (getchar() != '\n')
            ;
        return;
    }
    printf("请输入离开时间（年 月 日 时 分）：");
    if (scanf("%d %d %d %d %d", &exit_dt.year, &exit_dt.month, &exit_dt.day, &exit_dt.hour, &exit_dt.minute) != 5)
    {
        printf("时间输入错误，取消操作。\n");
        while (getchar() != '\n')
            ;
        return;
    }

    // 检查是否在便道
    Car *waiting_node = remove_from_waiting_by_plate(plate);
    if (waiting_node)
    {
        printf("车辆 %s 在便道上，直接离开，不收费。到达时间：", plate);
        print_datetime(waiting_node->time);
        printf("，离开时间：");
        print_datetime(exit_dt);
        printf("\n");
        free(waiting_node);
        return;
    }

    // 在停车场否
    if (!exists_in_parking(plate))
    {
        printf("未找到车牌 %s\n", plate);
        return;
    }

    Car *temp_top = NULL;
    int moved = 0;
    while (parking_top)
    {
        if (strcmp(parking_top->plate, plate) == 0)
        {
            Car *target = pop_parking();
            printf("操作：车辆 %s 出栈（离开停车场），入场时间：", target->plate);
            print_datetime(target->time);
            printf("，离场时间：");
            print_datetime(exit_dt);
            printf("\n");
            int hours = calc_full_hours(target->time, exit_dt);
            if (hours < 0)
            {
                printf("错误：离场时间早于入场时间或时间无效，取消离开操作。\n");
                // 恢复
                while (temp_top)
                {
                    Car *t = temp_top;
                    temp_top = temp_top->next;
                    push_parking(t);
                }
                free(target);
                return;
            }
            int fee = hours * RATE_PER_HOUR;
            printf("停车时长（完整小时）：%d，小计费用：%d\n", hours, fee);
            free(target);

            // 恢复
            while (temp_top)
            {
                Car *t = temp_top;
                temp_top = temp_top->next;
                push_parking(t);
            }
            moved = 1;
            break;
        }
        else
        {
            Car *m = pop_parking();
            printf("操作：车辆 %s 出栈（移至临时区），入场时间：", m->plate);
            print_datetime(m->time);
            printf("\n");
            m->next = temp_top;
            temp_top = m;
        }
    }

    if (!moved)
    {
        printf("未能找到目标车辆\n");
        // 恢复
        while (temp_top)
        {
            Car *t = temp_top;
            temp_top = temp_top->next;
            push_parking(t);
        }
        return;
    }

    // 如果便道有车，首辆进入停车场
    if (queue_front && parking_count < car_v)
    {
        Car *from_queue = dequeue_wait();
        from_queue->time = exit_dt;
        push_parking(from_queue);
        printf("便道车辆 %s 出队并进入停车场：", from_queue->plate);
        print_datetime(from_queue->time);
        printf("\n");
    }
}

void show_status()
{
    printf("---- 停车场状态 ----\n");
    printf("停车位：%d/%d\n", parking_count, car_v);
    show_parking();
    printf("\n");
    printf("便道车辆数：%d\n", queue_count);
    show_waiting();
    printf("---------------------\n");
}

// 主菜单
void menu_loop()
{
    while (1)
    {
        printf("\n===== 停车场管理菜单 =====\n");
        printf("1. 显示停车场状态\n");
        printf("2. 车辆到达\n");
        printf("3. 车辆离开\n");
        printf("4. 退出程序\n");
        printf("请选择（1-4）：");
        int choice;
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("输入无效，请重试。\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            show_status();
            break;
        case 2:
            car_arrival();
            break;
        case 3:
            car_departure();
            break;
        case 4:
            printf("退出程序，清理内存...\n");
            /* 释放所有剩余节点 */
            while (parking_top)
            {
                Car *t = pop_parking();
                free(t);
            }
            while (queue_front)
            {
                Car *t = dequeue_wait();
                free(t);
            }
            return;
        default:
            printf("无效选项，请输入1-4。\n");
        }
    }
}

int main()
{
    printf("请输入停车场车位总数 n：");
    if (scanf("%d", &car_v) != 1 || car_v <= 0)
    {
        printf("非法的停车位数量，程序退出。\n");
        return 1;
    }
    printf("每小时收费：%d（不满1小时不收费）。\n", RATE_PER_HOUR);
    menu_loop();
    printf("程序结束。\n");
    return 0;
}
