#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define static take
#define ST 1

int main(int argc, char  *argv[]) {
    
    
    
    // Read file
    FILE* ptr;
    char prediction[500];

    while (fscanf(ptr, "%*s %s", buf) == 1)


    
}



#include <fstream>
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "ERROR: Provide a file name for both input and output files.\n";
        return 0;
    }

    ifstream fileIn(argv[1]);
    if (!fileIn.is_open()) {
        cerr << "ERROR: The input file does not exist.\n";
        return 1;
    }

    ofstream fileOut(argv[2], std::ios::out | std::ios::app);
    if (!fileOut.is_open()) {
        cerr << "ERROR: The output file does not exist.\n";
        return 2;
    }

	// Create Counters
    int alwaysT = 0;
    int iCount = 0;

    while (!fileIn.eof()) {
		// Reading Trace File
		// format: address(hex)\ T/NT(actual branch direction)
        long long address;
        fileIn >> hex >> address;
        if (fileIn.fail()) break;

        char branchTaken;
        fileIn >> branchTaken;
        if (fileIn.fail()) break;

        fileIn.ignore(256, '\n');

        if (branchTaken == '1') {
            alwaysT++;
        } 

        iCount++;	//Instruction Count
    }

	//Calculate the accuracy rate of predictor
    float accurateT = ((float)alwaysT * 100 / iCount + 0.5f);

    fileOut << accurateT << endl;

    fileIn.close();
    fileOut.close();
}