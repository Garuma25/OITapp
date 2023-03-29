#include <iostream>
#include <string>

using namespace std;

class RomanNumeralConverter {
private:
    int result;
    string s;

public:
    RomanNumeralConverter() {
        result = 0;
    }
  
    //input function to get the roman numeral
    void input() {
        cout << "Enter a Roman numeral: ";
        cin >> s;
    }
  
    //once we get the roman numeral as a string we call the function convert
    void convert() {
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case 'I':
                    if (i < s.size() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                        result -= 1;
                    } else if (i < s.size() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C' || s[i + 1] == 'D' || s[i + 1] == 'M')) {
                        cout << "This Roman numeral is invalid." << endl;
                        break;
                    } else {
                        result += 1;
                    }
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    if (i < s.size() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                        result -= 10;
                    } else if (i < s.size() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                        cout << "This Roman numeral is invalid." << endl;
                        break;
                    } else {
                        result += 10;
                    }
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    if (i < s.size() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                        result -= 100;
                    } else {
                        result += 100;
                    }
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
                default:
                    break;
            }
        }
    }
  
    //output result; it could be valid or invalid
    void output() {
        cout << "The decimal equivalent of the Roman numeral is: " << result << endl;
    }
};

int main() {
    RomanNumeralConverter converter;
    converter.input();
    converter.convert();
    converter.output();

    return 0;
}
