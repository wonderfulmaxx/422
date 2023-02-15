#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;

		ATarget();

	public:
		std::string const& getType() const;

		~ATarget();

		ATarget(ATarget const & other);

		ATarget& operator=(ATarget const & other);

		virtual ATarget* const clone() = 0;

		ATarget(std::string const & _type);

		void getHitBySpell(ASpell const& mechant) const; //here, jai mis des const nulle part...

};


#endif