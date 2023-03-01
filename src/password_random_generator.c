#include <stdio.h>
#include "../include/db/db.h"

#define PROJECT_NAME "password-random-generator"

int main(int argc, char **argv) {
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
  void* db = db_get_instance();
  struct Db_model_password model;
  model.password = "1234a";
  model.site_or_application = "discord";
  db_insert(db, &model);
    printf("This is project %s.\n", PROJECT_NAME);
    return 0;
}
