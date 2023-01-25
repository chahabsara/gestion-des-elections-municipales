#include<gtk/gtk.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listelc.h"
enum{
	EID,
	EIDT,
	EORIENT,
	EN1,
	EN2,
	EN3,
	ED,
	EGENRE,
	ENBVOTE,
	ECOLUMNS,
};
enum{
	ID,
	ORIENT,
	N1,
	N2,
	N3,
	COLUMNS,
};
//Ajout
void ajouter(liste l){
    FILE *f;

    f = fopen("liste.txt","a+");
    if(f!= NULL){
        fprintf(f,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,l.dch.j,l.dch.m,l.dch.a,l.genre,l.nbvote);

    }
    fclose(f);

}
//CHERCHER
int chercherch(char id[]){

  liste l ;
  FILE *f;
  f=fopen("liste.txt","r");
  while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.dch.j,&l.dch.m,&l.dch.a,l.genre,&l.nbvote) != EOF){
      if(strcmp(l.id,id) == 0){
        return 1 ; 
}
      }
return 0 ;
  }

liste findlById(char id[]){

  liste l ;
  FILE *f;
  f=fopen("liste.txt","r");
  while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.dch.j,&l.dch.m,&l.dch.a,l.genre,&l.nbvote) != EOF){
      if(strcmp(l.id,id) == 0){
        return l ; 
}
      }
return  ;

}
//MODIFIER

void modifierch(liste nouv){
    liste l;

    FILE *f;
    FILE *g;
    f = fopen("liste.txt","r");
    g = fopen("tmp.txt","a");
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.dch.j,&l.dch.m,&l.dch.a,l.genre,&l.nbvote) != EOF){
        if(strcmp(l.id,nouv.id) ==0){
            fprintf(g,"%s %s %s %s %s %s %d %d %d %s %d\n",nouv.id,nouv.idt,nouv.orient,nouv.n1,nouv.n2,nouv.n3,nouv.dch.j,nouv.dch.m,nouv.dch.a,nouv.genre,nouv.nbvote);

        }
        else{
            fprintf(g,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,l.dch.j,l.dch.m,l.dch.a,l.genre,l.nbvote);
        }
    }
    fclose(f);
    fclose(g);
    remove("liste.txt");
    rename("tmp.txt","liste.txt");
}

int modifierl(int id,liste nouv )
{
    int tr=0;
    liste l;
    FILE * f=fopen("liste.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(tr!=1 && fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.dch.j,&l.dch.m,&l.dch.a,l.genre,&l.nbvote)!=EOF)
        {
            if(l.id== id)
            {
                fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %d\n",nouv.id,nouv.idt,nouv.orient,nouv.n1,nouv.n2,nouv.n3,nouv.dch.j,nouv.dch.m,nouv.dch.a,nouv.genre,nouv.nbvote);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,l.dch.j,l.dch.m,l.dch.a,l.genre,l.nbvote);

        }
    }
    fclose(f);
    fclose(f2);
    remove("liste.txt");
    rename("nouv.txt", "liste.txt");
    return tr;

}

//SUPPRIMER

void supprimer(char id[]){
    liste l;
    FILE *f1;
    FILE *f2;
    f1 = fopen("liste.txt","r");
    f2 = fopen("tmp.txt","a+");
    if(f1 != NULL && f2 != NULL){
	while(fscanf(f1,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.dch.j,&l.dch.m,&l.dch.a,l.genre,&l.nbvote)!= EOF){	
        	if(strcmp(l.id,id) != 0){
            		fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,l.dch.j,l.dch.m,l.dch.a,l.genre,l.nbvote);

        }

    }
    fclose(f1);
    fclose(f2);
    remove("liste.txt.txt");
    rename("tmp.txt","liste.txt");
    }

}

void afficherliste(GtkWidget *lit,char *fname){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;


    liste l ;
    char datech[40];
    char nvote[50];


    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(lit);

    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Liste",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID tête",renderer,"text",EIDT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Orientation",renderer,"text",EORIENT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID nom n°1",renderer,"text",EN1,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);
 
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID nom n°2",renderer,"text",EN2,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID nom n°3",renderer,"text",EN3,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date d'ajout",renderer,"text",ED,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Genre de l'ID tête",renderer,"text",EGENRE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre de vote",renderer,"text",ENBVOTE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);



    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.dch.j,&l.dch.m,&l.dch.a,l.genre,&l.nbvote) != EOF){
			sprintf(nvote,"%d",l.nbvote);
			sprintf(datech,"%d/%d/%d",l.dch.j,l.dch.m,l.dch.a);
			

			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,l.id,EIDT,l.idt,EORIENT,l.orient,EN1,l.n1,EN2,l.n2,EN3,l.n3,ED,datech,EGENRE,l.genre,ENBVOTE,nvote,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(lit),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    

}

void afficherlistelc																												(GtkWidget *lit,char *fname){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;


    liste l ;

    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(lit);

    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Liste",renderer,"text",ID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Orientation",renderer,"text",ORIENT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom n°1",renderer,"text",N1,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);
 
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom n°2",renderer,"text",N2,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom n°3",renderer,"text",N3,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(lit),column);




    }
	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.dch.j,&l.dch.m,&l.dch.a,l.genre,&l.nbvote) != EOF){


			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,ID,l.id,ORIENT,l.orient,N1,l.n1,N2,l.n2,N3,l.n3,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(lit),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    

}

//VOTE
/*int vote(char file[], int id)
{
    int nbv;
    liste l;
    FILE * f=fopen(file, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.d.j,&l.d.m,&l.d.a,l.genre,&l.nbvote)!=EOF)
			{ nbv=nbv+l.nbvote;
				
				if(id==l.id)
					{
					l.nbvote=l.nbvote+1;
					nbv=l.nbvote;
				fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,l.d.j,l.d.m,l.d.a,l.genre,l.nbvote);}
           else
                fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,l.d.j,l.d.m,l.d.a,l.genre,l.nbvote);
					
						}
							
							
	 fclose(f);
   	 fclose(f2);
 	 remove(file);
   	 rename("nouv.txt", file);}
	return nbv;


}

//TRI

void tri(char file1[],char file2[])
{
liste tab[100];
int min,n=0;
liste l,temp;
FILE * f;
f=fopen(file1, "r");
if (f!=NULL)
{
  while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,&l.d.j,&l.d.m,&l.d.a,l.genre,&l.nbvote)!=EOF)
  {
      tab[n]=l;
      n++;
}
}
fclose(f);

for(int i=0;i<n-1;i++)
{
min=i;
for(int j=i+1;j<n;j++)
{
if(vote(file2,tab[min].id)>vote(file2,tab[j].id))
min=j;
}
if(min!=i)
{
temp=tab[i];
tab[i]=tab[min];
tab[min]=temp;
}}
f=fopen("sorted.txt","w");
for(int i=0 ;i<n;i++){
    if(f!=NULL)
   {
        l=tab[i];
	fprintf(f,"%s %s %s %s %s %s %d %d %d %s %d\n",l.id,l.idt,l.orient,l.n1,l.n2,l.n3,l.d.j,l.d.m,l.d.a,l.genre,l.nbvote);}
}
fclose(f);
}*/
	


