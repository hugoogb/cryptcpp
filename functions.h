#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define CAESAR_KEY 3
#define ROT13_KEY 13

// Function: reverse transformation encode
string reverse_encode(string plainText);
// Function: reverse transformaton decode
string reverse_decode(string cipherText);

// Function: Caesar cipher encode
string caesar_encode(string plainText, int key);
// Function: Caesar cipher decode
string caesar_decode(string cipherText, int key);

// Function: ROT13 cipher encode
string ROT13_encode(string plainText, int key);
// Function: ROT13 cipher decode
string ROT13_decode(string cipherText, int key);

// Function: ROT_X (you type the numeric key that you want) cipher encode
string ROT_X_encode(string plainText, int key);
// Function: ROT_X (you type the numeric key that you want) cipher decode
string ROT_X_decode(string cipherText, int key);

// Function: Vigenère key generator
string vigenere_key_gen(string str, string key);

// Function: Vigenère cipher encode
string vigenere_encode(string plainText, string key);
// Function: Vigenère cipher decode
string vigenere_decode(string cipherText, string key);
