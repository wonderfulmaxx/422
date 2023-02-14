#include <iostream>
#include <list>
#include "Dummy.hpp"
#include "ATarget.hpp"
#include "Warlock.hpp"
#include "ASpell.hpp"


int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}