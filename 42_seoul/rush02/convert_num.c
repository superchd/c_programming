void	convert_num(char *num)
{
	if (num[0] == '0')
		print(0) // 제일 앞자리가 0이면 빼박 0이지 ㅇ.ㅇ
	else
	{

}


char	*make_unit_str(int index)
{
	int	i;
	char	*unit;

	i = 1;
	unit = (char *)malloc(sizeof(char) * (index + 1));
	unit[0] = '1';
	while (*index--)
	{
		unit[i] = '0';
		i++;
	}
	return (unit);
}



}

char	*val_from_key(char *key)
{











}



void	print_unit(int index)
{
	char	*big_unit;

	if (idx % 3 == 0) // what is g_unit3?
	{
		big_unit = make_unit_str(index);
		print(val_from_key(big_unit));
		free(big_unit);
	}
	else if (idx % 3 == 2)
		p








	char *unit;
	int i;

	unit = malloc(sizeof(char) * (idx + 1));
	while (idx)
	{






	}













}


















}
