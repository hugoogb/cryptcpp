#include "alphabet.h"
#include "cipher.h"
#include "encoding.h"
#include "menu.h"
#include "struct.h"
#include "transform.h"

int main() {
  int num_messages = 1, index = 0;
  TMessage message[num_messages];

  int option_1, option_2, option_3;
  string method;

  string vigenere_fullKey;

  do {
    system("clear");

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
            cout << "\t-----------------------" << endl;
            cout << "\t| Transform - Reverse |" << endl;
            cout << "\t-----------------------" << endl;
            menu_encrypt_decrypt();
            cin >> option_3;

            switch (option_3) {
            case 1:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              plainText_get(message, index);
              message[index].cipherText =
                  reverse_encrypt(message[index].plainText);

              cout << "\n--> Encrypted text: " << message[index].cipherText
                   << endl;

              num_messages++;
              index++;

              break;
            case 2:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              cipherText_get(message, index);
              message[index].plainText =
                  reverse_decrypt(message[index].cipherText);

              cout << "\n--> Decrypted text: " << message[index].cipherText
                   << endl;

              num_messages++;
              index++;

              break;
            }
          } while (option_3 != 3);
          system("clear");
          break;
        case 2:
          // Lower case transform goes here
          break;
        case 3:
          // Upper case transform goes here
          break;
        case 4:
          // Capitalize transform goes here
          break;
        case 5:
          // Invers case transform goes here
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
            cout << "\t-------------------" << endl;
            cout << "\t| Cipher - Caesar |" << endl;
            cout << "\t-------------------" << endl;
            menu_encrypt_decrypt();
            cin >> option_3;

            switch (option_3) {
            case 1:
              initialize_messages(message, num_messages, index);

              message[index].method = method;
              message[index].keyNumber = 3;

              plainText_get(message, index);
              message[index].cipherText =
                  caesar_encrypt(message[index].plainText, CAESAR_KEY);

              cout << "\n--> Encrypted text: " << message[index].cipherText
                   << endl;

              num_messages++;
              index++;

              break;
            case 2:
              initialize_messages(message, num_messages, index);

              message[index].method = method;
              message[index].keyNumber = 3;

              cipherText_get(message, index);
              message[index].plainText =
                  caesar_decrypt(message[index].cipherText, CAESAR_KEY);

              cout << "\n--> Decrypted text: " << message[index].cipherText
                   << endl;

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
            cout << "\t------------------" << endl;
            cout << "\t| Cipher - ROT13 |" << endl;
            cout << "\t------------------" << endl;
            menu_encrypt_decrypt();
            cin >> option_3;

            switch (option_3) {
            case 1:
              initialize_messages(message, num_messages, index);

              message[index].method = method;
              message[index].keyNumber = 13;

              plainText_get(message, index);
              message[index].cipherText =
                  ROT13_encrypt(message[index].plainText, ROT13_KEY);

              cout << "\n--> Encrypted text: " << message[index].cipherText
                   << endl;

              num_messages++;
              index++;

              break;
            case 2:
              initialize_messages(message, num_messages, index);

              message[index].method = method;
              message[index].keyNumber = 13;

              cipherText_get(message, index);
              message[index].plainText =
                  ROT13_decrypt(message[index].cipherText, ROT13_KEY);

              cout << "\n--> Decrypted text: " << message[index].cipherText
                   << endl;

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
            cout << "\t------------------" << endl;
            cout << "\t| Cipher - ROT_X |" << endl;
            cout << "\t------------------" << endl;
            menu_encrypt_decrypt();
            cin >> option_3;

            switch (option_3) {
            case 1:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              numberKey_get(message, index);

              plainText_get(message, index);
              message[index].cipherText = ROT_X_encrypt(
                  message[index].plainText, message[index].keyNumber);

              cout << "\n--> Encrypted text: " << message[index].cipherText
                   << endl;

              num_messages++;
              index++;

              break;
            case 2:
              initialize_messages(message, num_messages, index);

              message[index].method = method;

              numberKey_get(message, index);

              cipherText_get(message, index);
              message[index].plainText = ROT_X_decrypt(
                  message[index].cipherText, message[index].keyNumber);

              cout << "\n--> Decrypted text: " << message[index].cipherText
                   << endl;

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
            cout << "\t---------------------" << endl;
            cout << "\t| Cipher - Vigenère |" << endl;
            cout << "\t---------------------" << endl;
            menu_encrypt_decrypt();
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
                  vigenere_encrypt(message[index].plainText, vigenere_fullKey);

              cout << "\n--> Encrypted text: " << message[index].cipherText
                   << endl;

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
                  vigenere_decrypt(message[index].cipherText, vigenere_fullKey);

              cout << "\n--> Decrypted text: " << message[index].cipherText
                   << endl;

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
