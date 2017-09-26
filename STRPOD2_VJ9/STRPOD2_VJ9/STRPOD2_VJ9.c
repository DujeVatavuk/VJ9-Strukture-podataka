/*
Napisati program koji èita iz datoteke dio teksta, te kreira binarno stablo pretraživanja. Binarno stablo se //DIO TEKSTA, JA SAM ODABRA CITAT MAX 50 RICI, AKO IMA VISE TO NECE BI PROCITANO
kreira na naèin da se u njega upisuju sve razlièite rijeèi iz teksta koji je zapisan u datoteci s pripadajuæim
duljinama unesene rijeèi.
struct _Cvor{char *rijec; int length; struct _Cvor *Left; struct _Cvor *Right;};
Potrebno je izraèunati prosjeènu duljinu svake rijeèi zapisane u binarnom stablu.
Napisati program koji iz tako kreiranog binarnog stabla u vezanu listu puni samo one rijeèi koje su dulje
od prosjeène duljine svih rijeèi, te ispisati tu vezanu listu.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct stablo *node;
typedef struct stablo
{
	char *rijec;
	int lenght;
	node left;
	node right;
}stablo;

typedef struct lista *pos;
typedef struct lista
{
	char *rijec;
	pos next;
}lista;

node unosIzFilea(char pracenje[][50], node, int*);//ez radi i sa int bez "*"
node unosUStablo(node, node);
void printInline(node);
node unosIzStablaUListu(float, node, pos);
void printListu(pos);

int main()
{
	node root = NULL;
	lista head;
	head.next = NULL;
	char pracenje[50][50];
	int i = 0, *p = &i;
	float prosjek;//da nebi bilo komplikacija necu gledat koliko je rijeci uneseno nego cu po defaultu racunat ka da je 50

	root = unosIzFilea(pracenje, root, p);
	printInline(root);
	prosjek = (float)i / 50;
	printf("\n\n%f\n", prosjek);
	root = unosIzStablaUListu(prosjek, root, &head);
	printListu(&head);
	printf("\n");
	return 0;
}

node unosIzFilea(char pracenje[][50], node S, int *p)
{
	FILE *dat;
	dat = fopen("Text.txt", "r");
	int b = 0, check = 1;
	*p = 0;
	char word[50];
	while (!feof(dat) && b < 50)
	{
		node temp = (node)malloc(sizeof(stablo));
		fscanf(dat, " %s", word);
		check = 1;
		for (int i = 0; i < b; i++)
		{
			if (strcmp(pracenje[i], word) == 0)
			{
				check = 0;
				break;
			}
		}
		if (check)
		{
			temp->lenght = strlen(word);
			*p += temp->lenght;
			temp->rijec = malloc(temp->lenght * sizeof(char));//ode ispred malloca dodat (char) ili ekvivalent
			strcpy(temp->rijec, word);
			S = unosUStablo(temp, S);
			b++;//OVO BI MOZDA TREBALO BITI IZVAN IFA, PROVJERI
		}
	}
	fclose(dat);
	return S;
}

node unosUStablo(node temp, node S)
{
	if (NULL == S)
	{
		S = (node)malloc(sizeof(stablo));
		S->left = NULL;
		S->right = NULL;
		S->lenght = temp->lenght;
		S->rijec = malloc(S->lenght * sizeof(char));
		strcpy(S->rijec, temp->rijec);
	}
	else if (strcmpi(S->rijec, temp->rijec) > 0)
	{
		S->left = unosUStablo(temp, S->left);
	}
	else if (strcmpi(S->rijec, temp->rijec) < 0)
	{
		S->right = unosUStablo(temp, S->right);
	}
	return S;
}

void printInline(node S)
{
	if (NULL != S)
	{
		printInline(S->left);
		printf("\n%s %d", S->rijec, S->lenght);
		printInline(S->right);
	}
}

node unosIzStablaUListu(float f, node S, pos P)
{
	if (NULL != S)
	{
		unosIzStablaUListu(f, S->left, P);
		if ((int)f < S->lenght)
		{
			pos temp = (pos)malloc(sizeof(lista));
			temp->rijec = malloc(S->lenght * sizeof(char));
			strcpy(temp->rijec, S->rijec);
			temp->next = P->next;
			P->next = temp;
		}
		unosIzStablaUListu(f, S->right, P);
	}
}

void printListu(pos P)
{
	P = P->next;
	while (NULL != P)
	{
		printf("\n\t%s", P->rijec);
		P = P->next;
	}
}