//位运算的学习，& | ~ << >> ^
//编写一个函数，该函数反转一个值中的最后n位，参数为n和要反转的值
//思路：~可以反转位，但是该运算符反转一个字节中所有的位，而不是选定的少数位，
//^异或可以用来转置单个位，假设设置一个掩码，该掩码最后n位设置为1，其余为设置为0，然后对
//该改吗和一个值使用^运算符可以反转这个值的最后n位，同时保留该值的其他位不变

//异或操作是这样的：0^0 = 0   0^1 = 1   1^0 = 0  1^1 = 0

#include <stdio.h>

char *itobs(int n,char *ps);
void show_bstr(const char *);
int invert_end(int num,int bits);

int main(void)
{
	char bin_str[8*sizeof(int)+1];
	int number;

	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while(scanf("%d",&number) == 1)
	{
		itobs(number,bin_str);
		printf("%d is\n",number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number,4);
		printf("Inverting the last 4 bits gives\n");
		show_bstr(itobs(number,bin_str));
		putchar('\n');
	}

	puts("Bye!");
	return 0;
}

//将整形int数转换为二进制，将每一位使用char类型存储
//方法是：求当前位时，将01与n做与运算，每次都将n >>= 1
char *itobs(int n,char *ps)
{
	int i;
	static int size = 8 *sizeof(int);

	for(i=size-1;i >= 0;i--,n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return 0;
}


//4位显示二进制字符串
void show_bstr(const char *str)
{
	int i = 0;

	while(str[i])
	{
		putchar(str[i]);
		if(++i %4 == 0 && str[i])
			putchar(' ');
	}
}


//反转位函数，将
int invert_end(int num,int bits)
{
	int mask = 0;
	int bitval = 1;

	while(bits-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}

	return num ^ mask;
}




