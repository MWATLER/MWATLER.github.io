// memoryUsage.h - header file for memory monitoring
//
// 19-Jul-21  M. Watler         Created.
//
#ifndef MEMORY_USAGE_H
#define MEMORY_USAGE_H
#include <linux/random.h>

//Question 31: Is keyFile (/dev/urandom) a file that we can edit with vim?
const char keyFile[]="/dev/urandom";
const char logFile[]="midterm.log";

#endif// MEMORY_USAGE_H
