#include "functions.h"

// Show cipher menu: pick cipher method
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

// Show inside menu: pick encode or decode
void menu_encode_decode() {
  cout << "1. Encode" << endl;
  cout << "2. Decode" << endl;
  cout << "3. Exit" << endl;
  cout << "Pick an option: ";
}

int main() {
  int num_messages = 1, index = 0;
  TMessage message[num_messages];

  int option_1, option_2;
  string method;

  string vigenere_fullKey;

  system("clear");

  do {
    menu_cipher();
    cin >> option_1;

    switch (option_1) {
    case 1:
      system("clear");

      method = "Transform --> Reverse";

      do {
        cout << "\t-------------------------" << endl;
        cout << "\t| Reverse transformation|" << endl;
        cout << "\t-------------------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          initialize_messages(message, num_messages, index);

          message[index].method = method;

          plainText_get(message, index);
          message[index].cipherText = reverse_encode(message[index].plainText);

          num_messages++;
          index++;

          break;
        case 2:
          initialize_messages(message, num_messages, index);

          message[index].method = method;

          cipherText_get(message, index);
          message[index].plainText = reverse_decode(message[index].cipherText);

          num_messages++;
          index++;

          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 2:
      system("clear");

      method = "Cipher --> Caesar";

      do {
        cout << "\t-----------------" << endl;
        cout << "\t| Caesar cipher |" << endl;
        cout << "\t-----------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          initialize_messages(message, num_messages, index);

          message[index].method = method;
          message[index].keyNumber = 3;

          plainText_get(message, index);
          message[index].cipherText =
              caesar_encode(message[index].plainText, CAESAR_KEY);

          num_messages++;
          index++;

          break;
        case 2:
          initialize_messages(message, num_messages, index);

          message[index].method = method;
          message[index].keyNumber = 3;

          cipherText_get(message, index);
          message[index].plainText =
              caesar_decode(message[index].cipherText, CAESAR_KEY);

          num_messages++;
          index++;

          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 3:
      system("clear");

      method = "Cipher --> ROT13";

      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT13 cipher |" << endl;
        cout << "\t----------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          initialize_messages(message, num_messages, index);

          message[index].method = method;
          message[index].keyNumber = 13;

          plainText_get(message, index);
          message[index].cipherText =
              ROT13_encode(message[index].plainText, ROT13_KEY);

          num_messages++;
          index++;

          break;
        case 2:
          initialize_messages(message, num_messages, index);

          message[index].method = method;
          message[index].keyNumber = 13;

          cipherText_get(message, index);
          message[index].plainText =
              ROT13_decode(message[index].cipherText, ROT13_KEY);

          num_messages++;
          index++;

          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 4:
      system("clear");

      method = "Cipher --> ROT_X";

      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT_X cipher |" << endl;
        cout << "\t----------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          initialize_messages(message, num_messages, index);

          message[index].method = method;

          numberKey_get(message, index);

          plainText_get(message, index);
          message[index].cipherText =
              ROT_X_encode(message[index].plainText, message[index].keyNumber);

          num_messages++;
          index++;

          break;
        case 2:
          initialize_messages(message, num_messages, index);

          message[index].method = method;

          numberKey_get(message, index);

          cipherText_get(message, index);
          message[index].plainText =
              ROT_X_decode(message[index].cipherText, message[index].keyNumber);

          num_messages++;
          index++;

          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 5:
      system("clear");

      method = "Cipher --> Vigenère";

      do {
        cout << "\t-------------------" << endl;
        cout << "\t| Vigenère cipher |" << endl;
        cout << "\t-------------------" << endl;
        menu_encode_decode();
        cin >> option_2;

        switch (option_2) {
        case 1:
          initialize_messages(message, num_messages, index);

          message[index].method = method;

          charKey_get(message, index);

          plainText_get(message, index);
          vigenere_fullKey = vigenere_key_gen(message[index].plainText,
                                              message[index].keyChar);

          message[index].cipherText =
              vigenere_encode(message[index].plainText, vigenere_fullKey);

          num_messages++;
          index++;

          break;
        case 2:
          initialize_messages(message, num_messages, index);

          message[index].method = method;

          charKey_get(message, index);

          cipherText_get(message, index);
          vigenere_fullKey = vigenere_key_gen(message[index].cipherText,
                                              message[index].keyChar);

          message[index].plainText =
              vigenere_decode(message[index].cipherText, vigenere_fullKey);

          num_messages++;
          index++;

          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;
    }

  } while (option_1 != 6);

  return 0;
}
