#include "ATarget.hpp"

std::string const& ATarget::getType() const
{
	return(this->type);
}


ATarget::~ATarget(){}

ATarget::ATarget(ATarget const & other)
{
	*this=other;
}

ATarget&  ATarget::operator=(ATarget const & other)
{
	this -> type = other.getType();
	return(*this);
}

ATarget::ATarget(){}

ATarget::ATarget(std::string const & _type):type(_type)
{}

void ATarget::getHitBySpell(ASpell const& mechant) const
{
	std::cout << this->getType() << " has been " << mechant.getEffects()<<"!\n";
}


