#include<stdio.h>

int main() {
#include<stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

	typedef struct amout {
		float get;
		float pay;
	}amout;

	typedef struct node {
		amout amt;
		struct node* next;
	}node;

	node* head = NULL;

	void recordGet() {
		printf("Please enter the income data to be recorded\n");
		node* newNode = (node*)malloc(sizeof(node));
		newNode->next = NULL;
		if (head = NULL) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		float money;
		printf("Please enter��");
		scanf("%f", &money);
		newNode->amt.get = money;
		printf("\nPlease enter\n");
	}

	void recordPay() {
		printf("Please enter the expenditure data to be recorded\n");
		node* newNode = (node*)malloc(sizeof(node));
		newNode->next = NULL;
		if (head = NULL) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		float money;
		printf("Please enter��");
		scanf("%f", &money);
		newNode->amt.pay = money;
		printf("\nRecord success\n");
	}
	int main() {
		while (1) {
			printf("Please select the function of recording income or expenses\n");
			printf("1��Record income\n");
			printf("2��Record expenses\n");
			printf("0��quit");
			printf("Please press the option serial number.\n");
			char ch = getch();
			switch (ch) {
			case '1':
				recordGet();
				break;
			case'2':
				recordPay();
				break;
			case'0':
				printf("successful exit\n");
				return 0;
				break;
			}
		}

		return 0;

	}

	
	return;
}