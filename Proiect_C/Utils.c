#include "Utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned short int Len(int value)
{
	unsigned int length = 0;
	while (value)
		++length, value /= 10;
	return length;
}

char* ToString(int value)
{
	char* str = (char*)malloc(sizeof(Len(value)) + 1);
	int count = 0;
	while (value)
	{
		str[count] = (value % 10) + '0';
		++count;
		value /= 10;
	}
	return str;
}

CV* CreateCV(Account* account)
{
	char string[500];
	CV* newCV = (CV*)malloc(sizeof(CV));
	newCV->lastName = account->lastName;

	newCV->firstName = account->firstName;

	printf("Introduceti numarul de telefon: ");
	scanf("%s", string);
	newCV->phoneNumber = (char*)malloc(strlen(string) * sizeof(char));
	strcpy(newCV->phoneNumber, string);

	printf("Introduceti adresa de email: ");
	scanf("%s", string);
	newCV->email = (char*)malloc(strlen(string) * sizeof(char));
	strcpy(newCV->email, string);

	printf("Introduceti domeniul in care activati: ");
	scanf("%s", string);
	newCV->domain = (char*)malloc(strlen(string) * sizeof(char));
	strcpy(newCV->domain, string);

	printf("Intoduceti o descriere: ");
	newCV->description = (char*)malloc(500 * sizeof(char));
    fflush(stdin);
	gets(string);
	strcpy(newCV->description, string);
	return newCV;
}

Account* CreateAccount()
{
	char string[50];
	Account* newAccount = (Account*)malloc(sizeof(Account));
	printf("Insert last name: ");
	scanf("%s", string);
	newAccount->lastName = (char*)malloc(strlen(string) * sizeof(char) + 1);
	strcpy(newAccount->lastName, string);
	
	
	printf("Insert first name: ");
	scanf("%s", string);
	newAccount->firstName = (char*)malloc(strlen(string) * sizeof(char) + 1);
	strcpy(newAccount->firstName, string);
	
	newAccount->ID = (int)RAND_MAX / rand() + ((newAccount->firstName[0] ^ 0xCF) * 100 + (newAccount->lastName[0] ^ 0xDC));
	
	printf("Insert password: ");
	scanf("%s", string);
	

	newAccount->password = (char*)malloc(sizeof(string) + 1);
	strcpy(newAccount->password, string);

	newAccount->cv = CreateCV(newAccount);

	newAccount->next = NULL;
	newAccount->prev = NULL;

	return newAccount;
}

AccountList CreateList()
{
	AccountList list;
	list.first = NULL;
	list.last = NULL;
	list.size = 0;
	return list;
}

void LS_AddAccount(AccountList* list)
{
	Account* newAccount = CreateAccount();
	if (list->first == NULL)
	{
		list->first = newAccount;
		list->last = newAccount;
		++list->size;
		return;
	}

	else
	{
		if (list->first == list->last)
		{
			list->last = newAccount;
			list->first->next = list->last;
			list->last->prev = list->first;
			return;
		}

		newAccount->prev = list->last;
		list->last = newAccount;
	}
}