#include <stdio.h>
#include <stdlib.h>

int mystrcmp(const char *src,const char *dst)
{
  int ret = 0;
  while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *src)
     ++src,++dst;

  if(ret < 0)
    ret = -1;
  else if(ret > 0)
    ret = 1;
  return ret;
}

int main()
{
   char str1[] = "i am a coder";
   char str2[] = "i am a coder";
   int result = 0;
   result = mystrcmp(str1,str2);
   if(result == 0)
     printf("str1:%s,str2:%s,str1 and str2 are the same!\n",str1,str2);
   else
     printf("str1:%s,str2:%s,str1 and str2 are not the same!\n",str1,str2);

  return 0; 
}
