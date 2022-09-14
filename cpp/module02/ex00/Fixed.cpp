/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:35:37 by mwinter-          #+#    #+#             */
/*   Updated: 2022/09/14 14:19:43 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():integer(0)
{
	std::cout<<"Default constructor called"<<std::endl;
	return;
}

Fixed::Fixed(const Fixed & src)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
	return;
}

Fixed& Fixed::operator=(const Fixed & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&rhs != this)
		setRawBits(rhs.getRawBits());
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->integer);
}

void Fixed::setRawBits( int const raw )
{
	this->integer = raw;
}