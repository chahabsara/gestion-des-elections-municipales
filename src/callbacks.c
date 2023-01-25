#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <string.h>
#include <gtk/gtk.h>


#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"
#include "user.c"
#include "reclamation.h"
#include"election.h"
#include "fonction.h"
#include "listelc.h"
#include "observateur.h"
int x = 1;
int y = 1;
int checkAj = 0 ;
int check = 0 ;
int tab[1]={0,0};
int z=1,w=1,j,m,a;
int type2=0;
enum {
ID,
 EMAIL,
 LASTNAME,
 FIRSTNAME,
 ADDRESS,
 NIC,
SEXE,
BIRTHDATE,
VOTED,
VOTEPLACE,
NUM_COLS
};


void on_login_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryEmail = lookup_widget(GTK_WIDGET(button), "entryEmail");
GtkWidget *entryPassword = lookup_widget(GTK_WIDGET(button), "entryPassword");
GtkWidget *window1;

currentUser = login(gtk_entry_get_text(GTK_ENTRY(entryEmail)), gtk_entry_get_text(GTK_ENTRY(entryPassword)),  "./user.txt");
if(currentUser) {
print_user(*currentUser);

if(strstr(currentUser->email, "@esprit.tn") != NULL){
GtkWidget *page4=create_page4();
window1 = lookup_widget(button,"page1");
gtk_widget_show (page4);
gtk_widget_destroy(window1);
} else {
GtkWidget *page=create_MenuDeChoix();
window1 = lookup_widget(button,"page1");
gtk_widget_show (page);
gtk_widget_destroy(window1);
}


} else {
GtkWidget* dialog = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Email or password incorrect !");

int response = gtk_dialog_run(GTK_DIALOG(dialog));
if(response == GTK_RESPONSE_OK) {
gtk_widget_destroy(dialog);
}
}
}


void
on_create_account_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page2=create_page2();
gtk_widget_show (page2);

}


void
on_cancel_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1=create_page1();
gtk_widget_show (page1);
GtkWidget *window1 = lookup_widget(button,"page2");
gtk_widget_destroy(window1);

}


void
on_save_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *emailEntry = lookup_widget(GTK_WIDGET(button), "emailEntry");
GtkWidget *firstnameEntry = lookup_widget(GTK_WIDGET(button), "firstnameEntry");

GtkWidget *lastnameEntry = lookup_widget(GTK_WIDGET(button), "last_name_entry");

GtkWidget *nic_entry = lookup_widget(GTK_WIDGET(button), "nic_entry");


GtkWidget *day_spin = lookup_widget(GTK_WIDGET(button), "day");
GtkWidget *month_spin = lookup_widget(GTK_WIDGET(button), "month");
GtkWidget *year_spin = lookup_widget(GTK_WIDGET(button), "year");

GtkWidget *adress_entry = lookup_widget(GTK_WIDGET(button), "adress_entry");

GtkWidget *password_entry = lookup_widget(GTK_WIDGET(button), "password_entry");

GtkWidget *sexeComboBox = lookup_widget(GTK_WIDGET(button), "sexeComboBox");

GtkWidget *place1 = lookup_widget(GTK_WIDGET(button), "bv1");
GtkWidget *place2 = lookup_widget(GTK_WIDGET(button), "bv2");

char votePlace[200];
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(place1))){
strcpy(votePlace, "Ariana");
}
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(place2))){
strcpy(votePlace, "Tunis");

}

int total = getNumberOfUsers("./user.txt");
int offset = 100000;

User *user = createUser(
gtk_entry_get_text(GTK_ENTRY(emailEntry)),
gtk_entry_get_text(GTK_ENTRY(lastnameEntry)),
gtk_entry_get_text(GTK_ENTRY(firstnameEntry)),
gtk_entry_get_text(GTK_ENTRY(nic_entry)),
gtk_entry_get_text(GTK_ENTRY(password_entry)),
gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexeComboBox)),
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day_spin)),
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month_spin)),
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year_spin)),
gtk_entry_get_text(GTK_ENTRY(adress_entry)),
0,0,
votePlace,
offset+total+1
);

print_user(*user);

const char *email = gtk_entry_get_text(GTK_ENTRY(emailEntry));
int isEmailValid = 0;

if(strstr(email, "@") != NULL && strstr(email, ".") != NULL){
isEmailValid = 1;
} else {
GtkWidget* dialog = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Email invalide !");

int response = gtk_dialog_run(GTK_DIALOG(dialog));
if(response == GTK_RESPONSE_OK) {
gtk_widget_destroy(dialog);
}
}

const char *password  = gtk_entry_get_text(GTK_ENTRY(password_entry));
int isPasswordValid = 0;
if(strlen(password) == 8){
isPasswordValid = 1;
} else {
GtkWidget* dialog = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Password doit contenir 8 caractères !");

int response = gtk_dialog_run(GTK_DIALOG(dialog));
if(response == GTK_RESPONSE_OK) {
gtk_widget_destroy(dialog);
}
}


FILE *file = fopen( "./user.txt", "r");
if(isEmailValid && isPasswordValid){

if(isUserExist(user->email, "./user.txt") == 0) {
saveUserToFile(user, "./user.txt");
} else {
updateUserToFile(user, "./user.txt");
}


fclose(file);
GtkWidget *page1=create_page4();
gtk_widget_show (page1);
GtkWidget *window1 = lookup_widget(button,"page2");
gtk_widget_destroy(window1);
}
}





void
on_bv3_group_changed                   (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_bv2_group_changed                   (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_bv1_group_changed                   (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_exit1_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1=create_page4();
gtk_widget_show (page1);
GtkWidget *window1 = lookup_widget(button,"page2");
gtk_widget_destroy(window1);


}


void
on_exit0_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1=create_page1();
gtk_widget_show (page1);

}


void
on_exit2_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1=create_page1();
gtk_widget_show (page1);

}


void
on_voter_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryPassword = lookup_widget(GTK_WIDGET(button), "passwordEntry3");
GtkWidget *check1 = lookup_widget(GTK_WIDGET(button), "check1");
GtkWidget *check2 = lookup_widget(GTK_WIDGET(button), "check2");
GtkWidget *check3 = lookup_widget(GTK_WIDGET(button), "check3");
GtkWidget *check4 = lookup_widget(GTK_WIDGET(button), "check4");
GtkWidget *check5 = lookup_widget(GTK_WIDGET(button), "check5");

if(strcmp(currentUser->password, gtk_entry_get_text(GTK_ENTRY(entryPassword))) == 0){

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check5)) == TRUE) {

currentUser-> voted =0;


} else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1)) == TRUE){
currentUser -> voted=1;
voter("Ennahdha", "./vote.txt");
}else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check2)) == TRUE) {
currentUser -> voted=1;
voter("Eetilef el karama", "./vote.txt");
} else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check3)) == TRUE) {
currentUser -> voted=1;
voter("Nida tounes", "./vote.txt");
} else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check4)) == TRUE) {
voter("Jabha chaabeya", "./vote.txt");
currentUser -> voted=1;
}

updateUserToFile(currentUser, "./user.txt");
GtkWidget* dialog = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "We recorded your vote successfully!");

int response = gtk_dialog_run(GTK_DIALOG(dialog));
if(response == GTK_RESPONSE_OK) {
gtk_widget_destroy(dialog);
printf("%s\n",currentUser->password);
exit(0);

}

} else {


GtkWidget* dialog = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Password incorrect !");

int response = gtk_dialog_run(GTK_DIALOG(dialog));
if(response == GTK_RESPONSE_OK) {
gtk_widget_destroy(dialog);
printf("%s\n",currentUser->password);GtkWidget *page1=create_page1();
gtk_widget_show (page1);

}
}

}

void
on_arriere_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1=create_page1();
gtk_widget_show (page1);

}


void
on_checkbutton3_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton11_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton2_group_changed          (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton3_group_changed          (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_deleteUser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page5=create_page5();
gtk_widget_show (page5);
GtkWidget *window1 = lookup_widget(button,"page4");
gtk_widget_destroy(window1 );


}


void
on_modifyUser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page2=create_page2();
gtk_widget_show (page2);

}


void
on_displayUser_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *page4 = lookup_widget(GTK_WIDGET(button), "page4");
gtk_widget_destroy(page4);

GtkWidget *page7=create_page7();
gtk_widget_show (page7);

