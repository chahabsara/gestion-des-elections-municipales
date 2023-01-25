#include "user.h"

void save_users(User* users, char *filepath){
}

void save_user(User user, char *filepath){
}

User find_user_by_id(int id, char *filepath){
    User u;
    return u;
}

User* findUsers(char *filepath){
    return NULL;
}

void print_user(User user){
    printf("email: %s \n", user.email);
    printf("lastname: %s \n", user.lastname);
    printf("firstname: %s \n", user.firstname);
    printf("CIN: %s \n", user.identityCard);
printf("id: %d\n", user.id);

printf("vote place : %s\n", user.votePlace);

    printf("password: %s \n", user.password);
    printf("address: %s \n", user.address);
    printf("sexe: %s \n", user.sexe);
    printf("birthdate : %d/%d/%d\n", user.birthdate.day, user.birthdate.month, user.birthdate.year);
}

User* createUser(const char *email, const char *lastname, const char *firstname, const char *identityCard, const char *password, const char *sexe, int day, int month, int year, const char* address, int isAdmin, int voted, const char *votePlace, int id){
   User *user = (User*) malloc(sizeof(User));
 

   user->isAdmin = isAdmin;
   user->voted = voted;
   strcpy(user->lastname, lastname);
   strcpy(user->firstname, firstname);
   strcpy(user->identityCard, identityCard);
   strcpy(user->address, address);
   strcpy(user->email,email);
   strcpy(user->password,password);
   strcpy(user->sexe,sexe);
  ( user->birthdate).day = day;
   (user->birthdate).month = month;
  ( user->birthdate).year = year;
user->id = id;
strcpy(user->votePlace, votePlace);

   return user;
}

void saveUserToFile(User *user, const char *filepath) {
   FILE *file = fopen(filepath, "a");
   fprintf(file, "%s / %s / %s / %s / %s / %s / %d / %d / %d / %s / %d / %d / %s / %d \n", user->email, user->lastname, user->firstname, user->identityCard, user->password, user->sexe, ( user->birthdate).day, ( user->birthdate).month, ( user->birthdate).year, user->address, user->isAdmin, user->voted, user->votePlace, user->id);
   fclose(file);
}


void readUsersFromFile(User** users, const char *filepath) {																																																																						       
int counter = 0;
FILE *file = fopen(filepath, "r"); 
    if(file) {
      char email [200];
char lastname[200];
char firstname[200];
char identityCard[200];
char password[200];
char sexe[200];
char birthday[200];
char address[200];
int isAdmin;
int day;
int month;
int year;
int voted;
char votePlace[200];
int id;

while(fscanf(file, "%s / %s / %s / %s / %s / %s / %d / %d / %d / %s / %d / %d / %s / %d \n", email, lastname, firstname, identityCard, password, sexe, &day, &month, &year, address, &isAdmin, &voted, votePlace, &id) != EOF){

    User *user = createUser(email, lastname, firstname, identityCard, password, sexe, day, month, year, address, isAdmin, voted, votePlace, id);
    users[counter] = user;
																																																																			
    counter++;
}
    
    fclose(file);
    }


   
}

int getNumberOfUsers(char *filepath) { 
    FILE *file = fopen(filepath, "r");

if(file) {
    int lines = 0;

    while(!feof(file))
        {
            char ch = fgetc(file);
            if(ch == '\n')
                {
                    lines++;
                }
        }

        return lines;
} else {
return 0;
}
}


void deleteUserByEmail(char* email, char*filepath) {
printf("email : %s\n",email);
  int usersLength = getNumberOfUsers(filepath);
printf("length : %d\n", usersLength);
  User** users = (User**) malloc(sizeof(User) * usersLength);
 readUsersFromFile(users, filepath);

  int newSize = usersLength;

  for(int i=0; i<usersLength; i++) {
    printf("email: %s\n", users[i]->email);
    printf("cmp: %d\n", strcmp(users[i]->email, email));
    if(strcmp(users[i]->email, email) == 0) {
        newSize -= 1;
printf("size: %d\n", usersLength);
printf("new size: %d\n", newSize);

        for(int j=i; j<usersLength - 1; j++) {
            users[j] = users[j+1];
            
        }
    }
  }



  FILE *file = fopen(filepath, "w");
  fclose(file);
  for(int i=0; i<newSize; i++) {
    saveUserToFile(users[i], filepath);
    free(users[i]);
  }
}

int isUserExist(char* email, char* filepath) {
  int usersLength = getNumberOfUsers(filepath);
  User** users = (User**) malloc(sizeof(User) * usersLength);
 readUsersFromFile(users, filepath);

  int newSize = usersLength;

  for(int i=0; i<usersLength; i++) {
    if(strcmp(users[i]->email, email) == 0) {
	return 1;
    }
  }

return 0;
}

