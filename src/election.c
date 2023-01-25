#include<gtk/gtk.h>
#include"election.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum
{
	EID,
	EJOUR,
	EMOIS,
	EANNEE,
	EGOV,
	ENBH,
	ENBCS,
	EMUNI,
	EROBOT,
	COLUMNS,
};
//ajout
void ajouter_election( election e ) {
     FILE *f;
  f=fopen("election.txt","a+");
    if(f!=NULL)
    {
fprintf(f,"%s %d %d %d %s %d %s %s %s\n",e.id,e.jour,e.mois,e.annee,e.gov,e.nbh,e.nbcs,e.muni,e.robot);

     fclose(f);
              }
}
//modif
void modifier_election(election e)
{

FILE *f=NULL,*f2;
f=fopen("election.txt","r");
f2=fopen("nouv.txt","a+");
election el;
if (f!=NULL)
{
while (fscanf(f,"%s %d %d %d %s %d %s %s %s\n",el.id,&el.jour,&el.mois,&el.annee,el.gov,&el.nbh,el.nbcs,el.muni,el.robot )!= EOF)
{
if (strcmp(e.id,el.id)==0)
{
fprintf(f2,"%s %d %d %d %s %d %s %s %s\n",e.id,e.jour,e.mois,e.annee,e.gov,e.nbh,e.nbcs,e.muni,e.robot) ;
}
else
{
fprintf(f2,"%s %d %d %d %s %d %s %s %s\n",el.id,el.jour,el.mois,el.annee,el.gov,el.nbh,el.nbcs,el.muni,el.robot);
}
}
}
fclose(f2);
fclose(f);
remove("election.txt");
rename("nouv.txt","election.txt");

}
//supp
void supprimer_election(election e, char ch[] )
{

   char id[20];
   int jour;
   int mois;
   int annee;
   char gov[20];
   int nbh;
   char nbcs[20];
   char muni[20];
   char robot[20];
FILE *f=NULL;
FILE *f2=NULL ;
f=fopen("election.txt","r");
f2=fopen("nouv.txt","a");
if (f!=NULL)
{
while (fscanf(f,"%s %d %d %d %s %d %s %s %s\n",e.id,&e.jour,&e.mois,&e.annee,e.gov,&e.nbh,e.nbcs,e.muni,e.robot)!= EOF)
{
if (strcmp(ch,e.id)!=0)
{
fprintf(f2,"%s %d %d %d %s %d %s %s %s\n",e.id,e.jour,e.mois,e.annee,e.gov,e.nbh,e.nbcs,e.muni,e.robot) ;
}
}
}
fclose(f2);
fclose(f);

remove("election.txt");
rename("nouv.txt","election.txt");
}
//recherche
int chercher(char * futil,char ch[])
{
   
    int tr=0;
    election e;
    FILE * f=fopen(futil, "r");
    if(f!=NULL)
    {
while(tr==0 && fscanf(f,"%s %d %d %d %s %d %s %s %s\n",e.id,&e.jour,&e.mois,&e.annee,e.gov,&e.nbh,e.nbcs,e.muni,e.robot)!=EOF)
        {
            if(strcmp(e.id,ch)==0)
                tr=1;
        }
    }
    fclose(f);
    return (tr) ;
}
//affichage
void affiche_election(GtkWidget *liste)
{
    
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    election a;
    char id1[20];
    char jour1[20];
    char mois1[20];
    char annee1[20];
    char gov1[20];
    char nbh1[20];
    char nbcs1[20];
    char muni1[20];
    char robot1[20];
    store= NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EID,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("governorat",renderer,"text",EGOV,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("nombre d'habitant",renderer,"text",ENBH,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("nombre de conseiller",renderer,"text",ENBCS,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("municipalitée",renderer,"text",EMUNI,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("robot",renderer,"text",EROBOT,NULL);
column = gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f=fopen("election.txt","r");
   if (f==NULL)
   {
return;
}
else
{
f=fopen("election.txt","a+");
while (fscanf(f,"%s %d %d %d %s %d %s %s %s\n",a.id,&a.jour,&a.mois,&a.annee,a.gov,&a.nbh,a.nbcs,a.muni,a.robot)!= EOF)
    {	
	sprintf(jour1,"%d",a.jour);
	sprintf(mois1,"%d",a.mois);
	sprintf(annee1,"%d",a.annee);
	sprintf(nbh1,"%d",a.nbh);
	gtk_list_store_append(store,&iter);
	gtk_list_store_set (store,&iter,EID,a.id,EJOUR,jour1,EMOIS,mois1,EANNEE,annee1,EGOV,a.gov,ENBH,nbh1,ENBCS,a.nbcs,EMUNI,a.muni,EROBOT,a.robot,-1);    
   }

gtk_tree_view_set_model (GTK_TREE_VIEW (liste) ,GTK_TREE_MODEL (store));
g_object_unref(store);
fclose(f);
}
}
}
