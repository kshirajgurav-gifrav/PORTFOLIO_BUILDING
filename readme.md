# Simple Line Editor in C

## Team Members
1. KSHIRAJ K GURAV (SRN-R25EJ057)
2. ABAAN SUFIYAN (R25EJ001)
3. ARUN  M (R25EJ015)

## Features Implemented
We implemented the 3 core features required for the competition:
* Insert a line: Adds text at a specific line number.
* Delete a line: Removes text at a specific line number.
* Display the document: Shows all current lines and line numbers.

## Data Structure Justification
We chose an array of strings (`char lines[100][500]`) to hold the document's lines in memory. We chose this because the document is small, it is highly efficient for accessing specific line numbers, and it makes shifting lines up or down straightforward. The trade-off is a fixed maximum document size (100 lines).

## How to Compile
Compile the program using GCC in the terminal:
gcc LineEditor.c -o lineeditor.exe

## How to Run
Run the executable in the terminal:
.\lineeditor.exe