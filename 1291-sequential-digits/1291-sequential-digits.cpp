#include <vector>

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        int lowDigitCount = countDigits(low);
        int highDigitCount = countDigits(high);

        for (int numDigits = lowDigitCount; numDigits <= highDigitCount; ++numDigits) {
            for (int start = 1; start <= 9 - numDigits + 1; ++start) {
                int num = buildSequentialNumber(start, numDigits);
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }

private:
    int countDigits(int num) {
        int count = 0;
        while (num > 0) {
            num /= 10;
            ++count;
        }
        return count;
    }

    int buildSequentialNumber(int start, int numDigits) {
        int num = 0;
        for (int i = 0; i < numDigits; ++i) {
            num = num * 10 + (start + i);
        }
        return num;
    }
};
