package Domain.ADTs;

import java.util.List;

public interface iDictionary<K,V> {

    void add(K key,V value);
    V get(K key);
    String toString();
    boolean isDefined(K key);
    void update(K k,V v);
    List<String> keySet();

}