int usersLength = getNumberOfUsers("./user.txt");

User** users = (User**) malloc(sizeof(User) * usersLength);

readUsersFromFile(users, "./user.txt");


GtkWidget *treeview1 = lookup_widget(page7, "treeview1");
displayTreeView(treeview1,users,usersLength);
}


void
on_addUser_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page2=create_page2();
GtkWidget *window1 = lookup_widget(button,"page4");
gtk_widget_show (page2);
gtk_widget_destroy(window1);

}


void
on_exit3_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *page1=create_page1();
window1 = lookup_widget(button,"page4");
gtk_widget_show (page1);
gtk_widget_destroy(window1);


}


void
on_exit4_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1=create_page4();
gtk_widget_show (page1);
GtkWidget *window1 = lookup_widget(button,"page5");
gtk_widget_destroy(window1);
//page4
}




void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *page4=create_page4();
GtkWidget *window1 = lookup_widget(button,"page5");
gtk_widget_show (page4);
gtk_widget_destroy(window1);

}


void
on_exit5_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1=create_page1();
gtk_widget_show (page1);
}

void on_modify_clicked(GtkButton       *button,
                                        gpointer         user_data) {}

void
on_stat_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *aaaa = create_pageStatSarra();
gtk_widget_show (aaaa);

}


void
on_delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryEmailOfUserToDelete = lookup_widget(GTK_WIDGET(button), "entryEmailOfUserToDelete");
deleteUserByEmail(gtk_entry_get_text(GTK_ENTRY(entryEmailOfUserToDelete)), "./user.txt");
}


void
on_exit6_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page4=create_page1();
GtkWidget *window1 = lookup_widget(button,"page7");
gtk_widget_show (page4);
gtk_widget_destroy(window1);

}


void
on_getBack_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page4=create_page4();
GtkWidget *window1 = lookup_widget(button,"page7");
gtk_widget_show (page4);
gtk_widget_destroy(window1);
}


void displayTreeView(GtkWidget *treeview, User** users,int usersLength) {

 GtkListStore *store = gtk_tree_view_get_model(treeview);
if (store){

gtk_list_store_clear(store);
}
else {GtkCellRenderer *renderer;


  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  ID",  
                                               renderer,
                                              "text", ID,
                                               NULL);


renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Email",  
                                               renderer,
                                              "text", EMAIL,
                                               NULL);

renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Last name",  
                                               renderer,
                                              "text",  LASTNAME,
                                               NULL);




renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  First name",  
                                               renderer,
                                              "text", FIRSTNAME,
                                               NULL);
renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Address",  
                                               renderer,
                                              "text", ADDRESS,
                                               NULL);


renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  NIC",  
                                               renderer,
                                              "text", NIC,
                                               NULL);
renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Sexe",  
                                               renderer,
                                              "text", SEXE,
                                               NULL);
renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Vote place",  
                                               renderer,
                                              "text", VOTEPLACE,
                                               NULL);
renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Vote",  
                                               renderer,
                                              "text", VOTED,
                                               NULL);
renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Birthdate",  
                                               renderer,
                                              "text", BIRTHDATE,
                                               NULL);



 store = gtk_list_store_new (NUM_COLS,
                                              G_TYPE_UINT,
                                            G_TYPE_STRING, 
G_TYPE_STRING, 
G_TYPE_STRING, 
G_TYPE_STRING, 
G_TYPE_STRING, 
G_TYPE_STRING, 
G_TYPE_STRING, 
G_TYPE_UINT,
G_TYPE_STRING, 
G_TYPE_STRING);

} 

for(int i=0; i<usersLength; i++) {
User *user = users[i];


char day[20];
char month[20];
char year[20];
sprintf( day, "%d" ,( user->birthdate).day );
sprintf( month, "%d" ,( user->birthdate).month );
sprintf( year, "%d" ,( user->birthdate).year);

GtkTreeIter iter;
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter,
                      ID, user->id,
                      EMAIL, user->email,
LASTNAME, user->lastname,
FIRSTNAME, user->firstname,
ADDRESS, user->address,
NIC, user->identityCard,
SEXE, user->sexe,
VOTEPLACE, user->votePlace,
VOTED,user->voted,
BIRTHDATE,strcat(strcat(day, "/"), strcat(strcat(month,"/"),year )), 
  -1);

 
  }

gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

}

void
on_search_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *treeview1 = lookup_widget(GTK_WIDGET(button), "treeview1");
GtkWidget *radioButtonHomme = lookup_widget(GTK_WIDGET(button), "radioButtonHomme");
GtkWidget *radioButtonFemme = lookup_widget(GTK_WIDGET(button), "radioButtonFemme");
 
GtkWidget *voteYes = lookup_widget(GTK_WIDGET(button), "voteYes");
GtkWidget *voteNo = lookup_widget(GTK_WIDGET(button), "voteNo");
 



int usersLength = getNumberOfUsers("./user.txt");
User** users = (User**) malloc(sizeof(User) * usersLength);
readUsersFromFile(users, "./user.txt");

char sexe[200];
User**array = users;
int length = usersLength;




if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radioButtonHomme))){

strcpy(sexe,"Homme");
 FilterUser fu1 =filterUsersBySexe(array, length, sexe); 
array = fu1.array; 
length = fu1.length;}


else if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radioButtonFemme))){

strcpy(sexe,"Femme");
FilterUser fu2 =filterUsersBySexe(array, length, sexe); 
array = fu2.array; 
length = fu2.length;}

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(voteYes))){
printf("1\n");
 FilterUser fu1 =filterUsersAdmin(array, length, 1); 
array = fu1.array; 
length = fu1.length;
} else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(voteNo))){ 
printf("2\n");
 FilterUser fu1 =filterUsersAdmin(array, length, 0);  
array = fu1.array; 
length = fu1.length;
}
 
displayTreeView(treeview1,array,length);
}


void
on_clear_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AllerMenuChoix_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"page1");
	window2 = create_MenuDeChoix();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_treeviewRecla_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter Iter;
	gchar* id;		
	char id_supp[20];	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if(gtk_tree_model_get_iter(model,&Iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&Iter,0,&id,-1);
		

		strcpy(id_supp,id);
		supprimer_reclamation(id_supp);
		afficher_reclamation(treeview,"reclamation.txt");
		
		GtkWidget *dialog ; 
		dialog = create_supDialog () ; 
		gtk_widget_show(dialog);
	}
}


void
on_NombreReclamationparl_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"Affichagehamza");
	window2 = create_NombreReclParL();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_refreshTreeRecl_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *current_window ; 
	GtkWidget * treeview ; 
	current_window = lookup_widget(objet,"Affichagehamza");
	
	treeview = lookup_widget(current_window,"treeviewRecla");
	afficher_reclamation(treeview,"reclamation.txt");
}


void
on_SuprimerAffichageRec_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"Affichagehamza");
	window2 = create_Supprimerhamza ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_ModifierAffichageRec_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Affichagehamza");
	window2 = create_Modifhamza();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_AjouterAffichageRec_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Affichagehamza");
	window2 = create_Ajouthamza();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_exitGesRecla_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=1;
	}
}


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=2;
	}
}


