#include "ASpell.hpp"

class ATarget
{

	protected:
		std::string type;

	public:
		ATarget();
		ATarget(std::string const &_type);
		ATarget(const ATarget &other);
		ATarget &operator=(const ATarget &other);
		virtual ~ATarget();


		std::string const &getType() const;

		void getHitBySpell(ASpell const &mechant) const;

		virtual ATarget *clone() const = 0; 

};