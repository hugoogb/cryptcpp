#include "transform.h"

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
