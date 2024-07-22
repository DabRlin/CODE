package experiment;

import java.util.List;
import java.util.Optional;

public class StudentManagementSystem {
    private List<Student> students;

    public StudentManagementSystem(List<Student> students) {
        this.students = students;
    }

    // 添加学生
    public void addStudent(Student student) {
        students.add(student);
    }

    // 删除学生
    public void deleteStudent(String name) {
        students.removeIf(student -> student.getName().equals(name));
    }

    // 更新学生信息
    public void updateStudent(String name, int newAge, double newGrade) {
        students.stream()
            .filter(student -> student.getName().equals(name))
            .findFirst()
            .ifPresent(student -> {
                student.setAge(newAge);
                student.setGrade(newGrade);
            });
    }

    // 根据姓名查找学生
    public Optional<Student> findStudentByName(String name) {
        return students.stream()
            .filter(student -> student.getName().equals(name))
            .findFirst();
    }
}
    