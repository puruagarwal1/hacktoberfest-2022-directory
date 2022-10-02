# solution for the classic leetcode problem, two sum in O(n) runtime in python
def twoSum(nums, target)
  # hashmap for each num
  hmap = {}
  # adding each num to hashmap
  for i in range(len(nums)):
    hmap[nums[i]] = i
  # checking to see if the compliment exists
  for i in range(len(nums)):
            comp = target - nums[i]
            if comp in hmap and hmap[comp] != i:
                return [i, hmap[comp]]
