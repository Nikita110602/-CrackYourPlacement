class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp(nums1.begin(),nums1.end());
        int p = 0;
        int q = 0;
        nums1.clear();
       while(p<m && q<n){
            if(temp[p]<nums2[q]){
                nums1.push_back(temp[p]);
                p++;
            }
           else if(temp[p]>nums2[q]){
            nums1.push_back(nums2[q]);
            q++;
           }
           else{
            nums1.push_back(temp[p]);
             nums1.push_back(nums2[q]);
             p++;
             q++;
           }
        }
        while(p<m){
             nums1.push_back(temp[p]);
                p++;
        }
          while(q<n){
             nums1.push_back(nums2[q]);
            q++;
          }
    }
};