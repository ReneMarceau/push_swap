/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:00 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/28 13:35:55 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

char	ft_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	ft_lower(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

void	ft_del(void *content)
{
	content = 0;
}

void	ft_lst_plus_5(void *content)
{
	content += 5;
}

void	*ft_lst_minus_5(void *content)
{
	content -= 5;
	return (content);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("The real function : %d\n", isalpha(argv[1][0]));
// 		printf("My Function : %d\n", ft_isalpha(argv[1][0]));
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("The real function :%d\n", isdigit(argv[1][0]));
// 		printf("My Function : %d\n", ft_isdigit(argv[1][0]));
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("The real function : %d\n", isalnum(argv[1][0]));
// 		printf("My Function : %d\n", ft_isalnum(argv[1][0]));
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("The real function : %d\n", isascii(argv[1][0]));
// 		printf("My Function : %d\n", ft_isascii(argv[1][0]));
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("The real function : %d\n", isprint(argv[1][0]));
// 		printf("My Function : %d\n", ft_isprint(argv[1][0]));
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
//  		printf("The real function : %zu\n", strlen(argv[1]));
//   		printf("My Function : %zu\n", ft_strlen(argv[1]));
//   	}
//   	return (0);
// }

// int	main(void)
// {
// 	char str1[] = "Wesh la zone!";
// 	char str2[] = "Wesh la zone!";
// 	int character = '$';
// 	size_t len = 3;

// 	printf("The real function : %s\n", memset(str2, character, len));
// 	printf("My Function : %s\n", ft_memset(str1, character, len));
// 	return (0);
// }

// int	main(void)
// {
// 	char str1[] = "Wesh la zone!";
// 	char str2[] = "Wesh la zone!";
// 	size_t len = 3;

// 	ft_bzero(str1, len);
// 	bzero(str2, len);
// 	printf("The real function : %s\n", str2);
// 	printf("My Function : %s\n",str1);
// 	return (0);
// }

// int	main(void)
// {
// 	char str1[100] = "bite";
// 	char str2[] = "Wesh la zone!";
// 	size_t len = 7;

// 	printf("The real function : %d\n", memcpy(((void *)0), ((void *)0), len));
// 	printf("My Function : %d\n", ft_memcpy(((void *)0), ((void *)0), len));
// 	return (0);
// }

// int	main(void)
// {
// 	char str1[100] = "Learningisfun";
// 	char str2[100] = "Learningisfun";
// 	char *first;
// 	char *second;

// 	first = str1;
// 	second = str2;
// 	printf("Original string : %s\n ",str1);
// 	memmove(second + 8, second, 10);
// 	printf("real memmove overlap : %s\n ", str2);
// 	ft_memmove(first + 8, first, 10);
// 	printf("my memmove overlap : %s\n ", str1);
// 	return (0);
// }

// int	main(void)
// {
// 	char dst1[100] = "bit";
// 	char src1[] = "Wesh la zone!";
// 	char dst2[100] = "bit";
// 	char src2[] = "Wesh la zone!";
// 	size_t len = 7;

// 	printf("The real function : %lu\n", strlcpy(dst2, src2, len));
// 	printf("%s\n", dst1);
// 	printf("My Function : %zu\n", ft_strlcpy(dst1, src1, len));
// 	return (0);
// }

// int	main(void)
// {
// 	// char dst1[100] = "bite";
// 	// char src1[] = "Wesh la zone!";
// 	// char dst2[100] = "bite";
// 	// char src2[] = "Wesh la zone!";
// 	// size_t len = 7;

// 	char b[0xF] = "nyan !";
// 	char c[0xF] = "nyan !";
// 	printf("The real function : %lu\n", strlcat(((void *)0), c, 0));
// 	printf("My Function : %zu\n", ft_strlcat(((void *)0), b, 0));
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("The real function : %c\n", toupper(argv[1][0]));
// 		printf("My Function : %c\n", ft_toupper(argv[1][0]));
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("The real function : %c\n", tolower(argv[1][0]));
// 		printf("My Function : %c\n", ft_tolower(argv[1][0]));
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	char str[] = "Wesh la zone!";

// 	printf("The real function : %s\n", strchr(str, 'e'));
// 	printf("My function : %s\n", ft_strchr(str, 'e'));
// 	return (0);
// }

// int	main(void)
// {
// 	char str[] = "Avada kedavra\nWesh la zone\ncoller la petite";

// 	printf("The real function : %s\n", strrchr(str, '\n'));
// 	printf("My function : %s\n", ft_strrchr(str, '\n'));
// 	return (0);
// }

// int	main(void)
// {
// 	char str1[100] = "bite";
// 	char str2[] = "Wesh la zone!";
// 	char str3[100] = "bite";
// 	char str4[] = "Wesh la zone!";
// 	size_t len = 7;

// 	printf("The real function : %d\n", strncmp(str3, str4, len));
// 	printf("My Function : %d\n", ft_strncmp(str1, str2, len));
// 	return (0);
// }

// int	main(void)
// {
// 	char str[] = "bonjourno";
// 	int	c = 0;
// 	size_t len = 0;

// 	printf("The real function : %s\n", memchr(str, c, len));
// 	printf("My function : %s\n", ft_memchr(str, c, len));
// 	return (0);
// }

// int	main(void)
// {
// 	char	str1[] = "ça pue le prout";
// 	char	str2[] = "ça pue le pet";

// 	printf("The real function : %d\n", ft_memcmp(str1, str2, 20));
// 	printf("My function : %d\n", ft_memcmp(str1, str2, 20));
// 	return (0);
// }

// int	main(void)
// {
// 	char haystack[50] = "aaabcabcd";
// 	char needle[10] = "abcd";

// 	size_t max = ft_strlen(haystack);

// 	char *i1 = strnstr(haystack, needle, max);
// 	char *i2 = ft_strnstr(haystack, needle, max);

// 	printf("The real function : %s\n", i1);
// 	printf("My Function : %s\n", i2);
// 	return (0);
// }

// int	main(void)
// {
// 	char n[40] = "99999999999999999999999999";
// 	int i1 = atoi(n);
// 	int i2 = ft_atoi(n);

// 	printf("The real function : %d\n", i1);
// 	printf("My Function : %d\n", i2);
// 	return (0);
// }

// int	main(void)
// {
// 	char	str[] = "vache qui rit";

// 	printf("The real function : %s\n", strdup(str));
// 	printf("My function : %s\n", ft_strdup(str));
// 	return (0);
// }

// int	main(void)
// {
// 	int	size = 8593;

// 	void * d1 = ft_calloc(size, sizeof(int));
// 	void * d2 = calloc(size, sizeof(int));
// 	char *s1 = d1;
// 	char *s2 = d2;

// 	printf("The real function : %s\n", s2);
// 	printf("My function : %s\n", s1);
// 	return (0);
// }

// int	main(void)
// {
// 	char	str[] = "j'aime le caca";
// 	int 	start = 2;
// 	int		len = 4;

// 	printf("%s\n", ft_substr(str, start, len));
// 	return (0);
// }

// int	main(void)
// {
// 	char	str1[] = "wesh";
// 	char	str2[] = " la zone";
// 	printf("%s\n", ft_strjoin(str1, str2));
// 	return (0);
// }

// int	main(void)
// {
// 	char	s1[] = "caca... c'est bon le caca";
// 	char	set[] = "caca";

// 	printf("%s\n", ft_strtrim(s1, set));
// 	return (0);
// }

// int	main(void)
// {
// 	char	tr[] = "hello!";
// 	char	c = ' ';
// 	char	**str = ft_split(s, c);
// 	while (*str)
// 	{
// 		printf("%s\n", *str);
// 		str++;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int	num = 123;
// 	printf("%s\n", ft_itoa(num));
// 	return (0);
// }

// int	main(void)
// {
// 	char	str[] = "Rend moi mon chocolat!!";

// 	printf("%s\n", ft_strmapi(str, ft_upper));
// 	return (0);
// }

// int	main(void)
// {
// 	char	str[] = "LOWERCASE GANG";

// 	ft_striteri(str, ft_lower);
// 	printf("%s\n", str);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		ft_putchar_fd(argv[1][0], 1);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		ft_putstr_fd(argv[1], 1);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		ft_putendl_fd(argv[1], 1);
// 	return (0);
// }

// int	main(void)
// {
// 	int	num = 1234;
// 	ft_putnbr_fd(num, 1);
// 	return (0);
// }

// int	main(void)
// {
// 	ft_putnbr_base_fd(200, "0123456789abcdef", 1);
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*item = ft_lstnew((void *)4);
// 	printf("%d\n", (int)item->content);
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);

// 	head = item4;
// 	item4->next = NULL;
// 	ft_lstadd_front(&head, item3);
// 	ft_lstadd_front(&head, item2);
// 	ft_lstadd_front(&head, item1);
// 	ft_lstadd_front(&head, new);
// 	while (head)
// 	{
// 		printf("%d\n", (int)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);

// 	head = item4;
// 	item4->next = NULL;
// 	ft_lstadd_front(&head, item3);
// 	ft_lstadd_front(&head, item2);
// 	ft_lstadd_front(&head, item1);
// 	ft_lstadd_front(&head, new);
// 	printf("%d\n", ft_lstsize(head));
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);

