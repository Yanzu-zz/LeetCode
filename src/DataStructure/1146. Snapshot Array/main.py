class SnapshotArray:

  def __init__(self, length: int):
    self.snap_id = 0
    # 用一个字典记录这个index修改过的历史，因为是不可逆，所以自然就是有序的
    self.history = defaultdict(list)

  def set(self, index: int, val: int) -> None:
    self.history[index].append((self.snap_id, val))

  def snap(self) -> int:
    self.snap_id += 1
    return self.snap_id - 1

  def get(self, index: int, snap_id: int) -> int:
    # 这里查找 snap_id + 1 是因为一个快照期间可能调用多次 set 修改同一个地方的值
    # 所以只需要拿到最后一次被修改的值就行（也就是 -1index）
    j = bisect_left(self.history[index], (snap_id+1,)) - 1
    return self.history[index][j][1] if j >= 0 else 0
