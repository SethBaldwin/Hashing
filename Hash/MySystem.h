#ifndef MYSYSTEM_H
#define MYSYSTEM_H

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

struct sethnix_user{
	std::string usrname;
	unsigned int password;
	unsigned int user_id;
	std::string name;
	std::string home_dir;

	// Default
	sethnix_user(){ usrname = ""; password = 0; user_id = 0; name = ""; home_dir = ""; };
	
	// Constructor 1
	sethnix_user(std::string usrnamein, unsigned int passwordin, unsigned int user_idin, std::string namein, std::string home_dirin){
		usrname = usrnamein; password = passwordin; user_id = user_idin; name = namein; home_dir = home_dirin;
	};

	// Constructor 2
	sethnix_user(std::string usrnamein){
		//usrname = usrnamein; password = " "; user_id = fnv322(usrnamein)%101; name = " "; home_dir = " ";
		usrname = usrnamein; password = 0; user_id = 0; name = ""; home_dir = "";
	};

	sethnix_user FromPasswdLine(std::string line){
		unsigned int cur_index = 0; // Iterator of each char in line
		sethnix_user temp_usr;	// Return item

		// For each field in sethnix_user. or each item. there are 5.
		for (int x = 0; x < 5; x++){
			std::string temp = ""; // holds items from line
			while (line[cur_index] != ':' && cur_index < line.length()){
				temp.push_back(line[cur_index]);
				cur_index++;
			}
			cur_index++;
			switch (x)
			{
			case 0:
				temp_usr.usrname = temp;
				break;
			case 1:
				temp_usr.password = atoi(temp.c_str());
				break;
			case 2:
				temp_usr.user_id = atoi(temp.c_str());
				break;
			case 3:
				temp_usr.name = temp;
				break;
			case 4:
				temp_usr.home_dir = temp;
				break;
			default:
				break;
			}
		}
		return temp_usr;
	}

	bool operator== (const sethnix_user&) const;
	friend std::ostream& operator<< (std::ostream& os, const sethnix_user& item);
};
bool sethnix_user::operator == (const sethnix_user& a) const
{
	if (usrname == a.usrname)
		return true;
	else
		return false;
}
std::ostream& operator<<(std::ostream& os, const sethnix_user& item){
	os << item.usrname << ":" << item.password << ":" << item.user_id << ":" << item.name << ":" << item.home_dir;
	return os;
}



template<class ItemType>
class MySystem
{
public:
	// Default constructor
	// Pre: None.
	// Post: tree is empty.
	MySystem();

	bool LoadSystem();

	bool UserLogin(std::string, std::string);

	int Run(std::string);

	bool NewSystem(){ return new_system; }


	unsigned int fnv32(std::string);

	unsigned int djb(std::string);


private:
	HashTable<ItemType> system_users; // The hash table
	bool new_system; // If the system is new, it should not try to read the passwd file

	bool force_unique_names;

};

#include "MySystem.template"

#endif