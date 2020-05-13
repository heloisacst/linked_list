// http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs1723/lecture4.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _student {
	int		    id;
	char		name[100];
	float		gpa;
} student;


// n�
typedef struct _node {
	student		   k;
	struct _node  *next; // ponteiro para o próximo elemento
} node, *list;


void insert_list (list *L, student k) {
	node	*p;
	p = (node *)malloc(sizeof(node));
	p->k = k;
	p->next = *L;

	*L = p;
}

student *search_list (list L, int id) {
	node	*p;

	for (p=L; p && p->k.id != id; p=p->next);

	if (p)
		return &p->k;
	else
		return NULL;
}

/* make an empty list */

void create_list (list *L) {
	*L = NULL;
}


int searchStudents() {
	
	system("@cls||clear");
	
	list		C;	/* a class of students */
	student		s, *p;
	int		    id;
	FILE		*f;

	f = fopen ("list.txt", "r"); //alterado nome arquivo
	if (!f) {
		perror ("List");
		exit (1);
	}

	create_list (&C);

	for (;;) {
		fscanf (f, "%d %s %f\n", &s.id, s.name, &s.gpa);
		if (feof (f))
      break;
		insert_list (&C, s);
	}
	fclose (f);

	for (;;) {
		printf ("Enter student ID: (0: voltar ao menu)");
		scanf("%d", &id);

		if (id == 0) //zero � mais f�cil
           main();

		p = search_list (C, id);


		if (!p)
			printf ("ID #%d not found!\n", id);
		else
			printf ("%d\t%s\t%0.2f\n", p->id, p->name, p->gpa);
	}
	exit (0);
}

int main(){ //inserido menu
	
	setlocale(LC_ALL, "Portuguese"); //inserido locale
	
	int opcao;
	
	do{
		printf("Escolha uma op��o\n\n");
		printf("1- Buscar Alunos\n");
		printf("2- Sair\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				searchStudents();
				break;
		}
	}
	
	while(opcao!=2);
}
