//Message encryption program by A.j
#include <stdio.h>
#include<string.h>
const int SIZE=500;

//Compiler version gcc  6.3.0

int main()
{
  printf("Welcome to A.j encrytion service\n\n");
  printf("CAUTION :- Message size should be less than 500 letters (including spaces)\n");

  char input_msg[SIZE];
  scanf("%[^\n]%*c",input_msg); //using charset scan instead of gets()
  int true_size=strlen(input_msg);
  //printf("true_size=%d\n",true_size);
  int int_array[true_size],rem,q;
  int eml=2*true_size; //eml-> encrypt message length
  char encrypt_msg[eml+1];
  for(int i=0;i<true_size;i++)
  {
    int_array[i]=(int)input_msg[true_size-1-i];
    int_array[i]=int_array[i]+i;
    rem=int_array[i]%37;
    q=(int_array[i]-rem)/37;
    //printf("rem=%d , q=%d\n",rem,q);
    encrypt_msg[2*i]=(char) (31+rem);
    encrypt_msg[2*i+1]=(char) (31+q);
  }
  encrypt_msg[eml]='\0';
  printf("Your encrypted message is -->%s\n\n", encrypt_msg);
  printf("If you want to Decrypt a Encrypted Message (of this service) Then use our Decryption service\n");
  printf("Thank you for using our service Hope you like it.\n");

  return 0;
}