#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	this->name="Fwoosh";
	this->effects="fwooshed";
}

Fwoosh::~Fwoosh()
{}

ASpell* const Fwoosh::clone()
{
	return(new Fwoosh);
}