class Solution {
public:
    int calPoints(vector<string>& operations) {
        int x = 0;
        vector<int> records;

        for(int i = 0; i < operations.size(); i++) {
            string op = operations[i];
            int n = records.size();

            if(op == "+") {
                int record = records[n-1] + records[n-2];
                records.push_back(record);
            } else if(op == "D") {
                int record = 2 * records[n-1];
                records.push_back(record);
            } else if(op == "C") {
                records.pop_back();
            } else {
                records.push_back(stoi(operations[i]));
            }
        }

        for(int i = 0; i < records.size(); i++) {
            x += records[i];
        }

        return x;
    }
};