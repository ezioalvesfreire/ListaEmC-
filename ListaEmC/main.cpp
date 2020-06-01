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
	novo = (node *) malloc (sizeof (node));
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


int main () {
	list		C;	/* a class of students */
	student		s, *novo;
	int		id;
	FILE		*arquivo;



	arquivo = fopen ("./List.txt", "r");
	if (!arquivo) {
		perror ("List");
		exit (1);
	}

	create_list (&C);

 while (!feof(arquivo)){
		fscanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);

		insert_list (&C, s);
	}
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
