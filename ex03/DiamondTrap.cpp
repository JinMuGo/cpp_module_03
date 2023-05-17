/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:53 by jgo               #+#    #+#             */
/*   Updated: 2023/05/17 17:18:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << DTP_DFLT_CTOR << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(),
	  FragTrap(),
	  name_(name),
	  hit_points_(FragTrap::getInitHitPoints()),
	  energy_points_(ScavTrap::energy_points_),
	  attack_damage_(FragTrap::attack_damage_) {
	std::cout << DTP_CTOR << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& inst)
	: ClapTrap(inst.ClapTrap::getName(), inst.getHitPoints(),
			   inst.getEnergyPoints(), inst.getAttackDamage()),
	  ScavTrap(),
	  FragTrap(),
{
	std::cout << DTP_CPY_CTOR << std::endl;
	*this = inst;
}
DiamondTrap::~DiamondTrap() {
	std::cout << DTP_DTOR << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& inst) {
	std::cout << DTP_CPY_ASGMT_OP_CALL << std::endl;

	if (this != &inst) {
		this->name_ = inst.getName();
		this->hit_points_ = inst.getHitPoints();
		this->energy_points_ = inst.getEnergyPoints();
		this->attack_damage_ = inst.getAttackDamage();
		this->ClapTrap::name_ = inst.ClapTrap::getName();
	}

	return (*this);
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "hi my name is " << this->getName() << "nice to meet you" << std::endl;
	std::cout << "and my base class name is " << this->ClapTrap::getName() << " hi :)" << std::endl;
}