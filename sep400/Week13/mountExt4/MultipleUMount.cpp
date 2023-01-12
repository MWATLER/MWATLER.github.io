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
   char trgt[8];
   printf("Enter the filesystem to unmount (\"all\" for all): ");
   scanf("%s", trgt);
   int ret=0;

   if(strcmp(trgt, "all")==0) {
       const int NUM=2;
       for(int i=0; i<NUM && ret==0; ++i) {
           sprintf(trgt, "cdrom%d", i);
           //verify this umount by executing the following from the command line "df -l"
	   ret=umount(trgt);
           if(ret==0) {
                printf("%s successfully unmounted\n", trgt);
           } else {
                printf("Error : Failed to unmount %s\n" "Reason: %s [%d]\n", trgt, strerror(errno), errno);
           }
       }
   } else {
       //verify this umount by executing the following from the command line "df -l"
       ret=umount(trgt);
       if(ret==0) {
            printf("%s successfully unmounted\n", trgt);
       }
       else
       {
          printf("Error : Failed to unmount %s\n" "Reason: %s [%d]\n", trgt, strerror(errno), errno);
       }
   }

   return ret;
}
