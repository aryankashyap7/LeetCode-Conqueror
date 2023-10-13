class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        step1, step2 = 0, 0
        for i in range(len(cost)):
            step1, step2 = step2, cost[i] + min(step1, step2)
        return min(step1, step2)