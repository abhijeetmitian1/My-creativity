#include <stdio.h>
#include <string.h>
const int SIZE=500;
//Compiler version gcc  6.3.0

int main()
{
  char input_encrypt_msg[SIZE];
  printf("Welcome to A.j encryption service\n\n");
  printf("Enter the encrypted message from our service (copy and paste here) : ");
  gets(input_encrypt_msg);
  int true_size = strlen(input_encrypt_msg);
  int int_array[true_size];
  for(int i=0,p=0;i<true_size;i++)
  {
    int_array[i]=(int)input_encrypt_msg[i];
    int_array[i]=int_array[i]-31;
  }
  int dml=(true_size/2);//dml -> decrypt message length
  int final_int_array[dml];
  char decrypt_msg[dml+1];
  for(int i=0,p=0;i<true_size;i=i+2,p++)
  {
    final_int_array[p]=int_array[i]+37*int_array[i+1];
    final_int_array[p]=final_int_array[p]-p;
    decrypt_msg[dml-1-p]=(char)final_int_array[p];
  }
  decrypt_msg[dml]='\0';
  printf("Your message is :  %s\n\nThank you!\n", decrypt_msg);
  
  return 0;
}