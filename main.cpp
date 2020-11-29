#include <cstring>
#include <iostream>
#include <string.h>

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

void encrypt_cesar() {

  char msg[1000], ch;
  cout << "\nType the message to encrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int key = 3, aux = 0, unknown_chars_count = 0;

  for (int i = 0; i < strlen(msg); ++i) {
    ch = msg[i];

    if (ch >= 'a' && ch <= 'z') {
      ch = ch + key;

      if (ch > 'z') {
        ch = ch - 'z' + 'a' - 1;
      }

      msg[i] = ch;
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = ch + key;

      if (ch > 'Z') {
        ch = ch - 'Z' + 'A' - 1;
      }

      msg[i] = ch;
    }
  }

  cout << "\nEncrypted message: " << msg << endl << endl;

  if (unknown_chars_count != 0) {
    unknown_chars_message(unknown_chars_count);
  }
}

void decrypt_cesar() {
  char msg[1000], ch;
  cout << "\nType the message to decrypt: ";
  cin.ignore();
  cin.getline(msg, 1000);

  int key = 3, aux = 0, unknown_chars_count = 0;

  for (int i = 0; i < strlen(msg); ++i) {
    ch = msg[i];

    if (ch >= 'a' && ch <= 'z') {
      ch = ch - key;

      if (ch > 'z') {
        ch = ch - 'z' + 'a' - 1;
      }

      msg[i] = ch;
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = ch - key;

      if (ch > 'Z') {
        ch = ch - 'Z' + 'A' - 1;
      }

      msg[i] = ch;
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

  int aux, unknown_chars_count = 0;

  for (int i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      for (int j = 0; j < strlen(alfabet_m); j++) {
        if (msg[i] == alfabet_m[j]) {
          aux = (j + 13) % 26;
          msg[i] = alfabet_m[aux];
        }
      }
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      for (int j = 0; j < strlen(alfabet_M); j++) {
        if (msg[i] == alfabet_M[j]) {
          aux = (j + 13) % 26;
          msg[i] = alfabet_M[aux];
        }
      }
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

  int aux, unknown_chars_count = 0;

  for (int i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      for (int j = 0; j < strlen(alfabet_m); j++) {
        if (msg[i] == alfabet_m[j]) {
          if ((j - 13) < 0) {
            aux = (j - 13) + 26;
          } else {
            aux = (j - 13) % 26;
          }
          msg[i] = alfabet_m[aux];
        }
      }
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      for (int j = 0; j < strlen(alfabet_M); j++) {
        if (msg[i] == alfabet_M[j]) {
          if ((j - 13) < 0) {
            aux = (j - 13) + 26;
          } else {
            aux = (j - 13) % 26;
          }
          msg[i] = alfabet_M[aux];
        }
      }
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

  int aux, unknown_chars_count = 0;

  for (int i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      for (int j = 0; j < strlen(alfabet_m); j++) {
        if (msg[i] == alfabet_m[j]) {
          aux = (j + key) % 26;
          msg[i] = alfabet_m[aux];
        }
      }
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      for (int j = 0; j < strlen(alfabet_M); j++) {
        if (msg[i] == alfabet_M[j]) {
          aux = (j + key) % 26;
          msg[i] = alfabet_M[aux];
        }
      }
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

  int aux, unknown_chars_count = 0;
  for (int i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90) {
      for (int j = 0; j < strlen(alfabet_m); j++) {
        if (msg[i] == alfabet_m[j]) {
          if ((j - key) < 0) {
            aux = (j - key) + 26;
          } else {
            aux = (j - key) % 26;
          }
          msg[i] = alfabet_m[aux];
        }
      }
    } else if (msg[i] >= 97 && msg[i] <= 122) {
      for (int j = 0; j < strlen(alfabet_M); j++) {
        if (msg[i] == alfabet_M[j]) {
          if ((j - key) < 0) {
            aux = (j - key) + 26;
          } else {
            aux = (j - key) % 26;
          }
          msg[i] = alfabet_M[aux];
        }
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
  for (int i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90 && msg[i] >= 97 && msg[i] <= 122) {
      for (int j = 0; j < strlen(alfabet_m); j++) {
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

  for (int i = 0; i < strlen(msg); i++) {
    if (msg[i] >= 65 && msg[i] <= 90 && msg[i] >= 97 && msg[i] <= 122) {
      for (int j = 0; j < strlen(alfabet_m); j++) {
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

int main() {
  int option_1, option_2;

  system("clear");
  do {
    cout << "\t--------" << endl;
    cout << "\t| MENU |" << endl;
    cout << "\t--------" << endl;
    cout << "1. Reverse cypher" << endl;
    cout << "2. Caesar cypher" << endl;
    cout << "3. ROT13 cypher" << endl;
    cout << "4. ROT_X cypher" << endl;
    cout << "5. Vigenere cypher" << endl;
    cout << "6. Exit" << endl;
    cout << "\nPick an option: ";
    cin >> option_1;

    switch (option_1) {
    case 1:
      system("clear");
      do {
        cout << "\t------------------" << endl;
        cout << "\t| Reverse cypher |" << endl;
        cout << "\t------------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_reverse();
          break;
        case 2:
          decrypt_reverse();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 2:
      system("clear");
      do {
        cout << "\t-----------------" << endl;
        cout << "\t| Caesar cypher |" << endl;
        cout << "\t-----------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_cesar();
          break;
        case 2:
          decrypt_cesar();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 3:
      system("clear");
      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT13 cypher |" << endl;
        cout << "\t----------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_ROT13();
          break;
        case 2:
          decrypt_ROT13();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 4:
      system("clear");
      do {
        cout << "\t----------------" << endl;
        cout << "\t| ROT_X cypher |" << endl;
        cout << "\t----------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_ROT_X();
          break;
        case 2:
          decrypt_ROT_X();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;

    case 5:
      system("clear");
      do {
        cout << "\t-------------------" << endl;
        cout << "\t| Vigenere cypher |" << endl;
        cout << "\t-------------------" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option_2;

        switch (option_2) {
        case 1:
          encrypt_vigenere();
          break;
        case 2:
          decrypt_vigenere();
          break;
        }
      } while (option_2 != 3);
      system("clear");
      break;
    }

  } while (option_1 != 6);

  cout << "\n\n";
  // system("pause");
  return 0;
}
