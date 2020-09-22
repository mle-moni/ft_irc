/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:24:57 by qfeuilla          #+#    #+#             */
/*   Updated: 2020/09/22 10:58:37 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_H
# define FT_IRC_H

# include <sys/select.h>
# include <string>
# include <vector>
# include <iostream>
# include "defines.hpp"
# include "Command.hpp"
# include "structs.hpp"
# include <ctime>

# define Xv(err,res,str)	(x_void(err,res,str,__FILE__,__LINE__))
# define X(err,res,str)		(x_int(err,res,str,__FILE__,__LINE__))
# define MAX(a,b)			((a > b) ? a : b)
# define reply_formating(server, err, params, user) _reply_formating(server, err, params, user, __FILE__, __LINE__)

int							x_int(int, int, std::string, std::string, int);
void						*x_void(void *, void *, std::string, std::string, int);
Command						*parse(std::string cmd);
std::string					_reply_formating(const char *, Error, 
								std::vector<std::string>, const char *,
								const char*, int);
bool						is_special(char c);

#endif