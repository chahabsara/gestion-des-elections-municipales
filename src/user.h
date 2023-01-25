#ifndef SET_USER
#define SET_USER



typedef struct BirthDate BirthDate;
struct BirthDate {
  int day;
  int month;
  int year;
};

typedef struct User User;
struct User {
  char email[200];//. @
  char lastname[200];
  char firstname[200];
  char address[200];
  char identityCard[200];
  char password[200];//8cara
  char sexe[200]; //Homme or Femme
  BirthDate birthdate;
  int isAdmin; 
  char votePlace[200];
int voted;
  int id;
};

typedef struct FilterUser FilterUser;
struct FilterUser {
  User** array;
  int length
};

User* currentUser ="@esprit.tn";

User* createUser(const char *email, const char *lastname, const char *firstname, const char *identityCard, const char *password, const char *sexe, int day, int month, int year, const char* address, int isAdmin, int voted, const char* votePlace, int id);
User find_user_by_id(int id, char *filepath);
User* findUsers(char *filepath);
void print_user(User user);
void saveUserToFile(User *user, const char *filepath);
void readUsersFromFile(User** users, const char *filepath);
int getNumberOfUsers(char *filepath);
void deleteUserByEmail(char* email, char*filepath);
int isUserExist(char* email, char* filepath);
void updateUserToFile(User *user, const char *filepath);
User* login(char* email, char* password, const char *filepath);
void calculateStats(const char *filepath, const char *statPath);

FilterUser filterUsersBySexe(User** users, int length, char* sexe);
FilterUser filterUsersAdmin(User** users, int length, int isAdmin);
User* copyUser(User* src);
void voter(char* candidate, char* filePath);
// chercher les id des user femme et admin



#endif
