#include "../../include/methods/transform.h"
#include <cctype>
#include <string>

// Function: reverse transform encrypt
string reverse_encrypt(string plainText) {
  string cipherText;

  reverse(plainText.begin(), plainText.end());
  cipherText = plainText;

  return cipherText;
}

// Function: reverse transform decrypt
string reverse_decrypt(string cipherText) {
  string plainText;

  reverse(cipherText.begin(), cipherText.end());
  plainText = cipherText;

  return plainText;
}

// Funtion: lower case transform encrypt
string lowerCase_encrypt(string plainText) {
  string cipherText;

  for (size_t i = 0; i < plainText.length(); i++) {
    plainText[i] = tolower(plainText[i]);
  }

  cipherText = plainText;

  return cipherText;
}

// Funtion: lower case transform encrypt
string lowerCase_decrypt(string cipherText) {
  string plainText;

  for (size_t i = 0; i < cipherText.length(); i++) {
    cipherText[i] = toupper(cipherText[i]);
  }

  plainText = cipherText;

  return plainText;
}

// Funtion: upper case transform encrypt
string upperCase_encrypt(string plainText) {
  string cipherText;

  for (size_t i = 0; i < plainText.length(); i++) {
    plainText[i] = toupper(plainText[i]);
  }

  cipherText = plainText;

  return cipherText;
}

// Funtion: upper case transform encrypt
string upperCase_decrypt(string cipherText) {
  string plainText;

  for (size_t i = 0; i < cipherText.length(); i++) {
    cipherText[i] = tolower(cipherText[i]);
  }

  plainText = cipherText;

  return plainText;
}

// Function: capitalize transform encrypt
string capitalize_encrypt(string plainText) {
  string cipherText;

  plainText[0] = toupper(plainText[0]);

  cipherText = plainText;

  return cipherText;
}

// Function: capitalize transform decrypt
string capitalize_decrypt(string cipherText) {
  string plainText;

  cipherText[0] = tolower(cipherText[0]);

  plainText = cipherText;

  return plainText;
}

// Function: inverse case transform encrypt
string inverseCase_encrypt(string plainText) {
  string cipherText;

  for (size_t i = 0; i < plainText.length(); i++) {
    if (isupper(plainText[i])) {
      plainText[i] = tolower(plainText[i]);
    } else if (islower(plainText[i])) {
      plainText[i] = toupper(plainText[i]);
    }
  }

  cipherText = plainText;

  return cipherText;
}

// Function: inverse case transform decrypt
string inverseCase_decrypt(string cipherText) {
  string plainText;

  for (size_t i = 0; i < cipherText.length(); i++) {
    if (islower(cipherText[i])) {
      cipherText[i] = toupper(cipherText[i]);
    } else if (isupper(cipherText[i])) {
      cipherText[i] = tolower(cipherText[i]);
    }
  }

  plainText = cipherText;

  return plainText;
}
