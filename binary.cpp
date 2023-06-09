#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// Function to convert decimal to binary using stack
void decimalToBinary(int decimal) {
    stack<int> binaryStack;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binaryStack.push(remainder);
        decimal /= 2;
    }

    cout << "Binary representation: ";

    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }

    cout << endl;}
// Function to convert binary to decimal
int binaryToDecimal(string binary) {

    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

int main()
 {
    int decimal;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    decimalToBinary(decimal);

    string binary;

    cout << "Enter a binary number: ";
cin >> binary;
int result = binaryToDecimal(binary);

    cout << "Decimal representation: " << result << endl;

    return 0;
}
