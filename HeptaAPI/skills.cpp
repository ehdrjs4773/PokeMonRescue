#include "stdafx.h"
#include "skills.h"

skills::skills()
{
}
skills::~skills()
{
}

HRESULT skills::init(string name)
{
	_skillName = DATABASE->getSkillsData(name)->name;
	_skillElement = (SKILL_ELEMENT)DATABASE->getSkillsData(name)->skillElement;
	_power = DATABASE->getSkillsData(name)->power;
	_currentPP = DATABASE->getSkillsData(name)->pp;
	_maxPP = DATABASE->getSkillsData(name)->pp;
	return S_OK;
}

void skills::setSkill(string name, int currentPP)
{
	_skillName = DATABASE->getSkillsData(name)->name;
	_skillElement = (SKILL_ELEMENT)DATABASE->getSkillsData(name)->skillElement;
	_power = DATABASE->getSkillsData(name)->power;
	_maxPP = DATABASE->getSkillsData(name)->pp;
	_currentPP = currentPP;
}