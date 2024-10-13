#include <stdio.h>
#include <string.h>
#include <time.h>

/*char *getDateAndTime();*/
int getInteger();
/* Read user input into a character string using fgets() */

/*void decimalToBinary(int decValue, char binString[]); /*
/*Accepts a decimal value and a character string buffer and converts
into it's corrosponding binary value and stores the result as a character
string with binString[]. binString[] may then be displayed from within
main() */

/*void decimalToHex(int decValue, char hexString[]);
/*Accepts a decimal value and a character string buffer and converts into
it's corrosponding hexadecimal value and store the reslut as a
character string within hexString[]. hexString[] may then be displayed
from within main(). */

/*int saveFile(char name[], char date[], int decValue, char octString[],
        char hexString[], char binString[]);
/*Promp the user whether the output should be saved to a text file. If the
user replies in yes, a name for the text file is requested. The newly
created text file will contain the user's name, current date, and output
results. If the output file cannot be opened, print an appropriate error
message and return 0. Otherwise return 1. */

int main(){
        print(getInteger());
        }

int getInteger(){
        char buffer[10]
        printf("Enter an Integer [1 - 1,000,000]: ");
        fgets(buffer,10,stdin);
        if(buffer[0] == 'x'){
                return -1;
        }else{
                int user_input = atoi(buffer);
                return user_input;
}