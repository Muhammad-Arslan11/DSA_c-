
#include<iostream>
#include <unordered_map>
#include<string>
#include<vector>
using namespace std;



int main(){

   // create a hashmap
    unordered_map<string,int> map;

 // insertion
  
   //1
  //  map["Arslan"];
  //  map["Usman"] = 2;
  //  // 2
  //   pair<string,int> p = make_pair("Noman", 3);
  //   map.insert(p);
  //   map["Arslan"];
  //   map["Arslan"];

    // searching
    //  cout<< map["Arslan"]<<endl;
    //  cout<< map.at("Usman")<<endl;

     // try to access unknown entries
      //  cout<< map["unknown"]<<endl;  // this will check if this entry is available in the entries we provided
      //  // if not found, it will simply create a new entry with with value set as 0
      //  cout<< map.at("unknown")<<endl;  // however, This will not create a new entry. Instead, it will through an error if no entry corresponding to this key is found

     // deletion
    //  map.erase("Arslan");

     // check if the key has been removed
//       if(map.find("Arslan") == map.end()){
//  cout<< "The key has been removed :"<<endl;
//       }

      // how to iterate over a hashmap
      //  for(auto i: map){
      //   cout<< i.first <<" "<< i.second<<endl;
      //  }

      // how to check wether a particular item is available
        //  cout<< map.count("Arslan")<<endl;
       
       // make an iterator and iterate over the map
      //  unordered_map<string, int> :: iterator it = map.begin();

      //  while(it != map.end()){
      //   cout<< it ->first<< " "<< it->second<<endl;
      //   it++;
      //  }

      unordered_map<int,int> my_map;
 vector<int> arr = {1,2,4,6,8,1,1,2,2,6,6};

 for( int i= 0; i<arr.size(); i++){
         my_map[arr[i]]++;
 }

 for( int i= 0; i<arr.size(); i++){
       cout<<my_map[arr[i]];
 }
 
          


    return 0; 
}







