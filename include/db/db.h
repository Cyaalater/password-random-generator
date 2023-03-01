#ifndef _DB_H
#define _DB_H
#include "sqlite3.h"
#include "stdio.h"

// SETTINGS
#define DB_CHECK_EXISTS

struct Db_model_password {
  char* password;
  char* site_or_application;
};


sqlite3* db_get_instance();
void db_insert(void* db, struct Db_model_password *model);
char* db_get_password(void* db, char* application);

#endif

