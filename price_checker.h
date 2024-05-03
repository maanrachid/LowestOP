#ifndef PRICE_CHECKER_H
#define PRICE_CHECKER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;



void parsePriceList(const std::string& filename, std::unordered_map<string, std::pair<std::string, float>>& priceMap);
std::pair<std::string, float> findCheapestOperator(const std::string& phoneNumber, const std::unordered_map<string, std::pair<std::string, float>>& priceMap);
bool isPhoneNumberValid(const std::string& phoneNumber);
void printMapfunc( unordered_map<string , pair<string, float>>& priceMap) ;
void testPrintMapfunc();

#endif // PRICE_CHECKER_H