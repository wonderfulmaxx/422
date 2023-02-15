#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <list>

class Warlock
{
	private:
		std::string name;
		std::string title;

		Warlock();
		Warlock(Warlock const &other);
		Warlock& operator=(Warlock const &other);

		std::list<ASpell*>			spell_list;
		std::list<std::string>		name_list;

	public:
		std::string const &getName() const;
		std::string const &getTitle() const;

		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		void setTitle(std::string const &new_title);

		void introduce() const;


		void learnSpell (ASpell * new_spell);

		void forgetSpell (std::string const & new_spell) ;

		void launchSpell (std::string const & spell_name , ATarget & target);

};

#endif 