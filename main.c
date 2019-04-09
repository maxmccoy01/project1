#include <stdio.h>
//the value of A in ASCII is 65, B = 66, C = 67,...., Z = 90
//The values of the letters change with upper and lower case 
void RotEncrypt(char origtext[100], int key); //takes entered text and key value. 

int main(){
    int key;
    printf("please enter a key:");
    scanf("%d", &key);
    char origtext[100];//string capable of storing 99 letter words
    printf("please enter the text you want to encrypt in CAPITALS: \n");
    scanf("%s", origtext); //stores the entered value in origtext
    RotEncrypt(origtext,key);
}
void RotEncrypt(char origtext[100], int key){
    int i = 0; //counts
    int lettervalue; //variable that represents the number value of each ASCII charcter after the key has been applied
    int temp; // declared a temporary variable
    char encrypted[100];
    
    while(origtext[i]!= '\0'){
        temp  = origtext[i]; //takes the numerical value of the letter at i and stores it into temp
        lettervalue = (temp + key - 65)%26+65; //conversion equation
        encrypted[i] = lettervalue; //takes the numerical value of the letter after the equation and stores it at point i in the string
        printf("%c", encrypted[i]); 
        i++;
    }
    printf("\n");
}
