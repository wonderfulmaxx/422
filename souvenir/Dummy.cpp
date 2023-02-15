#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Target Practice Dummy\n";
}

Dummy::~Dummy()
{}

ATarget* const Dummy::clone()
{
	return(new Dummy);
}