#include "../include/log.h"
#include "stdio.h"


struct LogData log_initialize(char* name, void (*fptr)(char* log))
{
  struct LogData logger;
  logger.namespace = name;
  logger.callback = (*fptr);
  return logger;
}


void log_unformatted_nc(struct LogData logger, char* log)
{
  char* buff;
  sprintf(buff, "[%s] %s", logger.name, log);


  // Initial Printing the event
  printf("%s",buff);

}

void log_unformatted(struct LogData logger, char* log)
{
  char* buff;
  sprintf(buff, "[%s] %s", logger.name, log);


  // Initial Printing the event
  printf("%s",buff);

  // Callback incase of saving in file
  void (*ptr)(char* log) = logger.callback;
  ptr(buff);
}

