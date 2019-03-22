package Repository;

import Domain.PrgState;

public interface iRepo {
    PrgState getCrtPrg();
    void addPrg(PrgState prg);
    void logPrgStateExec();

}
