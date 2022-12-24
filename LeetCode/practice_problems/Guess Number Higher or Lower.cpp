/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int nGuess;

        while(true){
            nGuess = (right - left)/2 + left; 
            if(!guess(nGuess)) 
                return nGuess;
            else if(guess(nGuess) > 0)
                left = nGuess + 1;
            else
                right = nGuess - 1;
        }

        return nGuess;
    }
};