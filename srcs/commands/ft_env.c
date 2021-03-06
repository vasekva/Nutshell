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

int	ft_env(t_data *shell, t_cmd *node)
{
	t_env_list	*env_node;

	if (!shell->env_node)
		return (exception("env", NULL, EMPTYENV));
	env_node = get_node_by_content(shell->env_node, "PATH", 0);
	if (!env_node)
		return (exception("env", NULL, NO_FILE_OR_DIR));
	env_node = shell->env_node;
	while (env_node)
	{
		if (ft_strchr(env_node->str, '='))
			ft_putstr_fd(node->fd_output, env_node->str, 1);
		env_node = env_node->next;
	}
	return (0);
}
