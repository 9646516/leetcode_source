// id:65866271
// runtime:88 ms
// memory:25.9 MB
// title:期望个数统计
// translatedTitle:期望个数统计
// questionId:1000086
// time:2020-04-25 18:08:34

class Solution:
    def expectNumber(self, scores: List[int]) -> int:
        return len(set(scores))