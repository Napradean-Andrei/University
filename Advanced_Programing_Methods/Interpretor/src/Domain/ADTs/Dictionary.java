package Domain.ADTs;




import javax.management.openmbean.KeyAlreadyExistsException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;

public class Dictionary<K,V> implements iDictionary<K,V>{

    private HashMap<K,V> dictionary;

    public Dictionary(){this.dictionary=new HashMap<K,V>();}


    @Override
    public void add(K key, V value) {
        if(key == null || value ==null)
            throw new NullPointerException("The values are null");
        if(dictionary.containsKey(key))
            throw new KeyAlreadyExistsException("Element already in the dictionary");
        this.dictionary.put(key,value);

    }


    @Override
    public V get(K key) {
        return this.dictionary.get(key);
    }

    @Override
    public List<String> keySet(){
        List<String> l= new ArrayList<String>((Collection<? extends String>) dictionary.keySet());
        return l;
    }

    @Override
    public String toString(){
        String dct="";
        for(HashMap.Entry<K,V> element: this.dictionary.entrySet()){
            dct=dct+"Key: "+element.getKey().toString()+" "+"Value: "+element.getValue().toString()+"\n";
        }
        return dct;
    }

    @Override
    public boolean isDefined(K key)
    {
        return this.dictionary.containsKey(key);
    }

    @Override
    public void update(K new_key,V new_value){
        this.dictionary.put(new_key,new_value);
    }
}
