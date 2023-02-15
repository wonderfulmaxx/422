#include "ASpell.hpp"

std::string const& ASpell::getName() const
{
	return(this->name);
}

std::string const& ASpell::getEffects() const
{
	return(this->effects);
}


ASpell::~ASpell(){}

ASpell::ASpell(ASpell const & other)
{
	*this=other;
}

ASpell&  ASpell::operator=(ASpell const & other)
{
	this -> name = other.getName();
	this -> effects = other.getEffects();
	return(*this);
}

ASpell::ASpell(){}

ASpell::ASpell(std::string const & _name, std::string const & _effects):name (_name), effects(_effects)
{}


void ASpell::launch(ATarget &launcher) const
{
	launcher.getHitBySpell(*this);
}