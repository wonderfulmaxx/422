/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:57:24 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/07 17:51:56 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

phoneBook::phoneBook(std::string lieu) : titre(lieu)
{
	std::cout << "constructeur called" << std::endl;
	phoneBook::nbInst ++;
}

phoneBook::~phoneBook(void)
{
	std::cout << "destructeur called"<< std::endl;
	phoneBook::nbInst --;
}

 void	phoneBook::afficher(void)
 {
 	std::cout << "Titre = "<< this->titre <<" Name = " <<  phoneBook::m_name << std::endl;
 }

void	phoneBook::add(void)
{
	this ->m_name = "Tyler";
	//this -> m_number_of_contacts = 1;
	useless();
}

void	phoneBook::useless(void) const
{
	std::cout << "Mwa jeime pa les gourdin"<< std::endl;
	//this -> m_name = "Gourdin";
	//this -> m_number_of_contacts = 1;
}

std::string	phoneBook::getTitle(void) const
{

	return (this-> titre);
}

int		phoneBook::compare(phoneBook * other) const
{
	if (this -> getTitle() == other -> getTitle())
		std::cout << "Meme region" << std::endl;
	else
		{
			std::cout << "pas les memes region" << std::endl;
			return (0);
		}
	return (1);
}

int	phoneBook::getnbinst(void)
{
	return (phoneBook::nbInst);
}

int phoneBook::nbInst = 0;

int main()
{
	std::cout << "nb inst : " << phoneBook::getnbinst() << std::endl;
	phoneBook pageJaunes("Alsace");
	phoneBook pageBlanches("Corse");
	//pageJaunes.m_name = "tyler";
	pageJaunes.add();
	pageJaunes.afficher();
	std::cout << "nb inst : " << phoneBook::getnbinst() << std::endl;
	pageJaunes.compare(&pageBlanches);
	if (&pageBlanches == &pageJaunes)
		std::cout << "equal" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;
std::cout << "nb inst : " <<phoneBook::getnbinst() << std::endl;

	return 0; 
}