package Domain.Expressions;

import Domain.ADTs.iDictionary;

public class VarExp extends Expression {

    private String id;

    public VarExp(){};
    public VarExp(String id){this.id=id;}




    @Override
    public int eval(iDictionary<String, Integer> symTable) {
        return symTable.get(id);
    }

    public String toString(){
        return this.id;
    }
}
