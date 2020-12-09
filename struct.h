#include <iostream>
#include <string.h>

using namespace std;

typedef struct {
  string method;
  string plainText;
  string cipherText;
  int keyNumber;
  string keyChar;
} TMessage;

// Initialize the messages
void initialize_messages(TMessage message[], int num_messages, int actual_index);

// Void function: Asks for the plain text to encode
void plainText_get(TMessage message[], int actual_index);
// Void function: Asks for the cipher text to decode
void cipherText_get(TMessage message[], int actual_index);
// Void function: Asks for the numeric key
void numberKey_get(TMessage message[], int actual_index);
// Void function: Asks for the alfabetic key
void charKey_get(TMessage message[], int actual_index);

// Void function: Show encrypted text
void show_encrypted(TMessage message[], int actual_index);
// Void function: Show decrypted text
void show_decrypted(TMessage message[], int actual_index);
