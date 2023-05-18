/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:00 by jgo               #+#    #+#             */
/*   Updated: 2023/05/18 10:47:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include "ClapTrap.h"

class ClapTrap {
   private:
	static const unsigned int init_hit_points_ = 10;
	static const unsigned int init_energy_points_ = 10;
	static const unsigned int init_attack_damage_ = 0;

   protected:
	std::string name_;
	unsigned int hit_points_;
	unsigned int energy_points_;
	unsigned int attack_damage_;
	bool canYouDoIt(void) const;

   public:
	ClapTrap();
	ClapTrap(const ClapTrap& obj);
	ClapTrap(const std::string name);
	ClapTrap(const std::string name, const unsigned int hit_points,
			 const unsigned int energy_points,
			 const unsigned int attack_damage);
	ClapTrap& operator=(const ClapTrap& obj);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void setAttackDamage(unsigned int amount);
	void prtStatus(void) const;

	virtual ~ClapTrap();
	virtual void beRepaired(unsigned int amount);
};

#endif