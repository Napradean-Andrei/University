package Domain.ADTs;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

public class MyStack<T> implements iStack<T> {
    private Stack<T> stack;

    public MyStack(){this.stack=new Stack<T>();}


    @Override
    public void push(T x) {
        this.stack.push(x);

    }

    @Override
    public T pop() {
       return this.stack.pop();
    }

    @Override
    public boolean isEmpty() {
         return this.stack.isEmpty();
    }

    @Override
    public String toString(){
        StringBuilder stack = new StringBuilder();
        ArrayList<T> auxStack = new ArrayList<>(this.stack);
        Collections.reverse(auxStack); // reverse executable stack to look like a stack for printing
        for (T elem : auxStack)
            stack.append(elem.toString()).append("\n");
        return stack.toString();
    }

}
