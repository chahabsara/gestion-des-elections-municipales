#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct observateur
{
char id [20];
char nom [20];
char prenom [20];
char nationalite [20];
char profession [20];
char sexe [20];
char gouvernerat [20];
int nbv;

} observateur ;

void afficher_observateur(GtkWidget *liste,char *fname);
void ajouterh(observateur o);
void modifierh(observateur o );
void supprimerh(char identifiant[]);
int verif(char identifiant[]);
void chercherh(GtkWidget *liste, char identifiant[]);
int rech_id(char id[]);
observateur findObsById(char id[]);
int nbrobservateurstot();
//void ttaux ( char filename[20],float *tn,float*te);
void tone ( char* filename,int *tn, int *te);



#endif
