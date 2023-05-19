/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:01 by jgo               #+#    #+#             */
/*   Updated: 2023/05/19 14:02:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static inline void prtClapTrap(void) {
	std::cout << "_______             _______                \n";
	std::cout << "(_______)           (_______)               \n";
	std::cout << "_____ ____ _____  ____ _  ____ _____ ____  \n";
	std::cout << "|  ___) ___|____ |/ _  | |/ ___|____ |  _ \\ \n";
	std::cout << "| |  | |   / ___ ( (_| | | |   / ___ | |_| |\n";
	std::cout << "|_|  |_|   \\_____|\\___ |_|_|   \\_____|  __/ \n";
	std::cout << "(_____|	             		     |_|    \n";
}

int main(void) {
	prtClapTrap();
	ClapTrap enemy("enemy");
	ScavTrap jgo("jgo");
	FragTrap frog("frog");	

	frog.highFivesGuys();
	jgo.guardGate();

	jgo.attack("enemmmm");
	enemy.takeDamage(9);
	enemy.beRepaired(10);
	
	frog.attack("enemy~~");
	enemy.takeDamage(3);

	jgo.attack("froggg");
	frog.takeDamage(8);
	frog.beRepaired(10);

	jgo.prtStatus();
	enemy.prtStatus();
	frog.prtStatus();

	return (0);
}