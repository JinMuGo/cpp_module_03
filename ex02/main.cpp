/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:01 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 17:19:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static inline void prtClapTrap(void) {
	std::cout << "  .-')                ('-.          (`-.    .-') _   _  .-') "
				 "    ('-.      _ (`-.  \n";
	std::cout << " ( OO ).             ( OO ).-.    _(OO  )_ (  OO) ) ( \\( -O "
				 ")   ( OO ).-. ( (OO  ) \n";
	std::cout << "(_)---\\_)   .-----.  / . --. /,--(_/   ,. \\/     '._ "
				 ",------.   / . --. /_.`     \\ \n";
	std::cout << "/    _ |   '  .--./  | \\-.  \\ \\   \\   /(__/|'--...__)|   "
				 "/`. '  | \\-.  \\(__...--'' \n";
	std::cout << "\\  :` `.   |  |('-..-'-'  |  | \\   \\ /   / '--.  .--'|  / "
				 " | |.-'-'  |  ||  /  | | \n";
	std::cout << " '..`''.) /_) |OO  )\\| |_.'  |  \\   '   /,    |  |   |  "
				 "|_.' | \\| |_.'  ||  |_.' | \n";
	std::cout << ".-._)   \\ ||  |`-'|  |  .-.  |   \\     /__)   |  |   |  .  "
				 "'.'  |  .-.  ||  .___.' \n";
	std::cout << "\\       /(_'  '--'\\  |  | |  |    \\   /       |  |   |  "
				 "|\\  \\   |  | |  ||  |      \n";
	std::cout << " `-----'    `-----'  `--' `--'     `-'        `--'   `--' "
				 "'--'  `--' `--'`--'      \n";
}

int main(void) {
	prtClapTrap();
	ScavTrap jgo("jgo");
	ScavTrap enemy("enemy");

	jgo.attack(enemy.getName());
	enemy.takeDamage(jgo.getAttackDamage());

	jgo.attack(enemy.getName());
	enemy.takeDamage(jgo.getAttackDamage());
	enemy.beRepaired(10);

	jgo.attack(enemy.getName());
	enemy.takeDamage(jgo.getAttackDamage());
	enemy.beRepaired(42);
	enemy.takeDamage(111);

	enemy.attack(jgo.getName());

	enemy.guardGate();
	jgo.guardGate();

	jgo.prtStatus();
	enemy.prtStatus();

	return (0);
}