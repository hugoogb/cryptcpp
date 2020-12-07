#include <iostream>
#include <string.h>

using namespace std;

#define CAESAR_KEY 3
#define ROT13_KEY 13

// Function: Caesar cipher encrypt
string caesar_encrypt(string plainText, int key);
// Function: Caesar cipher decrypt
string caesar_decrypt(string cipherText, int key);

// Function: ROT13 cipher encrypt
string ROT13_encrypt(string plainText, int key);
// Function: ROT13 cipher decrypt
string ROT13_decrypt(string cipherText, int key);

// Function: ROT_X (you type the numeric key that you want) cipher encrypt
string ROT_X_encrypt(string plainText, int key);
// Function: ROT_X (you type the numeric key that you want) cipher decrypt
string ROT_X_decrypt(string cipherText, int key);

// Function: Vigenère key generator
string vigenere_key_gen(string str, string key);

// Function: Vigenère cipher encrypt
string vigenere_encrypt(string plainText, string key);
// Function: Vigenère cipher decrypt
string vigenere_decrypt(string cipherText, string key);
