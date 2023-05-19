/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:24:16 by jgo               #+#    #+#             */
/*   Updated: 2023/05/19 13:47:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap("scav_trap_default", ScavTrap::init_hit_points_,
			   ScavTrap::init_energy_points_, ScavTrap::init_attack_damage_) {
	std::cout << STP_DFLT_CTOR << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
	: ClapTrap(name, ScavTrap::init_hit_points_, ScavTrap::init_energy_points_,
			   ScavTrap::init_attack_damage_) {
	std::cout << STP_CTOR << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
	std::cout << STP_CPY_CTOR << std::endl;
	if (this != &obj)
		*this = obj;
}
ScavTrap::~ScavTrap() {
	std::cout << STP_DTOR << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	std::cout << STP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &obj) {
		this->name_ = obj.name_;
		this->hit_points_ = obj.hit_points_;
		this->energy_points_ = obj.energy_points_;
		this->attack_damage_ = obj.attack_damage_;
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

void ScavTrap::guardGate() {
	if (this->canYouDoIt())
		std::cout << "[" << this->name_ << "] " << STP_GATE_KEEPER_MODE
				  << std::endl;
	else
		std::cout << "[" << this->name_ << "] " << STP_CAN_T_FUNC << std::endl;
};

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