void
on_confirmAjoutRec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *idR , *nom , *prenom , *type , *dj , *dm , *da , *desc , *idLE ; 
	
	GtkWidget *output ;
	char message[200];

	int inputState = 1 ; 

	output = lookup_widget(objet,"outputAjHamza"); 
	Reclamation r ; 

	idR = lookup_widget(objet,"entry_id_ajout");
	strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(idR)));

	nom = lookup_widget(objet,"entry_nom_ajout");
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	if(strcmp(r.nom,"") == 0){
		inputState = 0 ; 
	}

	prenom = lookup_widget(objet,"entry_prenom_ajout");
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	if(strcmp(r.prenom,"") == 0){
		inputState = 0 ; 
	}

	type = lookup_widget(objet,"combobox_type_ajout");
	strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

	dj = lookup_widget(objet,"spinJA");
	r.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dj));

	dm = lookup_widget(objet,"spinMA");
	r.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dm));

	da = lookup_widget(objet,"spinAA");
	r.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(da));

	desc = lookup_widget(objet,"entry_description");
	strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(desc)));
	if(strcmp(r.description,"") == 0){
		inputState = 0 ; 
	}

	idLE = lookup_widget(objet,"spinIdListe");
	r.nbreliste = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(idLE));


	if(x == 1){
		strcpy(r.genre,"Homme");
	}
	else{
		strcpy(r.genre,"Femme");
	}

	
	if(check){	
		if(inputState){
			if(chercher_reclamation(r.cin) == 0){
				ajouter_reclamation(r);
				sprintf(message,"🙂 Votre Reclamation à été ajouté avec succés !");
				gtk_label_set_text(GTK_LABEL(output),message);
			}else{
				sprintf(message,"ID de Réclamation déja exist !");
				gtk_label_set_text(GTK_LABEL(output),message);
			}
		}else{
				sprintf(message,"Verifier Vos données !");
				gtk_label_set_text(GTK_LABEL(output),message);
		}
		
	}else{
		
		sprintf(message,"🙂 Confirrmer Votre Ajout ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}	

}


void
on_RetourAjoutRec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Ajouthamza");
	window2 = create_Affichagehamza ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_rechercherReclamation_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *idMod ; 
	Reclamation r; 

	char id[20] ; 
	idMod = lookup_widget(objet,"entry_ID_Modif");


	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idMod)));

	if(chercher_reclamation(id)){
		GtkWidget *nom , *prenom , *type , *dj , *dm , *da , *desc , *idLE ; 



		nom = lookup_widget(objet,"entry_nom_modif");
		strcpy(r.nom,findRecById(id).nom);
		gtk_entry_set_text(GTK_ENTRY(nom),r.nom);
		

		prenom = lookup_widget(objet,"entry_prenom_modif");
		strcpy(r.prenom,findRecById(id).prenom);
		gtk_entry_set_text(GTK_ENTRY(prenom),r.prenom);

		type = lookup_widget(objet,"combobox_type_modif");
		strcpy(r.type,findRecById(id).type);

		int comboValue ; 
		if(strcmp(r.type,"financiere") == 0){
			comboValue = 0 ;
		}
		else if(strcmp(r.type,"evenement") == 0 ){
			comboValue = 1 ;
		}
		else{
			comboValue = 2 ;
		}

		gtk_combo_box_set_active(type,comboValue);

		dj = lookup_widget(objet,"spinJM");
		r.d.j = findRecById(id).d.j;
		gtk_spin_button_set_value(dj,r.d.j);

		dm = lookup_widget(objet,"spinMM");
		r.d.m = findRecById(id).d.m;
		gtk_spin_button_set_value(dm,r.d.m);

		da = lookup_widget(objet,"spinAM");
		r.d.a = findRecById(id).d.a;
		gtk_spin_button_set_value(da,r.d.a);

		desc = lookup_widget(objet,"descriptionM");
		strcpy(r.description,findRecById(id).description);
		gtk_entry_set_text(GTK_ENTRY(desc),r.description);

		idLE = lookup_widget(objet,"spinbutton_nbrel_modif_6");
		r.nbreliste = findRecById(id).nbreliste;
		gtk_spin_button_set_value(idLE,r.nbreliste);
		
	}
}


void
on_radiobutton_homme_modif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
			y=1;
	}
}


void
on_radiobutton_femme_modif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		y=2;
	}
}


void
on_checkModif_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_confirmModifRec_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *idMod ; 
	GtkWidget *nom , *prenom , *type , *dj , *dm , *da , *desc , *idLE ;
	Reclamation r; 

	char id[20] ; 
	idMod = lookup_widget(objet,"entry_ID_Modif");


	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idMod)));
	if(chercher_reclamation(id)){
		Reclamation r ; 
		strcpy(r.cin,id);

		nom = lookup_widget(objet,"entry_nom_modif");
		strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

		prenom = lookup_widget(objet,"entry_prenom_modif");
		strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

		type = lookup_widget(objet,"combobox_type_modif");
		strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

		dj = lookup_widget(objet,"spinJM");
		r.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dj));

		dm = lookup_widget(objet,"spinMM");
		r.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dm));

		da = lookup_widget(objet,"spinAM");
		r.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(da));

		desc = lookup_widget(objet,"descriptionM");
		strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(desc)));

		idLE = lookup_widget(objet,"spinbutton_nbrel_modif_6");
		r.nbreliste = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(idLE));


		if(y == 1){
			strcpy(r.genre,"Homme");
		}
		else{
			strcpy(r.genre,"Femme");
		}

		modifier_reclamation(r);

	}
}


void
on_ReturnModifRec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Modifhamza");
	window2 = create_Affichagehamza ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_RetourSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"Supprimerhamza");
	window2 = create_Affichagehamza();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_confirmersupp_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	gchar* id;		
	char id_supp[20];
	
	id = lookup_widget(button,"RecSupp");
	strcpy(id_supp,gtk_entry_get_text(GTK_ENTRY(id)));
	supprimer_reclamation(id_supp);
}


void
on_confirmNombreRec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
GtkWidget *typeinf;
GtkWidget *tpi,*NBRL;
GdkColor color;
int nbrerec,nbrl;
window1=lookup_widget(objet,"NombreReclParL");
NBRL = lookup_widget(objet,"NbreListeCalcule");
	nbrl = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(NBRL));


char inf[50],rec[10];
nbrerec=nbreclamation(nbrl);

gtk_widget_destroy(window1);
typeinf=create_AfficheNbreReclamation();
gtk_widget_show(typeinf);
tpi=lookup_widget(typeinf,"label247");
sprintf(rec,"%d",nbrerec);
strcpy(inf,"🙂 Le nombre de reclamation est: ");
strcat(inf,rec);
gdk_color_parse("#ff250d",&color);
gtk_widget_modify_fg(tpi,GTK_STATE_NORMAL,&color);
gtk_label_set_text(tpi,inf);
}


void
on_ReturnNbreAffichage_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"NombreReclParL");
	window2 = create_Affichagehamza();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_OKNbreReclam_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"AfficheNbreReclamation");
	window2 = create_NombreReclParL();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_AllerReclamation_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"MenuDeChoix");
	window2 = create_Affichagehamza();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_ExitChoix_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_RetourChoix_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"MenuDeChoix");
	window2 = create_page1();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_RetourMenuRec_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"Affichagehamza");
	window2 = create_MenuDeChoix();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}





void
on_modif_aff_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sup_aff_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"aff_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"sup_th");
   window2=create_sup_th();
   gtk_widget_show(window2);
}

void
on_act_aff_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *current_window ; 
	GtkWidget * treeview ; 
	current_window = lookup_widget(objet,"aff_th");
	
	treeview = lookup_widget(current_window,"treeview_th");
	affiche_election(treeview);

}


void
on_dec_aff__clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"aff_th");
   gtk_widget_destroy(window1);

   window2=create_page4();
   gtk_widget_show(window2);
}


void
on_ajout_aff_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"aff_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"aj_th");
   window2=create_aj_th();
   gtk_widget_show(window2);
}


void
on_button_confirm_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_id_supp;
election c;

entry_id_supp=lookup_widget(button,"entry_id_supp1");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entry_id_supp)));
supprimer_election(c, c.id );
GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"sup_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"aff_th");
   window2=create_aff_th();
   gtk_widget_show(window2);
}


void
on_retour_supp_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"sup_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"aff_th");
   window2=create_aff_th();
   gtk_widget_show(window2);
}


