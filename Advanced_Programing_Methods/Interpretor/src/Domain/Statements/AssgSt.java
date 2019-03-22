package Domain.Statements;

import Domain.ADTs.iDictionary;
import Domain.Expressions.Expression;
import Domain.PrgState;

public class AssgSt implements iStatement {
    private String id;
    private Expression expr;

    public AssgSt(String id, Expression expr) {
        this.id = id;
        this.expr = expr;
    }

    @Override
    public PrgState execute(PrgState state) {
        iDictionary<String, Integer> symTable = state.getSymTable();
        int val = expr.eval(symTable);
        if (symTable.isDefined(id))
            symTable.update(id, val);
        else
            symTable.add(id, val);
        return state;
    }

    @Override
    public String toString() {
        return "AssgSt{" +
                "id= " + id + ' ' +
                ", expr= " + expr +
                '}';
    }
}
