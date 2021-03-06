/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OtherServ.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:36:23 by qfeuilla          #+#    #+#             */
/*   Updated: 2020/10/12 21:44:15 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHERSERV_HPP
# define OTHERSERV_HPP

#include "ft_irc.hpp"
#include "Client.hpp"
#include "ChannelMaster.hpp"
#include "utils.hpp"

class Channel;
class Environment;
class Client;

class OtherServ: public Fd {
public:
	OtherServ(int, Environment *, int);
	OtherServ(const OtherServ &);

	~OtherServ();

	void			NICK(Command *);
	void			QUIT(Command *);
	void			PRIVMSG(Command *);
	void			NOTICE(Command *);
	void			USER(Command *);
	void			MODE(Command *);
	void			AWAY(Command *);
	void			TIME(Command *);
	void			SERVER(Command *);
	void			DELS(Command *);
	void			KILL(Command *);
	void			TRACE(Command *);
	void			SQUIT(Command *);
	void			READY(Command *);

	void			JOIN(Command *);
	void			PART(Command *);
	void			KICK(Command *);
	void			TOPIC(Command *);
	void			INVITE(Command *);
	void			NAMES(Command *);
	void			VERSION(Command *);
	void			LINKS(Command *);
	void			ADMIN(Command *);
	void			INFO(Command *);

	// * RPL transmition
	void			RPL_351(Command *);
	void			RPL_364(Command *);
	void			RPL_365(Command *);
	void			RPL_391(Command *);
	void			RPL_NTRACE(Command *);
	void			RPL_ADMIN(Command *);
	void			RPL_NINFO(Command *);


	virtual void	read_func();
	virtual void	write_func();

	std::vector<Client *>::iterator	search_nick(std::string);
	std::vector<Client *>::iterator	search_history_nick(std::string);
	std::vector<Client *>			search_list_with_mode(char);
	std::vector<std::string>::iterator search_namecon(std::string);

	int				execute_parsed(Command *);

	bool			change_nick(std::string, std::string);

	std::string				name;
	int						hop_count = 1;
	std::string				info = "No specific info";
	std::vector<Client *>	clients;
	std::vector<Client *>	clients_history;
	std::vector<std::string>	connected_sv;
	
	std::map<std::string, int>	connected_hop;
	std::map<std::string, std::string> connected_info;

	int						recv_ms = 0;
	int						send_ms = 0;
	int						sendq = 0;
	size_t					Kb_sent = 0;
	size_t					Kb_recv = 0;

	time_t					creation;
	bool					already_setup_name;
	
	void	propagateChanMsg(const std::string &ms);
private :
	Environment		*ev;

	std::string		_stream;
};

#endif