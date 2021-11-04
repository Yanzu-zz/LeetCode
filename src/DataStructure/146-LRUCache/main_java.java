import java.util.HashMap;

// 单个结点类
class Node {
    public int key, val;
    public Node prev, next;

    public Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class DoubleList {
    private int size;
    private Node head, tail;

    // 在链表头部添加节点 x，时间 O(1)
    public void addFirst(Node x) {
        if (head == null) {
            head = tail = x;
        } else {
            Node tmp = head;
            tmp.prev = x;
            x.next = tmp;
            head = x;
        }
        size++; // 记得要维护链表节点的数量
    }

    // 删除链表中的 x 节点（x 一定存在）
    // 由于是双链表且给的是目标 Node 节点，时间 O(1)
    public void remove(Node x) {
        if (head == x && tail == x) {
            head = null;
            tail = null;
        } else if (tail == x) {
            x.prev.next = null;
            tail = x.prev;
        } else if (head == x) {
            x.next.prev = null;
            head = x.next;
        } else {
            x.prev.next = x.next;
            x.next.prev = x.prev;
        }
        size--; // 维护
    }

    // 删除最后一个节点
    public Node removeLast() {
        Node last = tail;
        remove(tail);
        return last;
    }

    public int size() {
        return size;
    }
}

class LRUCache {
    // 利用哈希表就能 O(1) 时间定为到节点
    private HashMap<Integer, Node> map;
    private DoubleList cache;
    private int capacity;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        cache = new DoubleList();
        this.capacity = capacity;
    }

    public int get(int key) {
        if (!map.containsKey(key))
            return -1;

        int val = map.get(key).val;
        put(key, val);  // 把该节点 put 到最前面
        return val;
    }

    public void put(int key, int val) {
        // 先创建待添加的节点
        Node x = new Node(key, val);

        // 然后判断是否已经存在该节点了
        if (map.containsKey(key)) {
            // 删除旧的节点，新的插入头部
            cache.remove(map.get(key));
            cache.addFirst(x);
            map.put(key, x);
        } else { // 否则就添加
            // 记得判断容量是否爆满了
            if (cache.size() == capacity)
                map.remove(cache.removeLast().key);

            // 下面就是正常添加情况了
            cache.addFirst(x);
            map.put(key, x);
        }
    }
}