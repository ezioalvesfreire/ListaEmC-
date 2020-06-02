// http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs1723/lecture4.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
	int		  id;
	char		name[100];
	float		gpa;
	struct _student* next;
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

 FILE* abreArquivo(char caminho[30], char caso){
    FILE *arquivo;
  // char caso = 'l';
    switch(caso){

        case'l':
            arquivo = fopen (caminho,"r");
        break;
        case'g':
            printf("caso <g> gravação em desenvolvimento!\n");
            arquivo = fopen (caminho,"wt");
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
                printf("VOLTANDO PARA O MENU...");                             
            }else if (!novo){
                  printf ("ID #%d nao encontrado!\n", id);
            }

		else{
            printf ("%d\t%s\t%0.2f\n", novo->id, novo->name, novo->gpa);
		}

	}
	 while (id !=0);
}

void insereH(int id, char n[100], float gpa, student **topo){ // int id, char n[100], float gpa, student **head   //student **head, int id, char n[], float gpa
    student *novo;
    novo =(student*) malloc(sizeof(student));
  //----------------------------------------------------------------------
     printf("informe a ID do Aluno\n");
      //  scanf("%d",&id);
         scanf("%d",&novo->id);
       /// fprintf(arquivo,"%d ",&s.id);

        printf("informe o nome do Aluno\n");
      //  scanf("%s", s.name);
        scanf("%s", &novo->name);
      ///  fprintf(arquivo,"%s ",s.name);

        printf("Informe a GPA do Aluno\n");
      //  scanf("%.20f ",&s.gpa);
         scanf("%.20f ",&novo->gpa);

      ///  fprintf(arquivo, "%f", &s.gpa);
  //------------------------------------------------------------

    novo->id = id;
    novo->name[100] = n[100];
    novo->gpa = gpa ;

    if(*topo == NULL){
            novo->next = NULL;

            *topo = novo;
    }else{
            novo->next = *topo;
            *topo = novo;
    }
     system("pause");
}
int main () {
	list		C;	/* a class of students */
	student		s, *novo;
	int		id;
	FILE		*arquivo;
	int opcao;
	char caso = 'l';

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
        	 arquivo = abreArquivo(caminho, caso);
             create_list (&C);
             carregarDados(arquivo, C, s);
             buscarEstudante(id, novo, C);
             fecharArquivo(arquivo);
             
            break;

        case 2:
        	caso = 'g';
        	 arquivo = abreArquivo(caminho, caso);
             create_list (&C);
             carregarDados(arquivo, C, s);
                    // buscarEstudante(id, novo, C);
            //	insereH(student);
            fecharArquivo(arquivo);
            system("pause");
        break;
        case 3:
          
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