void
on_recherche_id_modif_clicked          (GtkWidget       *objet,
                                           gpointer         user_data)
{
	GtkWidget *entry_id_modif;
	GtkWidget *label36;
	GtkWidget *label37;
	GtkWidget *entry_id2_modif;
	GtkWidget *label38;
	GtkWidget *ariana_modif;
	GtkWidget *tunis_modif;
	GtkWidget *label39;
	GtkWidget *combobox2;
	GtkWidget *spinbutton10_j;
	GtkWidget *label24;
	GtkWidget *spinbutton11_m;
	GtkWidget *spinbutton12_a;
	GtkWidget *label25;
	GtkWidget *entry5_nbh;
	GtkWidget *checkbutton2;
	GtkWidget *confirm_modif;
	

	char id[20];
	election e;
	int xt;

	entry_id_modif=lookup_widget(objet,"entry_id_modif1");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry_id_modif)));
	xt=chercher("election.txt",id);
	if (xt==1)
	{ label36=lookup_widget(objet,"label260");
	  gtk_label_set_text(GTK_LABEL(label36),"id trouveé");

	entry_id2_modif=lookup_widget(objet,"entry_id2_modif");
	gtk_widget_show(entry_id2_modif);
	

	label38=lookup_widget(objet,"label267");
	gtk_widget_show(label38);

	label37=lookup_widget(objet,"label266");
	gtk_widget_show(label37);

	ariana_modif=lookup_widget(objet,"ariana_modif");
	gtk_widget_show(ariana_modif);

	tunis_modif=lookup_widget(objet,"tunis_modif");
	gtk_widget_show(tunis_modif);

	label39=lookup_widget(objet,"label265");
	gtk_widget_show(label39);

	combobox2=lookup_widget(objet,"combobox22");
	gtk_widget_show(combobox2);

	spinbutton10_j=lookup_widget(objet,"spinbutton10_j");
	gtk_widget_show(spinbutton10_j);

	label25=lookup_widget(objet,"label264");
	gtk_widget_show(label25);

	spinbutton11_m=lookup_widget(objet,"spinbutton11_m");
	gtk_widget_show(spinbutton11_m);

	spinbutton12_a=lookup_widget(objet,"spinbutton12_a");
	gtk_widget_show(spinbutton12_a);

	label24=lookup_widget(objet,"label263");
	gtk_widget_show(label24);

	entry5_nbh=lookup_widget(objet,"entry5_nbh");
	gtk_widget_show(entry5_nbh);

	checkbutton2=lookup_widget(objet,"checkbutton22");
	gtk_widget_show(checkbutton2);

	confirm_modif=lookup_widget(objet,"confirm_modif1");
	gtk_widget_show(confirm_modif);

	

	

	}
	else {
		label36=lookup_widget(objet,"label36");
	  gtk_label_set_text(GTK_LABEL(label36),"id introuvables!!!!");
	 }
}



void
on_ariana_modif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		w=1;
	}
}


void
on_tunis_modif_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		w=2;
	}
}


void
on_checkbutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	
}


void
on_confirm_modif1_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
election c;

char idme[20];
GtkWidget *mdf_th;
GtkWidget *idr,*ide,*nbhe,*jour,*mois,*annee,*muni,*checkbutton_m;



ide=lookup_widget(button,"entry_id2_modif");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(ide)));
nbhe=lookup_widget(button,"entry5_nbh");
c.nbh=atoi(gtk_entry_get_text(GTK_ENTRY(nbhe)));
//spin

jour=lookup_widget(button,"spinbutton10_j");
c.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(button,"spinbutton11_m");
c.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(button,"spinbutton12_a");
c.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));



//combo
muni=lookup_widget(button,"combobox22");
strcpy(c.muni,gtk_combo_box_get_active_text(GTK_COMBO_BOX(muni)));
//radio
	if(y == 1){
		strcpy(c.gov,"Ariana");
	}
	else{
		strcpy(c.gov,"Tunis");
	}

//nbc
	if(c.nbh<5001){
	strcpy(c.nbcs,"10");
	}
	else if(c.nbh<10001){
	strcpy(c.nbcs,"12");
	}
	else if(c.nbh<25001){
	strcpy(c.nbcs,"16");
	}
	else if(c.nbh<50001){
	strcpy(c.nbcs,"22");
	}
	else if(c.nbh<100001){
	strcpy(c.nbcs,"30");
	}
	else if(c.nbh<500001){
	strcpy(c.nbcs,"40");
	}
	else {
	strcpy(c.nbcs,"60");
	}


checkbutton_m=lookup_widget(button,"checkbutton22");
if (tab[0]==1)
	strcpy(c.robot,"non_robot");
else if(tab[0]==0)
	strcpy(c.robot,"robot!!!");
idr=lookup_widget(button,"entry_id_modif1");
strcpy(idme,gtk_entry_get_text(GTK_ENTRY(idr)));
supprimer_election( c, idme );
ajouter_election( c );

   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"mdf_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"aff_th");
   window2=create_aff_th();
   gtk_widget_show(window2);

}


void
on_retour_modif_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"mdf_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"aff_th");
   window2=create_aff_th();
   gtk_widget_show(window2);
}


void
on_ariana_aj_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		z=1;
	}
}


void
on_Tunis_ajj_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		z=2;
	}
}


void
on_checkbutton22_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirm_ajj_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
election c;
int x;
GtkWidget *ide,*nbhe,*jour,*mois,*annee,*muni,*checkbutton_aj;



ide=lookup_widget(button,"entry_id_aj");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(ide)));
nbhe=lookup_widget(button,"entrynbh");
c.nbh=atoi(gtk_entry_get_text(GTK_ENTRY(nbhe)));
//spin

jour=lookup_widget(button,"spinbutton7_ajj");
c.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(button,"spinbutton8_ajm");
c.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(button,"spinbutton9_ajm");
c.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));



//combo
muni=lookup_widget(button,"combobox11");
strcpy(c.muni,gtk_combo_box_get_active_text(GTK_COMBO_BOX(muni)));
//radio
	if(z == 1){
		strcpy(c.gov,"Ariana");
	}
	else{
		strcpy(c.gov,"Tunis");
	}

//nbc
	if(c.nbh<5001){
	strcpy(c.nbcs,"10");
	}
	else if(c.nbh<10001){
	strcpy(c.nbcs,"12");
	}
	else if(c.nbh<25001){
	strcpy(c.nbcs,"16");
	}
	else if(c.nbh<50001){
	strcpy(c.nbcs,"22");
	}
	else if(c.nbh<100001){
	strcpy(c.nbcs,"30");
	}
	else if(c.nbh<500001){
	strcpy(c.nbcs,"40");
	}
	else {
	strcpy(c.nbcs,"60");
	}


checkbutton_aj=lookup_widget(button,"checkbutton111");
if (tab[1]==1)
	strcpy(c.robot,"non_robot");
else if(tab[1]==1)
	strcpy(c.robot,"robot!!!");
ajouter_election( c );
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"aj_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"aff_th");
   window2=create_aff_th();
   gtk_widget_show(window2);
}



void
on_retour_ajj_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"aj_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"aff_th");
   window2=create_aff_th();
   gtk_widget_show(window2);
}


void
on_checkbutton111_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	tab[1]=1;
}


void
on_checkbutton22_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	tab[0]=1;
}


void
on_th_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"page4");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"aff_th");
   window2=create_aff_th();
   gtk_widget_show(window2);
}

void
on_treeview_th_row_activated           (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

       GtkTreeIter iter;
    

    gchar id;
    gint jour;
    gint mois;
    gint annee;
    gchar gov;
    gint nbh;
    gchar nbcs;
    gchar muni;
    gchar robot;


election e;
GtkTreeModel *model = gtk_tree_view_get_model(treeview1);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&jour,2,&mois,3,&annee,4,&gov,5,&nbh,6,&nbcs,7,&muni,8,&robot,-1);
strcpy(e.id,id);
strcpy(e.jour,jour);
strcpy(e.mois,mois);
strcpy(e.annee,annee);
strcpy(e.gov,gov);
strcpy(e.nbh,nbh);
strcpy(e.nbcs,nbcs);
strcpy(e.muni,muni);
strcpy(e.robot,robot);
affiche_election(treeview1);
}

}


void
on_modif_aff1_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"aff_th");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"mdf_th");
   window2=create_mdf_th();
   gtk_widget_show(window2);
}

void
on_voterSH_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page3=create_page3();
gtk_widget_show (page3);

}


void
on_LcondidatSH_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"MenuDeChoix");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"int1");
   window2=create_int1();
   gtk_widget_show(window2);
}


void
on_statSarra_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_afficheGrapheSarra_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}

void displayStatTreeView(GtkWidget *treeview, const char* statPath) {

 GtkListStore *store = gtk_tree_view_get_model(treeview);
if (store){
gtk_list_store_clear(store);
printf("00000000\n");
} else {
GtkCellRenderer *renderer;



renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Homme",  
                                               renderer,
                                              "text", 0,
                                               NULL);

renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Femme",  
                                               renderer,
                                              "text",  1,
                                               NULL);

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Taux",  
                                               renderer,
                                              "text", 2,
                                               NULL);


 store = gtk_list_store_new (3, G_TYPE_INT, G_TYPE_INT, G_TYPE_FLOAT);
} 
	
double taux;
int nbrOfMen;
int nbrOfWomen;

