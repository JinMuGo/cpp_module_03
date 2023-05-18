/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:57:45 by jgo               #+#    #+#             */
/*   Updated: 2023/05/18 10:51:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "FragTrap.h"

class FragTrap : virtual public ClapTrap {
   protected:
	static const unsigned int init_hit_points_ = 100;
	static const unsigned int init_energy_points_ = 100;
	static const unsigned int init_attack_damage_ = 30;

   public:
	FragTrap();
	FragTrap(const FragTrap& inst);
	FragTrap(const std::string name);
	FragTrap& operator=(const FragTrap& inst);
	void highFivesGuys(void);
	
	virtual ~FragTrap();
	virtual void beRepaired(unsigned int amount);
};

#endif
