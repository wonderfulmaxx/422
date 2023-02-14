#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &_type):type(_type)
{}

ATarget::ATarget(const ATarget &other):type(other.type){}

ATarget &ATarget::operator=(const ATarget &other)
{
	this->type = other.getType();
	return(*this);
}

ATarget::~ATarget ()
{};

std::string const & ATarget::getType() const
{
	return (this->type);
}

void ATarget::getHitBySpell(ASpell const &mechant) const
{
	std::cout << mechant.getEffects() << std::endl;
}