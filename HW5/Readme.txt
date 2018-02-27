*******************************************************
*  Name      :  Cody Kelly
*  Student ID:  101886601
*  Class     :  CSCI 2421           
*  HW#       :  5
*  Due Date  :  March 5th, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program reads in input from a file. It stores each
word from the file into its own element in an STL list.
This is the dictionary list. It then takes the input
of another file and searches for them in the dictionary
list. It searches front to back, then back to front,
outputting the number of words it's had to go through
to do so. It then stores every word in the dictionary
list sorted in reverse into a new file called
revsorted.txt.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that gets
   input from files and calls the necessary methods to
   process the data.
   
   
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
       % unzip [KellyHW5]

   Now you should see a directory named homework with the files:
        main.cpp
        functions.cpp
        functions.hpp
	dictionary.cpp
	dictionary.hpp
	DictEntry.hpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [KellyHW5] 

    Compile the program by:
    % make

3. Run the program by:
   % ./main.out

4. Delete the obj files, executables, and core dump by
   %./make clean