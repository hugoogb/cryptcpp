#include <iostream>

#include "functions.h"

using namespace std;

int main() {
  int option_1, option_2;

  system("clear");
  do {
    cout << "\t--------" << endl;
    cout << "\t| MENU |" << endl;
    cout << "\t--------" << endl;
    cout << "1. Reverse cypher" << endl;
    cout << "2. Caesar cypher" << endl;
    cout << "3. ROT13 cypher" << endl;
    cout << "4. ROT_X cypher" << endl;
    cout << "5. Vigenere cypher" << endl;
    cout << "6. Exit" << endl;
    cout << "\nPick an option: ";
    cin >> option_1;

    switch (option_1) {
    case 1:
      system("clear");
      do {
        cout << "\t------------------" << endl;
        cout << "\t| Reverse cypher |" << endl;
        cout << "\t------------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_reverse();
          break;
        case 2:
          decrypt_reverse();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 2:
      system("clear");
      do {
        cout << "\t-----------------" << endl;
        cout << "\t| Caesar cypher |" << endl;
        cout << "\t-----------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_caesar();
          break;
        case 2:
          decrypt_caesar();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 3:
      system("clear");
      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT13 cypher |" << endl;
        cout << "\t----------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_ROT13();
          break;
        case 2:
          decrypt_ROT13();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 4:
      system("clear");
      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT_X cypher |" << endl;
        cout << "\t----------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_ROT_X();
          break;
        case 2:
          decrypt_ROT_X();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 5:
      system("clear");
      do {
        cout << "\t-------------------" << endl;
        cout << "\t| Vigenere cypher |" << endl;
        cout << "\t-------------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_vigenere();
          break;
        case 2:
          decrypt_vigenere();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;
    }

  } while (option_1 != 6);

  cout << "\n\n";
  // system("pause");
  return 0;
}
