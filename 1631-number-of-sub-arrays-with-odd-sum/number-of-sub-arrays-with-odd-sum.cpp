class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int o=0;
        int e=1;
        int result=0;
        int MOD=1000000007;
        int sum=0;
        for(int num:arr){
            sum+=num;
            if(sum%2==0){
                result=(result+o)%MOD;
                e++;

            }
            else{
                result=(result+e)%MOD;
                o++;
            }
        }
        return result;
        
    }
};