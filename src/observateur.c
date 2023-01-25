#include "observateur.h"
#include <string.h>
#include <gtk/gtk.h>
enum
{
	EID,
	ENOM,
	EPRENOM,
	ENATIONALITE,
	EPROFESSION,
	ESEXE,
	EGOUVERNERAT,
	ENBV,
	COLUMNS,
};

//---------------------------------------------------fonction_afficher-----------------------------------------------------//

void afficher_observateur(GtkWidget *liste,char *fname)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

	char id [20];
	char nom [20];
	char prenom [20];
	char nationalite [20];
        char profession [20];
	char sexe [20];
	char gouvernerat [20];
	char nbv[20];
observateur o;

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Nationalite",renderer,"text",ENATIONALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Profession",renderer,"text",EPROFESSION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Gouvernerat",renderer,"text",EGOUVERNERAT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Numero de bureau de vote",renderer,"text",ENBV,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);

f=fopen("observateur.txt","r");

if(f==NULL)
{
return;
}
else
{
f = fopen("observateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %d \n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,&o.nbv)!=EOF)
{


gtk_list_store_append(store,&iter);
    gtk_list_store_set(store,&iter,EID,o.id,ENOM,o.nom,EPRENOM,o.prenom,ENATIONALITE,o.nationalite,EPROFESSION,o.profession,ESEXE,o.sexe,EGOUVERNERAT,o.gouvernerat,ENBV,o.nbv,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


//-----------------------------------------------fonction_ajouter-----------------------------------------------------------//
void ajouterh(observateur o){
    FILE *f=NULL;

    f = fopen("observateur.txt","a+");
    if(f!= NULL){
        fprintf(f,"%s %s %s %s %s %s %s %d \n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,o.nbv);
    fclose(f);
    }
    


}
//-----------------------------------------------fonction_modifier------------------------------------------------------------//
void modifierh(observateur o)

{
	observateur o2;
	FILE *f,*g;
        

f=fopen("observateur.txt","r");
g=fopen("obs2.txt","w");
    if((f==NULL) && (g==NULL))
{
    return;}
    else
{



    while (fscanf (f,"%s %s %s %s %s %s %s %d \n",o2.id,o2.nom,o2.prenom,o2.nationalite,o2.profession,o2.sexe,o2.gouvernerat,&o2.nbv)!=EOF)
    {
      	if (strcmp(o.id,o2.id)!=0)
          fprintf(g,"%s %s %s %s %s %s %s %d \n",o2.id,o2.nom,o2.prenom,o2.nationalite,o2.profession,o2.sexe,o2.gouvernerat,o2.nbv);
        else
          fprintf(g,"%s %s %s %s %s %s %s %d \n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,o.nbv);
    }
   fclose(f);
   fclose(g);
remove("observateur.txt");
rename("obs2.txt","observateur.txt");       
}
}
//-----------------------------------------------------------supprimer-----------------------------------------------------//
void supprimerh(char identifiant[])
{
    observateur o;
FILE *f , *g;
    f=fopen("observateur.txt","r");
    g=fopen("dump.txt","a");
   if(f!=NULL || g!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,&o.nbv)!=EOF)
        {
            if(strcmp(o.id,identifiant) != 0)
            fprintf(g,"%s %s %s %s %s %s %s %d \n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,o.nbv);
        }
    }
fclose(f);
fclose(g);
remove("observateur.txt");
rename("dump.txt","observateur.txt");
}
//-----------------------------------------------------------verifier---------------------------------------------------//

int verif(char identifiant[])
{
	FILE *f=NULL;
	f=fopen("observateur.txt","r");
	int trouve=1;
	observateur o;
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,&o.nbv)!=EOF)
		{	
			if (strcmp(o.id,identifiant)==0)
			{
				trouve=0;
			}
		}
fclose(f);
	}
return trouve;
}
//-----------------------------------------------------------recherche--------------------------------------------------//
void chercherh(GtkWidget *liste, char identifiant[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


observateur o;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Nationalite",renderer,"text",ENATIONALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Profession",renderer,"text",EPROFESSION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Gouvernerat",renderer,"text",EGOUVERNERAT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Numero de bureau de vote",renderer,"text",ENBV,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);

f=fopen("observateur.txt","r");

if(f==NULL)
{
return;
}
else
{
f = fopen("observateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %d \n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,&o.nbv)!=EOF)
{
     if (strcmp(o.id,identifiant)==0)
gtk_list_store_append(store,&iter);
    gtk_list_store_set(store,&iter,EID,o.id,ENOM,o.nom,EPRENOM,o.prenom,ENATIONALITE,o.nationalite,EPROFESSION,o.profession,ESEXE,o.sexe,EGOUVERNERAT,o.gouvernerat,ENBV,o.nbv,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
//---------------------------------------------------------stat_1------------------------------------------------------------//


int nbrobservateurstot()
{
    observateur o;
    int nbo=0 ;
    FILE *f;
    f = fopen("observateur.txt","r");
    while(fscanf(f,"%s %s %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,&o.nbv) != EOF)
{
          
          nbo++;
}
return nbo;
}


//---------------------------------------------------------rech_id-----------------------------------------------------------//
int rech_id(char id[]){

  observateur o ;
  FILE *f;
  f=fopen("observateur.txt","r");
  while(fscanf(f,"%s %s %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,&o.nbv) != EOF){
      if(strcmp(o.id,id) == 0){
        return 1 ; 
}
      }
return 0 ;

}
//------------------------------------------------------findObsbyId-----------------------------------------------------------//
observateur findObsById(char id[])
{

  observateur o ;
  FILE *f;
  f=fopen("observateur.txt","r");
  while(fscanf(f,"%s %s %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.nationalite,o.profession,o.sexe,o.gouvernerat,&o.nbv) != EOF){
      if(strcmp(o.id,id) == 0){
        return o ; 
}
      }
return  ;

}


