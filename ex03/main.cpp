/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:01 by jgo               #+#    #+#             */
/*   Updated: 2023/05/17 20:27:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

static inline void prtDiamondTrap(void) {
	std::cout << "/\\\\\\\\\\                                                  "
				 "    /\\\\/\\\\\\ /\\\\\\\\\\\\                     "
			  << std::endl;
	std::cout << "/\\\\   /\\\\  /\\                                           "
				 "    /\\\\     /\\\\                             "
			  << std::endl;
	std::cout
		<< "/\\\\    /\\\\      /\\\\    /\\\\\\ /\\\\ /\\\\    /\\\\    /\\\\ "
		   "/\\\\       /\\\\     /\\\\    /\\ /\\\\\\   /\\\\    /\\ /\\\\  "
		<< std::endl;
	std::cout << "/\\\\    /\\\\/\\\\ /\\\\  /\\\\  /\\\\  /\\  /\\\\ /\\\\  "
				 "/\\\\  /\\\\  /\\\\ /\\\\ /\\\\     /\\\\     /\\\\    /\\\\ "
				 " /\\\\ /\\  /\\\\ "
			  << std::endl;
	std::cout << "/\\\\    /\\\\/\\\\/\\\\   /\\\\  /\\\\  /\\  /\\\\/\\\\    "
				 "/\\\\ /\\\\  /\\\\/\\   /\\\\     /\\\\     /\\\\   /\\\\   "
				 "/\\\\ /\\   /\\\\"
			  << std::endl;
	std::cout << "/\\\\   /\\\\ /\\\\/\\\\   /\\\\  /\\\\  /\\  /\\\\ /\\\\  "
				 "/\\\\  /\\\\  /\\\\/\\   /\\\\     /\\\\     /\\\\   /\\\\   "
				 "/\\\\ /\\\\ /\\\\ "
			  << std::endl;
	std::cout << "/\\\\\\\\\\    /\\\\  /\\\\ /\\\\\\/\\\\\\  /\\  /\\\\   "
				 "/\\\\    /\\\\\\  /\\\\ /\\\\ /\\\\     /\\\\    /\\\\\\     "
				 "/\\\\ /\\\\\\/\\\\     "
			  << std::endl;
	std::cout << "/\\\\     " << std::endl;
}

int main(void) {
	prtDiamondTrap();
	DiamondTrap jgo("jgo");
	FragTrap enemy("enemy");

	jgo.attack(enemy.getName());
	enemy.takeDamage(jgo.getAttackDamage());
	enemy.highFivesGuys();
	jgo.guardGate();
	enemy.beRepaired(100);
	jgo.whoAmI();

	ScavTrap jgo2(jgo);

	jgo2.attack(enemy.getName());
	jgo2.guardGate();

	ClapTrap enemy2;

	enemy2 = enemy;
	enemy2.attack(enemy.getName());
	jgo.prtStatus();
	jgo2.prtStatus();
	enemy2.prtStatus();
	enemy.prtStatus();

	return (0);
}