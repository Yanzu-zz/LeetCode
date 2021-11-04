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
}