//============================================================================
// Name        : Module5_append.cpp
// Author      : MS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>    // For input/output
#include <fstream>     // For file handling
#include <string>      // For string manipulation

// Function to append user input to a file
void appendToFile(const std::string& fileName, const std::string& userInput) {
    std::ofstream outFile(fileName, std::ios::app); // Open file in append mode
    if (outFile) {
        outFile << userInput << "\n"; // Write the user's input to the file
    } else {
        std::cerr << "Error: Unable to open file for appending." << std::endl;
    }
    outFile.close(); // Close the file after writing
}

// Function to reverse the contents of one file and save it in another file
void reverseFileContents(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inFile(inputFileName); // Open input file for reading
    std::ofstream outFile(outputFileName); // Open output file for writing

    if (inFile && outFile) {
        std::string content;
        // Read each line and add it to the content string
        while (std::getline(inFile, content)) {
            // Reverse the line
            std::string reversedLine(content.rbegin(), content.rend());
            // Write the reversed line to the output file
            outFile << reversedLine << "\n";
        }
    } else {
        std::cerr << "Error: Unable to open files for reading/writing." << std::endl;
    }

    inFile.close(); // Close the input file
    outFile.close(); // Close the output file
}

int main() {
    std::string userInput;
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput); // Get user input as a line of text

    const std::string inputFileName = "CSC450_CT5_mod5.txt";
    const std::string outputFileName = "CSC450-mod5-reverse.txt";

    // Append user input to the file
    appendToFile(inputFileName, userInput);

    // Reverse the content of the input file and save it to the output file
    reverseFileContents(inputFileName, outputFileName);

    std::cout << "Text appended and file reversed successfully." << std::endl;
    return 0;
}
