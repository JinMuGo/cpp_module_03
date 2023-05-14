/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:57:42 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 18:00:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("scav_trap_default", 100, 100, 30)
{
	std::cout << FTP_DFLT_CTOR << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << FTP_CTOR << std::endl;
}

FragTrap::FragTrap(const FragTrap &inst) : ClapTrap(inst)
{
	std::cout << FTP_CPY_CTOR << std::endl;
	if (this != &inst)
		*this = inst;
}
FragTrap::~FragTrap()
{
	std::cout << FTP_DTOR << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &inst)
{
	std::cout << FTP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &inst)
	{
		this->name_ = inst.getName();
		this->hit_points_ = inst.getHitPoints();
		this->energy_points_ = inst.getEnergyPoints();
		this->attack_damage_ = inst.getAttackDamage();
	}
	return (*this);
}