#include <iostream>
#include <string.h>

#include "functions.h"

using namespace std;

char alfabet_M[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char alfabet_m[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void unknown_chars_message(int unknown_chars_count) {
  cout << "Found " << unknown_chars_count << " unknown characters in message..."
       << endl;
}

void lower_char(char *str) {
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    }

    i++;
  }
}

void reverse_char(char *str) {
  int len;

  len = strlen(str);

  for (int i = 0; i < (len / 2); i++) {
    swap(str[i], str[len - i - 1]);
  }
}

void encrypt_reverse() {

  char msg[1000];
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  reverse_char(msg);

  cout << "\nEncrypted message: " << msg << endl << endl;
}

void decrypt_reverse() {
  char msg[1000];
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  reverse_char(msg);

  cout << "\nDecrypted message: " << msg << endl << endl;
}

void encrypt_caesar() {
  char msg[1000];
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int key = 3, unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      msg[i] = (msg[i] - 65 + key) % 26 + 65;
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      msg[i] = (msg[i] - 97 + key) % 26 + 97;
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nEncrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void decrypt_caesar() {
  char msg[1000];
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int key = 3, unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      msg[i] = (msg[i] - 65 - key) % 26 + 65;
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      msg[i] = (msg[i] - 97 - key) % 26 + 97;
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void encrypt_ROT13() {
  char msg[1000];
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int key = 13, unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      msg[i] = (msg[i] - 65 + key) % 26 + 65;
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      msg[i] = (msg[i] - 97 + key) % 26 + 97;
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nEncrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void decrypt_ROT13() {
  char msg[1000];
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int key = 13, unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      if (msg[i] < 78) {
        msg[i] = (msg[i] - 65 + key) % 26 + 65;
      } else {
        msg[i] = (msg[i] - 65 - key) % 26 + 65;
      }
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      if (msg[i] < 110) {
        msg[i] = (msg[i] - 97 + key) % 26 + 97;
      } else {
        msg[i] = (msg[i] - 97 - key) % 26 + 97;
      }
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void encrypt_ROT_X() {
  char msg[1000];
  int key = 0;
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);
  cout << "\nEnter the numeric key: ";
  cin >> key;

  int unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      msg[i] = ((msg[i] - key) % 26) + 65;
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      msg[i] = ((msg[i] - key) % 26) + 97;
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nEncrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void decrypt_ROT_X() {
  char msg[1000];
  int key = 0;
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);
  cout << "\nEnter the numeric key: ";
  cin >> key;

  int unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      msg[i] = ((msg[i] + key) % 26) + 65;
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      msg[i] = ((msg[i] + key) % 26) + 97;
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void encrypt_vigenere() {

  char msg[1000];
  char key[1000];
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);
  cout << "\nEnter the alfabetic key: ";
  cin.ignore();
  cin.getline(key, 1000);

  lower_char(key);

  int k = 0, aux_1 = 0, aux_2 = 0, aux_3 = 0, unknown_chars_count = 0;
  for (size_t i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90 && msg[i] >= 97 && msg[i] <= 122) {
      for (size_t j = 0; j < strlen(alfabet_m); j++) {
        if (msg[i] == alfabet_m[j]) {
          aux_1 = j;
        }
        if (key[k % strlen(key)] == alfabet_m[j]) {
          aux_2 = j;
        }
      }
      aux_3 = (aux_1 + aux_2) % 26;
      msg[i] = alfabet_m[aux_3];
      k++;
    }
  }

  cout << "\nEncrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void decrypt_vigenere() {
  char msg[1000], key[1000];
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);
  cout << "\nEnter the alfabetic key: ";
  cin.ignore();
  cin.getline(key, 1000);

  lower_char(key);

  int k = 0, aux_1 = 0, aux_2 = 0, aux_3 = 0, unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90 && msg[i] >= 97 && msg[i] <= 122) {
      for (size_t j = 0; j < strlen(alfabet_m); j++) {
        if (msg[i] == alfabet_m[j]) {
          aux_1 = j;
        }
        if (key[k % strlen(key)] == alfabet_m[j]) {
          aux_2 = j;
        }
        if ((aux_1 - aux_2) < 0) {
          aux_3 = (aux_1 - aux_2) + 26;
        } else {
          aux_3 = (aux_1 - aux_2) % 26;
        }
      }
      msg[i] = alfabet_m[aux_3];
      k++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}
