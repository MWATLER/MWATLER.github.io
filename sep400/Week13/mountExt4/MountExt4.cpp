//MountExt4.cpp - a program for mounting two types of file systems
//
// History:
// 20-Apr-22  M. Watler         Created.

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/mount.h>

int main()
{
   const int NUM=2;
   const char* src[16]  ={ "/dev/sda5", "/dev/sr0" };
   const char* type[9] = { "ext4", "tmpfs" };
   const char* trgt[7] = { "cdrom0", "cdrom1" };
   unsigned long mntflags = 0;
   const char* opts = "mode=0700,uid=65534";   /* 65534 is the uid of nobody */
   int result=0;

   //Create the mounts
   for(int i=0; i<NUM && result==0; ++i) {
       //verify this mount by executing the following from the command line "df -l"
       printf("mount(%s, %s, %s, %lu, %s)\n", src[i], trgt[i], type[i], mntflags, opts);
       result = mount(src[i], trgt[i], type[i], mntflags, opts);

       if (result == 0)
       {
          printf("Mount created at %s...\n", trgt[i]);
       }
       else
       {
          printf("Error : Failed to mount %s\n" "Reason: %s [%d]\n", src[i], strerror(errno), errno);
       }
   }

   return result;
}
