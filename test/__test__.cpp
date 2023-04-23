#include <iostream>
#include <cassert>
#include "../lib/CSVReader.hpp"

using namespace std;

int main()
{
    // Test constructor and read function
    CSVReader reader("./test/data/test.csv");
    bool success = reader.read();
    assert(success);

    // Test getData function
    std::vector<std::vector<std::string>> data = reader.getData();
    assert(data.size() == 5);
    assert(data[0].size() == 3);
    assert(data[1][2] == "2.0");
    assert(data[2][1] == "cat");

    // Test strip function
    assert(reader.strip("  apple ") == "apple");

    // Test findColByName function
    int index = reader.findColByName("C");
    assert(index == 2);

    // Test getValuesByCol function
    std::vector<std::string> values = reader.getValuesByCol("B");
    assert(values.size() == 4);
    assert(values[0] == "dog");
    assert(values[2] == "banana");

    // Testing the words with spaces
    assert(data[4][1] == "hello world");

    // Test printValuesByCol function
    reader.printValuesByCol("C");

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}
