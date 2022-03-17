#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Utils.h"

int main()
{
	unsigned int choice;
	unsigned int id;
	char password[50];

	AccountList list = CreateList();

	while (true)
	{
		MainMeniu:
		system("cls");
		printf("=====================MENIU=====================\n");
		printf("1 -> Logare ( pentru conturi existente )\n");
		printf("2 -> Create cont\n");
		printf("3 -> Exit\n");
		scanf("%d", &choice);

		system("cls");
		switch (choice)
		{
		case 1:
			printf("Introduceti ID-ul: ");
			scanf("%d", &id);
			printf("Introduceti parola: ");
			scanf("%s", &password);
			// urmeaza implementare logarii 
			// daca logarea a avut loc cu succes goto: AccountMeniu
			goto AccountMeniu;
			system("pause");
			break;
		case 2:
			LS_AddAccount(&list);
			printf("\n");
			system("pause");
			break;
		case 3:
			system("cls");
			goto Exit;
		default:
			printf("def\n");
			system("pause");
			break;
		}
	AccountMeniu:
		system("cls");
		printf("=====================Account Meniu=====================\n");
		printf("1 -> Vizualizare CV\n");
		printf("2 -> Vizualizare utilizatori\n");
		printf("3 -> Cautare dupa cuvant cheie\n");
		printf("4 -> Log Out si revenire la meniul principal\n");
		printf("5 -> Afiseaza datele contului: \n");
		printf("6 -> Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			system("cls");
			printf("....Vizualizare CV.....\n");
			system("pause");
			break;
		case 2:
			system("cls");
			printf(".....Vizualizare utilizatori ( ID, Nume si Prenume )......\n");
			system("pause");
			break;
		case 3:
			system("cls");
			char word[10];
			printf("Introduceti cuvantul cheie: ");
			scanf("%s", &word);
			printf(".....Vizualizare CV-uri care contin cuvantul cheie......\n");
			system("pause");
			break;
		case 4:
			system("cls");
			goto MainMeniu;
			break;
		case 5:
			system("cls");
			printf("Nume: %s\nPrenume: %s\nID: %d\n", list.last->lastName, list.last->firstName, list.last->ID);
			system("pause");
			break;
		case 6:
			system("cls");
			goto Exit;
			break;
		default:
			break;
		}
		goto AccountMeniu;
		system("pause");
	}
Exit:
	system("exit");
}