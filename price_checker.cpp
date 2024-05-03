#include "price_checker.h"

// Function to parse the input file and populate the unordered_map
void parsePriceList(const string& filename, unordered_map<string, pair<string, float>>& priceMap) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    string operatorName;
    string line;
    while (getline(file, line)) {
        if (line.find("Operator") == 0) {
           size_t colonPos = line.find(":");
            // Extract characters after "Operator" until just before the colon
            operatorName = line.substr(9, colonPos - 9); // Assuming "Operator" has 9 characters
            continue; // Move to the next line
        }

        istringstream iss(line);
        string  prefix;
        float price;
        if (iss >> prefix >> price) {
            // Check if the prefix already exists in the map and update only if the new price is lower
            if (priceMap.find(prefix) == priceMap.end() || price < priceMap[prefix].second) {
                priceMap[prefix] = make_pair(operatorName, price);
            }
        } else {
            //cerr << "Error parsing line: " << line << endl;
        }
    }

    file.close();
}

// Function to search for the cheapest operator for a given phone number
pair<string, float> findCheapestOperator(const string& phoneNumber, const unordered_map<string, pair<string, float>>& priceMap) {
    string operatorName="";
    float cheapestPrice;

    
    // Iterate over the phone number progressively removing digits from the end
    for (int i = phoneNumber.size(); i > 0; --i) {
        string prefix = phoneNumber.substr(0, i);
        if (priceMap.find(prefix) != priceMap.end() ) {
            operatorName = priceMap.at(prefix).first;
            cheapestPrice = priceMap.at(prefix).second;
            break;
        }
    }

    return make_pair(operatorName, cheapestPrice);
}

// Function to print the content of the map
void printMapfunc( unordered_map<string, pair<string, float>>& priceMap) {
    cout << "Content of the map:" << endl;
    for (auto it = priceMap.begin(); it != priceMap.end(); ++it) {
        string key = it->first;
        string op = it->second.first;
        float price = it->second.second; 
        cout << "Prefix: " << key << " Operator:" << op<< " Price:" << price << endl;
    }
}

bool isPhoneNumberValid(const std::string& phoneNumber) {
    // Check if all characters in the phone number are digits
    for (char c : phoneNumber) {
        if (!isdigit(c)) {
            return false; // Return false if any non-digit character is found
        }
    }
    return true; // Return true if all characters are digits
}
