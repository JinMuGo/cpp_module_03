/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:01 by jgo               #+#    #+#             */
/*   Updated: 2023/05/13 16:05:21 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static inline void prtClapTrap(void) {
	std::cout << "      _             _                   \n";
	std::cout << "     | |           | |                  \n";
	std::cout << "  ___| | __ _ _ __ | |_ _ __ __ _ _ __  \n";
	std::cout << " / __| |/ _` | '_ \\| __| '__/ _` | '_ \\ \n";
	std::cout << "| (__| | (_| | |_) | |_| | | (_| | |_) |\n";
	std::cout << " \\___|_|\\__,_| .__/ \\__|_|  \\__,_| .__/ \n";
	std::cout << "             | |                 | |    \n";
	std::cout << "             |_|                 |_|    \n\n";
}

int main(void) {
	prtClapTrap();
	ClapTrap jgo("jgo");
	ClapTrap enemy("enemy");

	jgo.attack(enemy.getName());
	enemy.takeDamage(jgo.getAttackDamage());

	jgo.setAttackDamage(5);
	jgo.attack(enemy.getName());
	enemy.takeDamage(jgo.getAttackDamage());
	enemy.beRepaired(10);

	jgo.setAttackDamage(9);
	jgo.attack(enemy.getName());
	enemy.takeDamage(jgo.getAttackDamage());
	enemy.beRepaired(42);
	enemy.takeDamage(111);

	enemy.attack(jgo.getName());

	jgo.prtStatus();
	enemy.prtStatus();

	return (0);
}