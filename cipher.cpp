#include "cipher.h"

// Function: Caesar cipher encrypt
string caesar_encrypt(string plainText, int key) {
  string cipherText;
  char ch;

  for (size_t i = 0; i < plainText.length(); i++) {

    // Encrypt Uppercase chars
    if ((plainText[i] >= 'A') && (plainText[i] <= 'Z')) {
      ch = (plainText[i] + key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if ((plainText[i] >= 'a') && (plainText[i] <= 'z')) {
      ch = (plainText[i] + key - 'a') % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    cipherText.push_back(ch);
  }

  return cipherText;
}

// Function: Caesar cipher decrypt
string caesar_decrypt(string cipherText, int key) {
  string plainText;
  char ch;

  for (size_t i = 0; i < cipherText.length(); i++) {

    // Decrypt Uppercase chars
    if ((cipherText[i] >= 'A') && (cipherText[i] <= 'Z')) {
      ch = (cipherText[i] - key - 'A') % 26 + 'A';
    }

    // Decrypt Lowercase chars
    else if ((cipherText[i] >= 'a') && (cipherText[i] <= 'z')) {
      ch = (cipherText[i] - key - 'a') % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    plainText.push_back(ch);
  }

  return plainText;
}

// Function: ROT13 cipher encrypt
string ROT13_encrypt(string plainText, int key) {
  string cipherText;
  char ch;

  for (size_t i = 0; i < plainText.length(); i++) {

    // Encrypt Uppercase chars
    if ((plainText[i] >= 'A') && (plainText[i] <= 'Z')) {
      ch = (plainText[i] + key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if ((plainText[i] >= 'a') && (plainText[i] <= 'z')) {
      ch = (plainText[i] + key - 'a') % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    cipherText.push_back(ch);
  }

  return cipherText;
}

// Function: ROT13 cipher decrypt
string ROT13_decrypt(string cipherText, int key) {
  string plainText;
  char ch;

  for (size_t i = 0; i < cipherText.length(); i++) {

    // Encrypt Uppercase chars
    if ((cipherText[i] >= 'A') && (cipherText[i] <= 'Z')) {
      ch = (cipherText[i] - key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if ((cipherText[i] >= 'a') && (cipherText[i] <= 'z')) {
      ch = (cipherText[i] - key - 'a') % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    plainText.push_back(ch);
  }

  return plainText;
}

// Function: ROT_X (you type the numeric key that you want) cipher encrypt
string ROT_X_encrypt(string plainText, int key) {
  string cipherText;
  char ch;

  for (size_t i = 0; i < plainText.length(); i++) {

    // Encrypt Uppercase chars
    if ((plainText[i] >= 'A') && (plainText[i] <= 'Z')) {
      ch = (plainText[i] + key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if ((plainText[i] >= 'a') && (plainText[i] <= 'z')) {
      ch = (plainText[i] + key - 'a') % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    cipherText.push_back(ch);
  }

  return cipherText;
}

// Function: ROT_X (you type the numeric key that you want) cipher decrypt
string ROT_X_decrypt(string cipherText, int key) {
  string plainText;
  char ch;

  for (size_t i = 0; i < cipherText.length(); i++) {

    // Decrypt Uppercase chars
    if ((cipherText[i] >= 'A') && (cipherText[i] <= 'Z')) {
      ch = (cipherText[i] - key - 'A') % 26 + 'A';
    }

    // Decrypt Lowercase chars
    else if ((cipherText[i] >= 'a') && (cipherText[i] <= 'z')) {
      ch = (cipherText[i] - key - 'a') % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    plainText.push_back(ch);
  }

  return plainText;
}

// Function: Vigenère key generator
string vigenere_key_gen(string str, string key) {
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

// Function: Vigenère cipher encrypt
string vigenere_encrypt(string plainText, string key) {
  string cipher_text, fullKey;
  char ch;

  fullKey = vigenere_key_gen(plainText, key);

  for (size_t i = 0; i < plainText.length(); i++) {
    // Encrypt Uppercase chars
    if ((plainText[i] >= 'A') && (plainText[i] <= 'Z')) {
      ch = (plainText[i] + fullKey[i]) % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if ((plainText[i] >= 'a') && (plainText[i] <= 'z')) {
      ch = (plainText[i] + fullKey[i]) % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    cipher_text.push_back(ch);
  }

  return cipher_text;
}

// Function: Vigenère cipher decrypt
string vigenere_decrypt(string cipherText, string key) {
  string plainText, fullKey;
  char ch;

  fullKey = vigenere_key_gen(plainText, key);

  for (size_t i = 0; i < cipherText.length(); i++) {
    // Decrypt Uppercase chars
    if ((cipherText[i] >= 'A') && (cipherText[i] <= 'Z')) {
      ch = (cipherText[i] - fullKey[i] + 26) % 26 + 'A';
    }

    // Decrypt Lowercase chars
    else if ((cipherText[i] >= 'a') && (cipherText[i] <= 'z')) {
      ch = (cipherText[i] - fullKey[i] + 26) % 26 + 'a';
    }

    // No change if not either Uppercase or Lowercase
    else {
      ch = plainText[i];
    }

    plainText.push_back(ch);
  }

  return plainText;
}
