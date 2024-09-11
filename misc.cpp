
#include<iostream>

#include<vector>
using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;
        
        // Iterate through the gain array
        for(int i = 0; i < gain.size(); ++i) {
            currentAltitude += gain[i];
            // cout<<"current Altitude at step "<<i+1<<" "<<currentAltitude<<endl;
            if(currentAltitude > maxAltitude) {
                maxAltitude = currentAltitude;
            }
        }
        
        return maxAltitude;
    }
};


int main(){
 
  vector<int> arr = {-5,1,5,0,-7};
  vector<int> arr1 = {-4,-3,-2,-1,4,3,2};

 Solution s1;
 s1.largestAltitude(arr);
//  s1.largestAltitude(arr1);
 
    return 0;
}
