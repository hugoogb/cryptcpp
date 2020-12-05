#include <iostream>
#include <string.h>

#include "functions.h"

using namespace std;

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
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      msg[i] = (msg[i] - 'A' + key) % 26 + 'A';
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      msg[i] = (msg[i] - 'a' + key) % 26 + 'a';
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nEncrypted message: " << msg << endl << endl;
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
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A' + 26;
      } else {
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A';
      }
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      if (((msg[i] - 'a' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a' + 26;
      } else {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a';
      }
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;
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
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A' + 26;
      } else {
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A';
      }
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      if (((msg[i] - 'a' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a' + 26;
      } else {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a';
      }
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;
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
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A' + 26;
      } else {
        msg[i] = (msg[i] - 'A' - key) % 26 + 'A';
      }
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      if (((msg[i] - 'a' - key) % 26) < 0) {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a' + 26;
      } else {
        msg[i] = (msg[i] - 'a' - key) % 26 + 'a';
      }
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;
}

// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text
string generateKey(string str, string key) {
  int len = str.size();

  for (int i = 0;; i++) {
    if (len == i)
      i = 0;
    if (key.size() == str.size())
      break;
    key.push_back(key[i]);
  }

  return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key) {
  string cipher_text;

  for (int i = 0; i < str.size(); i++) {
    // converting in range 0-25
    char ch = (str[i] + key[i]) % 26;

    // convert into alphabets(ASCII)
    ch += 'A';

    cipher_text.push_back(ch);
  }

  return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key) {
  string orig_text;

  for (int i = 0; i < cipher_text.size(); i++) {
    // converting in range 0-25
    char x = (cipher_text[i] - key[i] + 26) % 26;

    // convert into alphabets(ASCII)
    x += 'A';
    orig_text.push_back(x);
  }
  return orig_text;
}

void encrypt_vigenere() {
  char msg[1000], key[1000], full_key[1000];

  cout << "\nEnter the alfabetic key: ";
  cin.ignore();
  cin.getline(key, 1000);
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  lower_char(key);

  int unknown_chars_count = 0;

  generate_vigenere_key(msg, key, full_key);

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      msg[i] = ((msg[i] - 'A') + (full_key[i] - 'a')) % 26 + 'A' + 1;
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      msg[i] = ((msg[i] - 'a') + (full_key[i] - 'a')) % 26 + 'a' - 1;
    } else {
      unknown_chars_count++;
    }
  }

  cout << full_key << endl;

  cout << "\nEncrypted message: " << msg << endl << endl;
}

void decrypt_vigenere() {
  char msg[1000], key[1000], full_key[1000];

  cout << "\nEnter the alfabetic key: ";
  cin.ignore();
  cin.getline(key, 1000);
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  lower_char(key);

  int unknown_chars_count = 0;

  generate_vigenere_key(msg, key, full_key);

  for (size_t i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 'A' && msg[i] <= 'Z') {
      if (((msg[i] - 'A') - (full_key[i] - 'a')) < 0) {
        msg[i] = ((msg[i] - 'A') - (full_key[i] - 'a')) % 26 + 'A' + 26;
      } else {
        msg[i] = ((msg[i] - 'A') - (full_key[i] - 'a')) % 26 + 'A';
      }
    } else if (msg[i] >= 'a' && msg[i] <= 'z') {
      if (((msg[i] - 'a') - (full_key[i] - 'a')) < 0) {
        msg[i] = ((msg[i] - 'a') - (full_key[i] - 'a')) % 26 + 'a' + 26;
      } else {
        msg[i] = ((msg[i] - 'a') - (full_key[i] - 'a')) % 26 + 'a';
      }
    } else {
      unknown_chars_count++;
    }
  }

  cout << "\nDecrypted message: " << msg << endl << endl;
}
