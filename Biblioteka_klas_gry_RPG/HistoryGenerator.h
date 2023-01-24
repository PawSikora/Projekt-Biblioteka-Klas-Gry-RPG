#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<random>
#include"Parameters.h"
#include<ctime>
//zmiany beda konieczne przy dodaniu ras problem polega na tym zeby rasy w wektorze trzymac
class HistoryGenerator
{
	std::vector<std::string> adjective;
	std::vector<std::string> diplomacy;
	std::vector<std::string> kingdoms;
	std::vector<std::string> whoRule;
	unsigned int wiek;
	void addAdjective();
	void addWhoRule();
	void addDiplomacy();
	void addKingdoms();
public:
	HistoryGenerator()
	{
		addAdjective();
		addWhoRule();
		addDiplomacy();
		addKingdoms();
		std::mt19937 random(time(nullptr));
		wiek = random() % 3000;


	}
	std::string GenerujHistorie() {
		std::mt19937 random(time(nullptr));
		std::string resoult;
		int dontRepeat;
		int temp=0;
		resoult += std::to_string(wiek)+ " lat";
		resoult += " po wielkiej wojna miedzy ";
		dontRepeat = random() % kingdoms.size();
		resoult += kingdoms[dontRepeat];
		resoult += " oraz ";
		temp = random() % kingdoms.size();
		while(dontRepeat == temp) {
			temp = random() % kingdoms.size();
		}
		resoult += kingdoms[temp]+"."+'\n';
		resoult += "Swiat ten byl " + adjective[random() % adjective.size()]+",";
		resoult += " a rzadzil nim ten kto " + whoRule[random() % whoRule.size()] + "." + '\n';
		resoult += "Opowiesc Rozpoczyna sie w  " + kingdoms[random() % kingdoms.size()] + "." + '\n';
		resoult += "Czy bohaterowie przezyja niesamowita przygode, i co wazniejsze, czy beda mieli ja jak opowiedziec ?";
		return resoult;
	}

};