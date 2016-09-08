class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums);
        result = 0
        for num in nums:
            if not num-1 in nums:
                count = 1
                while count+num in nums:
                    count += 1
                result = max(result, count)
        return result
            