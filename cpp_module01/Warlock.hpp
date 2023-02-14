#pragma once

#include <iostream>
#include <list>
#include "ASpell.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);

        std::list <ASpell *> list_de_sort;
        std::list <std::string> list_de_noms;

    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        void learnSpell(ASpell* aspell);
        void forgetSpell(std::string const spell);
        void launchSpell(std::string const spell);


        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(std::string const &title);

        void introduce() const;
};