package Domain;

import Domain.ADTs.iDictionary;
import Domain.ADTs.iList;
import Domain.ADTs.iStack;
import Domain.Statements.iStatement;

public class PrgState {
    iStack<iStatement> exeStack;
    iDictionary<String, Integer> symTable;
    iList<Integer> out;

    public PrgState(iStack<iStatement> stk, iDictionary<String, Integer> symTable, iList<Integer> out, iStatement prg) {
        this.exeStack = stk;
        this.symTable = symTable;
        this.out = out;
        stk.push(prg);
    }

    public iStack<iStatement> getExeStack() {
        return this.exeStack;
    }

    public iDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public iList<Integer> getOut() {
        return this.out;
    }



    @Override
    public String toString() {
        return "PrgState{\n" + "exeStack=" + exeStack.toString() + "symTable=" + symTable.toString() + "out=" + out.toString() + "\n";
    }
}