printf("aaaa\n");
FILE *file = fopen(statPath, "r");
while(fscanf(file, "taux : %lf / homme : %d / femme : %d \n", &taux, &nbrOfMen, &nbrOfWomen) != EOF){	

	GtkTreeIter iter;
	gtk_list_store_append (store, &iter);
	
	gtk_list_store_set (store, &iter, 0, nbrOfMen, 1, nbrOfWomen, 2, taux, -1);

}
fclose(file);

gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

}

void plotStats(int max, int nbrOfMen, int nbrOfWomen, double votes) {
	char* command0 = "clear";
	char* command1 = "set title \"Statistiques des votes\"";

	char command2[200];
	sprintf(command2, "set xrange [0:%d]", max);
	
	char command3[200];
	sprintf(command3, "set yrange [0:%d]", max);
	
	char command4[200];
	sprintf(command4, "set label \"(Homme)\" at 0.5,%.1f center", (float) (nbrOfMen + 1.5));
	
	char command5[200];
	sprintf(command5, "set label \"(Femme)\" at 2.5,%.1f center", (float) (nbrOfWomen + 1.5));
	
	
	char command7[200];
	sprintf(command7, "set object 1 rect from 0,0 to 1,%d fc lt 2 front", nbrOfMen);
	
	char command8[200];
	sprintf(command8, "set object 2 rect from 2,0 to 3,%d fc lt 1 front", nbrOfWomen);
	

	
	char * commandsForGnuplot[] = {command0, command1, command2, command3, command4, command5, command7, command8, 				"plot 0"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

    for (int i=0; i < 9; i++)
    {
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
    }
    
    fclose(gnuplotPipe);
    
    	char* command11 = "set title \"Taux des votes\"";

	char command22[200] = "set xrange [0:5]";
	
	char command33[200] = "set yrange [0:100]";
	
	char command44[200];
	sprintf(command44, "set object 1 rect from 2,0 to 3,%.2f fc lt 3 front", (float) (votes * 100));
	printf("%f\n", (float) (votes * 100));
	
	char command55[200];
	sprintf(command55, "set label \"%.2f %\" at 2.5,%.1f center", (float) (votes * 100), (float) (votes * 100 + 5));
	printf("%f\n", (float) (votes * 100));
	
	char *commandsForGnuplot1[] = {command11, command22, command33, command44, command55, "plot 0"};
    gnuplotPipe = popen ("gnuplot -persistent", "w");

    for (int i=0; i < 6; i++)
    {
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot1[i]);
    }
    
    fclose(gnuplotPipe);
}

void
on_button_supprimerfer_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_supprimer ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}





void
on_button_chercherfer_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_chercher ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_afficherfer_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_afficher ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_ajouterfer_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_ajouter ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}


void
on_button_suppferr_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
*idbureau,*type,*output;
int x;
output=lookup_widget(objet_graphique,"label21fer");
idbureau=lookup_widget(objet_graphique,"entry5fer");
idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
x=supprimer_bureau (idbureau);
if (x==0)
gtk_label_set_text(GTK_LABEL(output),"bureau est supprimé avec succé");
else
gtk_label_set_text(GTK_LABEL(output),"bureau n'est pas supprimé");

}


void
on_button13fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_supprimer");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button17fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_ajouter");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_confirmerfer_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
 *nomecole,*idbureau,*idagent,*jour,*mois,*annee,*type,*capelect,*capobs,*windowinterface;


bureau c;

jour=lookup_widget(objet_graphique,"spinbutton_jourfer");
c.datef.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(objet_graphique,"spinbutton_moisfer");
c.datef.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(objet_graphique,"spinbutton_anneefer");
c.datef.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

nomecole=lookup_widget(objet_graphique,"entry_necolefer");
idbureau=lookup_widget(objet_graphique,"entry_idbureaufer");
idagent=lookup_widget(objet_graphique,"entry_idagentfer");
capelect=lookup_widget(objet_graphique,"entry_nefer");
capobs=lookup_widget(objet_graphique,"entry_nofer");
strcpy(c.nomecole,gtk_entry_get_text(GTK_ENTRY(nomecole)));
c.idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
strcpy(c.idagent,gtk_entry_get_text(GTK_ENTRY(idagent)));
c.capelect=atoi(gtk_entry_get_text(GTK_ENTRY(capelect)));
c.capobs=atoi(gtk_entry_get_text(GTK_ENTRY(capobs)));
if (x==1)
c.type=1;
else if (x==2)
c.type=2;
else if (x==3)
c.type=3;
ajout_bureau(c);

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"window_ajouter");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}



void
on_checkbutton_firas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton1fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=1;
}


void
on_radiobutton2fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=2;
}



void
on_radiobutton3fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=3;
}


void
on_button_dfer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget
*idbureau,*type,*output;
int x;
output=lookup_widget(button,"label24fer");
idbureau=lookup_widget(button,"entry_dfer");
idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
x=cherche_id(idbureau);
if (x==0)
gtk_label_set_text(GTK_LABEL(output),"Le bureau existe, veillez le modifier ou le supprimer");
else
gtk_label_set_text(GTK_LABEL(output),"Le bureau n'existe pas");
}


void
on_button16fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
	
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_chercher");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button14fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_modifier");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button15fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_modifier");
	window2 = create_window_afficher ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}


void
on_radiobutton4fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	type2=1;
}


void
on_radiobutton6fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	type2=3;
}


void
on_radiobutton5fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	type2=2;
}


void
on_treeviewfer_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button11fer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(button,"window_afficher");
window_afficher=create_window_afficher();
gtk_widget_show(window_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(window_afficher,"treeview1fer");
afficher_bureau(treeview1);

}



void
on_button12fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_afficher");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_modifer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *idbureau,*type,*vmax,*vmin;
	bureau c;
	idbureau=lookup_widget(button,"entry_modiffer");
	//type=lookup_widget(button,"label21");
	vmax=lookup_widget(button,"entry_nce");
	vmin=lookup_widget(button,"entry_nco");
	c.idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
	c.capelect=atoi(gtk_entry_get_text(GTK_ENTRY(vmax)));
	c.capobs=atoi(gtk_entry_get_text(GTK_ENTRY(vmin)));
	c.type=type2;
	
	printf("%d\n",type2);
	modifier(c.idbureau,c);

}




void
on_button_modifierfer_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_modifier ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);


}

void
on_bureauV_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"page4");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_suppch_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"interface1");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"supprimer");
   window2=create_supprimer();
   gtk_widget_show(window2);
}


void
on_modifch_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"interface1");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"modifier");
   window2=create_modifier();
   gtk_widget_show(window2);
}





void
on_ajoutch_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"interface1");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"ajouter");
   window2=create_ajouter();
   gtk_widget_show(window2);
}


void
on_refch_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *current_window ; 
	GtkWidget * treeview ; 
	current_window = lookup_widget(objet,"interface1");
	
	treeview = lookup_widget(current_window,"trv");
	afficherliste(treeview,"liste.txt");
}


void
on_closech_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(objet_graphique,"interface1");
   gtk_widget_destroy(window1);
   window2=lookup_widget(objet_graphique,"page4");
   window2=create_page4();
   gtk_widget_show(window2);
}


void
on_radiobutton2ch_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{z=0;}
}


void
on_confirch_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
liste l;
int x;	
	GtkWidget *id,*idt, *n1, *n2, *n3, *j, *m, *a, *or, *output;


l.nbvote=0;
id=lookup_widget(button,"entry1ch");
strcpy(l.id,gtk_entry_get_text(GTK_ENTRY(id)));
idt=lookup_widget(button,"entry2ch");
strcpy(l.idt,gtk_entry_get_text(GTK_ENTRY(idt)));
n1=lookup_widget(button,"entry3ch");
strcpy(l.n1,gtk_entry_get_text(GTK_ENTRY(n1)));
n2=lookup_widget(button,"entry4ch");
strcpy(l.n2,gtk_entry_get_text(GTK_ENTRY(n2)));
n3=lookup_widget(button,"entry5ch");
strcpy(l.n3,gtk_entry_get_text(GTK_ENTRY(n3)));

output = lookup_widget(button,"label37ch");
//spin
j=lookup_widget(button,"spinbutton1ch");
l.dch.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
m=lookup_widget(button,"spinbutton2ch");
l.dch.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
a=lookup_widget(button,"spinbutton3ch");
l.dch.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));
//radio
	if(z == 1){
		strcpy(l.genre,"Homme");
	}
	else{
		strcpy(l.genre,"Femme");
	}
