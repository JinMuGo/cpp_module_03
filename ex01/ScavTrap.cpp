/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:24:16 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 17:14:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scav_trap_default", 100, 50, 20) {
	std::cout << STP_DFLT_CTOR << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << STP_CTOR << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& inst) {
	std::cout << STP_CPY_CTOR << std::endl;
	if (this != &inst)
		*this = inst;
}
ScavTrap::~ScavTrap() {
	std::cout << STP_DTOR << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& inst) {
	std::cout << STP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &inst) {
		this->name_ = inst.getName();
		this->hit_points_ = inst.getHitPoints();
		this->energy_points_ = inst.getEnergyPoints();
		this->attack_damage_ = inst.getAttackDamage();
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (!this->canYouDoIt()) {
		std::cout << "ScavTrap [" << this->getName() << "] can't attack "
				  << target << " because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ScavTrap [" << this->getName() << "] attacks " << target
			  << ", causing " << this->getAttackDamage() << " points of damage!"
			  << std::endl;
}

void ScavTrap::guardGate(){
	if (this->canYouDoIt())
		std::cout << "[" << this->getName() << "] " << STP_GATE_KEEPER_MODE << std::endl;
	else
		std::cout << "[" << this->getName() << "] " << STP_CAN_T_FUNC << std::endl;
};
//ScavTrap and will inherit the constructors and destructor from Clap-
//Trap. However, its constructors, destructor and attack() will print different messages.

//the program starts by building a ClapTrap. Destruction is
//in reverse order. Why?