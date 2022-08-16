/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:48:17 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/07 16:34:49 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class phoneBook
{

public:
	
	std::string titre;

	phoneBook(std::string lieu); //constructeur
	~phoneBook(); //destucteur
	
	void	add(void);
	void	afficher(void);//int number);
	std::string getTitle(void) const;
	int		compare(phoneBook * other) const;

	static int getnbinst(void);

private:
	int m_number_of_contacts;
	void	useless(void) const;
	std::string m_name;
	static int nbInst;
};


///phoneBook::phoneBook()
//{
//	m_number_of_contacts = 1;
//	m_name = "Tyler";
//}
