class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        int curr = 31;

        while(curr >= 0){
            if((n & (1 << curr)) == (1 << curr))
                answer += 1 << (31 - curr);
            curr--;
        }

        return answer;
    }
};