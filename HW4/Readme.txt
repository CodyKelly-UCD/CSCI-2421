*******************************************************
*  Name      :  Cody Kelly
*  Student ID:  101886601
*  Class     :  CSCI 2421           
*  HW#       :  4
*  Due Date  :  Feb. 19, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program reads in input from a file. It stores each
word from the file into its own element in a linked 
list. 
It then prints the list then asks the user to choose
two words, which it will search the list for and make
a sublist of the words and any words in between the
two. If either of the user's words aren't in the list,
the program will exit.
Once the sublist has been selected, the program will 
sort the words in dictionary order, print the results,
and exit.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that gets
   input from file and calls the necessary methods to
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
       % unzip [KellyHW4]

   Now you should see a directory named homework with the files:
        main.cpp
        functions.cpp
        functions.hpp
        node1.cpp
        node1.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [KellyHW4] 

    Compile the program by:
    % make

3. Run the program by:
   % ./main.out

4. Delete the obj files, executables, and core dump by
   %./make clean