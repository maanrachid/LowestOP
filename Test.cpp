#include "price_checker.h"
#include <iostream>

// Helper function to compare floating point numbers with a tolerance
bool isEqual(float a, float b, float tolerance = 0.0001) {
    return std::abs(a - b) < tolerance;
}

// Manual unit tests for parsePriceList function
void testParsePriceList() {
    std::unordered_map<string, std::pair<std::string, float>> priceMap;
    parsePriceList("price_list.txt", priceMap);
    
    // Manual assertion: check if the map has the correct number of entries
    if (priceMap.size() != 11) {
        std::cerr << "Error: Incorrect number of entries in price map." << std::endl;
    }
    
}

// Manual unit tests for findCheapestOperator function
void testFindCheapestOperator() {
    std::unordered_map<string, std::pair<std::string, float>> priceMap;
    parsePriceList("price_list.txt", priceMap);
    
    // Manual assertion: check if the cheapest operator for a given phone number is correct
    auto cheapestOperator = findCheapestOperator("46313456789", priceMap);
    if (cheapestOperator.first != "C" || !isEqual(cheapestOperator.second, 0.13)) {
        std::cerr << "Error: Incorrect cheapest operator for phone number. " << std::endl;
    }
    
    // Additional manual assertions can be added for other test cases
}

// Manual unit tests for isPhoneNumberValid function
void testIsPhoneNumberValid() {
    // Manual assertion: check if valid phone numbers are correctly identified
    if (!isPhoneNumberValid("1234567890") || isPhoneNumberValid("1234abc567890")) {
        std::cerr << "Error: Invalid phone number validation." << std::endl;
    }
    
    // Additional manual assertions can be added for other test cases
}

void testPrintMapfunc() {
    // Create an unordered_map with some test data
    std::unordered_map<string, std::pair<std::string, float>> testMap;
    testMap["1"] = {"Operator A", 0.9};
    testMap["2680"] = {"Operator A", 5.1};
    testMap["46"] = {"Operator A", 0.17};
    testMap["0234"] = {"Operator B", 0.12};
    
    // Call the function with the test map
    printMapfunc(testMap);
}


int main() {
    // Run the manual unit tests
    testParsePriceList();
    testFindCheapestOperator();
    testIsPhoneNumberValid();
    testPrintMapfunc();
    return 0;
}
