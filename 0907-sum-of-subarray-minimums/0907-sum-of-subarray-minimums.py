class Solution:
    def sumSubarrayMins(self, nums):
        MOD = 10**9 + 7
        stack = []
        res = 0
        prevsum = 0

        for index, value in enumerate(nums):
            count = 1
            while stack and stack[-1][0] >= value:
                v, c = stack.pop()
                count += c
                prevsum -= v * c
            stack.append((value, count))
            prevsum += value * count
            res += prevsum

        return res % MOD
