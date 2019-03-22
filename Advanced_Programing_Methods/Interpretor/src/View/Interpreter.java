package View;
import Domain.ADTs.*;
import Domain.Expressions.ArithmeticEx;
import Domain.Expressions.ConstantExp;
import Domain.Expressions.VarExp;
import Domain.Statements.*;
import Repository.*;
import Controller.*;
import Domain.*;




public class Interpreter {
    public static void main(String[] args) {


        iStatement ex1 = new CompSt(new AssgSt("a", new ConstantExp(2)), new PrintStatement(new VarExp("a")));

        iStack<iStatement> exeStack1 = new MyStack<>();
        iDictionary<String, Integer> symTable1 = new Dictionary<>();
        iList<Integer> out1 = new MyList<>();

        PrgState prg1 = new PrgState(exeStack1, symTable1, out1, ex1);

        Repo repo1 = new Repo("D:\\Laboratory_3\\src\\Log.txt");
        repo1.addPrg(prg1);

        Controller ctr1 = new Controller(repo1);


        iStatement ex2 = new CompSt(new AssgSt("a", new ArithmeticEx(new ConstantExp(2),
                new ArithmeticEx(new ConstantExp(3), new ConstantExp(5), "*"), "+")),
                new CompSt(new AssgSt("b", new ArithmeticEx(new VarExp("a"), new ConstantExp(1), "+")),
                        new PrintStatement(new VarExp("b"))));

        iStack<iStatement> exeStack2 = new MyStack<>();
        iDictionary<String, Integer> symTable2 = new Dictionary<>();
        iList<Integer> out2 = new MyList<>();

        PrgState prg2 = new PrgState(exeStack2, symTable2, out2, ex2);

        Repo repo2 = new Repo("D:\\Laboratory_3\\src\\Log.txt");
        repo2.addPrg(prg2);

        Controller ctr2 = new Controller(repo2);


        iStatement ex3 = new CompSt(new AssgSt("a", new ArithmeticEx(new ConstantExp(2), new ConstantExp(2), "-")),
                new CompSt(new IfSt(new VarExp("a"), new AssgSt("v", new ConstantExp(2)), new AssgSt("v", new ConstantExp(3))),
                        new PrintStatement(new VarExp("v"))));

        iStack<iStatement> exeStack3 = new MyStack<>();
        iDictionary<String, Integer> symTable3 = new Dictionary<>();
        iList<Integer> out3 = new MyList<>();

        PrgState prg3 = new PrgState(exeStack3, symTable3, out3, ex3);

        Repo repo3 = new Repo("D:\\Laboratory_3\\src\\Log.txt");
        repo3.addPrg(prg3);

        Controller ctr3 = new Controller(repo3);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", "v=2;" + " Print(v) "+ ex1.toString(), ctr1));
        menu.addCommand(new RunExample("2", "a=2+3*5;" + " b=a-4/2 + 7;" + " Print(b) "+ ex2.toString(), ctr2));
        menu.addCommand(new RunExample("3", "a=2-2; If a Then v=2 Else v=3; Print(v)"+ ex3.toString(), ctr3));
        menu.show();

    }
}
