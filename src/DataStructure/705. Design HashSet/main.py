class MyHashSet:

  def __init__(self):
    self.h = [False] * 1_000_001

  def add(self, key: int) -> None:
    self.h[key] = True

  def remove(self, key: int) -> None:
    self.h[key] = False

  def contains(self, key: int) -> bool:
    return self.h[key]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
