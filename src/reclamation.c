#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "reclamation.h"

enum{
	EID,
	ENOM,
	EGENRE,
	ETYPE,
	EDATE,
	EDESC,
	EIDLISTE,
	ECOLUMNS,
};
/* ------------------------------------------------------------------------------ */ 
int nbreclamationtot(){
    Reclamation o;
    int i ;
    FILE *f;
    f = fopen("reclamation.txt","r");
    while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
          
          i++;
}
return i ;

}

/* ------------------------------------------------------------------------------ */ 
int nbreclamation( int nbrl){
    Reclamation o;
    int nbreclamL=0;
	int index=0;;
    
    int T[100],i;
    FILE *f;
    f = fopen("reclamation.txt","r");
    while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
          T[index]=o.nbreliste;
          index++;
}


    for(i=0;i<index;i++){
       if(T[i]==nbrl){
            nbreclamL+=1;
           }
    }
return nbreclamL;

}
      
    
    
    
    
/* ------------------------------------------------------------------------------ */ 

void ajouter_reclamation(Reclamation r){
    FILE *f;

    f = fopen("reclamation.txt","a");
    if(f!= NULL){
        fprintf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",r.nom,r.prenom,r.cin,r.type,r.d.j,r.d.m,r.d.a,r.description,r.genre,r.nbreliste);

    }
    fclose(f);


}
/* ------------------------------------------------------------------------------ */ 
void modifier_reclamation(Reclamation r){
    Reclamation o;

    FILE *f;
    FILE *g;
    f = fopen("reclamation.txt","r");
    g = fopen("tmp.txt","a");
    while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
        if(strcmp(o.cin,r.cin) ==0){
            fprintf(g,"%s %s %s %s %d/%d/%d %s %s %d\n",r.nom,r.prenom,r.cin,r.type,r.d.j,r.d.m,r.d.a,r.description,r.genre,r.nbreliste);

        }
        else{
            fprintf(g,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,o.d.j,o.d.m,o.d.a,o.description,o.genre,o.nbreliste);
        }
    }
    fclose(f);
    fclose(g);
    remove("reclamation.txt");
    rename("tmp.txt","reclamation.txt");

}
/* ------------------------------------------------------------------------------ */ 
void supprimer_reclamation(char cin[]){
    Reclamation o;
    FILE *f1;
    FILE *f2;
    f1 = fopen("reclamation.txt","r");
    f2 = fopen("tmp.txt","a+");
    if(f1 != NULL && f2 != NULL){
	while(fscanf(f1,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){	
        	if(strcmp(o.cin,cin) != 0){
            		fprintf(f2,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,o.d.j,o.d.m,o.d.a,o.description,o.genre,o.nbreliste);

        }

    }
    fclose(f1);
    fclose(f2);
    remove("reclamation.txt.txt");
    rename("tmp.txt","reclamation.txt");
    }

}

/* ------------------------------------------------------------------------------ */ 
void recherche_multi_critere()
{Reclamation o ;
FILE *f;
int x=0;
	

f=fopen("reclamation.txt","r");
while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
	if(strcmp(o.type,"finance")==0)
	{ if(strcmp(o.genre,"homme")==0)
		{
			x+=1;
		}
	}

}
printf("1.les reclamation qui ont le type 'finance' et genre 'homme' : \n nombre des reclamation=( %d ) \n",x);
}
		
		
/* ------------------------------------------------------------------------------ */ 
int chercher_reclamation(char cin[]){

  Reclamation o ;
  FILE *f;
  f=fopen("reclamation.txt","r");
  while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
      if(strcmp(o.cin,cin) == 0){
        return 1 ; 
}
      }
return 0 ;
  }
/* ------------------------------------------------------------------------------ */ 

Reclamation findRecById(char cin[]){

  Reclamation o ;
  FILE *f;
  f=fopen("reclamation.txt","r");
  while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
      if(strcmp(o.cin,cin) == 0){
        return o ; 
}
      }
return  ;

}

/* ------------------------------------------------------------------------------ */ 

void afficher_reclamation(GtkWidget *liste,char *fname){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;


    Reclamation o ;
    char idL[20];
    char date[40];
    char fullName[50];


    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Réclamation",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom & Prénom",renderer,"text",ENOM,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Genre",renderer,"text",EGENRE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date du réclamation",renderer,"text",EDATE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Description",renderer,"text",EDESC,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Id du la liste réclamée",renderer,"text",EIDLISTE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
			sprintf(fullName,"%s %s",o.prenom,o.nom);
			sprintf(idL,"%d",o.nbreliste);
			sprintf(date,"%d/%d/%d",o.d.j,o.d.m,o.d.a);
			

			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,o.cin,ENOM,fullName,EGENRE,o.genre,ETYPE,o.type,EDATE,date,EDESC,o.description,EIDLISTE,idL,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    

}


void trierReclamtion(){
	Reclamation o;
	Reclamation data[1000];
    	FILE *f;

	int count = 0; 
   	f = fopen("reclamation.txt","r");

    	while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
	    data[count] = o ;
		count++ ; 
    	}
    	fclose(f);

	int i,j;
	Reclamation temp;

	for (i = 0; i < count; i++) {
	    for (j = 0; j < count; j++){
	      if (strcmp(data[i].nom, data[j].nom) < 0)
		{
		  temp = data[i];
		  data[i] = data[j];
		  data[j] = temp;
		}
	  }
	}

	FILE *g;
	g = fopen("triReclamation.txt","a");
	for (i = 0; i < count; i++) {
		fprintf(g,"%s %s %s %s %d/%d/%d %s %s %d\n",data[i].nom,data[i].prenom,data[i].cin,data[i].type,data[i].d.j,data[i].d.m,data[i].d.a,data[i].description,data[i].genre,data[i].nbreliste);
	}

	fclose(g);
}

void filtrerReclamationType(char type[]){

	FILE *f,*g ; 
	Reclamation o; 
	int count = 0 ; 
	f = fopen("reclamation.txt","r");
	g = fopen("rectype.txt","a");
	while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
		if(strcmp(type,o.type) == 0 ){
			fprintf(g,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,o.d.j,o.d.m,o.d.a,o.description,o.genre,o.nbreliste);
		}
	
	}

	fclose(f);
	fclose(g);


}
void filtrerReclamationNB(int nb){
	FILE *f,*g ; 
	Reclamation o; 
	int count = 0 ; 
	f = fopen("reclamation.txt","r");
	g = fopen("recNombre.txt","a");
	while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,&(o.d.j),&(o.d.m),&(o.d.a),o.description,o.genre,&o.nbreliste) != EOF){
		if(o.nbreliste == nb ){
			fprintf(g,"%s %s %s %s %d/%d/%d %s %s %d\n",o.nom,o.prenom,o.cin,o.type,o.d.j,o.d.m,o.d.a,o.description,o.genre,o.nbreliste);
		}
	
	}

	fclose(f);
	fclose(g);
}
