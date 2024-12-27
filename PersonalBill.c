#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义账单结构体
typedef struct {
    char date[11];
    int amount;
    char category[20];
    char note[50];
} Bill;

// 函数声明
void recordIncome(Bill *bills, int *count);
void recordExpense(Bill *bills, int *count);
void viewAllBills(Bill *bills, int count);
void queryBill(Bill *bills, int count);
void setMonthlyBudget();
void viewMonthlyReport();
void exitSystem();

int main() {
    Bill bills[100];
    int count = 0;
    int choice;

    do {
        printf("欢迎使用个人账单管理系统\n");
        printf("1. 记录收入\n");
        printf("2. 记录支出\n");
        printf("3. 查看所有账单\n");
        printf("4. 查询账单\n");
        printf("5. 设置月度预算\n");
        printf("6. 查看月度统计报告\n");
        printf("7. 退出系统\n");
        printf("请输入选项序号: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordIncome(bills, &count);
                break;
            case 2:
                recordExpense(bills, &count);
                break;
            case 3:
                viewAllBills(bills, count);
                break;
            case 4:
                queryBill(bills, count);
                break;
            case 5:
                setMonthlyBudget();
                break;
            case 6:
                viewMonthlyReport();
                break;
            case 7:
                exitSystem();
                break;
            default:
                printf("无效的选项，请重新输入。\n");
        }
    } while (choice!= 7);

    return 0;
}


void recordIncome(Bill *bills, int *count) {
    Bill newBill;
    printf("请输入收入信息:\n");
    printf("日期(YYYY - MM - DD): ");
    scanf("%s", newBill.date);
    printf("金额: ");
    scanf("%d", &newBill.amount);
    printf("类别(如工资、奖金等): ");
    scanf("%s", newBill.category);
    printf("备注: ");
    scanf("%s", newBill.note);

    bills[*count] = newBill;
    (*count)++;
    printf("收入已成功记录!\n");
}

void recordExpense(Bill *bills, int *count) {
    Bill newBill;
    printf("请输入支出信息:\n");
    printf("日期(YYYY - MM - DD): ");
    scanf("%s", newBill.date);
    printf("金额: ");
    scanf("%d", &newBill.amount);
    printf("类别(如餐饮、购物等): ");
    scanf("%s", newBill.category);
    printf("备注: ");
    scanf("%s", newBill.note);

    bills[*count] = newBill;
    (*count)++;
    printf("支出已成功记录!\n");
}

// 查看所有账单函数
void viewAllBills(Bill *bills, int count) {
    printf("所有账单记录:\n");
    for (int i = 0; i < count; i++) {
        printf("日期: %s, 金额: %d, 类别: %s, 备注: %s\n",
               bills[i].date, bills[i].amount, bills[i].category, bills[i].note);
    }
}

// 查询账单函数
void queryBill(Bill *bills, int count) {
    char queryDate[11];
    printf("请输入要查询的日期(YYYY - MM - DD): ");
    scanf("%s", queryDate);
    for (int i = 0; i < count; i++) {
        if (strcmp(queryDate, bills[i].date) == 0) {
            printf("日期: %s, 金额: %d, 类别: %s, 备注: %s\n",
                   bills[i].date, bills[i].amount, bills[i].category, bills[i].note);
        }
    }
}

// 设置月度预算函数
void setMonthlyBudget() {
    int budget;
    printf("请输入月度预算: ");
    scanf("%d", &budget);
    printf("月度预算已设置为: %d\n", budget);
}

// 查看月度统计报告函数
void viewMonthlyReport() {
    printf("查看月度统计报告功能暂未实现。\n");
}

// 退出系统函数
void exitSystem() {
    printf("正在退出系统...\n");
    exit(0);
}