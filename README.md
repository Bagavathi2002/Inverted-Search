# Inverted-Search
Inverted Search is a C-based program that creates an index from text files, allowing quick lookup of words and the files they appear in. This is particularly useful for keyword-based file searching and retrieval.

# Features
Create Database: Reads provided text files and builds an inverted index where each word links to the files it appears in.
Display Database: Lists all indexed words and their occurrences across files.
Search: Quickly locates files that contain a specific word.
Update Database: Adds new files or words to the existing index without starting from scratch.
Save Database: Saves the current database state to a file for future use.

# Project Structure

├── inverted_search.h      # Header file with definitions and function declarations

├── main.c                 # Main program file with the user interface

├── readme.md              # README file (this file)

├── Makefile               # Makefile for compiling the project (if available)

└── data                   # Sample folder for storing input text files

# Prerequisites
C Compiler (e.g., gcc)

# Compile the program:
gcc main.c -o inverted_search

Usage
Run the program with one or more text files as arguments:

./inverted_search file1.txt file2.txt ...

# Interactive Menu
After starting, the program offers an interactive menu:

Create Database: Build the index from input files.
Display Database: View the entire index with words and file occurrences.
Search: Enter a word to find which files contain it.
Update Database: Add more files or new words to the current index.
Save Database: Save the indexed database to a file.
The program continues running until you choose to exit.
