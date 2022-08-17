/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:26:56 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/17 16:11:43 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int white(std::string input);

class PhoneBook
{
public:

	PhoneBook();
	~PhoneBook();
	
	int		input_number();
	int	get_n_contact();
	void	add_contact();
	void	afficher();
	Contact tab_contact[8];
	
private:

	static int nb_contacts;
	
};