//combo
or=lookup_widget(button,"comboboxentry1ch");
strcpy(l.orient,gtk_combo_box_get_active_text(GTK_COMBO_BOX(or)));

ajouter(l);
gtk_label_set_text(GTK_LABEL(output),"ajout avec succés");
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"ajouter");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"interface1");
   window2=create_interface1();
   gtk_widget_show(window2);


}


void
on_hom1ch_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"ajouter");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"interface1");
   window2=create_interface1();
   gtk_widget_show(window2);
}


void
on_hom2ch_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"modifier");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"interface1");
   window2=create_interface1();
   gtk_widget_show(window2);
}


void
on_confir_modifch_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *entry, *n1 , *n2 , *n3 , *con, *output;


int x,y;
char id[30],it[30],i1[30],i2[30],i3[30],or[30];
int j,m,a;
liste l;
	
	entry=lookup_widget(objet,"entry6ch");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));
	x=chercherch(id);
	if (x==1)
	{
		
		
		strcpy(l.idt,findlById(id).idt);
		strcpy(l.id,findlById(id).id);
		
		
		n1=lookup_widget(objet,"entry7ch");
		strcpy(l.n1,gtk_entry_get_text(GTK_ENTRY(n1)));
		
		n2=lookup_widget(objet,"entry8ch");
		strcpy(l.n2,gtk_entry_get_text(GTK_ENTRY(n2)));

		n3=lookup_widget(objet,"entry9ch");
		strcpy(l.n3,gtk_entry_get_text(GTK_ENTRY(n3)));
l.nbvote=0;
		l.dch.j=findlById(id).dch.j;
		l.dch.m=findlById(id).dch.m;
		l.dch.a=findlById(id).dch.a;
	strcpy(l.genre,findlById(id).genre);
		output=lookup_widget(objet,"label19ch");
	con = lookup_widget(objet,"comboboxentry2ch");
	strcpy(l.orient,gtk_combo_box_get_active_text(GTK_COMBO_BOX(con)));

supprimer( id);
ajouter( l);

/*y=modifierl(id,l1);
if (y==1)
{
gtk_label_set_text(GTK_LABEL(output),"modification avec succés");
}
else
{
gtk_label_set_text(GTK_LABEL(output),"Erreur!!");}*/
		
	}
}


void
on_cherchch_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *entry6;

liste l;
int x;
char id[30];
char i2[30];
char i3[30];
char i1[30];

	entry6=lookup_widget(objet,"entry6ch");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry6)));
	x=chercherch(id);
	if (x==1)
	{
	GtkWidget *n1 , *n2 , *n3 , *cm, *msg, *l20, *l21, *l22, *l23, *con;
	msg=lookup_widget(objet,"label19ch");
	  gtk_label_set_text(GTK_LABEL(msg),"id trouvée");
		
		n1=lookup_widget(objet,"entry7ch");
		strcpy(i1,findlById(id).n1);
		gtk_entry_set_text(GTK_ENTRY(n1),i1);
		n2=lookup_widget(objet,"entry8ch");
		strcpy(i2,findlById(id).n2);
		gtk_entry_set_text(GTK_ENTRY(n2),i2);
		n3=lookup_widget(objet,"entry9ch");
		strcpy(i3,findlById(id).n3);
		gtk_entry_set_text(GTK_ENTRY(n3),i3);
		cm=lookup_widget(objet,"comboboxentry2ch");
		strcpy(l.orient,findlById(id).orient);
		int comboValue ; 
		if(strcmp(l.orient,"Droite") == 0){
			comboValue = 0 ;
		}
		else if(strcmp(l.orient,"Centre") == 0 ){
			comboValue = 1 ;
		}
		else{
			comboValue = 2 ;
		}

		gtk_combo_box_set_active(cm,comboValue);
		
	}
else {
	GtkWidget *msg;
		msg=lookup_widget(objet,"label19ch");
	  gtk_label_set_text(GTK_LABEL(msg),"id introuvable!!");
	 }

}



void
on_confir_suppch_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_id_supp;
liste l;

entry_id_supp=lookup_widget(button,"entry10ch");
strcpy(l.id,gtk_entry_get_text(GTK_ENTRY(entry_id_supp)));
supprimer( l.id );
GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"supprimer");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"interface1");
   window2=create_interface1();
   gtk_widget_show(window2);
}


void
on_hom3ch_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"supprimer");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"interface1");
   window2=create_interface1();
   gtk_widget_show(window2);
}


void
on_treeview1ch_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_entrerch_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *current_window ; 
	GtkWidget * treeview ; 
	current_window = lookup_widget(objet,"int1");
	
	treeview = lookup_widget(current_window,"treeview1ch");
	afficherlistelc(treeview,"liste.txt");
}



void
on_radiobutton1ch_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{z=1;}
}


void
on_trv_row_activated                   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ch_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"page4");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"interface1");
   window2=create_interface1();
   gtk_widget_show(window2);
}

/* ----------------------------------- RECLAMATION -------------------------------------------------- */ 


void
on_checkAjout_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		check = 1 ;
	}
	else{
		check = 0 ; 
	}
}


void
on_okDialogSupp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *dialog ;
	dialog = lookup_widget(button,"supDialog");
	gtk_widget_destroy(dialog);
}


void
on_triNomReclm_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget * treeview ; 	
	treeview = lookup_widget(button,"treeviewRecla");
	trierReclamtion() ; 
	afficher_reclamation(treeview,"triReclamation.txt");
	remove("triReclamation.txt");
}


void
on_toRechReclama_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2  ;
	window1 = create_critereRec ();

	gtk_widget_show(window1);

	window2 = lookup_widget(button,"Affichagehamza");
	gtk_widget_destroy(window2);
}


void
on_retourRechCritere_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2  ;
	window1 = create_Affichagehamza ();

	gtk_widget_show(window1);

	window2 = lookup_widget(button,"critereRec");
	gtk_widget_destroy(window2);
}

int critere = 1 ; 
void
on_radioCrit1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		critere=1;
	}
}


void
on_radioCriter2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		critere=2;
	}
}


void
on_afficherCritere_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *input  , *treeview;

	input = lookup_widget(button,"critere_value");

	char inputValue[30];
	strcpy(inputValue,gtk_entry_get_text(GTK_ENTRY(input)));

	treeview = lookup_widget(button,"treeviewCritere");

	if(strcmp(inputValue,"") == 0){
		afficher_reclamation(treeview,"reclamation.txt");
	}else{
		if(critere == 1){
			filtrerReclamationType(inputValue);
			afficher_reclamation(treeview,"rectype.txt");
			remove("rectype.txt");
		}else{
			int nombre = atoi(inputValue ) ;
			filtrerReclamationNB(nombre);
			afficher_reclamation(treeview,"recNombre.txt");
			remove("recNombre.txt");
		}	
	}
	
}


int toggle;
int t;
char search[100];

int m;

void
on_treeview_mm_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
observateur o;
GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* prenom;
gchar* nationalite;
gchar* profession;
gchar* sexe;
gchar* gouvernerat;
gchar* nbv;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&nationalite,4,&profession,5,&sexe,6,&gouvernerat,7,&nbv,-1);



}

}


void
on_button_ajouter_mm2_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *affichage_ob,*ajout_observateur;

affichage_ob=lookup_widget(button,"affichage_ob");
ajout_observateur=create_ajout_observation();
gtk_widget_show(ajout_observateur);
gtk_widget_destroy(affichage_ob);
}





void
on_button_modifier_mm3_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *affichage_ob,*modifier_obs;

affichage_ob=lookup_widget(button,"affichage_ob");
modifier_obs=create_modifier_obs();
gtk_widget_show(modifier_obs);
gtk_widget_destroy(affichage_ob);
}


void
on_button_chercher_mm8_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
char identifiant[20];
GtkWidget *treeview,*filter,*label1;
treeview=lookup_widget(button,"treeview_mm");
filter=lookup_widget(button,"entry_mm7");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(filter)));
if (verif(identifiant)==0)
{
	chercherh(treeview,identifiant);
label1=lookup_widget(button,"label_recherche_mm");
gtk_label_set_text(GTK_LABEL(label1),"Observateur existe");
strcpy(search,identifiant);
}
else
{
label1=lookup_widget(button,"label_recherche_mm");
gtk_label_set_text(GTK_LABEL(label1),"Observateur n'existe pas");
}
}


