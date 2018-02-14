#include "chicorita.h"



chicorita::chicorita()
{
	_pokemon.speed = 4;
}


chicorita::~chicorita()
{
}


void chicorita::attack()
{
	_pokemon.state = STATE_ATTACK;
}