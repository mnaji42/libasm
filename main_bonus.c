/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:53:06 by najimehdi         #+#    #+#             */
/*   Updated: 2019/12/10 15:08:33 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

int		ft_strlen(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, char const *src);
size_t	ft_write(int fd, void const *buf, size_t nbyte);
size_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(char const *s1);
int		ft_atoi_base(char const *str, char const *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void*));
void	ft_list_sort(t_list **begin_list,int (*cmp)());

static void	print_lst(t_list *list)
{
	int i;

	i = 1;
	while (list)
	{
		printf("lst %d| %s\n", i++, list->data);
		list = list->next;
	}
}

static void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

int		main(void)
{
	t_list *lst;

	printf("\n======================= ft_list_push_front ===============================\n");
	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = ft_strdup("lst1");
	lst->next = NULL;
	ft_list_push_front(&lst, ft_strdup("lst2"));
	ft_list_push_front(&lst, ft_strdup("lst3"));
	ft_list_push_front(&lst, ft_strdup("lst4"));
	ft_list_push_front(&lst, ft_strdup("lst5"));
	ft_list_push_front(&lst, ft_strdup("lst6"));
	ft_list_push_front(&lst, ft_strdup("lst7"));
	print_lst(lst);
	printf("\n========================= ft_list_size ==================================\n");
	printf("List size = %d\n", ft_list_size(lst));
	ft_lstclear(&lst);
	return (0);
}
