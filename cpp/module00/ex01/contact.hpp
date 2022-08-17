/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:10:45 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/17 16:11:38 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string.h>

class Contact
{
public:

	Contact();
	~Contact();
	
	void	add();
	void	search();
	void	full_print();

private:

	std::string	info[5];
};