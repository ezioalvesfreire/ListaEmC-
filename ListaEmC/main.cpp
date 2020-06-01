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

	for (;;) {
		fscanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);
		if (feof (arquivo))
      break;
		insert_list (&C, s);
	}
	fclose (arquivo);

	for (;;) {
		printf ("Informe ID do estudante, ou <-1> para finalizar: ");
		scanf ("%d", &id);

		if (id == -1)
       break;

		novo = search_list (C, id);


		if (!novo)
			printf ("ID #%d nao encontrado!\n", id);
		else
			printf ("%d\t%s\t%0.2f\n", novo->id, novo->name, novo->gpa);
	}
	exit (0);
}
