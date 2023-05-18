/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:49:59 by jgo               #+#    #+#             */
/*   Updated: 2023/05/18 10:17:10 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name_("default"), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << CTP_DFLT_CTOR << std::endl;
};

ClapTrap::ClapTrap(const std::string name)
	: name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << CTP_CTR << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std::cout << CTP_CPY_CTOR << std::endl;
	*this = obj;
}
ClapTrap::~ClapTrap() {
	std::cout << CTP_DTOR << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& inst) {
	std::cout << CTP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &inst) {
		this->name_ = inst.name_;
		this->energy_points_ = inst.energy_points_;
		this->attack_damage_ = inst.attack_damage_;
		this->hit_points_ = inst.hit_points_;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (this->hit_points_ == 0 || this->energy_points_ == 0) {
		std::cout << "ClapTrap [" << this->name_ << "] can't attack " << target
				  << " because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ClapTrap [" << this->name_ << "] attacks " << target
			  << ", causing " << this->attack_damage_ << " points of damage!"
			  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hit_points_ == 0 || this->energy_points_ == 0) {
		std::cout << "ClapTrap [" << this->name_ << "] can't repair "
				  << "because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	this->hit_points_ += amount;
	if (this->hit_points_ > ClapTrap::init_hit_points_)
		this->hit_points_ = ClapTrap::init_hit_points_;
	std::cout << "ClapTrap [" << this->name_ << "] repair " << amount
			  << " points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points_ == 0) {
		std::cout << "there's no reaction...." << this->name_
				  << " may be it just died" << std::endl;
		return;
	}
	const unsigned int prev_hp = this->hit_points_;
	std::cout << "ClapTrap [" << this->name_ << "] take " << amount
			  << " damage ";
	this->hit_points_ -= amount;
	if (prev_hp <= amount) {
		std::cout << "boom!!" << std::endl;
		this->hit_points_ = 0;
	} else
		std::cout << "ouch!!" << std::endl;
}

void ClapTrap::prtStatus(void) const {
	std::cout << std::setw(5) << "Name: " << this->name_ << "\n";
	std::cout << std::setw(5) << "HP: " << this->hit_points_ << "\n";
	std::cout << std::setw(5) << "EP: " << this->energy_points_ << "\n";
	std::cout << std::setw(5) << "AD: " << this->attack_damage_ << "\n";
}