// 	head = item4;
// 	item4->next = NULL;
// 	ft_lstadd_front(&head, item3);
// 	ft_lstadd_front(&head, item2);
// 	ft_lstadd_front(&head, item1);
// 	ft_lstadd_front(&head, new);
// 	printf("%d\n", (int)ft_lstlast(head)->content);
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*head1;
// 	t_list	*head2;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);

// 	head1 = NULL;
// 	head2 = NULL;
// 	ft_lstadd_back(&head1, item1);
// 	ft_lstadd_back(&head1, item2);
// 	ft_lstadd_back(&head1, item3);
// 	ft_lstadd_back(&head2, item4);
// 	ft_lstadd_back(&head2, new);
// 	ft_lstadd_back(&head1, head2);
// 	while (head1)
// 	{
// 		printf("%d\n", (int)head1->content);
// 		head1 = head1->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);

// 	head = item4;
// 	item4->next = NULL;
// 	ft_lstadd_front(&head, item3);
// 	ft_lstadd_front(&head, item2);
// 	ft_lstadd_front(&head, item1);
// 	ft_lstadd_front(&head, new);
// 	ft_lstdelone(head->next, ft_del);
// 	while (head)
// 	{
// 		printf("%d\n", (int)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);

// 	head = item4;
// 	item4->next = NULL;
// 	ft_lstadd_front(&head, item3);
// 	ft_lstadd_front(&head, item2);
// 	ft_lstadd_front(&head, item1);
// 	ft_lstadd_front(&head, new);
// 	ft_lstclear(&head->next->next, ft_del);
// 	while (head)
// 	{
// 		printf("%d\n", (int)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);

