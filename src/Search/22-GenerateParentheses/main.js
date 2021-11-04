/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
  var ret = []
  dfs('', n, n)

  return ret;

  function dfs(str, left, right) {
    if (left === 0 && right === 0) {
      ret.push(str)
      return;
    }

    if (left > right)
      return

    if (left > 0)
      dfs(str + '(', left - 1, right)

    if (right > 0)
      dfs(str + ')', left, right - 1)
  }
};