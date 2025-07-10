class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> beams;

        for(int i = 0; i < bank.size(); i++) {
            int ones = 0;
            for(int j = 0; j < bank[i].size(); j++) {
                if(bank[i][j] == '1') ones++;
            }
            if(ones) beams.push_back(ones);
        }

        if(beams.size() == 1) return 0; 

        int ans = 0;
        for(int i = 1; i < beams.size(); i++) {
            ans += (beams[i]*beams[i-1]);
        }


        return ans;
    }
};