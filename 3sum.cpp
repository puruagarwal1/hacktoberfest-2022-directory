class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
         bool found = false;
 vector<int> vect;
        vector<vector<int>> ans;
    // sort array elements
    sort(arr.begin(), arr.end());
 int n=arr.size();
        int i=0;
    while(i<n-2)
    {
        // initialize left and right
        int l = i + 1;
        int r = n - 1;
        int x = arr[i];
        while (l < r)
        {
            int low=arr[l];
            int high=arr[r];
            if (x + arr[l] + arr[r] == 0)
            {
                // print elements if it's sum is zero
                vect.clear();
                vect.push_back(x);
                vect.push_back(arr[l]);
                vect.push_back(arr[r]);
                ans.push_back(vect);
                
               while(l<r && arr[l]==low)l++;
                while(r>l && arr[r]==high)r--;
               
            }
 
            // If sum of three elements is less
            // than zero then increment in left
            else if (x + arr[l] + arr[r] < 0)
            {
                while(l<r && arr[l]==low)l++;
            }
            // if sum is greater than zero than
            // decrement in right side
            else
            {
               while(r>l && arr[r]==high)r--;
            }
        }
        while(i<n-2 && arr[i]==x)i++;
    }
 
   return ans;
        
    }
};