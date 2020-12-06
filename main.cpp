#include "functions.h"

void menu_cipher() {
  cout << "\t--------" << endl;
  cout << "\t| MENU |" << endl;
  cout << "\t--------" << endl;
  cout << "1. Reverse cipher" << endl;
  cout << "2. Caesar cipher" << endl;
  cout << "3. ROT13 cipher" << endl;
  cout << "4. ROT_X cipher" << endl;
  cout << "5. Vigenere cipher" << endl;
  cout << "6. Exit" << endl;
  cout << "\nPick an option: ";
}

void menu_encode_decode() {
  cout << "1. Encode" << endl;
  cout << "2. Decode" << endl;
  cout << "3. Exit" << endl;
  cout << "Pick an option: ";
}

int main() {
  int option_1, option_2;

  system("clear");

  do {
    menu_cipher();
    cin >> option_1;

    switch (option_1) {
    case 1:
      system("clear");

      do {
        cout << "\t------------------" << endl;
        cout << "\t| Reverse cipher |" << endl;
        cout << "\t------------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          reverse_encode(plainText);
          break;
        case 2:
          reverse_decode(cipherText);
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 2:
      system("clear");
      do {
        cout << "\t-----------------" << endl;
        cout << "\t| Caesar cipher |" << endl;
        cout << "\t-----------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          caesar_encode(plainText, CAESAR_KEY);
          break;
        case 2:
          caesar_decode(cipherText, CAESAR_KEY);
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 3:
      system("clear");
      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT13 cipher |" << endl;
        cout << "\t----------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          ROT13_encode(plainText, ROT13_KEY);
          break;
        case 2:
          ROT13_decode(plainText, ROT13_KEY);
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 4:
      system("clear");
      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT_X cipher |" << endl;
        cout << "\t----------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          ROT_X_encode(plainText, key);
          break;
        case 2:
          ROT_X_decode(plainText, key);
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 5:
      system("clear");
      do {
        cout << "\t-------------------" << endl;
        cout << "\t| Vigenere cipher |" << endl;
        cout << "\t-------------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          vigenere_encode(plainText, key);
          break;
        case 2:
          vigenere_decode(plainText, key);
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;
    }

  } while (option_1 != 6);

  cout << "\n\n";
  return 0;
}
