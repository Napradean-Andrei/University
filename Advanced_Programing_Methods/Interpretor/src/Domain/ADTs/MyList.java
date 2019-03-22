package Domain.ADTs;

import java.util.ArrayList;


public class MyList<L> implements iList<L> {

    private ArrayList<L> list;

    public MyList(){this.list=new ArrayList<L>();}

    @Override
    public void add(L l) {
        this.list.add(l);
    }

    @Override
    public void delete(L l) {
        this.delete(l);
    }


    public ArrayList<L> getList(){return list;}

    @Override
    public String toString(){
        String prt="";
        for(L elem: list){

            prt=prt+elem.toString()+"";

        }
     return prt;
    }
}
