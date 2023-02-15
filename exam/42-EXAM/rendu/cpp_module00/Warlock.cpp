#include "Warlock.hpp"

Warlock::Warlock(std::string const &_name, std::string const &_title):name(_name),title(_title)
{
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->getName()<<": My job here is done!"<<std::endl;
}

std::string const& Warlock::getName() const
{
	return (this->name);
}

std::string const& Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::introduce() const
{
	std::cout << this->getName()<<": I am " << this->getName() << ", " << this->getTitle() << "!"<<std::endl;
}

void Warlock::setTitle(std::string const & new_title)
{
	this->title = new_title;
}