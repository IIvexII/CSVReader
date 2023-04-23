#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "CSVReader.hpp"

/**
 * @brief Constructor for the Reader class
 * @param filename Name of the file to be read
 */
CSVReader::CSVReader(std::string filename)
{
    this->filename = filename;
}

/**
 * @brief Function to read the file
 * @return True if file is read successfully
 */
bool CSVReader::read()
{
    std::ifstream file(this->filename);
    if (!file.is_open())
    {
        return false;
    }

    std::string line = "";
    int row = 0, col = 0;

    // get the single
    while (getline(file, line))
    {
        std::string word = "";
        std::stringstream ss(line);

        std::vector<std::string> colVector;

        row++;
        while (getline(ss, word, ','))
        {
            colVector.push_back(this->strip(word));
            col++;
        }

        csv.push_back(colVector);
    }

    file.close();

    return true;
}

/**
 * @brief Function to print the data from the file
 */
void CSVReader::printData() const
{
    std::vector<std::vector<std::string>> csv = this->csv;

    // ignore the first row and start looping from 2nd row
    for (auto i = csv.begin() + 1; i != csv.end(); i++)
    {
        for (auto j = i->begin(); j != i->end(); j++)
        {
            std::cout << *j << " ";
        }

        std::cout << std::endl;
    }
}

/**
 * @brief Function to get the data from the file
 * @return csv from the file
 */
std::vector<std::vector<std::string>> CSVReader::getData() const
{
    return this->csv;
}

/**
 * @brief Function to strip the string
 * @param s String to be stripped
 * @return Stripped string
 */
std::string CSVReader::strip(std::string str) const
{
    // Find the position of the first non-whitespace character
    std::size_t first = str.find_first_not_of(" \t\n\r\f\v");

    // If the string is all whitespace, return an empty string
    if (first == std::string::npos)
        return "";

    // Find the position of the last non-whitespace character
    std::size_t last = str.find_last_not_of(" \t\n\r\f\v");

    // Extract the substring between the first and last non-whitespace characters
    return str.substr(first, last - first + 1);
}

/**
 * @brief Function to find column index by column name
 * @param colName Name of the column to be searched
 * @return Index of the column, -1 if not found
 */
int CSVReader::findColByName(std::string colName) const
{
    // headerRow points to the first vector of the csv vector that represent the header
    auto headerRow = this->csv.begin();

    for (auto col = headerRow->begin(); col != headerRow->end(); col++)
    {
        if (*col == colName)
        {
            return col - headerRow->begin();
        }
    }

    return -1;
}

/**
 * @brief Function to get values of a given column
 * @param colName Name of the column to get values from
 * @return Vector of strings containing values of the given column
 */
std::vector<std::string> CSVReader::getValuesByCol(std::string colName) const
{
    std::vector<std::string> colVector;

    // Find the column index using column name
    int col = this->findColByName(colName);

    // If column not found
    if (col == -1)
    {
        std::cout << col << " not found in this csv file" << std::endl;
        // Return the empty vector of strings
        return colVector;
    }

    // Loop through each row and push the value of the given column to the vector
    for (auto row = this->csv.begin() + 1; row != csv.end(); row++)
    {
        colVector.push_back(row->at(col));
    }

    return colVector;
}

/**

@brief Function to print the values of a column by its name

@param colName Name of the column
*/
void CSVReader::printValuesByCol(std::string colName) const
{
    auto colValues = this->getValuesByCol(colName);

    // Print the values of the column
    for (auto col = colValues.begin(); col != colValues.end(); col++)
    {
        std::cout << *col << std::endl;
    }
}