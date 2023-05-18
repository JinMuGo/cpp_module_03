/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:24:16 by jgo               #+#    #+#             */
/*   Updated: 2023/05/18 10:51:51 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scav_trap_default", 100, 50, 20) {
	std::cout << STP_DFLT_CTOR << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << STP_CTOR << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& inst) : ClapTrap(inst) {
	std::cout << STP_CPY_CTOR << std::endl;
	if (this != &inst)
		*this = inst;
}
ScavTrap::~ScavTrap() {
	std::cout << STP_DTOR << this->name_ << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& inst) {
	std::cout << STP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &inst) {
		this->name_ = inst.name_;
		this->hit_points_ = inst.hit_points_;
		this->energy_points_ = inst.energy_points_;
		this->attack_damage_ = inst.attack_damage_;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (!this->canYouDoIt()) {
		std::cout << "ScavTrap [" << this->name_ << "] can't attack " << target
				  << " because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ScavTrap [" << this->name_ << "] attacks " << target
			  << ", causing " << this->attack_damage_ << " points of damage!"
			  << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (!this->canYouDoIt()) {
		std::cout << "ClapTrap [" << this->name_ << "] can't repair "
				  << "because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	this->hit_points_ += amount;
	if (this->hit_points_ > ScavTrap::init_hit_points_)
		this->hit_points_ = ScavTrap::init_hit_points_;
	std::cout << "ClapTrap [" << this->name_ << "] repair " << amount
			  << " points" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->canYouDoIt())
		std::cout << "[" << this->name_ << "] " << STP_GATE_KEEPER_MODE
				  << std::endl;
	else
		std::cout << "[" << this->name_ << "] " << STP_CAN_T_FUNC << std::endl;
};
//ScavTrap and will inherit the constructors and destructor from Clap-
//Trap. However, its constructors, destructor and attack() will print different messages.

//the program starts by building a ClapTrap. Destruction is
//in reverse order. Why?