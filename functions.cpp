#include "functions.h"

// Function: reverse transformation encode
string reverse_encode(string plainText) {
  string cipherText;

  reverse(plainText.begin(), plainText.end());
  cipherText = plainText;

  return cipherText;
}

// Function: reverse transformaton decode
string reverse_decode(string cipherText) {
  string plainText;

  reverse(cipherText.begin(), cipherText.end());
  plainText = cipherText;

  return plainText;
}

// Function: Caesar cipher encode
string caesar_encode(string plainText, int key) {
  string cipherText;
  char ch;

  for (size_t i = 0; i < plainText.length(); i++) {

    // Encrypt Uppercase chars
    if (isupper(plainText[i])) {
      ch = (plainText[i] + key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if (islower(plainText[i])) {
      ch = (plainText[i] + key - 'a') % 26 + 'a';
    }

    cipherText.push_back(ch);
  }

  return cipherText;
}

// Function: Caesar cipher decode
string caesar_decode(string cipherText, int key) {
  string plainText;
  char ch;

  for (size_t i = 0; i < cipherText.length(); i++) {

    // Decrypt Uppercase chars
    if (isupper(cipherText[i])) {
      ch = (cipherText[i] - key - 'A') % 26 + 'A';
    }

    // Decrypt Lowercase chars
    else if (islower(cipherText[i])) {
      ch = (cipherText[i] - key - 'a') % 26 + 'a';
    }

    plainText.push_back(ch);
  }

  return plainText;
}

// Function: ROT13 cipher encode
string ROT13_encode(string plainText, int key) {
  string cipherText;
  char ch;

  for (size_t i = 0; i < plainText.length(); i++) {

    // Encrypt Uppercase chars
    if (isupper(plainText[i])) {
      ch = (plainText[i] + key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if (islower(plainText[i])) {
      ch = (plainText[i] + key - 'a') % 26 + 'a';
    }

    cipherText.push_back(ch);
  }

  return cipherText;
}

// Function: ROT13 cipher decode
string ROT13_decode(string cipherText, int key) {
  string plainText;
  char ch;

  for (size_t i = 0; i < cipherText.length(); i++) {

    // Encrypt Uppercase chars
    if (isupper(cipherText[i])) {
      ch = (cipherText[i] - key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if (islower(cipherText[i])) {
      ch = (cipherText[i] - key - 'a') % 26 + 'a';
    }

    plainText.push_back(ch);
  }

  return plainText;
}

// Function: ROT_X (you type the numeric key that you want) cipher encode
string ROT_X_encode(string plainText, int key) {
  string cipherText;
  char ch;

  for (size_t i = 0; i < plainText.length(); i++) {

    // Encrypt Uppercase chars
    if (isupper(plainText[i])) {
      ch = (plainText[i] + key - 'A') % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if (islower(plainText[i])) {
      ch = (plainText[i] + key - 'a') % 26 + 'a';
    }

    cipherText.push_back(ch);
  }

  return cipherText;
}

// Function: ROT_X (you type the numeric key that you want) cipher decode
string ROT_X_decode(string cipherText, int key) {
  string plainText;
  char ch;

  for (size_t i = 0; i < cipherText.length(); i++) {

    // Decrypt Uppercase chars
    if (isupper(cipherText[i])) {
      ch = (cipherText[i] - key - 'A') % 26 + 'A';
    }

    // Decrypt Lowercase chars
    else if (islower(cipherText[i])) {
      ch = (cipherText[i] - key - 'a') % 26 + 'a';
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

// Function: Vigenère cipher encode
string vigenere_encode(string plainText, string key) {
  string cipher_text, fullKey;
  char ch;

  fullKey = vigenere_key_gen(plainText, key);

  for (size_t i = 0; i < plainText.length(); i++) {
    // Encrypt Uppercase chars
    if (isupper(plainText[i])) {
      ch = (plainText[i] + fullKey[i]) % 26 + 'A';
    }

    // Encrypt Lowercase chars
    else if (islower(plainText[i])) {
      ch = (plainText[i] + fullKey[i]) % 26 + 'a';
    }

    cipher_text.push_back(ch);
  }

  return cipher_text;
}

// Function: Vigenère cipher decode
string vigenere_decode(string cipherText, string key) {
  string plainText, fullKey;
  char ch;

  fullKey = vigenere_key_gen(plainText, key);

  for (size_t i = 0; i < cipherText.length(); i++) {
    // Decrypt Uppercase chars
    if (isupper(cipherText[i])) {
      ch = (cipherText[i] - fullKey[i] + 26) % 26 + 'A';
    }

    // Decrypt Lowercase chars
    else if (islower(cipherText[i])) {
      ch = (cipherText[i] - fullKey[i] + 26) % 26 + 'a';
    }

    plainText.push_back(ch);
  }

  return plainText;
}
