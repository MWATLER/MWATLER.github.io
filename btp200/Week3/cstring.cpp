#include "cstring.h"
namespace sdds {
   void strCpy(char* des, const char* src) {
      while (*src) {
         *des++ = *src++;
      }
      *des = 0;
   }
   int strLen(const char* s) {
      int i = -1;
      while (s[++i]);
      return i;
   }
}