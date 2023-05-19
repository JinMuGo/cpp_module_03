/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:01 by jgo               #+#    #+#             */
/*   Updated: 2023/05/19 14:03:57 by jgo              ###   ########.fr       */
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
				 "'--'  `--' `--'`--'      \n\n";
}

int main(void) {
	prtClapTrap();
	ClapTrap jgo("jgo");
	ScavTrap enemy("enemy");
	ClapTrap *s1 = new ScavTrap("s1");

	s1->attack("hihi");

	delete s1;
	jgo.attack("enemy");
	enemy.takeDamage(10);

	jgo.attack("enemy");
	enemy.takeDamage(23);
	enemy.beRepaired(10);

	jgo.attack("enemyyy");
	enemy.takeDamage(32);
	enemy.beRepaired(42);
	enemy.takeDamage(111);

	enemy.attack("jgooooo");

	enemy.guardGate();

	jgo.prtStatus();
	enemy.prtStatus();


	return (0);
}