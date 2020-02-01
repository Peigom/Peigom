#include <stdio.h>
#include <string.h>  
#include <ctype.h>
char* my_toupper(char* dest, const char* src)
{
	char *aa = dest;
	char a ;
	static unsigned int i = 0;
	unsigned int b = 0;
	while (b < strlen(src))
	{
		a = src[b];
		if (a > 64 && a < 91)
		{
			dest[i] = a;
		}
		if (a <= 123 && a >=96)
		{
			dest[i] = toupper(a);
		}
		if (a == '.')
		{
			dest[i] = '!';
			i++;
			dest[i] = '!';
			i++;
			dest[i] = '!';
		}
		if (a == '?')
		{
			dest[i] = '!';
		}
		if (a == ' ')
		{
			dest[i] = ' ';
		}
		if (a == '\n')
		{
			dest[i] = a;
		}
		if (a == ',')
		{
			dest[i] = ',';
		}
		i++;
		b++;
	}
	unsigned int bb = i;
	while (bb < strlen(dest))
	{
		dest[bb] = '\0';
		bb++;
	}
	return aa;
}
int main(void)
{
	char dest[200];

	/* The following helps detecting string errors, e.g. missing final nil */
	memset(dest, '#', 199);
	dest[199] = 0;

	printf("%s",
		my_toupper(dest,
			"Would you like to have a sausage? It will be two euros. Here you are.\n"));

	printf("%s",
		my_toupper(dest,
			"Madam, where are you going? The health care center is over there.\n"));

	return 0;
}