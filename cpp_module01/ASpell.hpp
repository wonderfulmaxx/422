#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "Warlock.hpp"
#include "ATarget.hpp"


class ASpell
{

	protected:
		std::string name;
		std::string effects;

	public:
		ASpell();
		ASpell(std::string const &_name , std::string _effects);
		ASpell(const ASpell &other);
		ASpell& operator=(const ASpell &other);
		virtual ~ASpell();

		void launch (ATarget const &cible) const;

		std::string const &getName() const;
		std::string const &getEffects() const;

		virtual ASpell *clone() = 0; 

};

#endif