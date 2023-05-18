/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:00 by jgo               #+#    #+#             */
/*   Updated: 2023/05/18 10:16:23 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include "ClapTrap.h"

class ClapTrap {
   private:
	std::string name_;
	unsigned int hit_points_;
	unsigned int energy_points_;
	unsigned int attack_damage_;

	static const unsigned int init_hit_points_ = 10;
	static const unsigned int init_energy_points_ = 10;
	static const unsigned int init_attack_damage_ = 0;

   public:
	ClapTrap();
	ClapTrap(const ClapTrap& obj);
	ClapTrap(const std::string name);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& obj);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void prtStatus(void) const;
};

#endif