#include "../push_swap.h"

void	get_pivot(t_info *info, int size, int flag)
{
	int *arr;
	int pivot;

	arr = duplicate_stack(info, flag);
	sort_duplicate_stack(arr, size);
	pivot = size / 4;
	if (flag == 1)
	{
		info->pivot2 = arr[size - pivot];
		info->pivot1 = arr[size - pivot * 2];
	}
	else
	{
		info->pivot2 = arr[pivot * 2 - 1];
		info->pivot2 = arr[pivot - 1];
	}
	free(arr);
}

void	push_to_a_step(t_info *info, t_argument *arg_cnt, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (info->b->arr[0] <= info->pivot2)
		{
			rb(info);
			arg_cnt->rb++;
		}
		else
		{
			pa(info);
			arg_cnt->pa++;
			if (info->a->arr[0] <= info->pivot1)
			{
				ra(info);
				arg_cnt->ra++;
			}
		}
		idx++;
	}
}

void	push_to_a(t_info *info, int size)
{
	int 		idx;
	t_argument	arg_cnt;

	arg_cnt  = (t_argument){0, 0, 0, 0};
	if(is_stack_sorted(info, 2))
	{
		while (info->b->size >= 0)
			pa(info);
		return ;
	}
	if (size <= 3)
	{
		element_under_5(info, 2);
		return ; 
	}
	get_pivot(info, info->a->size, 2);
	push_to_a_step(info, &arg_cnt, size);
	push_to_b(info, arg_cnt.pa - arg_cnt.ra);
	idx = -1;
	while (++idx < arg_cnt.ra)
		rrr(info);
	push_to_b(info, arg_cnt.rb);
	push_to_a(info, arg_cnt.ra);
}

void	push_to_b_step(t_info *info, t_argument *arg_cnt, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (info->a->arr[0] >= info->pivot1)
		{
			ra(info);
			arg_cnt->ra++;
		}
		else
		{
			pb(info);
			arg_cnt->pb++;
			if (info->b->arr[0] >= info->pivot2)
			{
				rb(info);
				arg_cnt->rb++;
			}
		}
		idx++;
	}
}

void	push_to_b(t_info *info, int size)
{
	int 		idx;
	t_argument arg_cnt;

	arg_cnt  = (t_argument){0, 0, 0, 0};
	if(is_stack_sorted(info, 1))
		return;
	if (size <= 3)
	{
		element_under_5(info, 1);
		return ; 
	}
	get_pivot(info, info->size, 1);
	push_to_b_step(info, &arg_cnt, size);
	idx = -1;
	while (++idx < arg_cnt.ra)
		rrr(info);
	push_to_b(info, arg_cnt.ra);
	push_to_a(info, arg_cnt.rb);
	push_to_a(info, arg_cnt.pb - arg_cnt.rb);
}