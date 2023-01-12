//Mount.cpp - a program for mounting a file system
//
// History:
// 14-Apr-22  M. Watler         Created.

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/mount.h>

int main()
{
   const char* trgt = "cdrom";

   //verify this umount by executing the following from the command line "df -l"
   int ret=umount(trgt);
   if(ret==0) {
        printf("%s successfully unmounted\n", trgt);
   }
   else
   {
      printf("Error : Failed to unmount %s\n" "Reason: %s [%d]\n", trgt, strerror(errno), errno);
   }

   return ret;
}
