#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

		ASpell();

	public:
		std::string const& getName() const;
		std::string const& getEffects() const;

		~ASpell();

		ASpell(ASpell const & other);

		ASpell& operator=(ASpell const & other);

		virtual ASpell* const clone() = 0;

		ASpell(std::string const & name, std::string const & effects);

		void launch(ATarget &launcher) const; 

};

#endif