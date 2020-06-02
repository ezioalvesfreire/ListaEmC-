// http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs1723/lecture4.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
	int		  id;
	char		name[100];
	float		gpa;
} student;


// nó
typedef struct _node {
	student		k;
	struct _node	*next; // ponteiro para o próximo elemento
} node, *list;


void insert_list (list *topo, student k) {
	node	*novo;
	novo = (node*) malloc (sizeof (node));
	novo->k = k;
	novo->next = *topo;

	*topo = novo;
}

student *search_list (list topo, int id) {
	node	*novo;

	for (novo=topo; novo && novo->k.id != id; novo=novo->next);

	if (novo)
		return &novo->k;
	else
		return NULL;
}

/* make an empty list */

void create_list (list *L) {
	*L = NULL;
}

 FILE* abreArquivo(char caminho[30]){
    FILE *arquivo;
   char caso = 'l';
    switch(caso){

        case'l':
            arquivo = fopen (caminho,"r");
        break;
        case'g':
            printf("caso <g> gravação em desenvolvimento!");
            system("pause");
        break;
        case'a':
            printf("caso <a> append em desenvolvimento!");
            system("pause");
        break;
        default:
            printf("opção invalida");
    }


	if (arquivo == NULL){
            printf("Nao foi possivel abrir o arquivo");
			exit (1);
	}
	return arquivo;
   }
void fecharArquivo(FILE *arquivo){
    fclose(arquivo);
}

carregarDados(FILE *arquivo, list &C, student s){
while (!feof(arquivo)){
		fscanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);

		insert_list (&C, s);
	}
}

buscarEstudante(int id, student *novo, list C){
		do{
		 printf("\n");
         printf ("Informe a ID do estudante:");
         printf("\n");
         printf ("Voltar ao MENU digite 0(zero)");
         printf("\n");
         scanf ("%d", &id);

         novo = search_list (C, id);
		if (id == 0)
            {
                printf("VOLTANDO PARA O MENU...");                              // modularizr como buscarEstudante
            }else if (!novo){
                  printf ("ID #%d nao encontrado!\n", id);
            }

		else{
            printf ("%d\t%s\t%0.2f\n", novo->id, novo->name, novo->gpa);
		}

	}
	 while (id !=0);
}
//}
int main () {
	list		C;	/* a class of students */
	student		s, *novo;
	int		id;
	FILE		*arquivo;
	int opcao;

	char caminho[30] = "./List.txt";
	
printf("============================LISTA ENCADEADA==========================\n\n");

  //  arquivo = abreArquivo(caminho);
  // create_list (&C);
  //  carregarDados(arquivo, C, s);
  //  buscarEstudante(id, novo, C);
    
    do{

    printf("\n\tMENU\n");

     printf("informe a opcao desejada\n");
    printf("\n1 - Consultar estudante digite 1");
    printf("\n2 - Cadastrar estudante digite 2");
    printf("\n3 - Listar estudantes digite 3");
    printf("\n4 - sair 4\n\n");

    scanf("%d", &opcao);
   system( "clear||cls");

    switch(opcao){
        case 1:
        	 arquivo = abreArquivo(caminho);
             create_list (&C);
             carregarDados(arquivo, C, s);
             buscarEstudante(id, novo, C);
          // buscarEstudante(opcao, arquivoTexto, textoAux);
        break;

        case 2:
           // buscarEstudante(opcao, arquivoTexto, textoAux );
       // cadastrarEstudante();
         system("pause");
        break;
        case 3:
            // buscarEstudante(opcao, arquivoTexto, textoAux);
           // printf("caso 3 em desenvolvimento!!!\n");
           // system("pause");
        break;
        case 4:
            printf("SAINDO...\n");
            system("pause");
        break;
        default:
            printf("opcao invalida\n");

         system("pause");

     }
     	system("@cls||clear");

}while(opcao != 4);

}

