/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:18:01 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/11/15 17:20:54 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
ssize_t		ft_read(int fd, void *buff, size_t nbyte);
ssize_t		ft_write(int fd, void *buff, size_t nbyte);

int			main()
{
	char	*str;
	char	*s1 = "hello";
	char	dest[10];
	char	s[5] = "hello";
	int		bz;
    ssize_t	n;
	int		fd1;
	int		fd2;
	
	str = malloc(sizeof(char) * 5);
	// ============ FT_STRLEN =================
	printf("mine == %zu\n", ft_strlen("NULL"));
	printf("orig == %zu\n", strlen("NULL"));
	printf("mine == %zu\n", ft_strlen(""));
	printf("orig == %zu\n", strlen(""));
	printf("mine == %zu\n", ft_strlen(s1));
	printf("orig == %zu\n", strlen(s1));
	printf("mine == %zu\n", ft_strlen(NULL));
	printf("orig == %zu\n", strlen(NULL));
	printf("|M| ==> Return value by ft_strlen = |%zu|\n", ft_strlen(s));
	printf("|O| ==> Return value by    strlen = |%zu|\n", strlen(s)); 
	printf("mine == %zu\n", ft_strlen("NULL"));
	printf("orig == %zu\n", strlen("NULL"));
	printf("mine == %zu\n", ft_strlen("-1"));
	printf("orig == %zu\n", strlen("-1"));

	// ============ FT_STRCPY =================
	printf("mine == %s|\n", ft_strcpy(dest, NULL));
	printf("orig == %s|\n", strcpy(dest, NULL));
	printf("mine == %s|\n", ft_strcpy(dest, "hello"));
	printf("orig == %s|\n", strcpy(dest, "hello"));
	printf("mine == %s|\n", ft_strcpy(NULL, NULL));
	printf("orig == %s|\n", strcpy(NULL, NULL));
	printf("mine == %s|\n", ft_strcpy(NULL, "hello"));
	printf("orig == %s|\n", strcpy(NULL, "hello"));
	
	printf("|M| ==> the dest1 by ft_strcpy is |%s|\n", ft_strcpy(s, "How are you ?"));
	printf("|O| ==> the dest2 by    strcpy is |%s|\n", strcpy(s, "How are you ?"));
	printf("%s|\n", ft_strcpy(dest, "hello"));
	printf("mine = %s|\n", ft_strcpy(dest, "hello"));
	printf("origin = %s|\n", strcpy(dest, "hello"));
	
	// ============ FT_STRDUP =================
	printf("mine == |%s|\n", ft_strdup("Hello"));
	printf("orig == |%s|\n", strdup("Hello"));
	printf("mine == %s\n", ft_strdup(NULL));
	printf("orig == %s\n", strdup(NULL));
	printf("mine == |%s|\n", ft_strdup(""));
	printf("orig == |%s|\n", strdup(""));
	printf("|M| ==> string by ft_strdup is |%s|\n", ft_strdup("NULL"));
	printf("errno = |%d|\n", errno);
	printf("|O| ==> string by    strdup is |%s|\n",  strdup("NULL"));
	printf("errno = |%d|\n", errno);

	// ============ FT_STRCMP =================
	printf("mine == %d\n", ft_strcmp("abe", "abe"));
	printf("orig == %d\n",    strcmp("abe", "abe"));
	printf("mine == %d\n", ft_strcmp("ab", "abea"));
	printf("orig == %d\n",    strcmp("ab", "abea"));
	printf("mine == %d\n", ft_strcmp("abe", "ab"));
	printf("orig == %d\n",    strcmp("abe", "ab"));
	printf("mine == %d\n", ft_strcmp("abex", NULL));
	printf("orig == %d\n",    strcmp("abex", NULL));
	printf("mine == %d\n", ft_strcmp(NULL, "eve"));
	printf("orig == %d\n",    strcmp(NULL, "eve"));
	printf("mine == %d\n", ft_strcmp("b", ""));
	printf("orig == %d\n",    strcmp("b", ""));
	printf("mine == %d\n", ft_strcmp("", ""));
	printf("orig == %d\n",    strcmp("", ""));
	printf("|MINE| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("\xff\xff", "\xff"));
	printf("|ORIG| ==> the return value of    strcmp is |%d|\n",  strcmp("\xff\xff", "\xff"));
	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("", "hello"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("", "hello"));

	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("h", "h"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("h", "h"));

	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hello", "helloa"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hello", "helloa"));

	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("helloa", "hello"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("helloa", "hello"));

	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hella", "hello"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hella", "hello"));
	
	// ============ FT_READ   =================
	printf("mine == %d | %s\n", (int)ft_read(1, str, 5), str);
	printf("orig == %d | %s\n", (int)read(1, str, 5), str);
	printf("mine == %d | %s\n", (int)ft_read(-1, str, 5), str);
	printf("orig == %d | %s\n", (int)read(-1, str, 5), str);
	printf("mine == %d | %s\n", (int)ft_read(42, str, 5), str);
	printf("orig == %d | %s\n", (int)read(42, str, 5), str);
	printf("mine == %d | %s\n", (int)ft_read(1, NULL, 5), str);
	printf("orig == %d | %s\n", (int)read(1, NULL, 5), str);
	
	fd1 = open("test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	fd2 = open("test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	n = ft_read(fd1, s, bz);
	printf("\n|M| ==> the return value of ft_read is |%zd| and s=|%s|\n", n, s);
	printf("errno = |%d|\n", errno);
	n =    read(fd2, s, bz);
	printf("|O| ==> the return value of    read is |%zd| and s=|%s|\n", n, s);
	printf("errno = |%d|\n", errno);
	close(fd1);
	close(fd2); 
	
	// ============ FT_WRITE  =================
	printf("mine == %d\n", (int)ft_write(1, "NULL\n", 5));
	printf("orig == %d\n", (int)write(1, "NULL\n", 5));
	printf("mine == %d\n", (int)ft_write(1, NULL, 5));
	printf("orig == %d\n", (int)write(1, NULL, 5));
	printf("mine == %d\n", (int)ft_write(-1, "NULL\n", 5));
	printf("orig == %d\n", (int)write(-1, "NULL\n", 5));
	printf("mine == %d\n", (int)ft_write(42, "NULL\n", 5));
	printf("orig == %d\n", (int)write(42, "NULL\n", 5));
	
	fd1 = open("./test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	fd2 = open("./test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	n = ft_write(fd1, s, bz);
	printf("\n|M| ==> the return value of ft_write is |%ld|\n", n);
	printf("errno = |%d|", errno);
	n =    write(fd2, s, bz);
	printf("\n|O| ==> the return value of    write is |%ld|\n", n);
	printf("errno = |%d|\n", errno);
	close(fd1);
	close(fd2); 
}
