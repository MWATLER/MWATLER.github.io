// client.h - Header file for named semaphores
//
// 02-Dec-20  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const char SEMNAME[]="FileSem";
const char FILENAME[]="dentists.txt";
const int  BUF_LEN=16;
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

#endif//CLIENT_H
