// client.h - Header file for named semaphores
//
// 01-Apr-19  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const char SEMNAME[]="MemPool";
const char FIFO[]="/tmp/mempool";
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
char32_t *memPool;

#endif//CLIENT_H
