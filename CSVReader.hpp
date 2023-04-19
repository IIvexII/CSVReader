// Include guard to prevent multiple inclusion of this header file
#ifndef CSV_READER_H
#define CSV_READER_H

// Include necessary libraries
#include <iostream>
#include <vector>

// Define the CSVReader class
class CSVReader
{
public:
    /**
     * @brief Constructor for the Reader class
     * @param filename Name of the file to be read
     */
    CSVReader(std::string filename);

    /**
     * @brief Function to read the file
     * @return True if file is read successfully
     */
    bool read();

    /**
     * @brief Function to get the data from the file
     * @return csv from the file
     */
    std::vector<std::vector<std::string>> getData() const;

    /**
     * @brief Function to strip the string
     * @param str String to be stripped
     * @return Stripped string
     */
    std::string strip(std::string str) const;

    /**
     * @brief Function to print the CSV data to the console
     */
    void printData() const;

    /**
     * @brief Function to find the column index by column name
     * @param colName Name of the column to search for
     * @return Index of the column, or -1 if not found
     */
    int findColByName(std::string colName) const;

    /**
     * @brief Function to get the values in a column by column name
     * @param colName Name of the column to retrieve values from
     * @return Vector of values in the specified column
     */
    std::vector<std::string> getValuesByCol(std::string colName) const;

    /**
     * @brief Function to print the values in a column to the console
     * @param colName Name of the column to print values from
     */
    void printValuesByCol(std::string colName) const;

private:
    // Name of the CSV file
    std::string filename;

    // The data from the CSV file
    std::vector<std::vector<std::string>> csv;
};

// Include the implementation of the class in a separate CPP file
#include "./CSVReader.cpp"

// End the include guard
#endif // CSV_READER_H
