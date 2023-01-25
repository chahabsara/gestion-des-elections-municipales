#ifdef HAVE_CONFIG_H
#include "fonction.h"
#include <malloc.h>
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

/*enum
{
ENOMECOLE,
EIDBUREAU,
EIDAGENT,
EJOUR,
EMOIS,
EANNEE,
ETYPE,
ECAPE,
ECAPO,
COLUMNS
};*/

enum
{
ENOMECOLE,
EIDBUREAU,
EIDAGENT,
EJOUR,
EMOIS,
EANNEE,
ETYPE,
ECAPE,
ECAPO,
COLUMNS
};

int cherche_id(int num)
{
FILE *f ;
bureau c;
int x=0;
    f=fopen("bureau.txt","r");
 if(f!=NULL)
    {
	while(fscanf(f,"%s %d %s %d %d %d %d %d %d \n",c.nomecole,&c.idbureau,c.idagent,&c.datef.jour,&c.datef.mois,&c.datef.annee,&c.type,&c.capelect,&c.capobs)!=EOF)
	{ 
 	 if(c.idbureau!=num)
{
	  x=1;
}
else
{ 
x=0;
}
}
}
fclose(f);

return x;
}

void ajout_bureau(bureau c)
{
FILE *f;
f=fopen("bureau.txt","a+");
		if(f!=NULL)
		{
			fprintf(f,"%s %d %s %d %d %d %d %d %d \n",c.nomecole,c.idbureau,c.idagent,c.datef.jour,c.datef.mois,c.datef.annee,c.type,c.capelect,c.capobs);
			fclose(f);
		}
}	
void modifier(int refmodif,bureau c)
{
  FILE *f;
    FILE *g;
    g=NULL;
    bureau cm ;
   
    f=fopen("bureau.txt","r+");
    g=fopen("bureau_modifie.txt","a+");
	printf("2\n");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %d %s %d %d %d %d %d %d \n",cm.nomecole,&cm.idbureau,cm.idagent,&cm.datef.jour,&cm.datef.mois,&cm.datef.annee,&cm.type,&cm.capelect,&cm.capobs)!=EOF);
        {
	printf("3\n"); 
            if(refmodif==cm.idbureau)
            {
		      	printf("4\n"); 
		       cm.type=c.type;
		       cm.capelect=c.capelect;
                       cm.capobs=c.capobs;
                       
                       
            }
            fprintf(g,"%s %d %s %d %d %d %d %d %d \n",cm.nomecole,cm.idbureau,cm.idagent,cm.datef.jour,cm.datef.mois,cm.datef.annee,cm.type,cm.capelect,cm.capobs);
        }

    }
    fclose(g);
    fclose(f);
    remove("bureau.txt");
    rename("bureau_modifie.txt","bureau.txt");


}


int supprimer_bureau (int num)
{
FILE *f ;
FILE *g;
bureau c;
int x=0;
    f=fopen("bureau.txt","r");
    g=fopen("ancien_bureau","w+");
 if(f!=NULL)
    {
	while(fscanf(f,"%s %d %s %d %d %d %d %d %d \n",c.nomecole,&c.idbureau,c.idagent,&c.datef.jour,&c.datef.mois,&c.datef.annee,&c.type,&c.capelect,&c.capobs)!=EOF)
	{ 
 	 if(c.idbureau!=num)
{
	  fprintf(g,"%s %d %s %d %d %d %d %d %d \n",c.nomecole,c.idbureau,c.idagent,c.datef.jour,c.datef.mois,c.datef.annee,c.type,c.capelect,c.capobs);
	  x=1;
}
else
{ 
x=0;
}
}
}
fclose(f);
fclose(g);
remove("bureau.txt");
rename("ancien_bureau","bureau.txt");
return x;
}




void afficher_bureau(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nomecole[50];
	int idbureau;
	char idagent[50];
	datefr datef;
	int type;
	int capelect;
	int capobs;
	char ch[20];
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom de l ecole",renderer, "text",ENOMECOLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Bureau",renderer, "text",EIDBUREAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Agent",renderer, "text",EIDAGENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" bloc",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des élécteurs",renderer, "text",ECAPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des observateurs",renderer, "text",ECAPO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	f=fopen("bureau.txt","a+");
	if (f==NULL)
	{
		return;
	}
	else
	{ f=fopen("bureau.txt","a+");
		while (fscanf(f,"%s %d %s %d %d %d %d %d %d \n",nomecole,&idbureau,idagent,&datef.jour,&datef.mois,&datef.annee,&type,&capelect,&capobs)!=EOF)
			{
				if (type==1)
					strcpy(ch,"A");
				else if (type==2)
					strcpy(ch,"B"); 
				else if (type==3)
					strcpy(ch,"C");
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ENOMECOLE,nomecole,EIDBUREAU,idbureau,EIDAGENT,idagent,EJOUR,datef.jour,EMOIS,datef.mois,EANNEE,datef.annee,ETYPE,ch,ECAPE,capelect,ECAPO,capobs,-1);
			}
			fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}
}
void vider (GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;

	
	char nomecole[50];
	int idbureau;
	char idagent[50];
	datefr datef;
	int type;
	int capelect;
	int capobs;
	char ch[20];
	store=NULL;
	FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom de l ecole",renderer, "text",ENOMECOLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	idbureau = gtk_tree_view_column_new_with_attributes(" ID Bureau",renderer, "text",EIDBUREAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Agent",renderer, "text",EIDAGENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" bloc",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des élécteurs",renderer, "text",ECAPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des observateurs",renderer, "text",ECAPO,NULL);
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);	
}
if (type==1)
strcpy(ch,"A");
else if (type==2)
strcpy(ch,"B"); 
else if (type==3)
strcpy(ch,"C");

store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}


