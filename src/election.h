#include <stdio.h>
#include<gtk/gtk.h>


typedef struct {
char id[20];
int jour;
int mois;
int annee;
char gov[20];
int nbh;
char nbcs[20];
char muni[20];
char robot[20];
}election;

void ajouter_election( election e );
void modifier_election(election e);
int chercher(char * futil,char ch[]);
void affiche_election(GtkWidget *liste);
void supprimer_election(election e, char ch[] );


