/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:41:00 by qfeuilla          #+#    #+#             */
/*   Updated: 2020/09/22 10:49:08 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "defines.hpp"

Command::~Command() { }

Command::Command(std::vector<std::string> cmd, std::string ln) {
	if (cmd[0][0] == ':') {
		prefix = cmd[0];
		command = cmd[1];
		if (cmd.size() > 2)
			arguments = std::vector<std::string>(&cmd[2], &cmd[cmd.size()]);
	} else {
		prefix = "";
		command = cmd[0];
		if (cmd.size() > 1)
			arguments = std::vector<std::string>(&cmd[1], &cmd[cmd.size()]);
	}
	line = ln;
}

int		Command::cmd_code() const {
	if (command == "PASS")	
		return (PASS_CC);
	else if (command == "NICK")
		return (NICK_CC);
	else if (command == "USER")
		return (USER_CC);
	else if (command == "OPER")	
		return (OPER_CC);
	else if (command == "MODE")	
		return (MODE_CC);
	else if (command == "SERVICE")	
		return (SERVICE_CC);
	else if (command == "QUIT")	
		return (QUIT_CC);
	else if (command == "SQUIT")	
		return (SQUIT_CC);
	else if (command == "JOIN")	
		return (JOIN_CC);
	else if (command == "PART")	
		return (PART_CC);
	else if (command == "TOPIC")	
		return (TOPIC_CC);
	else if (command == "NAMES")	
		return (NAMES_CC);
	else if (command == "LIST")	
		return (LIST_CC);
	else if (command == "INVITE")	
		return (INVITE_CC);
	else if (command == "KICK")	
		return (KICK_CC);
	else if (command == "PRIVMSG")	
		return (PRIVMSG_CC);
	else if (command == "NOTICE")	
		return (NOTICE_CC);
	else if (command == "MOTD")	
		return (MOTD_CC);
	else if (command == "LUSERS")	
		return (LUSERS_CC);
	else if (command == "VERSION")	
		return (VERSION_CC);
	else if (command == "STATS")	
		return (STATS_CC);
	else if (command == "LINKS")	
		return (LINKS_CC);
	else if (command == "TIME")	
		return (TIME_CC);
	else if (command == "CONNECT")	
		return (CONNECT_CC);
	else if (command == "TRACE")	
		return (TRACE_CC);
	else if (command == "ADMIN")	
		return (ADMIN_CC);
	else if (command == "INFO")	
		return (INFO_CC);
	else if (command == "SERVLIST")	
		return (SERVLIST_CC);
	else if (command == "SQUERY")	
		return (SQUERY_CC);
	else if (command == "WHO")	
		return (WHO_CC);
	else if (command == "WHOIS")	
		return (WHOIS_CC);
	else if (command == "WHOWAS")	
		return (WHOWAS_CC);
	else if (command == "KILL")	
		return (KILL_CC);
	else if (command == "PING")	
		return (PING_CC);
	else if (command == "PONG")	
		return (PONG_CC);
	else if (command == "ERROR")	
		return (ERROR_CC);
	else if (command == "AWAY")
		return (AWAY_CC);
	else if (command == "REHASH")	
		return (REHASH_CC);
	else if (command == "DIE")	
		return (DIE_CC);
	else if (command == "RESTART")	
		return (RESTART_CC);
	else if (command == "SUMMON")	
		return (SUMMON_CC);
	else if (command == "USERS")	
		return (USERS_CC);
	else if (command == "WALLOPS")	
		return (WALLOPS_CC);
	else if (command == "USERHOST")	
		return (USERHOST_CC);
	else if (command == "ISON")	
		return (ISON_CC);
	else if (command == "SERVER")	
		return (SERVER_CC);
	else if (command == "NJOIN")	
		return (NJOIN_CC);
	else
		return (WRONG_CMD);
}

std::ostream &			operator<<( std::ostream &o, Command const & cmd ) {
	o << "Line : " << cmd.line << "\n";
	if (!cmd.prefix.empty())
		o << "Prefix : " << cmd.prefix << "\n";
	o << "Command : " << cmd.command << "\n";
	o << "Arguments : [";
	if (cmd.arguments.size() >= 1) {
		for (size_t i = 0; i < cmd.arguments.size() - 1; i++)
				o << cmd.arguments[i] << ", ";
		o << cmd.arguments[cmd.arguments.size() - 1];
	}
	o << "]\n";
	return (o);
}