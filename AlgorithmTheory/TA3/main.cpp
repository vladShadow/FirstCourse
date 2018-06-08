#include "DBMS.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    DBMS db("../base.txt", "../index.txt");

    while (true) {
        int variant = db.menuItem();
        string key, value;
        switch (variant) {
            case 1:
                cout << "Input key and value of note" << endl;
                cin >> key;
                cin >> value;
                try {
                    db.add(stoi(key), stoi(value));
                } catch(invalid_argument e) {
                    cout << e.what() << endl << endl;
                    break;
                }
                cout << "Done" << endl << endl;
                break;
            case 2:
                cout << "Input key of note" << endl;
                cin >> key;
                try {
                    db.remove(stoi(key));
                } catch(invalid_argument e) {
                    cout << e.what() << endl << endl;
                    break;
                }
                cout << "Done" << endl << endl;
                break;
            case 3:
                cout << "Input key and new value of note" << endl;
                cin >> key;
                cin >> value;
                try {
                    db.change(stoi(key), stoi(value));
                } catch(invalid_argument e) {
                    cout << e.what() << endl << endl;
                    break;
                }
                cout << "Done" << endl << endl;
                break;
            case 4:
                cout << "Input key of searched note" << endl;
                cin >> key;
                try {
                    db.find(stoi(key));
                } catch(invalid_argument e) {
                    cout << e.what() << endl << endl;
                    break;
                }
                cout << "Value of note: " << db.find(stoi(key)) << endl << endl;
                break;
            case 5:
                cout << "Closing..." << endl;
                return 0;
            default:
                cerr << "Invalid choise. Try again" << endl << endl;
                break;
        }
    }
}