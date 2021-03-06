/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:28:49 by jberegon          #+#    #+#             */
/*   Updated: 2021/11/06 23:28:51 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	overflow_value(char *exit_line)
{
	size_t	i;

	i = ft_strlen(exit_line);
	if (i >= 21 || (i == 19 && (exit_line[i - 1] >= '8'
				|| exit_line[i - 2] > '0'))
		|| (i == 20 && (exit_line[i - 1] > '8' || exit_line[i - 2] > '0')))
		return (1);
	return (0);
}

static int	valid_exit_code(t_cmd *node)
{
	char	*exit_line;
	int		i;

	i = -1;
	exit_line = node->command[1];
	while (exit_line[++i])
	{
		if ((!i && !ft_isdigit(exit_line[i]) && exit_line[i] != '-') || \
		(!ft_isdigit(exit_line[i]) && i > 0))
			return (exception("exit", node->command[1], EXIT_NON_NUMERIC));
	}
	if (overflow_value(exit_line))
		return (exception("exit", node->command[1], EXIT_NON_NUMERIC));
	return (0);
}

int	ft_exit(t_data *shell, t_cmd *node)
{
	unsigned char	exit_code;

	ft_putstr_fd(node->fd_output, "exit", 1);
	if (node->num_args == 1)
		exit(g_err_code);
	exit_code = valid_exit_code(node);
	if (exit_code != 0)
		exit(exit_code);
	if (node->num_args > 2)
		return (exception("exit", NULL, EXIT_TOO_MANY_ARGS));
	exit_code = ft_atoi(node->command[1]);
	exit(exit_code);
}
