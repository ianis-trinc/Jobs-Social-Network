#pragma once

typedef struct cv {
	char* lastName, * firstName;
	char* phoneNumber;
	char* email;
	char* description;
	char** skills;
	char* domain;
}CV;

typedef struct node {
	char* lastName, * firstName;
	unsigned int ID;
	char* password;
	CV* cv;
	struct node* next;
	struct node* prev;
}Account;

typedef struct list {

	Account* first;
	Account* last;
	unsigned int size;
}AccountList;

Account* CreateAccount();
AccountList CreateList();
void LS_AddAccount(AccountList* list);