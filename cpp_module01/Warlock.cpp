#include "Warlock.hpp"
#include <list>

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {std::cout << this->name << ": My job here is done!\n";}

std::string const &Warlock::getName() const { return (this->name);}
std::string const &Warlock::getTitle() const { return (this->title);}

void Warlock::setTitle(std::string const &title) { this->title = title;}

void Warlock::introduce() const { std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";}

void Warlock::learnSpell(ASpell* aspell)
{
    list_de_sort.push_back(aspell);
    list_de_noms.push_back(aspell->getName());
}

void Warlock::launchSpell(std::string const spell)
{
    std::list<std::string>::iterator lol;

    lol = this->list_de_noms.begin();

    for (; lol != list_de_noms.end(); lol++)
        std::cout << *lol << std::endl;
}