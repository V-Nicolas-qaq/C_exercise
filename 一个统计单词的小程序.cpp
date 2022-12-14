#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define STOP '|'

int main(void)
{
	char c;					   // 读取一个字符
	char prev;				   // 读取的前一个字符
	long n_chars = 0L;		   // 总字符数
	int n_lines = 0;			   // 行数
	int n_words = 0;			   // 单词数
	int incomplete_lines = 0;	   // 不完整的行数
	bool inword = false;       // 字符是否处于单词之中

	printf("Enter text to be anelyzed (| to terminate):\n");
	prev = '\n';               // 表示完整的行
	while ((c = getchar()) != '|')
	{
		n_chars++;
		if (c == '\n')
			n_lines++;
		if (!isspace(c) and !inword)
		{
			inword = true;
			n_words++;
		}
		if (isspace(c) and inword)
			inword = false;    //达到单词的末尾
		prev = c;              //保存字符的值
	}

	if (prev != '\n')
		incomplete_lines = 1;
	printf("This text has %ld characters, %d words, %d line(s),\
and %d partial line(s).\n", n_chars, n_words, n_lines, incomplete_lines);

	return 0;
}
