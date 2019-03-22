package Domain.Statements;

import Domain.PrgState;

import Domain.ADTs.*;

public class CompSt implements iStatement {
    iStatement first;
    iStatement second;

    public CompSt(AssgSt a){};

    public CompSt(iStatement first, iStatement second){
        this.first=first;
        this.second=second;
    }

    @Override
    public PrgState execute(PrgState state) {
        iStack<iStatement> stk=state.getExeStack();
        stk.push(second);
        stk.push(first);
        return state;

    }

    @Override
    public String toString(){
        return "("+first.toString()+";"+second.toString()+")";
    }
}
