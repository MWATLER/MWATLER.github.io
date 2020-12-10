#ifndef DEVICE_FILE_H_
#define DEVICE_FILE_H_
#include <linux/compiler.h> /* __must_check */

__must_check int register_device(void); /* 0 if Ok*/
void unregister_device(void);

#define DEVICE_FILE_WRITE_STRING _IOW('a','a',char*)
#define DEVICE_FILE_READ_STRING  _IOR('a','b',char*)

#endif //DEVICE_FILE_H_
