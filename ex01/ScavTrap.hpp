/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:24:25 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 16:46:05 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ScavTrap.h"

class ScavTrap : public ClapTrap {
   public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& inst);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& inst);
	void guardGate();

	virtual void attack(const std::string& target);
};

#endif