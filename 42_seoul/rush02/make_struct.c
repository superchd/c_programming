/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:39:26 by hchd              #+#    #+#             */
/*   Updated: 2021/03/14 00:30:29 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	make_dict(char *file)
{
	if ((fd = open(file, O_RDONLY))  == -1)
	{
		printf("open fail in makind dict\n");
	}
	g_eof = 1; // 이건 왜 존재하는지 모르겠어 나는 생각한다 고로 존재?
	while ((g_final_line = read_line(g_fd)))
	{
		//if (g_eof++) --> 이게 없으면 무슨일이 일어날까요?
		// break;
		if (!*g_line) //--> 읽은 문장이 공백이면 멈춰라
			continue;
		if (!is_valid_key_value(g_line)) // 유효한 key값이 아니면
		{
			g_read_error = 1;
			break ;
		}
		//이제 검사 다했고 key , value 값을 구조체에 넣어준다
		insert_key_value (g_line);
	}
	if (g_read_error)
	{
		//에러가 나왔으니 에러 메시지를 출력하고 file을 close해라

	}
}


char	*read_line(char *file)
{
	int	i;
	char	*ret;
	
	ret = (char *)malloc(END_LINE + 1);
	while ((read(fd, &ret[i], 1)))
	{
		if (MAX_LENGTH) //문자열이 끝났을때면
		{

		}
		if (ret[i] = '\n')
		{
			ret[i] = 0;
			break;
		}
		++i;
	}
	return (ret);
}

//인자로 들어온 argv[1]을 배열에 저장해서 리턴해야쥬


char	*what_is_your_number( )
{




	return (number);
}

if (is_input_num_error && is_valid_num(g_num))
	print_error;
else if (!is_input_num_error) //  && !g_dict_error
{
	if (   )
		print_error;
	else






}






void	insert_key_value(char *key_value)
{
	char *tmp;

	tmp = key_value;
	key = key_value;
	ptr = key_value;// 나중에 동적할당을 얼마나 해줄까 계산위
	while (*ptr != ':')
		++ptr;
	key = (char *)malloc(ptr - key + 1);
	ft_strcpy(key, str, ptr - 1);
	//key = trim_allocated_str(key); why do this? i dont know
	val = ++ptr;
	str = val;
	while (*ptr)
		++ptr;
	val = (char *)malloc(ptr - val + 1);
	ft_strcpy(val, str, ptr - 1);
	//val = trim_allocated_str(val); why do this in here?
	*tmp = 0;
	free(tmp);
	setting_dictionary(key, val);
}

void	setting_dictionary(char *key, char *value)
{
	// what's happens??
	if (g_dict)
		g_dict = create_ele(key, value);
	else
	{
		tmp = g_dict;
		g_dict = create_ele(key, value);
		g_dict -> next = tmp;
	}
}

t_dict	*create_ele(char *key, char *val)
{
	t_dict *dict;

	dict = (t*)malloc(sizeof(t_dict));
	dict->key = key;
	dict->value = value;
	dict->next = 0;
	return (dict);
}

