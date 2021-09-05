/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 06:09:47 by jberegon          #+#    #+#             */
/*   Updated: 2021/09/04 06:09:49 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static int	get_envp_copy(t_loginfo *shell, char *envp[])
//{
//	int length;
//
//	length = 0;
//	while (envp[length])
//		length++;
//	shell->commands->envp_copy = (char **)malloc(sizeof(char*) * length + 1);
//	if (!shell->commands->envp_copy)
//		return (0);
//	shell->commands->envp_copy[length] = NULL;
//	while (--length >= 0)
//	{
//		shell->commands->envp_copy[length] = ft_strdup(envp[length]);
//		if (!shell->commands->envp_copy[length])
//			return (0);
//	}
//	return (1);
//}

/*
 * Копирует массив переменных окружения в
 * отдельный двумерный массив для удобства изменения
 */
static int	ft_copy_env(t_cmd *s_cmd, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		i++;
	}
	s_cmd->envp_copy = (char **)malloc(sizeof(s_cmd->envp_copy) * i + 1);
	if (!s_cmd->envp_copy)
		exception(ONE);
	i = 0;
	while (env[i])
	{
		s_cmd->envp_copy[i] = ft_strdup(env[i]);
		if (!s_cmd->envp_copy[i])
			exception(TWO);
		i++;
	}
	s_cmd->envp_copy[i] = NULL;
	return (0);
}

void	init_logs(t_loginfo *shell, char *envp[])
{
	shell->title = ft_strjoin(getenv("LOGNAME"), "/minishell/$> ", -1);
	shell->commands = malloc(sizeof(shell->commands));
	if (!shell->title || !shell->commands)
		exception(ONE);
	shell->commands->num_args = 0;
	shell->commands->command = NULL;
	shell->commands->envp_copy = NULL;
	shell->commands->next = NULL;
	ft_copy_env(shell->commands, envp);
}
