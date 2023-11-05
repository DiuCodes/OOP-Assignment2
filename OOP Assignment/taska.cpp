#include <iostream>
#include <string>

using namespace std;

class BigReal {
private:
    string number;
    string intpart;
    string fractionpart;
    string sign;

    bool isValidReal(const string& realNumber) {
        // Check if the string is empty
        if (realNumber.empty()) {
            return false;
        }
        // Check if the string starts with a valid sign (+ or -)
        if (realNumber[0] != '+' && realNumber[0] != '-' && !isdigit(realNumber[0])) {
            return false;
        }
        // Check if the string contains more than one decimal point
        int decimalCount = 0;
        for (char c : realNumber) {
            if (c == '.') {
                decimalCount++;
                if (decimalCount > 1) {
                    return false;
                }
            } else if (!isdigit(c) && c != '+' && c != '-') {
                return false;
            }
        }
        // Check if the string ends with a digit
        if (!isdigit(realNumber.back())) {
            return false;
        }
        return true;
    }
public:
    BigReal(string realNumber) {
        if (isValidReal(realNumber)) {
            if (realNumber[0] == '+' || realNumber[0] == '-') {
                sign = realNumber[0];
                realNumber.erase(0,1);
                if (realNumber.find('.') != string::npos) {
                    intpart = realNumber.substr(0, realNumber.find('.'));
                    fractionpart = realNumber.substr(realNumber.find('.') + 1);
                } else {
                    intpart = realNumber;
                }
            } else {
                if (realNumber.find('.') != string::npos) {
                    intpart = realNumber.substr(0, realNumber.find('.'));
                    fractionpart = realNumber.substr(realNumber.find('.') + 1);
                } else {
                    intpart = realNumber;
                }
            }
        } else {
            intpart = realNumber;
        }
    }

    BigReal operator+(const BigReal& other)  {
        BigReal result("");
        string fraction1 = fractionpart;
        string fraction2 = other.fractionpart;
        int max_fraction_length = max(fraction1.size(), fraction2.size());
        fraction1.resize(max_fraction_length, '0');
        fraction2.resize(max_fraction_length, '0');
        int carry = 0;
        for (int i = fraction1.length() - 1; i >= 0; i--) {
            int digit1 = fraction1[i] - '0';
            int digit2 = fraction2[i] - '0';
            int sum = digit1 + digit2 + carry;
            result.fractionpart = to_string(sum % 10) + result.fractionpart;
            carry = sum / 10;
        }
        string int1 = intpart;
        string int2 = other.intpart;
        int max_int_length = max(int1.size(), int2.size());
        int1 = string(max_int_length - int1.size(), '0') + int1;
        int2 = string(max_int_length - int2.size(), '0') + int2;
        for (int i = int1.length() - 1; i >= 0; i--) {
            int digit1 = int1[i] - '0';
            int digit2 = int2[i] - '0';
            int sum = digit1 + digit2 + carry;
            result.intpart = to_string(sum % 10) + result.intpart;
            carry = sum / 10;
        }
        return result;
    }
    void print() const {
        cout << intpart<<'.';
        if (!fractionpart.empty()) {
            // Remove trailing zeros from fractionpart
            size_t lastNonZero = fractionpart.find_last_not_of('0');
            if (lastNonZero != string::npos) {
                cout << fractionpart.substr(0, lastNonZero + 1);
            }
        }
        cout << endl;
    }

    friend ostream& operator<<(ostream& out, const BigReal& num) {
        out << num.number;
        return out;
    }
};

int main() {
    BigReal n1("11.9000000000000000000000000000000001");
    BigReal n2("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    n3.print();
    return 0;
}
