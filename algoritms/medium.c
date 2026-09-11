/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenoztur <kenoztur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:00:17 by esadikog          #+#    #+#             */
/*   Updated: 2026/09/11 05:58:20 by kenoztur         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

//ben burda kök alma işlemini yapıyorum
int	sqrt(int n)
{
	int i;

	if(n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}
// stack Adaki 0ıncıdan başlicam n-1 tanesinin indeksini hesaplicam
int	*get_indexes(t_stack *a)
{
	int *indexes;
	int i;
	
	indexes = malloc(sizeof(int) * a->size);
	if (!indexes)
		return (NULL);
	i = 0;
	
	return (indexes);
}
//diziye baş taraftan eleman girerken indeksleri bir kaydırıcam(pa,pb için)
void	shift_right(int *arr, int size)
{
	int i;
	
	i = size;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
}

//dizide baştan eleman çıkarırken indeksleri bir eleman sola kaydırıcam (pa,pb için)
void	shift_left(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
}

//B yığınındaki en büyük indekse sahip elemanın yerini bulmak için de fonksiyon lazım???
//Bdeki en büyük elemanları sırayla Aya atıcam(buna da fonksiyon)

//Chunk algoritmasını kurucam burda da
void	medium(t_stacks stacks, t_counter *counter)
{
	int *index_a;
	int *index_b;
	int i;

	index_a = get_indexes(stacks.a);
	index_b = malloc(sizeof(int) * stacks.a->size);
	//free yapmam lazım?
}