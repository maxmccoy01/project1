#include <stdio.h>
#include <string.h> //lets us use a function which finds the lenth of a string
//the value of A in ASCII is 65, B = 66, C = 67,...., Z = 90
//The values of the letters change with upper and lower case 
void RotEncrypt(char origtext[100], int key1); //takes entered text and key value. 
void RotDecrypt(char encryptext[100], int key2); //takes an encrypted text and the key that was used to encrypt it
void SubEncrypt(char initialtext[100], char key3[27]); //takes entered text and key
void SubDecrypt(char subencryptext[100], char key4[27]); //takes an encrypted text and the key that was used to encrypt it

/* 
Users will choose between rotation cipher encryption/decryption and substitution cipher
encryption/decryption through a switch statement menu system. The user chooses between these 
options by either pressing A, B, C or D. The user enters text and a key for each function.
 */

int main(){
    char i;
    printf("Press:\n A for rotation cipher encryption\n B for rotation cipher decryption\n C for substitution cipher encryption\n D for substitution cipher decryption\n");
    scanf("%c", &i);
    switch(i) {
    case 'A': ; int w = 0; //counts
              char c;
              char origtext[100];//string capable of storing 99 letter words
              printf("please enter the text you want to encrypt in CAPITALS:\n");
              while(1){ //a lopp that will allow whitespace to be used as well as characters
              scanf("%c", &c);
                if(c == '\n'){
                   origtext[w] = '\0'; //when a new line the string ends
                   break;
                }
              origtext[w] = c; //that point in the string becomes that character
              w++;
         }    
              int key1;
              printf("please enter a key:");
              scanf("%d", &key1); //user enters a value and it is stored in key1
              RotEncrypt(origtext, key1); //calling the function to encrypt the text
              break;
              
    case 'B': ; char encryptext[100]; //the string that the encrypted text will be stored in
              int x = 0; //counts
              char a;
              printf("please enter the encrypted text in CAPITALS:\n");
              while(1){
              scanf("%c", &a);
                if(a == '\n'){
                   encryptext[x] = '\0';
                   break;
                }
              encryptext[x] = a;
              x++;
          }
              int key2;
              printf("please enter the key used to encrypt the message:\n");
              scanf("%d", &key2); //user gives the key they used to encrypt the message
              RotDecrypt(encryptext, key2); //calling the function to decrypt the text
              break;
              
    case 'C': ; printf("please enter the message you want to encrypt in CAPITALS:\n");
              char initialtext[100];
              int y = 0; //counts
              char e;
              while(1){
              scanf("%c", &e);
                if(e == '\n'){
                   initialtext[y] = '\0';
                   break;
                }
              initialtext[y] = e;
              y++;
          }
              printf("please enter the key in CAPITALS (the 1st letter will substitute A, etc.):\n");
              char key3[27];
              scanf("%s", key3); //stores the key in key3
              SubEncrypt(initialtext, key3); //calling the function to encrypt the text
              break;
              
    case 'D': ; printf("please enter the encrypted message in CAPITALS:\n");
              char subencryptext[100];
              int z = 0; // counts
              char u;
              while(1){
              scanf("%c", &u);
                if(u == '\n'){
                   subencryptext[z] = '\0';
                   break;
                }
              subencryptext[z] = u;
              z++;
          }    
              printf("please enter the key used to encrypt the message in CAPITALS\n");
              char key4[27];
              scanf("%s", key4); //stores the key in key4
              SubDecrypt(subencryptext, key4); //calling the function to decrypt the text
              break;
                
    }
}
/*
  This function accepts text and a key as an argument. The text is encrypted by a rotation
  cipher. The size of the rotation is dependent on the size of the key. There is no return value,
  instead the function prints the encrypted text. The entered text can be a maximum of 99 letters
  long.
 */
