// =============================================================================
/* Brute Force: 
 * time complexity: O(n^2)
 * space complexity: O(1)
 */
// =============================================================================
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            for(int i = 0; i < nums.size(); i++) {
                int rest = target - nums[i];
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[j] == rest){
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
            }
            return res;
        }
};
/*
Runtime: 388 ms, faster than 33.50% of C++ online submissions for Two Sum.
Memory Usage: 9.2 MB, less than 83.09% of C++ online submissions for Two Sum.
 */



// =============================================================================
/* two-pass hash table 
 * time complexity: O(n)
 * space complexity: O(n)
 */
// =============================================================================
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash;

            for(int i = 0; i < nums.size(); i++){            
                hash[nums[i]] = i;
            }

            for(int i = 0; ; ++i){
                auto it = hash.find(target - nums[i]);

                if(it != hash.end() && i != it->second)
                    return vector<int> {it->second, i};

            }

        }
};
/*
Runtime: 16 ms, faster than 83.48% of C++ online submissions for Two Sum.
Memory Usage: 10.3 MB, less than 22.67% of C++ online submissions for Two Sum.
 */



// =============================================================================
/* one-pass hash table 
 * time complexity: O(n)
 * space complexity: O(n)
 */
// =============================================================================
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash;

            for(int i = 0; ; ++i){
                auto it = hash.find(target - nums[i]);

                if(it != hash.end())
                    return vector<int> {it->second, i};

                hash[nums[i]] = i;
            }

        }
};
/*
Runtime: 16 ms, faster than 83.48% of C++ online submissions for Two Sum.
Memory Usage: 10.2 MB, less than 35.95% of C++ online submissions for Two Sum.
 */
