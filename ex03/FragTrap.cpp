/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:57:42 by jgo               #+#    #+#             */
/*   Updated: 2023/05/18 10:51:18 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("scav_trap_default", 100, 100, 30) {
	std::cout << FTP_DFLT_CTOR << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << FTP_CTOR << std::endl;
}

FragTrap::FragTrap(const FragTrap& inst) : ClapTrap(inst) {
	std::cout << FTP_CPY_CTOR << std::endl;
	if (this != &inst)
		*this = inst;
}
FragTrap::~FragTrap() {
	std::cout << FTP_DTOR << this->name_ << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& inst) {
	std::cout << FTP_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &inst) {
		this->name_ = inst.name_;
		this->hit_points_ = inst.hit_points_;
		this->energy_points_ = inst.energy_points_;
		this->attack_damage_ = inst.attack_damage_;
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
