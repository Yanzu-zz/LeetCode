/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  const n = strs.length
  // const mod = 1e9 + 7 // 模数
  const mod = 1610612741;
  const hashVal = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103] // 每个字母的哈希值
  const map = new Map()

  for (let i = 0; i < n; i++) {
    let hash = 1;
    for (let j = 0; j < strs[i].length; j++) {
      let num = strs[i].charCodeAt(j) - 97 // 获取 ASCII 码后减去小写字母初始值获得对应数字
      hash = ((hash % mod) * (hashVal[num] % mod)) % mod
    }

    if (!map.get(hash)) // 之前没得话就新开一个空间
      map.set(hash, [])
    map.get(hash).push(strs[i]) // 加入对应数组
  }

  return [...map.values()]
}