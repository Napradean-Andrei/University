package Controller;
import Domain.ADTs.iStack;
import Domain.Exception.MyException;
import Domain.PrgState;
import Domain.Statements.iStatement;
import Repository.*;

public class Controller {
    private iRepo repo;

    public Controller(iRepo repo){this.repo=repo;}

    public void oneStep(PrgState state) {
        iStack<iStatement> stk=state.getExeStack();
        iStatement crtStatement=stk.pop();
        crtStatement.execute(state);
        System.out.println(state);
    }

    public void allSteps() {
        PrgState prg=repo.getCrtPrg();
        while(!prg.getExeStack().isEmpty()){
            oneStep(prg);
            repo.logPrgStateExec();
        }
    }

}


