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
   const char* src  = "/dev/sr0";
   const char* trgt = "cdrom";
   const char* type = "tmpfs";
   const unsigned long mntflags = 0;
   const char* opts = "mode=0700,uid=65534";   /* 65534 is the uid of nobody */

   //verify this mount by executing the following from the command line "df -l"
   int result = mount(src, trgt, type, mntflags, opts);

   if (result == 0)
   {
      printf("Mount created at %s...\n", trgt);
   }
   else
   {
      printf("Error : Failed to mount %s\n" "Reason: %s [%d]\n", src, strerror(errno), errno);
   }

   return result;
}
