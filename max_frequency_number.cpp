

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int max_frequency_number(vector<int> &arr)
{

    unordered_map<int, int> myMap;

    int maxFreq = 0;
    int maxAns = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        myMap[arr[i]]++;
        maxFreq = max(maxFreq, myMap[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq == myMap[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main()
{

    vector<int> arr = {1,2,4,6,8,1,1,2,2,6,6};
   
    int ans = max_frequency_number(arr);
    cout<<ans<<endl;


    return 0;
}