void updateUserToFile(User *user, const char *filepath) {

  int usersLength = getNumberOfUsers(filepath);
  User** users = (User**) malloc(sizeof(User) * usersLength);
 readUsersFromFile(users, filepath);

  

  for(int i=0; i<usersLength; i++) {
    
    if(strcmp(users[i]->email, user->email) == 0) {
	users[i] = user;
    }
  }



  FILE *file = fopen(filepath, "w");
  fclose(file);
  for(int i=0; i<usersLength; i++) {
    saveUserToFile(users[i], filepath);
    free(users[i]);
  }
}

User* login(char* email, char* password, const char *filepath) {
int usersLength = getNumberOfUsers(filepath);
  User** users = (User**) malloc(sizeof(User) * usersLength);
 readUsersFromFile(users, filepath);

  int newSize = usersLength;

  for(int i=0; i<usersLength; i++) {
    if(strcmp(users[i]->email, email) == 0 && strcmp(users[i]->password, password) == 0) {
	return users[i];
    }
  }
  return NULL;
}

void calculateStats(const char *filepath, const char *statPath) {
int nbrOfMen = 0;
int nbrOfWomen = 0;
int voted = 0;
float taux = 0;
int total = getNumberOfUsers(filepath);

User** users = (User**) malloc(sizeof(User) * total);
 readUsersFromFile(users, filepath);

  for(int i=0; i<total; i++) {
printf("voted : %d\n", users[i]->voted);
    if(strcmp(users[i]->sexe, "Homme") == 0) {
	nbrOfMen++;
    }

    if(strcmp(users[i]->sexe, "Femme") == 0) {
	nbrOfWomen++;
    }

    if(users[i]->voted == 1) {
	voted++;
    }
  }

taux = (float) ((float)voted / (float)total);

printf("taux : %f\n", taux);
printf("v : %d\n", voted);
printf("t : %d\n", total);

FILE *file = fopen(statPath, "a");
   fprintf(file, "taux : %lf / homme : %d / femme : %d \n", taux, nbrOfMen, nbrOfWomen);
   fclose(file);

}

FilterUser filterUsersBySexe(User** users, int length, char* sexe) {

User** dest = (User**) malloc(sizeof(User) * length); 
int destLength = 0;

for(int i=0; i<length; i++){
 if(strcmp(users[i]->sexe, sexe) == 0) {
	User *user = copyUser(users[i]);
 
dest[destLength] = user;  
destLength++;
    }
}

FilterUser fu;
fu.array = dest; fu.length = destLength;

return fu;

}


User* copyUser(User* src){
User *user = (User*) malloc(sizeof(User));
 

   user->isAdmin = src->isAdmin;
   user->voted = src->voted;
   strcpy(user->lastname, src->lastname);
   strcpy(user->firstname, src->firstname);
   strcpy(user->identityCard,src-> identityCard);
   strcpy(user->address, src->address);
   strcpy(user->email,src->email);
   strcpy(user->password,src->password);
   strcpy(user->sexe,src->sexe);
  ( user->birthdate).day =( src->birthdate).day;
   (user->birthdate).month = (src->birthdate).month;
  ( user->birthdate).year = ( src->birthdate).year;
user->id =src-> id;
strcpy(user->votePlace, src->votePlace);

   return user;
}

FilterUser filterUsersAdmin(User** users, int length, int isAdmin){
User** dest = (User**) malloc(sizeof(User) * length); 
int destLength = 0;

for(int i=0; i<length; i++){
if(isAdmin){
 if(strstr(users[i]->email, "@esprit.tn") != NULL) {
	User *user = copyUser(users[i]);
print_user(*user);
 
dest[destLength] = user;  
destLength++;
    }
} else {
 if(strstr(users[i]->email, "@esprit.tn") == NULL) {
	User *user = copyUser(users[i]);
 
dest[destLength] = user;  
destLength++;
    }
}

}

FilterUser fu;
fu.array = dest; fu.length = destLength;

return fu;
}

void voter(char* candidate, char* filePath) {
FILE *file = fopen(filePath, "r"); 
int voteEnnahdha;
int voteEetilefKarama;
int voteNidaTounes;
int voteJabhaChaabeya;

if(file == NULL) {
voteEnnahdha = 0;
voteEetilefKarama = 0;
voteNidaTounes = 0;
voteJabhaChaabeya = 0;

} else {
fscanf(file, "Ennahdha : %d / Eetilef el karama : %d / Nida tounes : %d / Jabha chaabeya : %d \n", &voteEnnahdha, &voteEetilefKarama, &voteNidaTounes, &voteJabhaChaabeya);  
fclose(file);
}


if(strcmp(candidate, "Ennahdha") == 0){
voteEnnahdha++;
} else if(strcmp(candidate, "Eetilef el karama") == 0) {
voteEetilefKarama++;
}else if(strcmp(candidate, "Nida tounes") == 0) {
voteNidaTounes++;
}else if(strcmp(candidate, "Jabha chaabeya") == 0) {
voteJabhaChaabeya++;
}


   

   file = fopen(filePath, "w");
   fprintf(file, "Ennahdha : %d / Eetilef el karama : %d / Nida tounes : %d / Jabha chaabeya : %d \n", voteEnnahdha, voteEetilefKarama, voteNidaTounes, voteJabhaChaabeya);
   fclose(file);
}

