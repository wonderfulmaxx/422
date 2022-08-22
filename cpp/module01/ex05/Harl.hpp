/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:49:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/22 14:32:14 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Harl
{
	public:
	void complain( std::string level );
	Harl();
	~Harl();

	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );