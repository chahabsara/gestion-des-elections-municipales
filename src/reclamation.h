#ifndef __REECLAMATION__H__
#define __RECLAMATION__H__
typedef struct{
    int j;
    int m;
    int a;
}date;
typedef struct{
    char nom[30];//not vide 
    char prenom[30];//not vide
    char cin[20];//de 8 chiffre
    char type[30];  
    date d  ;
    char description[100];//not vide
    char genre[20];
    int nbreliste ;

}Reclamation;


void ajouter_reclamation(Reclamation r);
void supprimer_reclamation(char cin[]);
void afficher_reclamation(GtkWidget *liste,char *fname);
void modifier_reclamation(Reclamation o);


int chercher_reclamation(char cin[]);
Reclamation findRecById(char cin[]);

int nbreclamation(int nbrl);
int nbreclamationtot();
//recherche multi critere nbliste dont type finance et utilisateurs homme 
void recherche_multi_critere();

void trierReclamtion();
void filtrerReclamationType(char type[]);
void filtrerReclamationNB(int nb);

		
		
#endif
