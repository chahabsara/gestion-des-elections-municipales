#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>

typedef struct
{
	int jour;
	int mois;
	int annee;
}datefr;


//typedef struct 
 //char entree[30];
 //char plat_principal[30];
//char dessert[30];
//}contenu;//

typedef struct //struct capteur
{
char nomecole[50];
int idbureau;
char idagent[50];
datefr datef;
int type;
int capelect;
int capobs;
}bureau;

void ajout_bureau(bureau c);
void affichage(bureau t);
int supprimer_bureau(int ref);
void modifier(int refmodif,bureau c);
int cherche_id(int ref);
void afficher_bureau (GtkWidget * liste);
void vider (GtkWidget *liste);
