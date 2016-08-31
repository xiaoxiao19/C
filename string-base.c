#include <stdio.h>
#include <stdlib.h>

字符串的两种表现方式：字符串指针和字符串数组：
	int main()
	{
		char char_data[20];
		char *char_point;
		char_point = (char*)malloc(sizeof(char)*20);

		//scanf("%s",char_data);
		//scanf("%s",char_point);
		gets(char_data);
		gets(char_point);

		printf("%s,%s\n",char_data,char_point);

		return 0;
	}
	scanf输入时，有三种方式：            输出
	使用空格：hello world           hello,world
	使用制表符（TAB）hello	world   hello,world
	使用回车键（ENTER）hello
					   world        hello,world
	getchar输入时：
	hello  world
	mary Li
	输出：hello world.mary Li

	使用scanf get输入：
	scanf("%s",char_data);
	gets(char_point);
	输入：hello（回车）
	输出：hello,

	scanf()在读取输入时会在缓冲区中留下一个字符'\n'（输入完s[i]的值后按回车键所致），
	所以如果不在此加一个getchar()把这个回车符取走的话，gets(）就
	不会等待从键盘键入字符，而是会直接取走这个“无用的”回车符，从而导致读取有误



scanf和getchar读取字符：
	int main()
	{
		char ch1,ch2;

		//scanf("%c",&ch1);
		//scanf("%c",&ch2);
		ch1 = getchar();
		ch2 = getchar();
		printf("%d  %d\n",ch1,ch2);

		return 0;
	}
	scanf和getchar读取字符时，因为每次读取的是一个字符，按下enter键之后刷新输入缓冲区，读取第一个字符串之后，会将
	enter键也使用getchar读取到

	此示例中，如果输入：
	a(回车)
	会输出：97 10(scanf和getchar会得到相同的输出)
	其他相关的输入输出处理
	那么输入是这样进行处理的：
	1、输入a(回车)  b(回车)
	   输出97  98
	2、输入a(空格)(回车)
	   输出97  32(空格的ASCII码)
	3、输入a(TAB)(回车)
	   输出97 9(TAB键的ASCII码)
	所以scanf和getchar进行字符串的读取时，会将空白字符(空格，TAB，回车)放在输入缓冲区中
	要得到正确的输入：
	ch1 = getchar();
	getchar();
	ch2 = getchar();   


scanf和gets读取字符串：
	scanf读取字符串时，遇到空格，TAB，ENTER就会停止读取，所以scanf不能读取带空格的字符串
	读取带空格的字符串要使用gets



scanf getchar混合读取字符串和字符：
	int main()
	{
		char ch1;
		char str1[20];

		scanf("%s",str1);
		ch1 = getchar();

		printf("%s   %d",str1,ch1);

		return 0;
	}
	输入：hello(回车)
	输出：hello  10(回车的ASCII)

	输入：hello（空格）（回车）
	输出：hello  32（空格的ASCII）

	输入：hello（TAB）（回车）
	输出：hello  9(TAB键的ASCII码)

	gets getchar混合读取字符串和字符：
	int main()
	{
		char ch1;
		char str1[20];

		gets(str1);
		ch1 = getchar();

		printf("%s   %d",str1,ch1);

		return 0;
	}  
	输入：hello(回车)   a
	输出：hello  97



