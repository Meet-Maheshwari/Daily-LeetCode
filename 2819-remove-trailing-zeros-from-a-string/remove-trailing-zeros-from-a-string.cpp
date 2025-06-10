class Solution {
public:
    string removeTrailingZeros(string num) {
        while((num.size() != 0) && num[num.size()-1] == '0') {
            num.erase(num.begin()+(num.size()-1));
        }

        return num;
    }
};