// client.h - Header file for named semaphores
//
// 23-Nov-20  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H
#include <sys/stat.h>

const int PORT=1160;//Port of the database
const char SEMNAME[]="FileSem";
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

#endif//CLIENT_H
