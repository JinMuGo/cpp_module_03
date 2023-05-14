/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:57:45 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 17:58:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "FragTrap.h"

class FragTrap: public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(const FragTrap &inst);
	~FragTrap();
	FragTrap &operator=(const FragTrap &inst);
};

#endif

