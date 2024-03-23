class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n_len=nums.size();
        int k=pattern.size();
        vector<int> indic(n_len-1);
        for(int i=0;i<n_len-1;i++){
            if(nums[i]<nums[i+1])
                indic[i]=1;
            else if(nums[i]==nums[i+1])
                indic[i]=0;
            else indic[i]=-1;
        }
        vector<int> kmp(k);
        kmp[0]=-1;  
        int i=0;    
        int j=-1;
        while(i<k-1){
            if(j==-1||pattern[i]==pattern[j]){
                i++;    j++;
                if(pattern[i]!=pattern[j])
                    kmp[i]=j;
                else kmp[i]=kmp[j];
            }
            else{
                j=kmp[j];
            }
        }
        for(auto i:kmp) cout<<i<<" ";
        i=0;    j=0;
        int ans=0;
        for(int i=0;i<n_len-1;i++){
            while(j!=-1&&indic[i]!=pattern[j]){
                j=kmp[j];
            }
            if(j==-1)   j=0;
            else{
                j++;
                if(j==k){
                    ans++;
                    j=kmp[j-1];
                }
            }
        }
        return ans;
    }
};