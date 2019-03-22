package Domain.Statements;
import Domain.Expressions.Expression;
import Domain.PrgState;
import Domain.ADTs.*;

public class PrintStatement implements iStatement {
    Expression exp;


    public PrintStatement(){};
    public PrintStatement(Expression exp){this.exp=exp;}

    @Override
    public PrgState execute(PrgState state) {
        iList<Integer> list=state.getOut();
        iDictionary<String,Integer> symTable=state.getSymTable();
        list.add(this.exp.eval(symTable));
        return state;
    }

    @Override
    public String toString(){
        return "Print(" +exp.toString()+")";
    }
}
