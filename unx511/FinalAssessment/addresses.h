//addresses.h - structure for encoder and decoder addresses
//
// 29-Jul-21  M. Watler         Created.
#ifndef ADDRESSES_H
#define ADDRESSES_H

const int ADDR_LEN=16;

struct Address {
    char ip_addr[ADDR_LEN];
    int  ip_port;
};

#endif//ADDRESSES_H
