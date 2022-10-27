//Book.cpp - function definitions for the Book class

#include "Book.h"

//Create a function to extract a string from the stream.
//It will be called four times from main() to extract the
//NAME, AUTHOR, YEAR OF PUBLICATION, and PRICE.

//Use below as a guide if you wish

//Extracting NAME:
//           NAME;AUTHOR;YEAR;PRICE;
//           ^   ^
//           |   |
//dataBeginPtr   dataEndPtr

//Extracting AUTHOR:
//           NAME;AUTHOR;YEAR;PRICE;
//                ^     ^
//                |     |
//     dataBeginPtr     dataEndPtr

//Extracting YEAR OF PUBLICATION:
//           NAME;AUTHOR;YEAR;PRICE;
//                       ^   ^
//                       |   |
//            dataBeginPtr   dataEndPtr

//Extracting PRICE:
//           NAME;AUTHOR;YEAR;PRICE;
//                            ^    ^
//                            |    |
//                 dataBeginPtr    dataEndPtr
