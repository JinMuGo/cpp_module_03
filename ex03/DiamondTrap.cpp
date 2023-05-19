/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:53 by jgo               #+#    #+#             */
/*   Updated: 2023/05/19 13:46:47 by jgo              ###   ########.fr       */
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

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
	: ClapTrap(obj.ClapTrap::name_, obj.hit_points_, obj.energy_points_,
			   obj.attack_damage_),
	  ScavTrap(obj),
	  FragTrap(obj) {
	std::cout << DTP_CPY_CTOR << std::endl;
	*this = obj;
}
DiamondTrap::~DiamondTrap() {
	std::cout << DTP_DTOR << this->name_ << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	std::cout << DTP_CPY_ASGMT_OP_CALL << std::endl;

	if (this != &obj) {
		this->name_ = obj.name_;
		this->hit_points_ = obj.hit_points_;
		this->energy_points_ = obj.energy_points_;
		this->attack_damage_ = obj.attack_damage_;
		this->ClapTrap::name_ = obj.ClapTrap::name_;
	}

	return (*this);
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::beRepaired(unsigned int amount) {
	if (!this->canYouDoIt()) {
		std::cout << "ClapTrap [" << this->name_ << "] can't repair "
				  << "because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	this->hit_points_ += amount;
	if (this->hit_points_ > DiamondTrap::init_hit_points_)
		this->hit_points_ = DiamondTrap::init_hit_points_;
	std::cout << "ClapTrap [" << this->name_ << "] repair " << amount
			  << " points" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "hi my name is " << this->name_ << " nice to meet you ";
	std::cout << "and my base class name is " << this->ClapTrap::name_
			  << " hi :)" << std::endl;
}

void DiamondTrap::prtStatus(void) const {
	std::cout << std::setw(5) << "Name: " << this->name_ << "\n";
	std::cout << std::setw(5) << "HP: " << this->hit_points_ << "\n";
	std::cout << std::setw(5) << "AD: " << this->attack_damage_ << "\n";
	std::cout << std::setw(5) << "EP: " << this->energy_points_ << "\n";
}