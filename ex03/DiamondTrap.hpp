/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:55 by jgo               #+#    #+#             */
/*   Updated: 2023/05/18 10:55:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "DiamondTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
   private:
	std::string name_;
	static const unsigned int init_hit_points_ = FragTrap::init_hit_points_;
	static const unsigned int init_energy_points_ = ScavTrap::init_energy_points_;
	static const unsigned int init_attack_damage_ = FragTrap::init_attack_damage_;

   public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& inst);
	DiamondTrap(const std::string name);
	DiamondTrap& operator=(const DiamondTrap& inst);
	void whoAmI();

	virtual ~DiamondTrap();
	virtual void beRepaired(unsigned int amount);
	virtual void attack(const std::string& target);
	virtual void prtStatus(void) const;
};

#endif
