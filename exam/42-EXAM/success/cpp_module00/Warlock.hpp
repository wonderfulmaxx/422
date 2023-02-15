#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;

		Warlock();
		Warlock(Warlock const &other);
		Warlock& operator=(Warlock const &other);

	public:
		std::string const &getName() const;
		std::string const &getTitle() const;

		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		void setTitle(std::string const &new_title);

		void introduce() const;

};

#endif 