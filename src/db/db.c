#include "../../include/db/db.h"


#ifdef DB_CHECK_EXISTS
void _db_check_exists(void* db)
{
  char* err_msg;
  int rc;

  char* sql_query = "CREATE TABLE IF NOT EXISTS passwords(id INTEGER PRIMARY KEY,application TEXT,password TEXT)";
  rc = sqlite3_exec(db,sql_query,NULL,0,&err_msg);
  if (rc != SQLITE_OK)
  {
    printf("Failed inserting a table");
  }
}
#else
void _db_check_exists(void* n)
{
  printf("CHECK UP IS DISABLED");
}
#endif

sqlite3* db_get_instance()
{
  sqlite3* db;
  int rc = sqlite3_open("save.db",&db);
  if (rc != SQLITE_OK)
  {    printf("Failed to load database");
    sqlite3_close(db);
    return db;
    // TODO: Crash the app
  }
  return db;
}
void db_insert(void* db, struct Db_model_password* model)
{
  int rc;
  sqlite3_stmt *fmt;

  //char* err_msg;

  _db_check_exists(db);
  
  char* sql_insertion = "INSERT INTO passwords(application, password) VALUES(?, ?)";
  sqlite3_prepare(db, sql_insertion, -1, &fmt, 0);
  sqlite3_bind_text(fmt, 1,model->site_or_application , 128, NULL);
  sqlite3_bind_text(fmt, 2, model->password, 128, NULL);
  sqlite3_step(fmt);
  sqlite3_finalize(fmt);
}
char* db_get_password(void* db, char* key)
{
  char* ret;
  int rc;
  sqlite3_stmt *fmt;
  char* sql_query = "SELECT password FROM passwords WHERE application=?";
  sqlite3_prepare(db,sql_query, -1, &fmt, 0);
  sqlite3_bind_text(fmt,1, key, 128, NULL);
  int step = sqlite3_step(fmt);
  if (step == SQLITE_ROW)
  {
    ret = sqlite3_column_text(fmt,0);
  }
  sqlite3_finalize(fmt);
  return ret;
}

