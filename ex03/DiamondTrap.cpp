/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:53 by jgo               #+#    #+#             */
/*   Updated: 2023/05/17 20:28:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << DTP_DFLT_CTOR << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
	: ClapTrap(name + "_clap_name", FragTrap::init_hit_points_,
			   ScavTrap::init_energy_points_, FragTrap::init_attack_damage_),
	  ScavTrap(),
	  FragTrap(),
	  name_(name) {
	std::cout << DTP_CTOR << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& inst)
	: ClapTrap(inst.ClapTrap::getName(), inst.getHitPoints(),
			   inst.getEnergyPoints(), inst.getAttackDamage()),
	  ScavTrap(inst),
	  FragTrap(inst) {
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
	std::cout << "hi my name is " << this->getName() << " nice to meet you ";
	std::cout << "and my base class name is " << this->ClapTrap::getName()
			  << " hi :)" << std::endl;
}

void DiamondTrap::prtStatus(void) const {
	std::cout << std::setw(5) << "Name: " << this->name_ << "\n";
	std::cout << std::setw(5) << "HP: " << this->getHitPoints() << "\n";
	std::cout << std::setw(5) << "AD: " << this->getAttackDamage() << "\n";
	std::cout << std::setw(5) << "EP: " << this->getEnergyPoints() << "\n";
}