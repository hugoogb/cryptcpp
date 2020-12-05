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

void generate_vigenere_key(char *str, char *key, char *full_key) {
  for (size_t i = 0; i < strlen(str); i++) {

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
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      msg[i] = (msg[i] - 'A' + key) % 26 + 'a';
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      msg[i] = (msg[i] - 'a' + key) % 26 + 'a';
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
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      if (((msg[i] - 'A' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'A' - key) % 26 + 91;
      } else {
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A';
      }
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      if (((msg[i] - 'a' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'a' - key) % 26 + 123;
      } else {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a';
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

void encrypt_ROT13() {
  char msg[1000];
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int key = 13, unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      msg[i] = (msg[i] - 'A' + key) % 26 + 'A';
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      msg[i] = (msg[i] - 'a' + key) % 26 + 'a';
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
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      if (((msg[i] - 'A' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'A' - key) % 26 + 91;
      } else {
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A';
      }
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      if (((msg[i] - 'a' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'a' - key) % 26 + 123;
      } else {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a';
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
  cout << "\nEnter the numeric key: ";
  cin >> key;
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      msg[i] = (msg[i] - 'A' + key) % 26 + 'A';
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      msg[i] = (msg[i] - 'a' + key) % 26 + 'a';
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
  cout << "\nEnter the numeric key: ";
  cin >> key;
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int unknown_chars_count = 0;

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      if (((msg[i] - 'A' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'A' - key) % 26 + 91;
      } else {
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A';
      }
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      if (((msg[i] - 'a' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'a' - key) % 26 + 123;
      } else {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a';
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

void encrypt_vigenere() {
  char msg[1000], key[1000];

  // cout << "\nEnter the alfabetic key: ";
  // cin.ignore();
  // cin.getline(key, 1000);
  // cout << "\nType the message to encrypt: ";
  // cin.ignore();
  // cin.getline(msg, 1000);

  lower_char(key);

  int unknown_chars_count = 0;

  cout << "\n -->> Development in process..." << endl << endl;

  cout << "\nEncrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void decrypt_vigenere() {
  char msg[1000], key[1000];

  // cout << "\nEnter the alfabetic key: ";
  // cin.ignore();
  // cin.getline(key, 1000);
  // cout << "\nType the message to decrypt: ";
  // cin.ignore();
  // cin.getline(msg, 1000);

  lower_char(key);

  int unknown_chars_count = 0;

  cout << "\n -->> Development in process..." << endl << endl;

  cout << "\nDecrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}
