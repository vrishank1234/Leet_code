class Solution {
public:

    int myMax(const int& a , const int& b )
    {
        if(a>b)
            return a ;
        else 
            return b;
    }
    int maxDepth(string s) {
        if (s.empty())
            return 0 ;

        int numPar = 0 ;
        int maxPar=std::numeric_limits<int>::min();
        
        for(const auto& element:s)
        {
            if(element=='(')
                numPar++;
            else if(element==')')
                numPar--;

            maxPar=myMax(maxPar,numPar);
        }


        return maxPar;
    }
};