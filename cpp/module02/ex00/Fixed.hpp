/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:44:00 by mwinter-          #+#    #+#             */
/*   Updated: 2022/09/14 14:00:35 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
	int	integer;
	static const int	fractional_bits = 8;

	public:
	Fixed();
	Fixed(const Fixed& src);
	~Fixed();

	Fixed & operator=(Fixed const & rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};