void RotEncrypt(char origtext[100], int key1){
    int i = 0; //counts
    int lettervalue; //variable that represents the number value of each ASCII charcter after the key has been applied
    int temp; // declared a temporary variable
    int temp2; //another temporary variable
    char encrypted[100];
    
    while(origtext[i]!= '\0'){
        temp  = origtext[i]; //takes the numerical value of the letter at i and stores it into temp
        temp2 = origtext[i] - 65; //generates a number between 0 and 25 for capital letters
        if(temp2 >= 0 && temp2 < 26 ){
         lettervalue = (temp + key1 - 65)%26 + 65; //conversion equation
         encrypted[i] = lettervalue; //takes the numerical value of the letter after the equation and stores it at point i in this string
         } else {
            encrypted[i] = origtext[i]; //for things that aren't capital letters in origtext
        }
        printf("%c", encrypted[i]); 
        i++;
    }
    printf("\n");
}
/*
  This function accepts a string of rotationally encrypted text and the key used to encrypt it as
  arguments. The function has no return value, instead the function prints the decrypted text.
  The encrypted text can be a maximum of 99 letters.
 */
void RotDecrypt(char encryptext[100], int key2){
    int i = 0; //counts
    int temp; //temporary variable
    int temp2; //another temporary variable
    int lettervalue; //the numeriacl value of each letter
    char decrypted[100];
    
    while(encryptext[i]!= '\0'){
        temp = encryptext[i]; //takes the numerical value of the letter at i and stores it in temp
        temp2 = encryptext[i] - 65; //generates a number between 0 and 25 for capital letters
        if(temp2 >= 0 && temp2 < 26){
        lettervalue = (temp - key2 + 65)%26 + 65; //conversion equation
        decrypted[i] = lettervalue; //takes the numerical value of the letter after the equation and stores it at point i in this string
        } else {
          decrypted[i] = encryptext[i];
        }
        printf("%c", decrypted[i]); //prints the letter at i in the string
        i++;
    }
    printf("\n");
}
/*
  This function accepts text and a key as an argument. The text is encrypted by a substitution
  cipher. The letter substitution is dependent on the key entered by the user. There is no return value,
  instead the function prints the encrypted text. The entered text can be a maximum of 99 letters
  long.
*/
void SubEncrypt(char initialtext[100], char key3[27]) {
   char subencrypted[100]; // the text after it has been encrypted
   int length = strlen(initialtext); //uses a function from string.h to find the lenth of initialtext
   
   for(int i=0; i < length; i++){
     int j = initialtext[i] - 65; //turns the value at i in initialtext into a number between 0 and 25 if it is a capital letter
     if(j >= 0 && j < 26){
         subencrypted[i] = key3[j]; //the value at i in subencrypted becomes the value that is at j in key3
     } else {
         subencrypted[i] = initialtext[i]; //for things that aren't capital letters in initialtext
     }
   printf("%c", subencrypted[i]);
   }
   printf("\n");
}
/*
  This function accepts a string of substitution encrypted text and the key used to encrypt it as
  arguments. The function has no return value, instead the function prints the decrypted text.
  The encrypted text can be a maximum of 99 letters.
 */
void SubDecrypt(char subencryptext[100], char key4[27]){
    char decryptedtext[100]; //string the decrypted text will be stored in
    int length = strlen(subencryptext); //stores the length of the string in the variable length
    
    for(int i=0; i < length; i++){
       int j = 0;
       int temp; //a temporary variable
       temp = subencryptext[i] - 65; //gets a number between 0 and 25 if it was a capital letter and stores in temp
       if(temp >= 0 && temp < 26){
         while(subencryptext[i] != key4[j]){ //finds when a value in the key matches a value in the encrypted text then stops
            j++; //increments
         } 
          decryptedtext[i] = 65 + j; //finds the decrypted letter
          printf("%c", decryptedtext[i]); //prints the decrypted letter
         } else {
          decryptedtext[i] = subencryptext[i]; //any value thatv isn't a capital letter gets passed un-altered to the decrypted text
          printf("%c", decryptedtext[i]); //prints the un-altered value
         }
       }
   printf("\n");
}

