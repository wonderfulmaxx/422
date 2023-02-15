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

void Warlock::learnSpell (ASpell * new_spell)
{

	int already_know = 0;

for (std::list<std::string>::iterator ite = name_list.begin();
		ite != name_list.end(); ite ++ )
	{
		// std::cout << "-"<<(*ite) << std::endl;
		if (*ite == new_spell->getName())
			already_know = 1;
	}

	if (already_know == 0)
	{
		this->spell_list.push_back(new_spell);
		this->name_list.push_back(new_spell->getName());
		std::cout << "learn " << new_spell->getName() << std::endl;
	}
	else
		std::cout << "sort deja connu\n";


	
}

void Warlock::forgetSpell (std::string const & new_spell) 
{

	std::list<ASpell*>::iterator ite_spell = spell_list.begin();

	for (std::list<std::string>::iterator ite = name_list.begin();
		ite != name_list.end(); ite ++  )
	{
		//std::cout << "-"<<(*ite) << std::endl;
		if (*ite == new_spell)
		{
			this->spell_list.erase(ite_spell);
			this->name_list.erase(ite);
			std::cout << "forget "<< new_spell << std::endl;
		}
		ite_spell ++;
	}

	//std::cout << "supprimer index " << name_list.find(new_spell) << ".\n";
	//this->name_list.erase(new_spell);
	//std::cout << "forget "<< new_spell << std::endl;
}

void Warlock::launchSpell (std::string const & spell_name , ATarget & target)
{

	std::list<ASpell>::iterator ite_spell = spell_list.begin();

	for (std::list<std::string>::iterator ite = name_list.begin();
		ite != name_list.end(); ite ++  )
	{
		if (*ite == spell_name)
		{
			std::cout << "launch ";
			//ite_spell->launch(target);
			std::cout << ite_spell->getName();
		}

		ite_spell ++;
	}

	//std::cout << "launch\n";
}







