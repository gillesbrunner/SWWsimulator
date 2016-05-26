/*
 * Settings.h
 *
 *  Created on: 1 avr. 2016
 *      Author: gbrunner
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "included.h"

class SettingsUnit {
	std::string Name;

public:
	SettingsUnit();
	virtual ~SettingsUnit();
};


static class Settings {

private:
	std::unordered_map<std::string, SettingsUnit*> units;

public:
	Settings();
	virtual ~Settings();

	void saveCurrentUnit(std::string Name = "default");

	void saveSettings();
	void loadSettings();
};

#endif /* SETTINGS_H_ */