void
on_button_actualiser_olm10_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_mm;
GtkWidget *affichage_ob;
affichage_ob=lookup_widget(button,"affichage_ob");
treeview_mm=lookup_widget(affichage_ob,"treeview_mm");
afficher_observateur(GTK_TREE_VIEW(treeview_mm),"observateur.txt");
}


void
on_checkbutton_mmp5_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   t=1;
/*tunisien*/
}


void
on_button_ajouter_obs_mm24_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
observateur o;


GtkWidget *id, *nom, * prenom, *profession, *gouvernerat, *nbv, *label;

id=lookup_widget (button, "entry_mm17");
strcpy(o.id,gtk_entry_get_text (GTK_ENTRY (id)));
 
nom=lookup_widget(button, "entry_mm99");
strcpy(o.nom,gtk_entry_get_text (GTK_ENTRY (nom)));

prenom=lookup_widget(button, "entry_mm20");
strcpy(o.prenom,gtk_entry_get_text (GTK_ENTRY(prenom)));

if (t==1) 
		strcpy(o.nationalite,"tunisien(ne)") ; 
else //if (t==2)
		strcpy(o.nationalite,"etranger(e)") ;

profession=lookup_widget (button, "comboboxentry_mm1");
strcpy(o.profession,gtk_combo_box_get_active_text(GTK_COMBO_BOX(profession)));


if (toggle==1)
{strcpy(o.sexe,"homme");}
else
{strcpy(o.sexe,"femme");}
 

gouvernerat=lookup_widget (button, "comboboxentry_mm888");
strcpy(o.gouvernerat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouvernerat)));

nbv=lookup_widget (button, "spinbuttonmm444");
o.nbv=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbv));

label=lookup_widget(button, "label_conf_ajout");

ajouterh(o);
gtk_label_set_text(GTK_LABEL(label),"Observateur ajouté avec succés :)");
}



void
on_button_retour_aff_mm26_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affichage_ob;
GtkWidget *ajout_observateur;

ajout_observateur=lookup_widget(button,"ajout_observateur");

gtk_widget_destroy(ajout_observateur); 
affichage_ob=lookup_widget(button,"affichage_ob");
affichage_ob=create_affichage_ob();

gtk_widget_show(affichage_ob);
}


void
on_radiobutton_mm2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		toggle=1;
	}
/*homme*/
}


void
on_radiobutton_mm1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		toggle=2;
	}
/*femme*/
}


void
on_button_verifier_m_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *idMod ; 
	observateur o; 

	char id[20] ; 
	idMod = lookup_widget(button,"entry_mm15");


	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idMod)));
	if(rech_id(id)){
               //labs = lookup_widget(button, "label_existance_id");
               //gtk_label_set_text(GTK_LABEL(labs),"Observateur trouvé");


		GtkWidget *nom , *prenom , *profession  , *gouvernerat , *nbv ,*label,*homme,*femme ,*tun,*etr  ;

		nom = lookup_widget(button,"entry_mm16");
		strcpy(o.nom,findObsById(id).nom);
		gtk_entry_set_text(GTK_ENTRY(nom),o.nom);
		

		prenom = lookup_widget(button,"entry_mm17");
		strcpy(o.prenom,findObsById(id).prenom);
		gtk_entry_set_text(GTK_ENTRY(prenom),o.prenom);

		profession = lookup_widget(button,"comboboxentry_mm65");
		strcpy(o.profession,findObsById(id).profession);

        homme = lookup_widget(button, "radiobutton_mm102");
        femme = lookup_widget(button, "radiobutton_mm100");

 if(strcmp(o.sexe,"homme")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme),TRUE);}
strcpy(o.sexe,findObsById(id).sexe);

if(strcmp(o.sexe,"femme")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme),TRUE);}
strcpy(o.sexe,findObsById(id).sexe);
        
        tun = lookup_widget(button, "checkbutton_mmpp");
        etr = lookup_widget(button, "checkbutton_mmhh");

 if(strcmp(o.nationalite,"tunisien(ne)")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(tun),TRUE);}
strcpy(o.nationalite,findObsById(id).nationalite);

if(strcmp(o.nationalite,"etranger(e)")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(etr),TRUE);}
strcpy(o.nationalite,findObsById(id).nationalite);



		int comboEntry ; 
		if(strcmp(o.profession,"parti_politique") == 0){
			comboEntry = 0 ;
		}
		else if(strcmp(o.profession,"presse") == 0 ){
			comboEntry = 1 ;
		}
		else if(strcmp(o.profession,"hote") == 0 ){
			comboEntry = 2 ;
		}
		else if(strcmp(o.profession,"societe_civile") == 0 ){
			comboEntry = 3 ;
		}
		else{
			comboEntry = 4 ;
		}
		gtk_combo_box_set_active(profession,comboEntry);
//////////////////////////////////////////////////////////////////////////////

		gouvernerat = lookup_widget(button,"comboboxentry_mmm84");
		strcpy(o.gouvernerat,findObsById(id).gouvernerat);

		int comboEntry2 ; 
		if(strcmp(o.gouvernerat,"Ariana") == 0){
			comboEntry2 = 0 ;
		}
		else if(strcmp(o.gouvernerat,"Ben_Arous") == 0 ){
			comboEntry2 = 1 ;
		}
		else if(strcmp(o.gouvernerat,"Tunis") == 0 ){
			comboEntry2 = 2 ;
		}
		else if(strcmp(o.gouvernerat,"Sousse") == 0 ){
			comboEntry2 = 3;
		}
		else if(strcmp(o.gouvernerat,"Sfax") == 0 ){
			comboEntry2 = 4 ;
		}
		else if(strcmp(o.gouvernerat,"Nabeul") == 0 ){
			comboEntry2 = 5 ;
		}
		else if(strcmp(o.gouvernerat,"Sidi_Bouzid") == 0 ){
			comboEntry2 = 6 ;
		}
		else if(strcmp(o.gouvernerat,"Bizerte") == 0 ){
			comboEntry2 = 7 ;
		}
		else{
			comboEntry2 = 8 ;
		}
		gtk_combo_box_set_active(gouvernerat,comboEntry2);
/////////////////////////////////////////////////////////////////////////
		nbv = lookup_widget(button,"spinbutton_mm711");
		o.nbv = findObsById(id).nbv;
		gtk_spin_button_set_value(nbv,o.nbv);

                label=lookup_widget(button, "label_existance_id");
                gtk_label_set_text(GTK_LABEL(label),"Observateur trouvé !!!");
        }
        else    
              {
                GtkWidget *label;              
                label=lookup_widget(button, "label_existance_id");
                gtk_label_set_text(GTK_LABEL(label),"Observateur n'existe pas !!!");}
}



void
on_checkbutton_mmpp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   m=1;
/*tunisien*/
}


void
on_checkbutton_mmhh_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   m=2;
/*etranger*/
}


void
on_radiobutton_mm100_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//modif_femme//
	if(gtk_toggle_button_get_active(togglebutton)){
		y=2;
	}

}


void
on_radiobutton_mm102_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//modif_homme//
	if(gtk_toggle_button_get_active(togglebutton)){
			y=1;
	}

}


void
on_button_modifier_obs_mm41_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idMod  ;
GtkWidget *nom , *prenom , *sexe ,*nationalite,*profession, *gouvernerat, *nbv, *label ;
	
	observateur o ; 
        char id[20];
	idMod = lookup_widget(button,"entry_mm15");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idMod)));
        
	if(rech_id(id))
         {
		observateur o ; 
		strcpy(o.id,id);

	
	nom = lookup_widget(button,"entry_mm16");
	strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	prenom = lookup_widget(button,"entry_mm17");
	strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

	gouvernerat=lookup_widget(button,"comboboxentry_mmm84");
	strcpy(o.gouvernerat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouvernerat)));

	profession = lookup_widget(button,"comboboxentry_mm65");
	strcpy(o.profession,gtk_combo_box_get_active_text(GTK_COMBO_BOX(profession)));
        

	nbv = lookup_widget(button,"spinbutton_nbv2_modifier_obs_KB");
	o.nbv = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbv));
        

	if(y == 1)
        {
		strcpy(o.sexe,"homme");
	}
	else
        {
		strcpy(o.sexe,"femme");
	}
      

        if(m == 1)
        {
		strcpy(o.nationalite,"tunisien(nne)");
	}
	else
        {
		strcpy(o.nationalite,"etranger(e)");
	}

            modifierh(o);
            
            label=lookup_widget(button, "label_conf_modif");
            gtk_label_set_text(GTK_LABEL(label),"Observateur modifié avec succés !");
}
}



