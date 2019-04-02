#include <stdio.h>
//the value of A in ASCII is 65, B = 66, C = 67,...., Z = 90
//The values of the letters change with upper and lower case 
void RotEncrypt(char origtext[7], int key); //takes entered text and key value. 

int main(){
    int key = 1;
    char origtext[7];//string with 51 characters
    printf("please enter the text you want to encrypt in CAPITALS: ");
    scanf("%s", &origtext); //stores the entered value in origtext
    RotEncrypt(origtext,key);
    //printf("the encrypted text is:%c\n ", Rotencrypt(origtext, key));
} 

void RotEncrypt(char origtext[7], int key){
    int i = 0; //counts
    int lettervalue; //variable that represents the number value of each ASCII charcter after the key has been applied
    //char encryption;
    int temp;
    char encrypted[51];
    
    while(origtext[i]!= '\0'){
        temp  = origtext[i];
        lettervalue = (temp + key - 65)%26+65;
        encrypted[i] = lettervalue;
        //lettervalue = ((int)origtext[i]- 65 + key) % 26 + 65; //65 is used as that is the value of A
        //encryption = (char)lettervalue;
        printf("%c", encrypted[i]);
        i++;
    }
    printf("\n");
}
