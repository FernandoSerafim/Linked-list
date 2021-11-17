#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
   int idade;
   struct no* prox;
}NO;

NO* novo_no()
{
    NO* novo = malloc(sizeof(NO));
    return novo;
}

NO* insere_inicio(NO* lista)
{
    NO* aux = novo_no();

    printf("digite a idade da pessoa a ser inserida\n");
    scanf("%d", &aux->idade);

    if(lista == NULL)
    {
        lista = aux;
        aux->prox = NULL;
    }else{
        aux->prox = lista;
        lista = aux;
    }
return lista;
}

void exibe_lista(NO* lista)
{
    NO* auxiliar = lista;

    if(lista == NULL) printf("A LISTA ESTA VAZIA\n");
    else{
        while(auxiliar != NULL){
            printf("A idade da pessoa e: %d\n\n", auxiliar->idade);
            auxiliar = auxiliar->prox;
        }
    }
}

NO* exclui_elemento(NO* lista)
{
    NO* auxiliar = lista;
    NO* auxiliar2 = NULL;

    int recebeIdade;

    printf("Digite a idade da pessoa que deseja deletar\n");
    scanf("%d", &recebeIdade);

        while(recebeIdade != auxiliar->idade && auxiliar != NULL){

            auxiliar2 = auxiliar;
            auxiliar = auxiliar->prox;

        }

    if(auxiliar == NULL) return lista;

    if(auxiliar2 == NULL) lista = auxiliar->prox;
    else auxiliar2->prox = auxiliar->prox;


free(auxiliar);
auxiliar = NULL;
return lista;
}

int main()
{
    NO* lista = NULL; 
    
    lista = insere_inicio(lista);
    lista = insere_inicio(lista);
    lista = insere_inicio(lista);
    exibe_lista(lista);
    lista = exclui_elemento(lista);
    exibe_lista(lista);

    free(lista);
    lista = NULL;
    return 0;
}
