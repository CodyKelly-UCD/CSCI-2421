*******************************************************
*  Name      :  Cody Kelly
*  Student ID:  101886601
*  Class     :  CSCI 2421           
*  HW#       :  6
*  Due Date  :  March 12th, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program reads in a number of words from a 
dictionary file and text input from a file. It finds
words in the input file that are not contained in the
dictionary files, and compiles a list of them. It
then outputs the possibly misspelled words to the user,
along with the number of words in the dictionary file,
the input file, and misspelled words list.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that gets
   input from files and calls the necessary methods to
   process the data.

functions.cpp
	Contains two functions used throughout the program.
   
   
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
       % unzip [KellyHW6]

   Now you should see a directory named homework with the files:
        main.cpp
        PostfixCalculater.hpp
        PostfixCalculater.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [KellyHW6] 

    Compile the program by:
    % make

3. Run the program by:
   % ./main.out

4. Delete the obj files, executables, and core dump by
   %./make clean