void
on_button_retour_aff_demodif_mm32_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affichage_ob;
GtkWidget *modifier_obs;

modifier_obs=lookup_widget(button,"modifier_obs");

gtk_widget_destroy(modifier_obs); 
affichage_ob=lookup_widget(button,"affichage_ob");
affichage_ob=create_affichage_ob();

gtk_widget_show(affichage_ob);
}


void
on_button_supprimer_lolm6_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
observateur o;
GtkWidget *identifiant, *label1;

identifiant=lookup_widget (button, "entry_mm7"); 
strcpy(o.id,gtk_entry_get_text (GTK_ENTRY (identifiant)));
label1=lookup_widget(button, "label_supp_mm");
supprimerh(o.id);
gtk_label_set_text(GTK_LABEL(label1),"Suppression éffectué");
}


void
on_retour_sup_h_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affichage_ob;
GtkWidget *supp;

supp=lookup_widget(button,"supp");

gtk_widget_destroy(supp); 
affichage_ob=lookup_widget(button,"affichage_ob");
affichage_ob=create_affichage_ob();

gtk_widget_show(supp);
}




void
on_he_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *window1;
   GtkWidget *window2;
   window1=lookup_widget(button,"page4");
   gtk_widget_destroy(window1);
   window2=lookup_widget(button,"affichage_ob");
   window2=create_affichage_ob();
   gtk_widget_show(window2);
}

void
on_score_condidats_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page = create_treeViewScore();
gtk_widget_show (page);

GtkWidget* treeView = lookup_widget(page,"treeview2");

displayScoreTreeView(treeView, "./vote.txt");
}


void
on_tauxPartEtDeVote_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
calculateStats("./user.txt", "./stat.txt");

GtkWidget *aaaa = create_page20();
gtk_widget_show (aaaa);


GtkWidget *statSarra = lookup_widget(aaaa, "statSarra");



displayStatTreeView(statSarra, "./stat.txt");
}


void
on_buttonExitPageStatSarra_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
exit(0);
}


void
on_returnPageStatSarra_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1 = lookup_widget(button, "pageStatSarra");
gtk_widget_destroy (page1);

GtkWidget *page2 = lookup_widget(page1, "page4");
gtk_widget_show (page2);
}


void
on_afficheStatScore_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
int voteEnnahdha;
int voteEetilefKarama;
int voteNidaTounes;
int voteJabhaChaabeya;

FILE *file = fopen("./vote.txt", "r");

fscanf(file, "Ennahdha : %d / Eetilef el karama : %d / Nida tounes : %d / Jabha chaabeya : %d \n", &voteEnnahdha, &voteEetilefKarama, &voteNidaTounes, &voteJabhaChaabeya);

fclose(file);

int max = voteEnnahdha;
if(max < voteEetilefKarama) {
max = voteEnnahdha;
}
if(max < voteNidaTounes) {
max = voteNidaTounes;
}
if(max < voteJabhaChaabeya) {
max = voteJabhaChaabeya;
}

plotScoreStats(max + 2, voteEnnahdha, voteEetilefKarama, voteNidaTounes, voteJabhaChaabeya);
}


void
on_afficherDiagVote_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
double taux;
int nbrOfMen;
int nbrOfWomen;

FILE *file = fopen("./stat.txt", "r");
while(fscanf(file, "taux : %lf / homme : %d / femme : %d \n", &taux, &nbrOfMen, &nbrOfWomen) != EOF){	

}
fclose(file);

printf("taux : %f\n", taux);
int max = nbrOfMen;
if(max < nbrOfWomen) {
max = nbrOfWomen;
}

plotStats(max + 2, nbrOfMen, nbrOfWomen, taux);
}


void
on_buttonExitTreeViewStatVote_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
exit(0);
}


void
on_annulerStatVote_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *page1 = lookup_widget(button, "page20");
gtk_widget_destroy (page1);

GtkWidget *page2 = lookup_widget(page1, "page4");
gtk_widget_show (page2);
}


void
on_exitStatScoreTreeView_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
exit(0);
}


void
on_annulercondidatTreeView_clicked     (GtkButton       *button,
                                        gpointer      user_data)
{
GtkWidget *page1 = lookup_widget(button, "treeViewScore");
gtk_widget_destroy (page1);

GtkWidget *page2 = lookup_widget(page1, "page4");
gtk_widget_show (page2);
}

void displayScoreTreeView(GtkWidget *treeview, const char* statPath) {

 GtkListStore *store = gtk_tree_view_get_model(treeview);
if (store){
gtk_list_store_clear(store);

} else {
GtkCellRenderer *renderer;


  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Candidat",  
                                               renderer,
                                              "text", 0,
                                               NULL);


renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
                                               -1,      
                                               "  Nombre de votes",  
                                               renderer,
                                              "text", 1,
                                               NULL);


 store = gtk_list_store_new (2, G_TYPE_STRING, G_TYPE_INT);
} 
	
int voteEnnahdha;
int voteEetilefKarama;
int voteNidaTounes;
int voteJabhaChaabeya;


printf("aaaa\n");
FILE *file = fopen(statPath, "r");

GtkTreeIter iter;

fscanf(file, "Ennahdha : %d / Eetilef el karama : %d / Nida tounes : %d / Jabha chaabeya : %d \n", &voteEnnahdha, &voteEetilefKarama, &voteNidaTounes, &voteJabhaChaabeya);

gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, 0, "Ennahdha", 1, voteEnnahdha, -1);

gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, 0, "Eetilef el karama", 1, voteEetilefKarama, -1);

gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, 0, "Nida tounes", 1, voteNidaTounes, -1);

gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, 0, "Jabha chaabeya", 1, voteJabhaChaabeya, -1);

fclose(file);

int max = voteEnnahdha;
if(max < voteEetilefKarama) {
max = voteEnnahdha;
}
if(max < voteNidaTounes) {
max = voteNidaTounes;
}
if(max < voteJabhaChaabeya) {
max = voteJabhaChaabeya;
}

gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

}

void plotScoreStats(int max, int voteEnnahdha, int voteEetilefKarama, int voteNidaTounes, int voteJabhaChaabeya) {
	char* command0 = "clear";
	char* command1 = "set title \"Score des candidats\"";

	char command2[200] = "set xrange [0:8]";

	
	char command3[200];
	sprintf(command3, "set yrange [0:%d]", max);
	
	char command4[200];
	sprintf(command4, "set label \"(Ennahdha)\" at 0.5,%.1f center", (float) (voteEnnahdha + 1.5));
	
	char command5[200];
	sprintf(command5, "set label \"(Eetilef el karama)\" at 2.5,%.1f center", (float) (voteEetilefKarama + 1.5));

	char command44[200];
	sprintf(command44, "set label \"(Nida tounes)\" at 4.5,%.1f center", (float) (voteNidaTounes + 1.5));
	
	char command55[200];
	sprintf(command55, "set label \"(Jabha chaabeya)\" at 6.5,%.1f center", (float) (voteJabhaChaabeya + 1.5));
	
	
	char command7[200];
	sprintf(command7, "set object 1 rect from 0,0 to 1,%d fc lt 2 front", voteEnnahdha);
	
	char command8[200];
	sprintf(command8, "set object 2 rect from 2,0 to 3,%d fc lt 1 front", voteEetilefKarama);

	char command77[200];
	sprintf(command77, "set object 3 rect from 4,0 to 5,%d fc lt 3 front", voteNidaTounes);
	
	char command88[200];
	sprintf(command88, "set object 4 rect from 6,0 to 7,%d fc lt 4 front", voteJabhaChaabeya);
	

	
	char * commandsForGnuplot[] = {command0, command1, command2, command3, command4, command5, command44, command55, command7, command8, command77, command88, 				"plot 0"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

    for (int i=0; i < 13; i++)
    {
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
    }
    
    fclose(gnuplotPipe);
}


void
on_Retourfirace_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"interface");
	window2 = create_page4 ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_exithadil_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"affichage_ob");
	window2 = create_page4 ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}

