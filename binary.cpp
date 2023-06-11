#include <iostream>
#include <stack>
#include <bitset>

// Function to convert decimal to binary using stack
std::string decimalToBinary(int decimal) {
    std::stack<int> binaryStack;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binaryStack.push(remainder);
        decimal /= 2;
    }

    std::string binaryString = "";

    while (!binaryStack.empty()) {
        binaryString += std::to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binaryString;
}

// Function to convert binary to decimal
int binaryToDecimal(std::string binary) {
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += (binary[i] - '0') << power;
        }
        power++;
    }

    return decimal;
}

int main() {
    int decimal;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    std::string binary = decimalToBinary(decimal);
    std::cout << "Binary representation: " << binary << std::endl;

    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    // Validate input
    bool validInput = true;
    for (char c : binary) {
        if (c != '0' && c != '1') {
            validInput = false;
            break;
        }
    }

    if (validInput) {
        int result = binaryToDecimal(binary);
        std::cout << "Decimal representation: " << result << std::endl;

        // Convert binary to hexadecimal using bitset
        std::bitset<32> bitset(binary);
        std::cout << "Hexadecimal representation: 0x" << std::hex << bitset.to_ulong() << std::endl;
    } else {
        std::cout << "Invalid input. Please enter a binary number." << std::endl;
    }

    return 0;
}
