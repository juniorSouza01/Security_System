#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a, i = 0;
    string text, old, password, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "       Security System" << endl;

    cout << " __________________________________" << endl << endl;
    cout << "|         1°  Register             |" << endl;
    cout << "|         2°  Login                |" << endl;
    cout << "|         3°  Change password      |" << endl;
    cout << "|_________4°  End Program__________|" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch (a) {
            case 1: {
                cout << "_________________________________________________" << endl << endl;
                cout << "|--------------------Register--------------------|" << endl;
                cout << "|________________________________________________|" << endl << endl;
                cout << "Please enter username: ";
                cin >> name;
                cout << "Please enter the password: ";
                cin >> password0;
                cout << "Please enter your age: ";
                cin >> age;

                ofstream of1;
                of1.open("file.txt");
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0;
                    cout << "Registration successful" << endl;
                    of1.close();
                } else {
                    cout << "Error opening file.txt for writing" << endl;
                }

                break;
            }

            case 2: {
                i = 0;

                cout << "________________________________________________" << endl << endl;
                cout << "|-------------------Login-----------------------|" << endl;
                cout << "|_______________________________________________|" << endl << endl;

                ifstream of2;

                of2.open("file.txt");
                if (!of2) {
                    cout << "Error opening file.txt for reading" << endl;
                    break;
                }

                cout << "Please enter the username: ";
                cin >> user;
                cout << "Please enter the password: ";
                cin >> pass;

                bool found = false;
                while (getline(of2, text)) {
                    if (text == user) {
                        getline(of2, text);
                        if (text == pass) {
                            cout << "Login successful" << endl;
                            found = true;
                        } else {
                            cout << "Incorrect password" << endl;
                        }
                        break;
                    }
                }

                if (!found) {
                    cout << "Username not found" << endl;
                }

                of2.close();
                break;
            }
        }
    } while (a != 4);

    return 0;
}
