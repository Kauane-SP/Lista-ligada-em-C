#include <stdio.h>
#include <windows.h>
#include <conio.h>

struct LISTA {
	int num;
	LISTA * prox;
};
	LISTA * insere_inicio(LISTA * inicio){
		LISTA * novo = new LISTA();
		printf("Informe um numero:");
		scanf("%d",&novo->num);
		if (inicio==NULL) {
			inicio = novo;
			inicio->prox=NULL;
		}else{
			novo->prox = inicio;
			inicio = novo;
		}
		return inicio;
	}
	LISTA * insere_fim(LISTA * inicio){
		LISTA * aux;
		LISTA * novo = new LISTA();
		printf("Informe um numero:");
		scanf("%d", & novo->num);
		if(inicio == NULL){
			inicio = novo;
			inicio->prox=NULL;
			
		}else{
			aux = inicio;
			while (aux->prox!=NULL){
				aux=aux->prox;
			}
			aux-> prox = novo;
			novo->prox = NULL;
		}
		return inicio;
	}
	LISTA * remove_lista(LISTA * inicio){
		int numero, achou=0;
		LISTA * aux;
		LISTA * anterior;
		printf("Informe um numero que deseja remover");
		scanf("%d",& numero);
		if(inicio == NULL){
			printf("A lista vazia");	
		}else{
			aux = inicio;
			anterior = inicio;
			while(aux != NULL){
				if(numero == aux ->num){
					if (aux== inicio){
						inicio = aux ->prox;
						delete(aux);
						aux = inicio;
					}else{
						anterior->prox = aux->prox;
						delete(aux);
						aux = anterior->prox;
					}
					achou++;
				}else {
					anterior = aux;
					aux = aux->prox;
				}
			}
			if (achou == 0){
				printf("\nNumero nao encontrado");
			}else{
				printf("\n Numero Removido %d vezes", achou);
			}
		}
		return inicio;
	}
	
	int varre_lista(LISTA * inicio){
		int i= 0;
			LISTA * aux = inicio;
			while(aux != NULL)
			{
				i ++;
				aux = aux -> prox;
			}
				return i;
	}
	void busca_lista(LISTA * inicio, int elemento){
		int achou = 0;
		if (inicio ==NULL)
		printf("\n A lista vazia");
		else{
			LISTA * aux;
			printf("\nLista: ");
			aux = inicio;
			while (aux != NULL){
				if(elemento == aux -> num)
				{
					achou=1;
					break;
				}
				aux = aux->prox;
			}
		}
		if(achou == 1){
		printf("O elemento na lista");
		}
		else{
		printf("O elemento nao esta na lista");
		}
	}
	int main()
	{
		LISTA * inicio = NULL;
		int menu, elemento;
		do {
			system("cls");
			printf("\nMenu de Opções");
			printf("\n1 - Inserir um numero no inicio da lista");
			printf("\n2 - Inserir um numero no final da lista");
			printf("\n3 - Remover um numero da lista");
			printf("\n4 - Buscar um Elemento na lista");
			printf("\n5 - Mostrar tamanho da lista ");
			printf("\n  - Qual a opcao desejada?");
			scanf("%d", & menu);
			switch(menu){
				case 1:
					inicio = insere_inicio(inicio);
					break;
				case 2:
					inicio = insere_fim(inicio);
					break;
				case 3:
					inicio = remove_lista(inicio);
					break;
				case 4:
					printf("Informe o elemento que deseja buscar:");
					scanf("%d",& elemento);
					busca_lista(inicio,elemento);
				case 5:
				int tamanho = varre_lista(inicio);
				printf("A lista contem : %d elementos", tamanho);
				break;
			}
		getch();
		} while (menu !=5);
	}
	
		

