/**
 * _strlen - Calculate size of string
 * @s: string to becalculated
 * Return: size of string
 */
int _strlen(char *s)
{
	int cont = 0;

	while (*(s + cont) != '\0')
		cont++;
	return (cont);
}

/**
 * _str_cmp - compare two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 1 if are equal 0 if not
 */
char _str_cmp(char *str1, char *str2)
{
	if (_strlen(str1) ==  _strlen(str2))
	{
		unsigned int i = 0;

		while (str1[i])
		{
			if (str1[i] != str2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
