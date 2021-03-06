/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fd.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:39:56 by qfeuilla          #+#    #+#             */
/*   Updated: 2020/09/20 15:50:31 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fd.hpp"
#include "utils.hpp"

Fd::Fd() {
	type = FD_FREE;
	utils::memset(buf_read, 0, BUF_SIZE + 1);
	utils::memset(buf_write, 0, BUF_SIZE + 1);
}

Fd::~Fd() { }

void Fd::read_func() { }

void Fd::write_func() { }
