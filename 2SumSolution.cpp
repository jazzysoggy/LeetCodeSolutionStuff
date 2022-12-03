#include <vector>

int HASH_MAX = 10000;
unsigned int hash(unsigned int x)
{
    return x % HASH_MAX;
}

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> hashTable(HASH_MAX, std::vector<int>(0));
    for (int i = 0; i < nums.size(); i++)
    {
        hashTable[hash(nums[i])].push_back(i);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int hashed = hash(target - nums[i]);
        if (hashed < HASH_MAX)
        {
            for (int j = 0; j < hashTable[hashed].size(); j++)
            {
                if (hashTable[hashed][j] > nums.size() || hashTable[hashed][j] < 0)
                {
                    continue;
                }
                if (hashTable[hashed][j] == i)
                {
                    continue;
                }
                if (nums[hashTable[hashed][j]] + nums[i] == target)
                {
                    std::vector<int> result = {i, hashTable[hashed][j]};
                    return result;
                }
            }
        }
    }
    return {};
}