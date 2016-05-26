/*
 * Settings.cpp
 *
 *  Created on: 1 avr. 2016
 *      Author: gbrunner
 */

#include "Settings.h"

Settings::Settings() {
	// TODO Auto-generated constructor stub

}

Settings::~Settings() {
	// TODO Auto-generated destructor stub
}


void Settings::saveSettings()
{
	std::ofstream stream(".settings", std::ios::binary);

	if (stream.is_open())
	{
		for(auto unit : units)
			stream.write(*unit, sizeof(SettingsUnit));
	}
	else throw "Impossible to save file .settings";
}

void Settings::loadSettings()
{
	std::ifstream stream(".settings", std::ios::binary);

	if (stream.is_open())
	{
		char buffer[sizeof(SettingsUnit)];
		SettingsUnit* unit;
		while(stream.good())
		{
			stream.read(buffer, sizeof(SettingsUnit));
			unit = new (SettingsUnit)buffer;
			units[unit->Name] = unit;
		}
	}
	else throw "Impossible to load file .settings";
}
