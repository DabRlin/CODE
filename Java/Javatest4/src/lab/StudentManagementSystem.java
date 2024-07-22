package lab;

import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.function.BinaryOperator;
import java.util.function.Function;

import static java.util.stream.Collectors.*;

public class StudentManagementSystem implements StreamAPI{
    private List<Student> students;

    public StudentManagementSystem(List<Student> students) {
        this.students = students;
    }

    public void addStudent(Student student) {
        students.add(student);
    }
    
    public void deleteStudent(int id) {
        students.removeIf(student -> student.getId() == id);
    }

    public Optional<Student> findStudentById(int id) {
        return students.stream()
                .filter(student -> student.getId() == id)
                .findFirst();
    }

    public List<Student> findAll(){
        return students;
    }

    public void updateStudent(int id, String newName, int newAge, String newGender, int newClassId, double newGPA) {
        students.stream()
                .filter(student -> student.getId() == id)
                .findFirst()
                .ifPresent(student -> {
                    student.setName(newName);
                    student.setAge(newAge);
                    student.setGender(newGender);
                    student.setClassId(newClassId);
                    student.setGPA(newGPA);
                });
    }

    public static void main(String[] args) {

    }

    @Override
    public void SortByClass(boolean Inplace) {
        List<Student> stu = students.stream()
                .sorted(Comparator.comparing(Student::getClassId))
                .toList();
        if(Inplace){
            students = stu;
        }
        for(Student i : stu){
            System.out.println(i);
        }

    }

    @Override
    public void SortByGpa(boolean Inplace) {
        List<Student> stu = students.stream()
                .sorted(Comparator.comparing(Student::getGPA).reversed())
                .toList();
        if(Inplace){
            students = stu;
        }
        for(Student i : stu){
            System.out.println(i);
        }
    }

    @Override
    public void SortByAge(boolean Inplace) {
        List<Student> stu = students.stream()
                .sorted(Comparator.comparing(Student::getAge))
                .toList();
        if(Inplace){
            students = stu;
        }
        for(Student i : stu){
            System.out.println(i);
        }

    }

    @Override
    public void FindSecondName(String Second) {
        List<Student> stu = students.stream()
                .filter(student -> student.getName().startsWith(Second))
                .toList();

        for(Student i : stu){
            System.out.println(i);
        }
    }

    @Override
    public void FindGPALowThan2() {
        List<Student> stu = students.stream()
                .filter(student -> student.getGPA() < 2.0)
                .toList();

        for(Student i : stu){
            System.out.println(i);
        }
    }

    @Override
    public void CalcAveGpaByClass() {
        students.stream().collect(groupingBy(Student::getClassId)).forEach((k, v)->{
            double ave = v.stream()
                    .mapToDouble(Student::getGPA)
                    .average()
                    .orElse(0.0);

            System.out.printf("班级%d的平均成绩为：%f\n", k, ave);
        });
    }

    @Override
    public void FindMaxGpaByClass() {
        students.stream().collect(toMap(Student::getClassId, Function.identity(),
                BinaryOperator.maxBy(Comparator.comparingDouble(Student::getGPA))))
                .forEach((k, v)-> System.out.printf("班级%d的最高成绩的学生信息：" + v + "\n", k));
    }
}