// Project 3 CMSC 313
// Author: Jacob Fruchey
// Email: ui41773@umbc.edu
// Description: Outputing a hex dump from a file

#include <stdio.h>
#include <ctype.h>    // Allows certain functions to be ran like isprint to be performed

// No function in this project, it is all ran through the main
int main(){
    // This allows us to read the binary file and grab data from it.
    // THe "rb" just means we are reading the file as binary
    FILE *binary = fopen("binary.out", "rb");
    
    // We check to see if the file is empty here
    if(binary == NULL){
        printf("File was empty or could not be opened\n");
        return 0;
    }

    // We assign 3 variables here, one for the characters we are reading
    // one for the offset, or the next line we are adding
    // and one for the size of the next inputed line
    unsigned char input[16];
    int offset = 0;
    size_t size;

    // This is the main loop that will go through the entire binary file
    while((size = fread(input, 1, 16, binary)) > 0 ){
        
        // This will print off the address at the beginning of each line
        printf("%08X  ", offset);

        // This for loop will then go and print out the hex version of the characters of the line we are on
        for(int i = 0; i < 16; i++){
            if (i < size){
                // The %02X means we are converting it to 2 hexadecimal characters and printing it
                printf("%02X ", input[i]);
            }
            else{
                // This gives us a gap so that it is not all bunched together when the program prints
                printf("   ");
            }
        }

        // This is for when we are done printing hex translation and we are now printing the original string
        printf("|");
        // This for loop goes through the string and prints the characters if they can be printed
        for(int i = 0; i < size; i++){
            if (isprint(input[i])){
                printf("%c", input[i]);
            }
            else{
                // If the character cannot be printed, then we print a .
                printf(".");
            }
        }
        // This and the other | above are just for making the output look better
        printf("|\n");

        // Finally, we increment the offset by the size and move onto the next line
        offset += size;

    }

    // After we are done the while loop, we close the binary file
    fclose(binary);

    return 0;
}

