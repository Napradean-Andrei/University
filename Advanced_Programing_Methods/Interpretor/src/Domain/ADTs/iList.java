package Domain.ADTs;

import java.util.ArrayList;

public interface iList<L> {

    void add(L l);
    void delete(L l);
    String toString();
    ArrayList<L> getList();
}
