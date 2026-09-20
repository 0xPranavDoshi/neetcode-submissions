class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit_count = 0;

        while (n > 0) {
            bit_count += (n % 2);
            n /= 2;
        }

        return bit_count;
    }
};
