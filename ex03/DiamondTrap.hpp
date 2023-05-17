/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:44:55 by jgo               #+#    #+#             */
/*   Updated: 2023/05/17 19:50:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "DiamondTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
   private:
	std::string name_;

   public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& inst);
	DiamondTrap(const std::string name);
	virtual ~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& inst);
	virtual void attack(const std::string& target);
	virtual void prtStatus(void) const;
	void whoAmI();
};

#endif