class Trie {
    private Trie[] children;
    private boolean isEnd;

    public Trie() {
        children = new Trie[26];
        isEnd = false;
    }

    // 添加新的字符串进字典树
    public void insert(String word) {
        Trie node = this;
        for (int i = 0; i < word.length(); i++) {
            int chIdx = word.charAt(i) - 'a'; // 获取当前字母的顺序索引
            if (node.children[chIdx] == null)
                node.children[chIdx] = new Trie();
            node = node.children[chIdx];
        }
        node.isEnd = true;
    }

    // 搜索 word 是否在字典树中
    public boolean search(String word) {
        Trie res = searchPrefix(word);
        return res != null && res.isEnd;
    }

    // 搜索前缀 prefix 是否在字典树中
    public boolean startsWith(String prefix) {
        return searchPrefix(prefix) != null;
    }

    // 查询前缀子功能，和插入逻辑完全一致，只不过这里遇不到需要找的字符就返回 null
    private Trie searchPrefix(String prefix) {
        Trie node = this;
        for (int i = 0; i < prefix.length(); i++) {
            int chIdx = prefix.charAt(i) - 'a'; // 当前字符索引
            if (node.children[chIdx] == null)
                return null;

            node = node.children[chIdx];
        }

        return node;
    }

    public Trie[] getChildren() {
        return children;
    }

    public boolean isEnd() {
        return isEnd;
    }
}

class WordDictionary {
    Trie root;

    public WordDictionary() {
        root = new Trie();
    }

    public void addWord(String word) {
        root.insert(word);
    }

    public boolean search(String word) {
        return dfs(word, 0, root);
    }

    // 用深搜的思路做搜索（主要是解决 . 匹配的问题）
    private boolean dfs(String word, int currIdx, Trie node) {
        if (currIdx == word.length())
            return node.isEnd();

        char ch = word.charAt(currIdx);
        if (ch != '.') {
            Trie child = node.getChildren()[ch - 'a'];
            if (child != null && dfs(word, currIdx + 1, child))
                return true;
        } else { // 是 . 的情况
            // 我们暴力遍历26遍字符就行
            for (int i = 0; i < 26; i++) {
                Trie child = node.getChildren()[i];
                if (!child && dfs(word, currIdx + 1, child))
                    return true;
            }
        }
        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */