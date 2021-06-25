#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Header.h"
using namespace std;

int main() {
    time_t result = time(nullptr);
    list *database = new list;
    char pass1[50] = "PASSWORD";
    char pass2[50] = "DROWSSAP";
    string tmp1 = pass1;
    string tmp2 = pass2;
    string input;
    passInfo password;
    cout << "Choose file: " << endl;
    cout << "File1\t" << "File2" << endl;
    cin >> input;

    while(input!="File1" && input!="File2"){
        cout << "Invalid file. Choose correct file." << endl;
        cin >> input;
    }

    if(input == "File1") {
        encrypt(2, pass1);
        cout << "File encrypted with Caesar cipher, key is 2, decrypt password: " << pass1 << endl;
        cin >> input;
        while (input!=tmp1){
            cout << "Invalid password. Try again." << endl;
            cin >> input;
        }
        if (input == tmp1) {
            ifstream timestamp("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/Timestamp1.txt");
            cout << "Password correct, last login: " << timestamp.rdbuf() << endl;
            timestamp.close();
            ofstream timeFile("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/Timestamp1.txt", ios::trunc);
            timeFile << asctime(localtime(&result));
            timeFile.close();

            ifstream file1("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File1.txt");
            if (file1.is_open()) {
                while (getline(file1, password.name, ',')) {
                    getline(file1, password.password, ',');
                    getline(file1, password.category);
                    database->addPassword(password.name, password.password, password.category);
                }
                file1.close();
            }
            while (input != "6") {
                cout << "Choose a number: " << endl;
                cout << "1. Show only given category\t" << "2. Sort by given parameter\t"
                     << "3. Add or delete password\n" << "4. Add or delete the whole category with passwords\t" <<
                     "5. Show passwords\t" << "6. Quit" << endl;
                cin >> input;

                while (input != "1" && input != "2" && input != "3"
                && input != "4" && input != "5" && input != "6") {
                    cout << "Wrong number. Choose correct number." << endl;
                    cin >> input;
                }

                if (input == "1") {
                    cout << "Choose category: system\tsocialmedia\tmail" << endl;
                    cin >> input;
                    while (input != "system" && input != "socialmedia" && input != "mail") {
                        cout << "Wrong category. Choose correct category" << endl;
                        cin >> input;
                    }
                    database->filter(input);
                } else if (input == "2") {
                    cout << "Sort by: 1. name length\t2. password length" << endl;
                    cin >> input;
                    while (input != "1" && input != "2") {
                        cout << "Wrong parameter. Choose correct parameter" << endl;
                        cin >> input;
                    }
                    if (input == "1"){
                        database->nameLengthSort();
                    }
                    else if (input == "2"){
                        database->passLengthSort();
                    }
                } else if (input == "3") {
                    cout << "Add or delete password?\t add\tdelete" << endl;
                    cin >> input;
                    while (input != "add" && input != "delete") {
                        cout << "Wrong option. Choose correct option" << endl;
                        cin >> input;
                    }
                    if (input == "add") {
                        string input2;
                        string input3;
                        cout << "Write name, password and category separated by line change" << endl;
                        cin >> input;
                        cin >> input2;
                        cin >> input3;
                        database->addPassword(input, input2, input3);
                        ofstream output("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File1.txt",
                                        ios::trunc);
                        database->writeToFile(output);
                    } else if (input == "delete") {
                        database->showList();
                        cout << "Choose index of a password to delete" << endl;
                        cin >> input;
                        database->deletePassword(std::stoi(input));
                        ofstream output("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File1.txt",
                                        ios::trunc);
                        database->writeToFile(output);
                    }
                } else if (input == "4") {
                    cout << "Add or delete category?\t add\tdelete" << endl;
                    cin >> input;
                    while (input != "add" && input != "delete") {
                        cout << "Wrong option. Choose correct option" << endl;
                        cin >> input;
                    }
                    if (input == "add") {
                        cout << "Type category to add" << endl;
                        cin >> input;
                        database->addCategory(input);
                    } else if (input == "delete") {
                        cout << "Type category to delete" << endl;
                        cin >> input;
                        database->deleteCategory(input);
                        ofstream output("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File1.txt",
                                        ios::trunc);
                        database->writeToFile(output);
                    }
                }
                else if (input == "5"){
                    database->showList();
                }
            }
        }
    }
    else if (input == "File2"){
        encrypt(2, pass2);
        cout << "File encrypted with Caesar cipher, key is 2, decrypt password: " << pass2 << endl;
        cin >> input;
        while (input!=tmp2){
            cout << "Invalid password. Try again." << endl;
            cin >> input;
        }
        if (input == tmp2) {
            ifstream timestamp("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/Timestamp2.txt");
            cout << "Password correct, last login: " << timestamp.rdbuf() << endl;
            timestamp.close();
            ofstream timeFile("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/Timestamp2.txt", ios::trunc);
            timeFile << asctime(localtime(&result));
            timeFile.close();

            ifstream file2("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File2.txt");
            if (file2.is_open()) {
                while (getline(file2, password.name, ',')) {
                    getline(file2, password.password, ',');
                    getline(file2, password.category);
                    database->addPassword(password.name, password.password, password.category);
                }
                file2.close();
            }
            while (input != "6") {
                cout << "Choose a number: " << endl;
                cout << "1. Show only given category\t" << "2. Sort by given parameter\t"
                     << "3. Add or delete password\n" << "4. Add or delete the whole category with passwords\t" <<
                     "5. Show passwords\t" << "6. Quit" << endl;
                cin >> input;

                while (input != "1" && input != "2" && input != "3" &&
                input != "4" && input != "5" && input != "6") {
                    cout << "Wrong number. Choose correct number." << endl;
                    cin >> input;
                }
                if (input == "1") {
                    cout << "Choose category: other\tgames\tundercover" << endl;
                    cin >> input;
                    while (input != "other" && input != "games" && input != "undercover") {
                        cout << "Wrong category. Choose correct category" << endl;
                        cin >> input;
                    }
                    database->filter(input);
                } else if (input == "2") {
                    cout << "Sort by: 1. name length\t2. password length" << endl;
                    cin >> input;
                    while (input != "1" && input != "2") {
                        cout << "Wrong parameter. Choose correct parameter" << endl;
                        cin >> input;
                    }
                    if (input=="1"){
                        database->nameLengthSort();
                    }
                    else if (input=="2"){
                        database->passLengthSort();
                    }
                } else if (input == "3") {
                    cout << "Add or delete password?\t add\tdelete" << endl;
                    cin >> input;
                    while (input != "add" && input != "delete") {
                        cout << "Wrong option. Choose correct option" << endl;
                        cin >> input;
                    }
                    if (input == "add") {
                        string input2;
                        string input3;
                        cout << "Write name, password and category separated by line change" << endl;
                        cin >> input;
                        cin >> input2;
                        cin >> input3;
                        database->addPassword(input, input2, input3);
                        ofstream output("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File2.txt",
                                        ios::trunc);
                        database->writeToFile(output);
                    } else if (input == "delete") {
                        database->showList();
                        cout << "Choose index of a password to delete" << endl;
                        cin >> input;
                        database->deletePassword(std::stoi(input));
                        ofstream output("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File2.txt",
                                        ios::trunc);
                        database->writeToFile(output);
                    }
                } else if (input == "4") {
                    cout << "Add or delete category?\t add\tdelete" << endl;
                    cin >> input;
                    while (input != "add" && input != "delete") {
                        cout << "Wrong option. Choose correct option" << endl;
                        cin >> input;
                    }
                    if (input == "add") {
                        cout << "Type category to add" << endl;
                        cin >> input;
                        database->addCategory(input);
                    } else if (input == "delete") {
                        cout << "Type category to delete" << endl;
                        cin >> input;
                        database->deleteCategory(input);
                        ofstream output("/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/File2.txt",
                                        ios::trunc);
                        database->writeToFile(output);
                    }
                }
                else if (input == "5"){
                    database->showList();
                }
            }
        }
    }
    return 0;
}