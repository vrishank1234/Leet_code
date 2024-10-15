class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
          int n = num.size();
          int carry = k;

    for (int i = n - 1; i >= 0; --i) {
        carry += num[i];       
        num[i] = carry % 10;   
        carry /= 10;          
    }

    
    while (carry > 0) {
        num.insert(num.begin(), carry % 10);
        carry /= 10;
    }

    return num;
        
    }
};