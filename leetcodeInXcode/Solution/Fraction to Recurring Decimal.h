//
//  Fraction to Recurring Decimal.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/17/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
private:
    // shift the '.' to left
    string shiftLeft(string &digits, int shift) {
        if (shift == 0)
            return digits;
        digits.insert(digits.end() - shift, '.');
        return digits;
    }
    // format output string
    string makeDecimal(string &digits, int shift, int recur, bool negative) {
        if (digits.empty()) {
            return "0";
        }
        if (recur >= 0) {
            // recur to pos before '.'
            if (recur == 0) {
                digits += digits[0];
                recur++;
                shift++;
            }
            digits.insert(digits.begin() + recur, '(');
            digits += ')';
            shift += 2;
        }
        digits = shiftLeft(digits, shift);
        return negative ? "-" + digits : digits;
    }
    
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool negative = ((numerator < 0) != (denominator < 0)) && (numerator != 0);
        long long d = llabs(denominator);
        long long n = llabs(numerator);
        string digits;
        unordered_map<long long, size_t> recurring;
        int shift = 0;
        int recur = -1;
        while (n > 0) {
            auto it = recurring.find(n);
            if (it != recurring.end()) {
                shift--;
                recur = int(it->second);
                break;
            }
            recurring[n] = digits.length();
            long long quotient = n / d;
            long long reminder = n % d;
            digits += to_string(quotient);
            if (reminder == 0) {
                break;
            }
            n = reminder * 10;
            shift++;
        }
        return makeDecimal(digits, shift, recur, negative);
    }
};