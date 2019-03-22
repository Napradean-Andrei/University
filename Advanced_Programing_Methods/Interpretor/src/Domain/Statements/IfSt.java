package Domain.Statements;

import Domain.Expressions.Expression;
import Domain.PrgState;
import Domain.ADTs.*;

public class IfSt implements iStatement {

    Expression exp;
    iStatement thenS;
    iStatement elseS;

    public IfSt(Expression exp,iStatement thenS,iStatement elseS){
        this.exp=exp;
        this.thenS=thenS;
        this.elseS=elseS;
    }

    @Override
    public String toString(){
        return "IF("+ exp.toString()+") THEN(" +thenS.toString()
            +")ELSE("+elseS.toString()+")";}

    @Override
    public PrgState execute(PrgState state) {
        iStack<iStatement> exeStack=state.getExeStack();
        iDictionary<String,Integer> symTable = state.getSymTable();
        if(this.exp.eval(symTable)!=0)
            exeStack.push(thenS);
        else
            exeStack.push(elseS);
        return state;


    }
}
