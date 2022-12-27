class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        int middle;

        while(left <= right){
            middle = (right - left) / 2 + left;

            if (letters[middle] >= target)
                right = middle - 1;
            else
                left = middle + 1;
        }

        if(left >= letters.size())
            return letters[0];

        while(letters[left] <= target and left < letters.size()){
            left++;
            if (left >= letters.size())
                return letters[0];
        }
        
        return letters[left];

    }
};