#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����˵��ṹ��
typedef struct {
    char date[11];
    int amount;
    char category[20];
    char note[50];
} Bill;

// ��������
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
        printf("��ӭʹ�ø����˵�����ϵͳ\n");
        printf("1. ��¼����\n");
        printf("2. ��¼֧��\n");
        printf("3. �鿴�����˵�\n");
        printf("4. ��ѯ�˵�\n");
        printf("5. �����¶�Ԥ��\n");
        printf("6. �鿴�¶�ͳ�Ʊ���\n");
        printf("7. �˳�ϵͳ\n");
        printf("������ѡ�����: ");
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
                printf("��Ч��ѡ����������롣\n");
        }
    } while (choice!= 7);

    return 0;
}


void recordIncome(Bill *bills, int *count) {
    Bill newBill;
    printf("������������Ϣ:\n");
    printf("����(YYYY - MM - DD): ");
    scanf("%s", newBill.date);
    printf("���: ");
    scanf("%d", &newBill.amount);
    printf("���(�繤�ʡ������): ");
    scanf("%s", newBill.category);
    printf("��ע: ");
    scanf("%s", newBill.note);

    bills[*count] = newBill;
    (*count)++;
    printf("�����ѳɹ���¼!\n");
}

void recordExpense(Bill *bills, int *count) {
    Bill newBill;
    printf("������֧����Ϣ:\n");
    printf("����(YYYY - MM - DD): ");
    scanf("%s", newBill.date);
    printf("���: ");
    scanf("%d", &newBill.amount);
    printf("���(������������): ");
    scanf("%s", newBill.category);
    printf("��ע: ");
    scanf("%s", newBill.note);

    bills[*count] = newBill;
    (*count)++;
    printf("֧���ѳɹ���¼!\n");
}

// �鿴�����˵�����
void viewAllBills(Bill *bills, int count) {
    printf("�����˵���¼:\n");
    for (int i = 0; i < count; i++) {
        printf("����: %s, ���: %d, ���: %s, ��ע: %s\n",
               bills[i].date, bills[i].amount, bills[i].category, bills[i].note);
    }
}

// ��ѯ�˵�����
void queryBill(Bill *bills, int count) {
    char queryDate[11];
    printf("������Ҫ��ѯ������(YYYY - MM - DD): ");
    scanf("%s", queryDate);
    for (int i = 0; i < count; i++) {
        if (strcmp(queryDate, bills[i].date) == 0) {
            printf("����: %s, ���: %d, ���: %s, ��ע: %s\n",
                   bills[i].date, bills[i].amount, bills[i].category, bills[i].note);
        }
    }
}

// �����¶�Ԥ�㺯��
void setMonthlyBudget() {
    int budget;
    printf("�������¶�Ԥ��: ");
    scanf("%d", &budget);
    printf("�¶�Ԥ��������Ϊ: %d\n", budget);
}

// �鿴�¶�ͳ�Ʊ��溯��
void viewMonthlyReport() {
    printf("�鿴�¶�ͳ�Ʊ��湦����δʵ�֡�\n");
}

// �˳�ϵͳ����
void exitSystem() {
    printf("�����˳�ϵͳ...\n");
    exit(0);
}