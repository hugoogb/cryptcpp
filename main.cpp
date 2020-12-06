#include "functions.h"
#include "menu.h"
#include "struct.h"

int main() {
  int num_messages = 1, index = 0;
  TMessage message[num_messages];

  int option_1, option_2, option_3;
  string method;

  string vigenere_fullKey;

  system("clear");

  do {
    menu_methods();
    cin >> option_1;

    switch (option_1) {
    case 1:
      system("clear");

      method = "Transform --> ";

      do {
        menu_transform();
        cin >> option_2;

        switch (option_2) {
        case 1:
          system("clear");

          method += "Reverse";

          do {
            cout << "\t-------------------------" << endl;
            cout << "\t| Reverse transformation|" << endl;
            cout << "\t-------------------------" << endl;
            menu_encode_decode();
            cin >> option_3;

            switch (option_3) {
            case 1:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              plainText_get(message, index);
              message[index].cipherText =
                  reverse_encode(message[index].plainText);

              num_messages++;
              index++;

              break;
            case 2:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              cipherText_get(message, index);
              message[index].plainText =
                  reverse_decode(message[index].cipherText);

              num_messages++;
              index++;

              break;
            }
          } while (option_3 != 3);
          system("clear");
          break;
        case 2:

          break;
        case 3:

          break;
        case 4:

          break;
        case 5:

          break;
        }

      } while (option_2 != 6);

      break;
    case 2:
      system("clear");

      method = "Alphabet --> ";

      do {

        menu_alphabets();
        cin >> option_2;

        switch (option_2) {
        case 1:
          // Mourse code goes here
          break;
        }

      } while (option_2 != 2);

      break;
    case 3:
      system("clear");

      method = "Cipher --> ";

      do {

        menu_cipher();
        cin >> option_2;

        switch (option_2) {
        case 1:
          system("clear");

          method += "Caesar";

          do {
            cout << "\t-----------------" << endl;
            cout << "\t| Caesar cipher |" << endl;
            cout << "\t-----------------" << endl;
            menu_encode_decode();
            cin >> option_3;

            switch (option_3) {
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
          } while (option_3 != 3);
          system("clear");
          break;

        case 2:
          system("clear");

          method += "ROT13";

          do {
            cout << "\t----------------" << endl;
            cout << "\t| ROT13 cipher |" << endl;
            cout << "\t----------------" << endl;
            menu_encode_decode();
            cin >> option_3;

            switch (option_3) {
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
          } while (option_3 != 3);
          system("clear");
          break;
        case 3:
          system("clear");

          method += "ROT_X";

          do {
            cout << "\t----------------" << endl;
            cout << "\t| ROT_X cipher |" << endl;
            cout << "\t----------------" << endl;
            menu_encode_decode();
            cin >> option_3;

            switch (option_3) {
            case 1:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              numberKey_get(message, index);

              plainText_get(message, index);
              message[index].cipherText = ROT_X_encode(
                  message[index].plainText, message[index].keyNumber);

              num_messages++;
              index++;

              break;
            case 2:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              numberKey_get(message, index);

              cipherText_get(message, index);
              message[index].plainText = ROT_X_decode(message[index].cipherText,
                                                      message[index].keyNumber);

              num_messages++;
              index++;

              break;
            }
          } while (option_3 != 3);
          system("clear");
          break;
        case 4:
          system("clear");

          method += "Vigenère";

          do {
            cout << "\t-------------------" << endl;
            cout << "\t| Vigenère cipher |" << endl;
            cout << "\t-------------------" << endl;
            menu_encode_decode();
            cin >> option_3;

            switch (option_3) {
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
          } while (option_3 != 3);
          system("clear");
          break;
        }
      } while (option_2 != 5);
    case 4:
      system("clear");

      method = "Encoding --> ";

      do {

        menu_encoding();
        cin >> option_2;

        switch (option_2) {
        case 1:
          // Base32 encoding goes here
          break;
        case 2:
          // Base64 encoding goes here
          break;
        case 3:
          // Ascii85 encoding goes here
          break;
        case 4:
          // Decimal encoding goes here
          break;
        case 5:
          // Hexadecimal encoding goes here
          break;
        case 6:
          // Binary encoding goes here
          break;
        case 7:
          // Octal encoding goes here
          break;
        case 8:
          // URL encoding goes here
          break;
        }

      } while (option_2 != 9);

      break;
    }
  } while (option_1 != 6);

  return 0;
}
