package university;

import java.util.ArrayList;
import java.util.List;

public class Student {
    private String name;
    private String fName;
    private List<Program> programs;

    public Student(String name, String fName) {
        this.name = name;
        this.fName = fName;
        this.programs = new ArrayList<>();
    }

    public boolean addProgram(Program program){
        if (isStudentEnrolledInProgramType(program.getProgramType())){
            return false;
        }
        return this.programs.add(program);
    }

    public boolean isStudentEnrolledInProgramType(ProgramType programType){
        for(Program program : this.programs){
            if (program.getProgramType().equals(programType))
                return true;
        }
        return false;
    }
}
