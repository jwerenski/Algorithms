#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Explanation of solution
// The brute force method of iterating [x1, ..., xn] to find indices such that xj + xk = target is O(N^2)
// Starting with i'th number iterate from i+1 to n, check sum, and if sum = target, return indices


// The shorter method is to use a map which maps each number in [x1, ..., xn] to its indice
// We iterate the list once and for each index, check if its compliment already exists in the map
// If it exists, return the indices


class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        vector<int> result;


        for(int i = 0; i < nums.size(); i++){
            int compliment = target - nums[i];

            if(m.find(compliment) != m.end()){
                result.push_back(m.find(compliment) -> second);
                result.push_back(i);
                break;
            } else {
                m[nums.at(i)] = i;
            }
        }
        return result;
    }
};


int main (){

    vector<int> v{ 1,3,5,7 };
    int target = 8;
    Solution s; 

    vector<int> soln = s.twoSum(v, target);



    if(soln.size() != 0){
        for(int value:soln){
            cout<<value<<" ";
        }
        cout<<endl;
        return 0;
    } else {
        cout << "No Solution Found" << endl;
    }

}


