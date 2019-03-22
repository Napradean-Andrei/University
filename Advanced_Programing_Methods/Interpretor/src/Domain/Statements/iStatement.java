package Domain.Statements;
import Domain.PrgState;

public interface iStatement {
    String toString();
    PrgState execute(PrgState state);
}
