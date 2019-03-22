package Domain.ADTs;

public interface iStack<T> {

    void push(T x);
    T pop();
    boolean isEmpty();
    String toString();

}
