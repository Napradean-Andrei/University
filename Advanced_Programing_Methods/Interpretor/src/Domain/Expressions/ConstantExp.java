package Domain.Expressions;

import Domain.ADTs.iDictionary;

public class ConstantExp extends Expression {
    int number;

    public ConstantExp(int number){this.number=number;}



    @Override
    public int eval(iDictionary<String, Integer> table) {
        return this.number;
    }

    @Override
    public String toString() {
        return "ConstantExp{" +
                "number=" + number +
                '}';
    }
}
