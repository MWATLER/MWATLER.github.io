//BindMount.cpp - a program for mounting a file system many times then binding two directories
//
// History:
// 14-Apr-22  M. Watler         Created.

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/mount.h>

int main()
{
   const int NUM=2;
   const char* src  = "/dev/sr0";
   char trgt[8];
   const char* type = "tmpfs";
   unsigned long mntflags = 0;
   const char* opts = "mode=0700,uid=65534";   /* 65534 is the uid of nobody */
   int result=0;

   //Create the mounts
   for(int i=0; i<NUM && result==0; ++i) {
       sprintf(trgt, "cdrom%d", i);
       //verify this mount by executing the following from the command line "df -l"
       result = mount(src, trgt, type, mntflags, opts);

       if (result == 0)
       {
          printf("Mount created at %s...\n", trgt);
       }
       else
       {
          printf("Error : Failed to mount %s\n" "Reason: %s [%d]\n", src, strerror(errno), errno);
       }
   }

   //Bind cdrom0 and cdrom1
   const char *trgt1="cdrom0";
   const char *trgt2="cdrom1";
   mntflags = MS_BIND;
   result = mount(trgt1, trgt2, NULL, mntflags, NULL);
   if (result == 0)
   {
      printf("Mount bind created at %s and %s...\n", trgt1, trgt2);
   }
   else
   {
      printf("Error : Failed to bind mounts %s and %s\n" "Reason: %s [%d]\n", trgt1, trgt2, strerror(errno), errno);
   }

   return result;
}
