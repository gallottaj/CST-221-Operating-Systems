/////Joey Gallotta
////CST-221 Memory Management
////10/25/2020
 
//take a decimal number between 0 and 4095 as input from a user that performs the following operations:

//Display the number as a 32-bit binary number displaying each binary digit as a 1 or 0 (with the least significant bit on right) in the console. 

//Display the number as a 32-bit hexadecimal number in the console. 

//Shift the number 16 bits to the left, then mask out (AND) the bottom 16 bits, and finally add (OR) the hex number 0x07FF to produce the final resultant number. 

//Display the final result in binary, hexadecimal, and decimal to the console.d.  

//Write your program in a modular fashion to eliminate redundant code.

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>

//declare variables
//creat 32 bit binary array
 
 int i, j, k, new_hex;
 char binary_array[32];
 unsigned int input = -1, shift;

//function to print to console 

 void* printMessage(char message []){
        printf("%s", message);
 }

//function to read input from console

 void* readInput(){
            scanf("%d", &input);
            while ((getchar()) != '\n');
 }

//function to convert input to a 32-bit binary number, displaying each digit as 1 or 0.

 void* calculate_binary() {
     if (input >= 0 && input < 4096){
         unsigned int mask = 1<<31;
         for (i = 0; i < 8; i++){
                 for (j = 0; j < 4; j++){
                      char m = (input & mask) == 0 ? '0' : '1';
                      binary_array[k++] = m;
                      putchar(m);
                      mask >>=1;
                 }
                 putchar(' ');
         }
         putchar('\n');
     }
 }


//function to convert input to hexadecimal and print to console

 void* print_hexadecimal(){
       printf("%04x\n", input);
 }

//function to print to console
 void* calculate_decimal(){
        printMessage("Result in binary: ");
        calculate_binary();
        printMessage("Result in hexadecimal: ");
        print_hexadecimal();
 }


//function to shift the decimal 16 bits to the left
//masks the bottom 16 bits and adds the new hexidecimal number
//prints results to the console

 void* shift_number(){
     shift = input << 16;
     new_hex = shift & input;
     unsigned int add_hex = 0x07FF;
     new_hex = new_hex | add_hex;
     printf("New decimal value: %d\n", new_hex);
     input = new_hex;
     calculate_decimal();
 }

//main function to take user input
//returns error if number is invalid
 
 int main (void){
    while (input < 0 || input > 4096){
        printMessage("Please enter an integer between 0 and 4095: ");
        readInput();
        printf("\nYou entered: %i\n", input);
        //error message
            if (input < 0 || input > 4095){
                printMessage("Error. Please enter a number  between 0 and 4095!\n");
            }
     }

    calculate_decimal();
    shift_number();

    return 0;

 }
