Q. Matchsticks to Square

class Solution {
public:
    // 4 possible way for every matchstick---->Recursion
    bool check(vector<int> &sides,int ind,vector<int> &arr,int side){
        if(ind == arr.size())
            return sides[0] == sides[1] and sides[1] == sides[2] and sides[2] == sides[3];
        
        for(int i=0; i<4; i++){
            if(sides[i] + arr[ind] > side)    // Optimization -1
                continue;              // Move to next side 
            int j = i-1;
            while(j >= 0){
                if(sides[j] == sides[i])  // We already calculate for that length (DP) Optimiz. -3
                    break;
                j--;                        
            }
            if(j != -1)   
                 continue;    // We alredy calculate so move to next side 

            sides[i] += arr[ind];
            if(check(sides,ind+1,arr,side))
                return true;
            sides[i] -= arr[ind];
        }
        return false;
    } 
    
    bool makesquare(vector<int>& arr) {
        int n = arr.size();
        if(n < 4)
            return false;
        int sum = 0;
        for(int &x : arr)
            sum += x;
        sort(arr.begin(),arr.end(),greater<int>()); // Optimization -2
        vector<int> sides(4,0);
        return check(sides,0,arr,sum/4);
    }
};