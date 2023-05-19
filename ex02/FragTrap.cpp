/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:57:42 by jgo               #+#    #+#             */
/*   Updated: 2023/05/19 13:50:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap("scav_trap_default", FragTrap::init_hit_points_,
			   FragTrap::init_energy_points_, FragTrap::init_attack_damage_) {
	std::cout << FTP_DFLT_CTOR << std::endl;
}

FragTrap::FragTrap(const std::string name)
	: ClapTrap(name, FragTrap::init_hit_points_, FragTrap::init_energy_points_,
			   FragTrap::init_attack_damage_) {
	std::cout << FTP_CTOR << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << FTP_CPY_CTOR << std::endl;
	if (this != &obj)
		*this = obj;
}
FragTrap::~FragTrap() {
	std::cout << FTP_DTOR << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	std::cout << FTP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &obj) {
		this->name_ = obj.name_;
		this->hit_points_ = obj.hit_points_;
		this->energy_points_ = obj.energy_points_;
		this->attack_damage_ = obj.attack_damage_;
	}
	return (*this);
}

void FragTrap::beRepaired(unsigned int amount) {
	if (!this->canYouDoIt()) {
		std::cout << "ClapTrap [" << this->name_ << "] can't repair "
				  << "because out of hp/ep points" << std::endl;
		return;
	}
	this->energy_points_--;
	this->hit_points_ += amount;
	if (this->hit_points_ > FragTrap::init_hit_points_)
		this->hit_points_ = FragTrap::init_hit_points_;
	std::cout << "ClapTrap [" << this->name_ << "] repair " << amount
			  << " points" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap: " << this->name_
			  << " a very positive request of high Fives jajaja" << std::endl;
}