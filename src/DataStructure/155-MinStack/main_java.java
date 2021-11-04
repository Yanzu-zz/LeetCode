import java.util.Stack;

class MinStack {
    Stack<Integer> s = new Stack<>();
    Stack<Integer> min_s = new Stack<>(); // 辅助最小栈

    public MinStack() {
        min_s.push(Integer.MAX_VALUE);
    }

    public void push(int val) {
        s.push(val); // s 正常添加就行
        min_s.push(Math.min(val, min_s.peek())); // 添加当前层次最小的元素
    }

    public void pop() {
        s.pop();
        min_s.pop();
    }

    public int top() {
        return s.peek();
    }

    public int getMin() {
        return min_s.peek();
    }
}