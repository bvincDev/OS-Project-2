# OS-Project-2
Programming assignment #2 for operating systems, Banker's Algorithm.

## Overview
#### Problem
- A system with limited resources it's important to have processes complete without entering a deadlock state. Banker's algorithm allocates proper resources requests to a process while using available resources and needs of a process.
#### Description
- Shows the Banker's Algorithm in C++. It reads an example system that holds a process count, resource types, current allocations, maximum demands, and available resources. The program will then compute the need matrix and simulate processes completing one at a time. This is determined by the process whose outstanding needs can be met by the work (available vector). The completion order is recording in the seq vector. Finally if all conditions are met the safe sequence can be printed.
- 
## Files:
- `BankerAlgorithm.hpp`: Defines the Banker class that computes the need matrix, checks the system, and creates the safe sequence.
- `BankerAlgorithm.cpp`: Implements the Banker class that loads `input.txt`, runs the safe check, and prints the results.
- `input.txt`: The input text file being read that stores the example system values.

## Prerequisites
- A Unix operating system or environment
- A C++ compiler

## Compiling and Running the Program
`g++ BankerAlgorithm.cpp -o banker` </br>
`./banker`
## Example
<i>(with the text file as input)</i></br></br>
![image](https://github.com/user-attachments/assets/4ed9a256-66d0-43c7-9046-5940b2be80c9)
