class FindElements:
  def __init__(self, root: Optional[TreeNode]):
    self.s = set()

    def _preorder(root, val):
      if root is None:
        return

      self.s.add(val)
      _preorder(root.left, val * 2 + 1)
      _preorder(root.right, val * 2 + 2)

    _preorder(root, 0)

  def find(self, target: int) -> bool:
    return target in self.s
