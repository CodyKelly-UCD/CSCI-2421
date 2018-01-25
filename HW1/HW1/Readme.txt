*******************************************************
*  Name      :  Cody Kelly
*  Student ID:  101886601
*  Class     :  CSCI 2421           
*  HW#       :  1                
*  Due Date  :  Jan. 29, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program implements an ADT for a one-person guess 
game that chooses n random integers in the range from 
1 to m and asks the user to guess them. The same 
integer might be chosen more than once.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that asks 
the user for input, checks if the player is correct in 
their guesses and if they would like to play again.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 4.4.2.  It was 
   compiled, run, and tested on gcc ouray.cudenver.edu.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [KellyHW1]

   Now you should see a directory named homework with the files:
        main.cpp
        guess.hpp
	guess.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [KellyHW1] 

    Compile the program by:
    % make

3. Run the program by:
   % ./main.out

4. Delete the obj files, executables, and core dump by
   %./make clean
