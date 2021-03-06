/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:20:46 by jberegon          #+#    #+#             */
/*   Updated: 2021/09/02 07:20:47 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H
# define EXCEPTIONS_H

# define MALLOC_ERROR	"Malloc error!"
# define SPLIT_ERROR	"Error during split string!"
# define CMD_NOT_FOUND	"command not found"
# define SYNTAX_ERROR	"syntax error near unexpected token"
# define EMPTYPOINTER	"Function has taken an empty pointer!"
# define INVALID_IDENT	"not a valid identifier"
# define EMPTYENV		"No such file or directory "
# define EMPTYVAR		"not set"
# define CD_ACCESS		"Permission denied"
# define CD_NOTDIR		"not a directory"
# define NO_FILE_OR_DIR "No such file or directory"
# define OPEN_FD_ERROR	"couldn't open file descriptor"
# define COPY_VAR_ERR	"error while copying a variable"
# define EXIT_TOO_MANY_ARGS	"too many arguments"
# define EXIT_NON_NUMERIC	"numeric argument required"

#endif
