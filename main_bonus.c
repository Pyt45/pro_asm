/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:18:28 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/12/01 10:00:46 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;


void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void				ft_list_sort(t_list **begin_list, int (*cmp)());
int					ft_atoi_base(char *str, char *base);



int		ft_isspace1(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
	|| c == '\n' || c == '\f' || c == '\r');
}

int		find_char_base1(char *base, char c)
{
	int		i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

int		check_base1(char *base, char *str)
{
	int		len;
	int		i;

	if ((len = (int)strlen(base)) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (find_char_base1(base, str[i]) < 0)
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (find_char_base1(base + i + 1, base[i]) >= 0)
			return (0);
		i++;
	}
	return (len);
}

int		ft_atoi_base1(char *str, char *base)
{
	int		base_len;
	int		index;
	int		i;
	int		num;
	int		sign = 1;
	if (!str || !base)
		return (0);
	num = 0;
	sign = (*str == '-') ? -1 : 1;
	str += (str[0] == '+' || sign < 0) ? 1 : 0;
	if (!(base_len = check_base1(base, str)))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if ((index = find_char_base1(base, str[i])) >= 0)
			num = num * base_len + index;
		i++;
	}
	return (sign * num);
}

t_list				*ft_new_list(void	*data)
{
	t_list  *list;

	if (!(list = (t_list *)malloc(sizeof(t_list) )))
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

void				ft_list_push_front1(t_list **begin_list, void *data)
{
	t_list  *list;

	if ((*begin_list) == NULL)
		*begin_list = ft_new_list(data);
	else
	{
		list = ft_new_list(data);
		list->next = *begin_list;
		*begin_list = list;
	}
}

void				print_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->next)
			printf("%s --> ", tmp->data);
		else
			printf("%s", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int					ft_list_size1(t_list *begin_list)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = begin_list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void				ft_list_remove_if1(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*current;
	t_list	*last;

	tmp = NULL;
	current = *begin_list;
	last = NULL;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
				if (current == *begin_list)
					*begin_list = current->next;
				else
					last->next = current->next;
				tmp = current;
				current = current->next;
				free(tmp);
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}

void				ft_list_sort1(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*head;
	void	*data_sort;

	if (!cmp)
		return ;
	head = *begin_list;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if ((*cmp)(head->data, tmp->data) > 0)
			{
				data_sort = head->data;
				head->data = tmp->data;
				tmp->data = data_sort;
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
}

int					intcmp(int a, int b)
{
	return (a - b);
}

void            ft_list_remove_if2(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list      *current;
    t_list      *tmp;
    if (*begin_list)
    {
        current = *begin_list;
        tmp = current->next;
        while (tmp != 0)
        {
            if (!(*cmp)(tmp->data, data_ref))
            {
                current->next = tmp->next;
                free(tmp);
            }
            else
                current = current->next;
            tmp = current->next;
        }
       current = *begin_list;
        if (!(*cmp)(current->data, data_ref))
        {
            *begin_list = current->next;
            free(current);
        }
    }
}

void			ft_list_remove_if3(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*tmp;
	t_list		*last;
	t_list		*current;
	
	if (*begin_list)
	{
		current = *begin_list;
		last = *begin_list;
		while (current)
		{
			if (!(*cmp)(current->data, data_ref))
			{
				tmp = current;
				current = current->next;
				free(tmp);
			}
			last = current->next;
			current = current->next;
		}
		*begin_list = current;
	}
}


int					main()
{
	t_list	*list;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	char	*data_rf = strdup("a");
	printf("orig == %d\n", ft_atoi_base1("101", "0123456789abcdef"));
	printf("mine == %d\n", ft_atoi_base("101", "0123456789abcdef"));
	

	list = NULL;
	list1 = NULL;
	list2 = NULL;
	list3 = NULL;

	list1 = ft_new_list(strdup("0"));
	list1->next = ft_new_list(strdup("4"));
	list1->next->next = ft_new_list(strdup("5"));
	list1->next->next->next = ft_new_list(strdup("3"));
	list1->next->next->next->next = ft_new_list(strdup("3"));
	// ==================== CREATE NEW LIST  ========================

	list2 = ft_new_list(strdup("b"));
	list2->next = ft_new_list(strdup("m"));
	list2->next->next = ft_new_list(strdup("c"));
	list2->next->next->next = ft_new_list(strdup("a"));
	list2->next->next->next->next = ft_new_list(strdup("a"));
	print_list(list2);
	
	// // =================== LIST_SIZE =================================
	printf("\n LIST_SIZE \n");
	printf("mine == %d\n", ft_list_size(list1));
	printf("orig == %d\n", ft_list_size1(list1));

	// // =================== ADD_LIST =================================
	printf("\n ADD_LIST \n");
	list1 = ft_new_list(strdup("1"));
	print_list(list1);
	ft_list_push_front(&list1, strdup("2"));
	ft_list_push_front(&list1, strdup("3"));
	ft_list_push_front(&list1, strdup("4"));
	printf("\n===== mine : ======\n");
	print_list(list1);
	// printf("\n=================================\n\n");
	list = ft_new_list(strdup("1"));
	ft_list_push_front(&list, strdup("2"));
	ft_list_push_front(&list, strdup("3"));
	ft_list_push_front(&list, strdup("4"));
	printf("\n===== orig : ======\n");
	print_list(list); 

	// =================== SORT_LIST ================================
	printf("\n SORT_LIST \n");
	printf("\n===== mine : ======\n");
	ft_list_sort(&list, strcmp);
	print_list(list);
	printf("\n===== orig : ======\n");
	ft_list_sort(&list1, intcmp);
	print_list(list1);
	
	// =================== REMV_ELMT ================================
	printf("\n REMV_ELMT \n");
	printf("\n===== mine :     ======\n");
	print_list(list1);
	printf("\n===== after rm : ======\n");
	ft_list_remove_if(&list1, "4", strcmp);
	print_list(list1);
	printf("\n===== orig : ======\n");
	ft_list_remove_if(&list1, strdup("3"), strcmp);
	print_list(list1);
	return 0;
}