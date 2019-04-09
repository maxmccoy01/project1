#include <stdio.h>
//the value of A in ASCII is 65, B = 66, C = 67,...., Z = 90
//The values of the letters change with upper and lower case 
void RotEncrypt(char origtext[100], int key1); //takes entered text and key value. 
void RotDecrypt (char encryptext[100], int key2); //takes an encrypted text and the key that was used to encrypt it

int main(){
    int x;
    Printf("Press A for rotation cypher encryption, B for rotation cypher decryption\n, C for substitution cypher encryption\n, D for substitution cypher decryption/n");
    Scanf("%d", &x);
    switch(x) {
    case 'A': int key1;
              printf("please enter a key:");
              scanf("%d", &key1); //user enters a value and it is stored in key1
              char origtext[100];//string capable of storing 99 letter words
              printf("please enter the text you want to encrypt in CAPITALS: \n");
              scanf("%s", origtext); //stores the entered value in origtext
              RotEncrypt(origtext, key1);
              break;
    case 'B': int key2;
              printf("please enter the key used to encrypt the message\n");
              scanf("%d", &key2); //user gives the key they used to encrypt the message
              char encryptext[100]; //the string that the encrypted text will be stored in
              printf("please enter the encrypted text in CAPITALS\n");
              scanf("%s", encryptext); //stores the ecncrypted text in the string encryptext
              RotDecrypt(encryptext, key2);
}
void RotEncrypt(char origtext[100], int key1){
    int i = 0; //counts
    int lettervalue; //variable that represents the number value of each ASCII charcter after the key has been applied
    int temp; // declared a temporary variable
    char encrypted[100];
    
    while(origtext[i]!= '\0'){
        temp  = origtext[i]; //takes the numerical value of the letter at i and stores it into temp
        lettervalue = (temp + key - 65)%26+65; //conversion equation
        encrypted[i] = lettervalue; //takes the numerical value of the letter after the equation and stores it at point i in a string
        printf("%c", encrypted[i]); 
        i++;
    }
    printf("\n");
}

void RotDecrypt(char encryptext[100], int key){
    
}



