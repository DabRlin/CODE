package Last;

import java.util.ArrayList;
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
    public void updateStudent(String name, int newAge) {
        students.stream()
            .filter(student -> student.getName().equals(name))
            .findFirst()
            .ifPresent(student -> {
                student.setAge(newAge);
            });
    }

    // 根据姓名查找学生
    public Optional<Student> findStudentByName(String name) {
        return students.stream()
            .filter(student -> student.getName().equals(name))
            .findFirst();
    }

    public static void main(String[] args) {
        // 创建学生列表
        List<Student> studentsList = new ArrayList<>();

        // 创建学生管理系统
        StudentManagementSystem studentSystem = new StudentManagementSystem(studentsList);

        // 添加学生

        // 删除学生
        studentSystem.deleteStudent("Alice");

        // 更新学生信息

        // 查找学生
        Optional<Student> foundStudent = studentSystem.findStudentByName("Charlie");
        foundStudent.ifPresent(student -> System.out.println("Found student: " + student));
    }
}
