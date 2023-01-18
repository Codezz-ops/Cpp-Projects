/**
 * @file Login.cpp
 * @author Codex-ops (Aiden@cyberfear.com)
 * @brief Simple Login system for Unix systems
 * @version 0.1
 * @date 2023-01-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <cctype>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
//#include "Menu.hpp"
//#include "json.hpp"

#define ADMIN_ID 0
#define USER_ID 1

const int MIN_USERNAME_LENGTH = 4;
const int MAX_USERNAME_LENGTH = 20;
const int MIN_PASSWORD_LENGTH = 8;
const int MAX_PASSWORD_LENGTH = 256;
 
class LoginSystem { 
	public:
	void AddUser(const std::string& username, const std::string& password) {
		users_[username] = password;
		}
		
		bool Login(const std::string& username, const std::string& password) {
			auto itter = users_.find(username);
			if (itter == users_.end()) {
				return false;
			}
				return itter->second == password;
		}
		private:
			std::unordered_map <std::string, std::string> users_;
};

void CreateUsers() {
	std::string CreateUsername, CreatePassword, Username, Password, CorrectPassword, CorrectUsername;
	while (true)
	{
		std::cout << "Create username (" << MIN_USERNAME_LENGTH << "-" << MAX_USERNAME_LENGTH << "characters): ";
		std::cin >> CreateUsername;

		std::ofstream Sfile("users.txt", std::ios::binary);
		Sfile << CreateUsername;
		Sfile.close();

		if (CreateUsername.length() >= MIN_USERNAME_LENGTH && CreateUsername.length() <= MAX_USERNAME_LENGTH) {
			break;
		} 
		std::cout << "\nInvaild username length. Please try again" << std::endl;
	}

	while (true)
	{
		std::cout << "Create password (" << MIN_PASSWORD_LENGTH << "-" << MAX_PASSWORD_LENGTH << "characters): ";
		std::system("stty -echo");
		std::cin >> CreatePassword;
		std::system("stty echo");

		std::ofstream file("passwords.txt", std::ios::binary);
		file << CreatePassword;
		file.close();

		if (CreatePassword.length() >= MIN_PASSWORD_LENGTH && CreatePassword.length() <= MAX_PASSWORD_LENGTH) {
			break;
		}
		std::cout << "\nInvaild password length. Please try again" << std::endl;
	}

	LoginSystem login_system;
	login_system.AddUser(CreateUsername, CreatePassword);
	std::system("clear");
	std::cout << "Enter Username: ";
	std::cin >> Username;
	std::cout << "Enter Password: ";
	std::system("stty -echo");
	std::cin >> Password;
	std::system("stty echo");

	std::ifstream file("password.txt", std::ios::binary);
	file >> CorrectPassword;
	file.close();

	std::ifstream Sfile("users.txt", std::ios::binary);
	Sfile >> CorrectUsername;
	Sfile.close();

	CorrectUsername = CreateUsername;
	CorrectPassword = CreatePassword;

	if (CorrectPassword == Password && CorrectUsername == Username && USER_ID == 1) {
		login_system.Login(Username, Password);
		std::cout << "\nLogin successful" << std::endl;
		//Menu();
	} else {
		std::cout << "\nInvaild username or password or USER_ID<EOF>." << std::endl;
	}
}

void ReturningUser()
{
	std::string Username, Password, CorrectPassword, CorrectUsername, FilePassword, FileuWord;
	LoginSystem login_system;
	std::cout << "Enter Username: ";
	std::cin >> Username;
	std::cout << "Enter Password: ";
	std::system("stty -echo");
	std::cin >> Password;
	std::system("stty echo");

	std::ifstream Ffile("passwords.txt", std::ios::binary);
	Ffile >> CorrectPassword;
	Ffile.close();

	std::ifstream Dfile("users.txt", std::ios::binary);
	Dfile >> CorrectUsername;
	Dfile.close();

	FilePassword = CorrectPassword;
	FileuWord = CorrectUsername;

	if (FilePassword == Password && FileuWord == Username) {
		login_system.Login(Username, Password);
		std::cout << "\nLogin successful" << std::endl;
		//Menu();
	} else {
		std::cout << "\nInvaild username or password." << std::endl;
	}
}

void Admin()
{
	int uefid;
	std::string username, password;
	std::cout << "Enter username: ";
	std::cin >> username;
	std::transform(username.begin(), username.end(), username.begin(), std::ptr_fun<int, int>(std::toupper));
	std::cout << "Enter password: ";
	std::cin >> password;
	std::transform(password.begin(), password.end(), password.begin(), std::ptr_fun<int, int>(std::toupper));
	if (password == "PASSWORD" && username == "ADMIN") {
		std::cout << "\nLogin successful" << std::endl;
		std::cout << "Enter UEFID: ";
		std::cin >> uefid;
		if (uefid == ADMIN_ID) {
			//Menu();
		} else {
			std::cout << "Invaild EFUID. Exiting..." << std::endl;
			std::cout << "-" << std::flush;
			for (int Timer = 2; Timer <= 6; Timer++) {
				sleep(1);
				std::cout << "\b\\" << std::flush;
				sleep(1);
				std::cout << "\b|" << std::flush;
				sleep(1);
				std::cout << "\b/" << std::flush;
				sleep(1);
				std::cout << "\b-" << std::flush;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	} else {
		std::cout << "Invaild Credentials. Exiting..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	}
}

/**
 * @brief Guest users only have limited access to the Menu
 * 
 */
void GuestUser()
{
	#undef USER_ID 
	#define USER_ID 2
	std::string username, password;
	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::system("stty -echo");
	std::cin >> password;
	std::system("stty echo");
	std::cout << "\nLogin successful" << std::endl; 
	//GuestMenu();
}

int main() {
	std::ifstream Gfile("passwords.txt");
	std::ifstream Kfile("users.txt");

	if (!Gfile && !Kfile) { 
		CreateUsers();
	} else {
		ReturningUser();
	}
	return 0;
}
