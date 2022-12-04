#include <vector>
#include <algorithm>

int HASH_MAX = 10000;
    unsigned int hash(uint64_t x)
    {
        static uint64_t m = (uint64_t(0xe9846af) << 32) + 0x9b1a615d;
        
        x ^= (x * m) >> 28;
        
        return x;
    }

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
       
        int HASH_MAX = int(0.5 * nums.size()) + 1;
        
        vector<vector<int>> hashTable(HASH_MAX, vector<int>(0));
        for (int i = 0; i < nums.size(); i++)
        {
            hashTable[hash(nums[i]) % HASH_MAX].push_back(i);
        }
     
        for (int i = 0; i < nums.size(); i++)
        {
            int hashed = hash(target - nums[i]) % HASH_MAX;
            if (hashed < HASH_MAX) {
                for (int j = 0; j < hashTable[hashed].size(); j++)
                {
                    if (hashTable[hashed][j] > nums.size() || hashTable[hashed][j] < 0)
                    {
                        continue;
                    }
                    if(hashTable[hashed][j] == i)
                    {
                        continue;
                    }
                    if (nums[hashTable[hashed][j]] + nums[i] == target)
                    {
                        vector<int> result = {i, hashTable[hashed][j]};          
                        return result;
                    }                    
                }
            } 
        }
        return {};
}

    struct myPair 
    {
        int number;
        int index;
        
        myPair (int number_ = 0)
        {
            number = number_;
        }
        
        bool operator== (const myPair& right) const
        {
            return number == right.number;
        }
        
        bool operator< (const myPair& right) const
        {
            return number < right.number;
        }
 
    };
    
vector<int> twoSumSort(vector<int>& nums, int target) {
        
        vector<myPair> numPairs(nums.size());
  
        for (int i = 0; i < nums.size(); i++)
        {
            auto &pair = numPairs[i];
            
            pair.number = nums[i];
            pair.index = i;
                  
        }
        
        
        
        std::sort(numPairs.begin(), numPairs.end());
        
        
        for (int i = 0; i < numPairs.size(); i++)
        {
            int numberOne = numPairs[i].number;
            int numberTwo = target - numberOne;
            
            
            myPair secTarget(target - numPairs[i].number);
            
            auto lower = lower_bound(numPairs.begin(), numPairs.end(), secTarget);
            
            if (lower == numPairs.end() || (*lower).number != numberTwo)
            {
            /*    if (lower != numPairs.end())
                    cout << "Number One:" << numberOne << "  Number Two:" << numberTwo << "  Failed Number Two:" << (*lower).number << endl;*/
                continue;
            }
            
            if (numberOne == numberTwo)
            {
                if ((++lower) == numPairs.end())
                {
                    continue;
                }
                if ((*lower).number != numberTwo)
                {
                    continue;
                }
            }
            
/*            cout << "Pair 1:  " << numPairs[i].number << "," << numPairs[i].index << "   Pair 2:  " << (*lower).number << "," << (*lower).index << std::endl;
            cout << "Number One:" << numberOne << "  Number Two:" << numberTwo << endl;*/
            return {numPairs[i].index, (*lower).index};
            
        }
        return {};
    }
