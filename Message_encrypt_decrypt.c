#include <stdio.h>
#include <string.h>
const int SIZE = 500;
int encryptor(char input_msg[], int);
int decryptor(char input_msg[], int true_size);

/* We add system("pause"); before return command of main function to keep the powershell open after executing otherwise powershell automatically get closed after execution of .exe program */

/* You can also add a personal code to encrypt a message such that only that person can decrypt the message*/

/* we are using charset scanf (scanf("%[^\n]%*c")) for not to take enter as next input (for clearing the INPUT BUFFER)
GO and learn about charset scanf , input/output buffer and how to clear it ,how to return array by as a function output */

int main()
{
  char option;
  char input_msg[SIZE];
  int true_size;
  int i = 2;
  while (i == 2)
  {
    printf("\nWelcome to A.j services \nselect any option :-\n1)Message encryption\n2)Message decryption\n3)Exit\n\nEnter option : ");
    scanf("%[^\n]%*c", &option);
    
    if (option == '1')
    {
      printf("CAUTION :- Message size should be less than 500 letters (including spaces)\nEnter message to encrypt : ");
      gets(input_msg);
      true_size = strlen(input_msg);
      encryptor(input_msg, true_size);
    }
    else if (option == '2')
    {
      printf("CAUTION :- Message size should be less than 500 letters (including spaces)\nPaste the encrypted message here : ");
      gets(input_msg);
      true_size = strlen(input_msg);
      decryptor(input_msg, true_size);
    }
    else if (option == '3')
    {
      printf("\nThank you ,For giving us a chance to Serve You. Hope you like it.\n\n");
      system("pause");
      return 1;
    }

    printf("Do you want to continue ? (y/n) :- ");
    char answer;
    scanf("%[^\n]%*c", &answer);\

    /* Quaternary operator */
    i = answer == 'y' ? 2 : 8, printf("Thank you ,For giving us a chance to Serve You. Hope you like it.");
  }
  system("pause");
  return 0;
}

int encryptor(char input_msg[], int true_size)
{
  int int_array[true_size], rem, q;
  int eml = 2 * true_size; //eml-> encrypt message length
  char encrypt_msg[eml + 1];
  for (int i = 0; i < true_size; i++)
  {
    int_array[i] = (int)input_msg[true_size - 1 - i];
    int_array[i] = int_array[i] + i;

    rem = int_array[i] % 37;
    q = (int_array[i] - rem) / 37;

    encrypt_msg[2 * i] = (char)(31 + rem);
    encrypt_msg[2 * i + 1] = (char)(31 + q);
  }
  encrypt_msg[eml] = '\0';
  printf("Your encrypted message is --> %s\n\n", encrypt_msg);
  printf("If you want to Decrypt a Encrypted Message (of this service) Then use our Decryption service\n");
  return 0;
}

int decryptor(char input_msg[], int true_size)
{
  int int_array[true_size];
  for (int i = 0, p = 0; i < true_size; i++)
  {
    int_array[i] = (int)input_msg[i];
    int_array[i] = int_array[i] - 31;
  }
  int dml = (true_size / 2); //dml -> decrypt message length
  int final_int_array[dml];
  char decrypt_msg[dml + 1];
  for (int i = 0, p = 0; i < true_size; i = i + 2, p++)
  {
    final_int_array[p] = int_array[i] + 37 * int_array[i + 1];
    final_int_array[p] = final_int_array[p] - p;
    decrypt_msg[dml - 1 - p] = (char)final_int_array[p];
  }
  decrypt_msg[dml] = '\0';
  printf("Your message is :  %s\n\n", decrypt_msg);

  return 0;
}