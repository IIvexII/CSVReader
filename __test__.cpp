#include "./lib/CSVReader.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    CSVReader csvReader("./data/test.csv");

    csvReader.read();

    csvReader.printData();

    cout << csvReader.findColByName("Values") << endl;

    csvReader.printValuesByCol("hello");

    auto values = csvReader.getValuesByCol("Values");

    for (auto value = values.begin(); value != values.end(); value++)
    {
        cout << stoi(*value) << endl;
    }

    return 0;
}