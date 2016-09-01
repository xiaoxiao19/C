#include <stdio.h>
#include <stdlib.h>

char * mystrcpy(char *dest,const char *src)
{
	char *p = dest;
	while(*dest++ = *src++)
		;
	dest = p;
}

char *mystrcpy(char *dest,const char *src)
{
	char *p = dest;
	while(*p++ = *src++)
		;
	return dest;
}

char *mystrcpy(char *dest,const char *src)
{
	int i = 0;
	for(;*(src+i) != '\0';i++)
		*(dest+i) = *(src+i);
	*(dest+i) = '\0';
}


int main()
{
	char str1[20];
	char str2[20];

	scanf("%s",str1);
	mystrcpy(str2,str1);

	printf("str1:%s,str2:%s\n",str1,str2);

	return 0;
}