class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        box = [0] * 46
        lo, id = lowLimit, 0
        while lo > 0:
            id += lo % 10
            lo //= 10
        box[id] += 1
        for i in range(lowLimit + 1, highLimit + 1):
            while i % 10 == 0:
                id -= 9
                i //= 10
            id += 1
            box[id] += 1
        return max(box)        