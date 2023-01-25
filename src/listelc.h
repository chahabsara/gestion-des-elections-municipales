
#include <stdio.h>
#include<gtk/gtk.h>


typedef struct{
    int j;
    int m;
    int a;
    }datech;

typedef struct{
    char id[30];// not vide 
    char idt[30];
    char orient[20];//not vide
    char n1[30];
    char n2[30];
    char n3[30];
    datech dch;
    char genre[20];
    int nbvote;
    }liste;


void ajouter(liste l);
void modifierch(liste nouv);
void supprimer(char id[]);
int chercherch(char id[]);
liste findlById(char id[]);
int modifierl(int id,liste nouv );
void afficherliste(GtkWidget *liste,char *fname);
void afficherlistelc(GtkWidget *liste,char *fname);
/*int vote(char file[], int id);
void tri(char file1[],char file2[]);
// la recherche multicritere chercher id des liste dont l orientation gauche et tete de liste sont femme


#endif // LISTELC_H_INCLUDED

%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste)*/





