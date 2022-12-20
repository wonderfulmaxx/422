#include <stdio.h>

int main()
{
	int semaines = 0;
	float argent = 15000;

	while (semaines < 120)
	{
		semaines ++;
		argent = argent + (argent *0.16);
		printf("argent = %f, mois = %d (soit %d an(s))\n",argent, semaines, semaines/12);
	}
	return(0);
}