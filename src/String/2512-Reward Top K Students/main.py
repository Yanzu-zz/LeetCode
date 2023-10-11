class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str],
                    student_id: List[int], k: int) -> List[int]:
        # 哈希表记录加分和减分值
        pos_s = set(positive_feedback)
        neg_s = set(negative_feedback)
        score = [[stu, 0] for stu in student_id]

        # 一个词一个词判断是否加减分
        for i, str in enumerate(report):
            pos_score = sum([w in pos_s for w in str.split()])
            neg_score = sum([w in neg_s for w in str.split()])
            score[i][1] = pos_score * 3 - neg_score

        # 接着按照分数排序
        score.sort(key=lambda x: (-x[1], x[0]))
        # 取 top-k 个
        return [i for i, j in score[:k]]
