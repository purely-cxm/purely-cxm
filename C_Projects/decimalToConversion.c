#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char *getDateAndTime();
int getInteger();
/* Read user input into a character string using fgets() */

void decimalToBinary(int decValue, char binString[]);
void decimalToHex(int decValue, char hexString[]);
void decimalToOctal(int decValue, char octString[]);

int saveFile(char name[], char date[], int decimalValue, char octalString[],
        char hexaString[], char binaryString[]);
/*Promp the user whether the output should be saved to a text file. If the
user replies in the affirmative, a name for the text file is requested. The newly
created text file will contain the user's name, current date, and output
results. If the output file cannot be opened, print an appropriate error
message and return 0. Otherwise return 1. */

/*Main Method*/
int main(){
        /*Initializations and Declarations*/
        char dateTime[32];
        char user_name[32];
        int decVal = 0;
        char binString[32];
        char octString[32];
        char hexString[32];
        printf("Enter your name: ");
        fgets(user_name,32,stdin);
        decVal = getInteger();
        strcpy(dateTime,getDateAndTime());

        /*Runs conversions*/
        decimalToBinary(decVal, binString);
        decimalToOctal(decVal, octString);
        decimalToHex(decVal, hexString);

        /*Prints values to terminal*/
        printf("\nDecimal: %d", decVal);
        printf("\nBinary:%s", binString);
        printf("\nOctal: %s \n", octString);
        printf("Hexadecimal:%s \n", hexString);
        saveFile(user_name,dateTime,decVal,octString,hexString,binString);
}

/*Takes in a user input and ensures it is in range or checks if it 'x' in which case it will return -1 and exit*/
int getInteger(){
        char buffer[30];
        int user_input;
        while(1){
                printf("Enter an Integer [1 - 1,000,000]: ");
                fgets(buffer,30,stdin);
                if(buffer[0] == 'x'){
                        return -1;
                }else{
                        user_input = atoi(buffer);
                }
                if(user_input >= 1 && user_input <= 1000000){
                        break;
                }else{
                        printf("Number not in range\n");
                        continue;
                        }
                }
        return user_input;
}

/*Converts the given decimal value to binary and puts it into a character string*/
void decimalToBinary(int decValue, char binString[]){
        int quotient;
        int binNumber[100], i=0,j;
        int k;
        quotient = decValue;
        while(quotient!=0){
                binNumber[i++]= quotient % 2;
                quotient = quotient / 2;
                }
        k=0;
        for(j = i-1 ;j>=0;j--){
                binString[k++] = binNumber[j] + '0';
        }
        binString[k] = '\0';
}

/*Converts given decimal value to it's octal form and prints it into the character string octString*/
void decimalToOctal(int decValue, char octString[]){
        int quotient;
        int octNumber[100], i=0,j;
        int k;
        quotient = decValue;

        while(quotient!=0){
                octNumber[i++]= quotient % 8;
                quotient = quotient / 8;
                }
        k=0;
        for(j = i-1 ;j>=0;j--){
                octString[k++] = octNumber[j]+'0';
        }
        octString[k] = '\0';
}

/*Converts given decimal value to it's hexadecimal form and prints it into the character string called hexString*/
void decimalToHex(int decValue, char hexString[]){
        int remainder, quotient;
        int i=0, j, temp;
        quotient = decValue;
        long int hexNumber[100];
        int k=0;
        while(quotient!=0){
                temp = quotient%16;
                if(temp<10){
                        temp=temp+48;
                }else{
                        temp=temp+55;
                }
                hexNumber[i++]=temp;
                quotient = quotient/16;
        }
        for(j=i-1;j>=0;j--){
                hexString[k++] = hexNumber[j];
        }
        hexString[k] = '\0';
}
/*Retrieves and Stores Date and Time*/
char *getDateAndTime(){
        time_t t;
        time(&t);
        return ctime(&t);
}

/*Saves file and accepts input as name. Adds a decimal, octal, hexadecimal, and binary versions of the value to the string in addition to the user's name*/
int saveFile(char name[], char date[], int decValue, char octString[],char hexString[], char binString[]){
        char user_answer[3];
        FILE *ptr_file;
        char fileName[30];
        while(1){
                printf("Save to File? (y/n): ");
                fgets(user_answer,3,stdin);
                user_answer[1] = '\0';
                if(user_answer[0] == 'y'){
                        break;
                }else if(user_answer[0] == 'n'){
                        return -1;
                }else{
                        printf("Error: Illegal Value \n");
                        continue;
                }
        }
        printf("Enter file name: ");
        scanf("%s",fileName);
        /*fgets(fileName,30,stdin);*/
        ptr_file = fopen(fileName,"w");
        if(!ptr_file){
                return 1;
        }
        fprintf(ptr_file,"%s",name);
        fprintf(ptr_file,"Today's Date: %s \n", date);
        fprintf(ptr_file,"Decimal: %d \n",decValue);
        fprintf(ptr_file,"Hexadecimal: %s \n",hexString);
        fprintf(ptr_file,"Octal: %s \n",octString);
        fprintf(ptr_file,"Binary: %s \n",binString);
        fclose(ptr_file);
        return 0;
}
