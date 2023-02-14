#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &_name , std::string _effects):name(_name), effects(_effects)
{}


ASpell::ASpell(const ASpell &other):name(other.getName()),effects(other.getEffects()) //here
{}

ASpell& ASpell::operator=(const ASpell &other)
{
	this->name = other.getName();
	this->effects= other.getEffects();

	return(*this);
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const { return (this->name);}

std::string const &ASpell::getEffects() const { return (this->effects);}

void ASpell::launch(ATarget const &atarget_ref) const
{
    atarget_ref.getHitBySpell((*this));
}