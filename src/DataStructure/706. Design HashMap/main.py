class MyHashMap:

  def __init__(self):
    self.h = [-1] * 1_000_001

  def put(self, key: int, value: int) -> None:
    self.h[key] = value

  def get(self, key: int) -> int:
    return self.h[key]

  def remove(self, key: int) -> None:
    self.h[key] = -1

    # Your MyHashMap object will be instantiated and called as such:
    # obj = MyHashMap()
    # obj.put(key,value)
    # param_2 = obj.get(key)
    # obj.remove(key)
