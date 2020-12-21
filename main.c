/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:52:52 by najimehdi         #+#    #+#             */
/*   Updated: 2019/12/10 14:21:50 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_strlen(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, char const *src);
size_t	ft_write(int fd, void const *buf, size_t nbyte);
size_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(char const *s1);

int		main(void)
{
	int		i;
	int		fd;
	long	r;
	char	buffer[100];
	char	*str;

	r = 0;
	i = 0;
	while (i < 100)
		buffer[i++] = 0;

	printf("======================== ft_strlen ========================\n");
	printf("ft_strlen = %3d || strlen = %3lu\n", ft_strlen("123456789"), strlen("123456789"));
	printf("ft_strlen = %3d || strlen = %3lu\n", ft_strlen(""), strlen(""));
	printf("ft_strlen = %3d || strlen = %3lu\n", ft_strlen("Bonjour"), strlen("Bonjour"));
	printf("ft_strlen = %3d || strlen = %3lu\n", ft_strlen("Ceci est une phrase un peu plus longue"), strlen("Ceci est une phrase un peu plus longue"));
	printf("ft_strlen = %3d || strlen = %3lu\n", ft_strlen("\n"), strlen("\n"));

	printf("\n======================== strcmp ==========================\n");
	printf("ft_strcmp = % d || strcmp = % d\n", ft_strcmp("s1","s2"), strcmp("s1","s2"));
	printf("ft_strcmp = % d || strcmp = % d\n", ft_strcmp("s1",""), strcmp("s1",""));
	printf("ft_strcmp = % d || strcmp = % d\n", ft_strcmp("test","test"), strcmp("test","test"));
	printf("ft_strcmp = % d || strcmp = % d\n", ft_strcmp("qwerty","asdfg"), strcmp("qwerty","asdfg"));
	printf("ft_strcmp = % d || strcmp = % d\n", ft_strcmp("123456789","123456789"), strcmp("123456789","123456789"));

	printf("\n======================== strcpy ===========================\n");
	ft_strcpy(buffer, "coucou");
	printf("ft_strcpy = %s || ", buffer);
	strcpy(buffer, "coucou");
	printf("strcpy = %s\n", buffer);
	ft_strcpy(buffer, "Ceci est une phrase un peu plus longue !!");
	printf("ft_strcpy = %s || ", buffer);
	strcpy(buffer, "Ceci est une phrase un peu plus longue !!");
	printf("strcpy = %s\n", buffer);
	ft_strcpy(buffer, "");
	printf("ft_strcpy = %s || ", buffer);
	strcpy(buffer, "");
	printf("strcpy = %s\n", buffer);
	ft_strcpy(buffer, "123");
	printf("ft_strcpy = %s || ", buffer);
	strcpy(buffer, "123");
	printf("strcpy = %s\n", buffer);

	printf("\n======================== write=============================\n");
	ft_write(1, "coucou\n", 7);
	ft_write(1, "", 0);
	ft_write(1, "\n", 1);
	ft_write(1, "Une phrase un peu plus longue !!\n", 33);

	printf("\n========================= read =============================\n");
	i = 0;
	while (i < 100)
		buffer[i++] = 0;
	fd = open("main.c", O_RDONLY);
	ft_read(0, buffer, 50);
	printf("read = %s\n", buffer);
	i = 0;
	while (i < 100)
		buffer[i++] = 0;
	ft_read(0, buffer, 50);
	printf("read = %s\n", buffer);
	i = 0;
	while (i < 100)
		buffer[i++] = 0;
	ft_read(0, buffer, 50);
	printf("read = %s\n", buffer);
	i = 0;
	while (i < 100)
		buffer[i++] = 0;
	ft_read(fd, buffer, 10);
	printf("read = %s\n", buffer);
	i = 0;
	while (i < 100)
		buffer[i++] = 0;
	close(fd);

	printf("\n====================== ft_strdup ============================\n");
	str = ft_strdup("coucou");
	printf("ft_strdup = %s\n", str);
	free(str);
	str = ft_strdup("");
	printf("ft_strdup = %s\n", str);
	free(str);
	str = ft_strdup("Ceci est une phrase un peu plus long !!");
	printf("ft_strdup = %s\n", str);
	free(str);
	str = ft_strdup("test123");
	printf("ft_strdup = %s\n", str);
	free(str);

	return (0);
}
