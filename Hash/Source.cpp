#include "MySystem.h"

using namespace std;


int main()
{
	MySystem<sethnix_user> sethnix;

	// Will run while = 1
	int program_exit = 1;
	string command = "";

	int temp_login = 0;
	int login_fails = 0;
	int login_fail_limit = 5;

	// Loging in
	while (temp_login != 1 && !sethnix.NewSystem()) {
		string username;
		string passwd;
		cout << "Username:"; // TODO should check to see if user name is taken
		cin >> username;
		cout << "Password:"; // TODO should not be echo'd but thats hard =[
		cin >> passwd;
		cin.get();
		temp_login = sethnix.UserLogin(username, passwd);

		if (!temp_login){
			system("cls");
			login_fails++;
			cout << "Login failed. Username/Password combination incorrect." << endl;
		}
	}

	// Running command line
	while (program_exit){
		cout << "sethnix>";
		getline(cin, command);
		program_exit = sethnix.Run(command);
	}

	MySystem<sethnix_user> unix(sethnix);

	//system("Pause");

	return 0;
}