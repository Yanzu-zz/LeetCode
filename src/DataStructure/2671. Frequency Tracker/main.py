class FrequencyTracker:

    def __init__(self):
      self.num_cnt = Counter()
      self.frequency_cnt = Counter()


    def add(self, number: int) -> None:
      if self.frequency_cnt[self.num_cnt[number]] > 0:
        self.frequency_cnt[self.num_cnt[number]] -= 1

      self.num_cnt[number] += 1
      self.frequency_cnt[self.num_cnt[number]] += 1


    def deleteOne(self, number: int) -> None:
      if self.num_cnt[number] > 0:
        self.frequency_cnt[self.num_cnt[number]] -= 1
        self.num_cnt[number] -= 1
        self.frequency_cnt[self.num_cnt[number]] += 1


    def hasFrequency(self, frequency: int) -> bool:
      return self.frequency_cnt[frequency] > 0



# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)