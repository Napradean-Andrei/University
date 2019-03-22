package Domain.Expressions;

import Domain.ADTs.iDictionary;

public class ArithmeticEx extends Expression {
    Expression e1;
    Expression e2;
    String operator;

    public ArithmeticEx(Expression e1,Expression e2, String operator){
        this.e1=e1;
        this.e2=e2;
        this.operator=operator;
    }

    public Expression getExp1(){return this.e1;}
    public Expression getExp2(){return this.e2;}
    public String getOperator(){return this.operator;}



    @Override
    public int eval(iDictionary<String, Integer> table) {
        if(this.operator.equals("+")) return (e1.eval(table)+e2.eval(table));
        if(this.operator.equals("-")) return (e1.eval(table)-e2.eval(table));
        if(this.operator.equals("*")) return (e1.eval(table)*e2.eval(table));
        if(this.operator.equals("/")&&e2.eval(table)!=0) return (e1.eval(table)/e2.eval(table));
        return 0;
    }

    @Override
    public String toString() {
        return "ArithmeticEx{" +
                "e1= " + e1 +
                ", e2= " + e2 +
                ", operator= " + operator + '\'' +
                '}';
    }
}
