/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:05:35 by jberegon          #+#    #+#             */
/*   Updated: 2021/09/02 07:05:36 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_data *shell)
{
	t_env_list	*env_node;

	if (!shell->env_node)
		return ;
	env_node = shell->env_node;
	while (env_node)
	{
		printf("%s\n", env_node->str);
		env_node = env_node->next;
	}
}
