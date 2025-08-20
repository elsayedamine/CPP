/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 02:33:40 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 03:20:30 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>

# define DEBUG "Debug: Detected 42 failed API calls in the last 3 seconds. Stack traces available for inspection."

# define INFO "Info: System latency has increased by 17%. Consider checking database indexes and cache performance."

# define WARNING "Warning: Disk space below 15%. Log files may fail to rotate and services could crash soon."

# define ERROR "Error: Server unreachable! Immediate intervention required or the whole network may go down!"

typedef std::string str;

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	unknown(void);
	public:
		Harl();
		~Harl();
		void	complain(str level);
};


#endif