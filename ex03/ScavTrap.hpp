/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:24:25 by jgo               #+#    #+#             */
/*   Updated: 2023/05/17 20:15:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ScavTrap.h"

class ScavTrap : virtual public ClapTrap {
   public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& inst);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& inst);
	void guardGate();

	virtual void attack(const std::string& target);
	protected :
		static const unsigned int init_hit_points_ = 100;
		static const unsigned int init_energy_points_ = 50;
		static const unsigned int init_attack_damage_ = 20;
};

#endif