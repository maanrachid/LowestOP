// Author : Maan Haj Rachid


#include "price_checker.h"


int main() {
    unordered_map<string, pair<string, float>> priceMap;
    parsePriceList("price_list.txt", priceMap);
    //printMapfunc(priceMap);
    char quit;

    do {
        string phoneNumber;
        cout << "Enter the phone number: ";
        cin >> phoneNumber;
        if (!isPhoneNumberValid(phoneNumber) ){
            cerr << "Phone Number has wrong format\n";
            return 0; 
        }

        pair<string, float> cheapestOperator = findCheapestOperator(phoneNumber, priceMap);

        if (cheapestOperator.first !="") {
            cout << "The cheapest operator for number " << phoneNumber << " is Operator " << cheapestOperator.first << " with price $" << cheapestOperator.second << "/min." << endl;
        } else {
            cout << "No operator available for this number." << endl;
        }

    } while (1);

    return 0;
}
