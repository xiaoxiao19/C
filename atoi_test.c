#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//atoi将字符串转换为整形
/*思想是：首先略过数字前面的空字符
再判断遇到的第一个字符是不是数字，如果不是则返回0
如果是，那么找到第一个非数字字符，
接下来就是将第一个数字和最后一个非数字字符之间的数字转换为数字*/
int myatoi(const char *s)
{
  int exp = 0,n = 0;
  const char *t = NULL;

  for(;*s == ' '|| *s == '\t' || *s == '\n';s++)
	;
  if(*s > '9' || *s < '0')
        return 0;
  for(t = s;*t >= '0' && *t <= '9';++t)
	;
  t--;

  while(t >= s)
  {
     n += (*t -48)*pow(10,exp);
     t--;
     exp++;
  }
  return n;
}

int power(int base,int exp)
{
  if(0 == exp)
     return 1;
  return base*power(base,exp-1);
}

int myatoi_1(const char *s)
{
  int exp = 0,n = 0;
  const char *t = NULL;
  
  for(;*s == ' '|| *s == '\t' || *s == '\n';++s)
    ;//跳过空字符
 
  if(*s > '9' || *s < '0')//判断第一个字符是不是数字
     return 0;

   //找到第一个非数字的字符
   for(t=s;*t>='0' && *t <= '9';++t)
     ;
   t--;
   
   while(t >= s)
   {
      n += (*t-48)*power(10,exp);
      t--;
      exp++;
   }
}

//添加了对正数负数的处理
int myatoi_3(char s[])
{
  int i,n,sign;
  //跳过空白字符
  for(i=0;isspace(s[i]);i++);
  sign = (s[i] == '-')?-1:1;
  if(s[i] == '+' || s[i] == '-')
     i++;
  for(n=0;isdigit(s[i]);i++)
     n = n*10+(s[i]-'0');
   return sign*n;
}

int main()
{
   int num;
   char *s = "12343d";
   num = myatoi_3(s);
   printf("the str is:%s,the num is:%d\n",
	s,num);

   return 0;
}