// 	head = item4;
// 	item4->next = NULL;
// 	ft_lstadd_front(&head, item3);
// 	ft_lstadd_front(&head, item2);
// 	ft_lstadd_front(&head, item1);
// 	ft_lstadd_front(&head, new);
// 	ft_lstiter(head, ft_lst_plus_5);
// 	while (head)
// 	{
// 		printf("%d\n", (int)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new = ft_lstnew((void *)10);
// 	t_list	*item1 = ft_lstnew((void *)20);
// 	t_list	*item2 = ft_lstnew((void *)30);
// 	t_list	*item3 = ft_lstnew((void *)40);
// 	t_list	*item4 = ft_lstnew((void *)50);
// 	t_list	*map;

// 	head = item4;
// 	item4->next = NULL;
// 	ft_lstadd_front(&head, item3);
// 	ft_lstadd_front(&head, item2);
// 	ft_lstadd_front(&head, item1);
// 	ft_lstadd_front(&head, new);
// 	map = ft_lstmap(head, ft_lst_minus_5, ft_del);
// 	while (map)
// 	{
// 		printf("%d\n", (int)map->content);
// 		map = map->next;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	char		character 				= 'c';
// 	char		*string 				= "Bien ou bien la famille ?";
// 	char		*ptr_character 			= &character;
// 	int			decimal 				= 1234;
// 	int			integer 				= 2000;
// 	unsigned int unsigned_decimal 		= 4589;
// 	unsigned int hexadecimal 			= 3000;
// 	unsigned int hexadecimal_forte 		= 3000;

// 	ft_printf("\
// 	---------------------------------------------------------\n\
// 	My printf:\n\n\
// 	character: %c\n\
// 	string: %s\n\
// 	ptr_character : %p\n\
// 	decimal: %d\n\
// 	integer : %i\n\
// 	unsigned_decimal: %u\n\
// 	hexadecimal: %x\n\
// 	hexadecimal_forte : %X\n\
// 	percentage: %%\n\n",\
// 	 character,\
// 	 string,\
// 	 ptr_character,\
// 	 decimal,\
// 	 integer,\
// 	 unsigned_decimal,\
// 	 hexadecimal,\
// 	 hexadecimal_forte\
// 	);

// 	printf("\
// 	----------------------------------------------------------\n\
// 	The real printf:\n\n\
// 	character: %c\n\
// 	string: %s\n\
// 	ptr_character : %p\n\
// 	decimal: %d\n\
// 	integer : %i\n\
// 	unsigned_decimal: %u\n\
// 	hexadecimal: %x\n\
// 	percentage: %%\n\n",\
// 	 character,\
// 	 string,\
// 	 ptr_character,\
// 	 decimal,\
// 	 integer,\
// 	 unsigned_decimal,\
// 	 hexadecimal\
// 	);
// 	return (0);
// }

// int	main(void)
// {
// 	int	fd;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
