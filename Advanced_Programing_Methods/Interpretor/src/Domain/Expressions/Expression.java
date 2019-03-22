package Domain.Expressions;
import Domain.ADTs.*;

public abstract class Expression {

    public abstract int eval(iDictionary<String, Integer> table);

}
