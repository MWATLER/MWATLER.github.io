// client.h - Header file for named semaphores
//
// 01-Apr-19  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const char SEMNAME[]="FileSem";
const char FILENAME[]="FileSem.txt";
const int NUM=5;
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
const int OPENFLAGS=(O_CREAT | O_WRONLY | O_APPEND);
const mode_t FILEPERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);/* rw-rw-rw- */

#endif//CLIENT_H
