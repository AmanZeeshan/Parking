#include <iostream>
#include <string>
#include <map>

// Function to validate the frequent parking number and calculate the discount.
bool isValidFrequentParkingNumber(const std::string& number) {
    if (number.length() != 5) return false; // Including check digit
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        if (!isdigit(number[i])) return false;
        sum += number[i] - '0';
    }
    int checkDigit = sum % 11;
    return checkDigit == (number[4] - '0');
}

// Function to calculate parking price.
double calculateParkingPrice(int day, int arrivalTime, int hours, const std::string& frequentParkingNumber) {
    double pricePerHour = (day == 0 || (arrivalTime >= 16)) ? 2.00 : (day == 6 ? 3.00 : 10.00);
    double discount = (arrivalTime >= 16) ? 0.50 : 0.10;
    double totalCost = pricePerHour * hours;
    if (isValidFrequentParkingNumber(frequentParkingNumber)) {
        totalCost *= (1 - discount);
    }
    return totalCost;
}

int main() {
    int day, arrivalTime, hours;
    std::string frequentParkingNumber;

    std::cout << "Enter day of the week (0=Sunday, 1=Monday, ..., 6=Saturday): ";
    std::cin >> day;
    std::cout << "Enter hour of arrival (0-23): ";
    std::cin >> arrivalTime;
    std::cout << "Enter number of hours to park: ";
    std::cin >> hours;
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::cout << "Enter frequent parking number (or press enter if none): ";
    std::getline(std::cin, frequentParkingNumber);

    double price = calculateParkingPrice(day, arrivalTime, hours, frequentParkingNumber);
    std::cout << "The price to park is: $" << price << std::endl;

    return 0;
}
double dailyTotal = 0;

// After calculating the price in the main function, add:
std::cout << "Enter amount paid: ";
double amountPaid;
std::cin >> amountPaid;
if (amountPaid >= price) {
    dailyTotal += amountPaid;
    std::cout << "Daily total is now: $" << dailyTotal << std::endl;
} else {
    std::cout << "Amount paid is less than the amount due. Transaction cancelled." << std::endl;
}
double calculateParkingPrice(int day, int arrivalTime, int hours, const std::string& frequentParkingNumber) {
    double morningRate = (day == 0 || day == 6) ? 2.00 : 10.00;
    double eveningRate = 2.00;
    double discount = (arrivalTime >= 16) ? 0.50 : 0.10;
    double totalCost = 0.0;

    if (arrivalTime < 16) {
        int morningHours = std::min(16 - arrivalTime, hours);
        int eveningHours = hours - morningHours;
        totalCost = morningRate * morningHours + eveningRate * eveningHours;
    } else {
        totalCost = eveningRate * hours;
    }

    if (isValidFrequentParkingNumber(frequentParkingNumber)) {
        totalCost *= (1 - discount);
    }
    return totalCost;
}
