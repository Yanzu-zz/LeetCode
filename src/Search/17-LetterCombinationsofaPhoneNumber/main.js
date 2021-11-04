/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  if (digits.length === 0) return []
  let numMap = new Map([
    ['0', ''],
    ['1', ''],
    ['2', 'abc'],
    ['3', 'def'],
    ['4', 'ghi'],
    ['5', 'jkl'],
    ['6', 'mno'],
    ['7', 'pqrs'],
    ['8', 'tuv'],
    ['9', 'wxyz']
  ])

  let ret = []
  dfs('', digits)

  return ret;


  function dfs(str, digit) {
    // 边界条件（一轮数字拼接完）
    if (digit.length === 0) {
      ret.push(str)
      return
    }

    // 拿到当前剩下数字字符串的第一个数字
    let currNumMapStr = numMap.get(digit[0])
    for (let i = 0; i < currNumMapStr.length; i++) {
      str += currNumMapStr[i]
      dfs(str, digit.slice(1))
      // 回溯
      str = str.slice(0, -1)
    }
  }
};