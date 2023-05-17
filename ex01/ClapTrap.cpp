/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:49:59 by jgo               #+#    #+#             */
/*   Updated: 2023/05/17 20:21:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name_("default"),
	  hit_points_(10),
	  energy_points_(10),
	  attack_damage_(0),
	  init_hit_points_(10),
	  init_energy_points_(10),
	  init_attack_damage_(0) {
	std::cout << CTP_DFLT_CTOR << std::endl;
};

ClapTrap::ClapTrap(const std::string name)
	: name_(name),
	  hit_points_(10),
	  energy_points_(10),
	  attack_damage_(0),
	  init_hit_points_(10),
	  init_energy_points_(10),
	  init_attack_damage_(0) {
	std::cout << CTP_CTR << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& obj)
	: init_hit_points_(10), init_energy_points_(10), init_attack_damage_(0) {
	std::cout << CTP_CPY_CTOR << std::endl;
	*this = obj;
}
ClapTrap::~ClapTrap() {
	std::cout << CTP_DTOR << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& inst) {
	std::cout << CTP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &inst) {
		this->name_ = inst.getName();
		this->energy_points_ = inst.getEnergyPoints();
		this->attack_damage_ = inst.getAttackDamage();
		this->hit_points_ = inst.getHitPoints();
	}
	return (*this);
}

ClapTrap::ClapTrap(const std::string name, const unsigned int hit_points,
				   const unsigned int energy_points,
				   const unsigned int attack_damage)
	: name_(name),
	  hit_points_(hit_points),
	  energy_points_(energy_points),
	  attack_damage_(attack_damage),
	  init_hit_points_(hit_points),
	  init_energy_points_(energy_points),
	  init_attack_damage_(attack_damage){
		  std::cout << CTP_CTR << std::endl;
	  };

std::string ClapTrap::getName(void) const {
	return (this->name_);
}
unsigned int ClapTrap::getHitPoints(void) const {
	return (this->hit_points_);
}
unsigned int ClapTrap::getEnergyPoints(void) const {
	return (this->energy_points_);
}
unsigned int ClapTrap::getAttackDamage(void) const {
	return (this->attack_damage_);
}

unsigned int ClapTrap::getInitHitPoints(void) const {
	return (this->init_hit_points_);
};
unsigned int ClapTrap::getInitEnergyPoints(void) const {
	return (this->init_energy_points_);
};
unsigned int ClapTrap::getInitAttackDamage(void) const {
	return (this->init_attack_damage_);
};

void ClapTrap::setAttackDamage(unsigned int amount) {
	this->attack_damage_ = amount;
	std::cout << "ClapTrap [" << this->getName() << "] set AttackDamage to "
			  << amount << std::endl;
}

bool ClapTrap::canYouDoIt(void) const {
	return (this->getHitPoints() && this->getEnergyPoints());
}

void ClapTrap::attack(const std::string& target) {
	if (!this->canYouDoIt()) {
		std::cout << "ClapTrap [" << this->getName() << "] can't attack "
				  << target << " because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ClapTrap [" << this->getName() << "] attacks " << target
			  << ", causing " << this->getAttackDamage() << " points of damage!"
			  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->canYouDoIt()) {
		std::cout << "ClapTrap [" << this->getName() << "] can't repair "
				  << "because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ClapTrap [" << this->getName() << "] repair ";
	if (this->hit_points_ + amount > this->getInitHitPoints()) {
		std::cout << ((amount >= this->getInitHitPoints())
						  ? this->getInitHitPoints() - this->hit_points_
						  : this->getInitHitPoints())
				  << " points" << std::endl;
		this->hit_points_ = this->getInitHitPoints();
	} else {
		this->hit_points_ += amount;
		std::cout << amount << " points" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() == 0) {
		std::cout << "there's no reaction...." << this->getName()
				  << " may be it just died" << std::endl;
		return;
	}
	const unsigned int prev_hp = this->hit_points_;
	std::cout << "ClapTrap [" << this->getName() << "] take " << amount
			  << " damage ";
	this->hit_points_ -= amount;
	if (prev_hp <= amount) {
		std::cout << "boom!!" << std::endl;
		this->hit_points_ = 0;
	} else
		std::cout << "ouch!!" << std::endl;
}

void ClapTrap::prtStatus(void) const {
	std::cout << std::setw(5) << "Name: " << this->getName() << "\n";
	std::cout << std::setw(5) << "HP: " << this->getHitPoints() << "\n";
	std::cout << std::setw(5) << "EP: " << this->getEnergyPoints() << "\n";
	std::cout << std::setw(5) << "AD: " << this->getAttackDamage() << "\n";
}