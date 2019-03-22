package Repository;


import Domain.PrgState;
import Domain.Statements.iStatement;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Repo implements iRepo {
    List<PrgState> prgList;
    String logFilePath;

    public Repo(String logFilePath) {
        this.prgList = new ArrayList<>();
        this.logFilePath = logFilePath;
    }

    @Override
    public void addPrg(PrgState prg) {
        prgList.add(prg);
    }

    @Override
    public PrgState getCrtPrg() {
        return this.prgList.get(prgList.size() - 1);
    }
    @Override
    public void logPrgStateExec() {
        try {
            File file = new File(logFilePath);
            if (!file.exists()) {
                file.createNewFile();
            }
            PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(file, true)));
            List<PrgState> auxProgramList = new ArrayList<>(prgList);
            exeStackContent(auxProgramList, logFile);
            symTableContent(auxProgramList, logFile);
            outContent(auxProgramList, logFile);
            logFile.println();
            logFile.println();
            logFile.println();
            logFile.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void exeStackContent(List<PrgState> auxProgramList, PrintWriter logFile) {
        logFile.println("Stack: ");
        List<iStatement> auxStatementList = new ArrayList<>();
        for (PrgState prgState : auxProgramList) {
            while (!prgState.getExeStack().isEmpty()) {
                iStatement statement = prgState.getExeStack().pop();
                logFile.println(statement.toString());
                auxStatementList.add(statement);
            }
            for(int i = auxStatementList.size()-1; i >= 0;i--){
                prgState.getExeStack().push(auxStatementList.get(i));
            }
        }
        logFile.println();
    }
    public void symTableContent(List<PrgState> auxProgramList, PrintWriter logFile) {
        logFile.println("Sym table: ");
        for (PrgState prgState : auxProgramList) {
            for (String key : prgState.getSymTable().keySet()) {
                logFile.println(key + " " + prgState.getSymTable().get(key));
            }
        }
        logFile.println();
    }
    public void outContent(List<PrgState> auxProgramList, PrintWriter logFile) {
        logFile.println("Out: ");
        for (PrgState prgState : auxProgramList) {
            for (int element : prgState.getOut().getList()) {
                logFile.println(element);
            }
        }
    }


}
