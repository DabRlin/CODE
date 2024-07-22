package gaonan;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.io.BufferedReader;
import java.io.FileReader;

public class StudentManagementSystem {
    private List<Student> students;

    public StudentManagementSystem() {
        this.students = new ArrayList<>();
    }

    public void addStudent(Student student) {
        students.add(student);
    }

    public boolean deleteStudent(int id) {
        return students.removeIf(student -> student.getId() == id);
    }

    public void updateStudent(int id, String name, String gender, int age, String className, double gpa) {
        students.stream()
                .filter(student -> student.getId() == id)
                .findFirst()
                .ifPresent(student -> {
                    student.setName(name);
                    student.setGender(gender);
                    student.setAge(age);
                    student.setClassName(className);
                    student.setGpa(gpa);
                });
    }

    public Student findStudentById(int id) {
        return students.stream()
                .filter(student -> student.getId() == id)
                .findFirst()
                .orElse(null);
    }

    public void listAllStudents() {
        students.forEach(student -> System.out.println(student.getId() + " " + student.getName()));
    }

    public List<Student> sortByClassName() {
        return students.stream()
                .sorted(Comparator.comparing(Student::getClassName))
                .collect(Collectors.toList());
    }

    public List<Student> sortByGpa() {
        return students.stream()
                .sorted(Comparator.comparingDouble(Student::getGpa))
                .collect(Collectors.toList());
    }

    public List<Student> sortByAge() {
        return students.stream()
                .sorted(Comparator.comparingInt(Student::getAge))
                .collect(Collectors.toList());
    }

    public List<Student> filterLiAndLowGpa() {
        Predicate<Student> lastNameIsLi = student -> student.getName().startsWith("李");
        Predicate<Student> lowGpa = student -> student.getGpa() < 2.0;

        return students.stream()
                .filter(lastNameIsLi.and(lowGpa))
                .collect(Collectors.toList());
    }

    public Map<String, Double> averageGpaByClassName() {
        return students.stream()
                .collect(Collectors.groupingBy(Student::getClassName, Collectors.averagingDouble(Student::getGpa)));
    }

    public Map<String, Student> topGpaByClassName() {
        return students.stream()
                .collect(Collectors.groupingBy(Student::getClassName,
                        Collectors.collectingAndThen(
                                Collectors.maxBy(Comparator.comparingDouble(Student::getGpa)),
                                Optional::get
                        )
                ));
    }

    public void exportToCSV(String fileName) {
        String filePath = "D:\\小韩来学Java\\streamapi\\" + fileName + ".csv";

        try {
            java.nio.file.Path path = Paths.get(filePath);
            if (!Files.exists(path.getParent())) {
                Files.createDirectories(path.getParent());
            }

            try (PrintWriter writer = new PrintWriter(new FileWriter(filePath))) {
                writer.println("ID,Name,Gender,Age,ClassName,GPA");

                for (Student student : students) {
                    writer.println(student.getId() + "," + student.getName() + "," + student.getGender() + ","
                            + student.getAge() + "," + student.getClassName() + "," + student.getGpa());
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void importFromCSV(String filePath) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            // 读取 CSV 文件的标题行，通常第一行是列名
            line = reader.readLine();

            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");
                if (data.length == 6) {
                    int id = Integer.parseInt(data[0]);
                    String name = data[1];
                    String gender = data[2];
                    int age = Integer.parseInt(data[3]);
                    String className = data[4];
                    double gpa = Double.parseDouble(data[5]);

                    Student student = new Student(id, name, gender, age, className, gpa);
                    addStudent(student);
                } else {
                    System.out.println("CSV 文件格式错误: " + line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        StudentManagementSystem system = new StudentManagementSystem();
        Menu menu = new Menu(system);
        menu.showMenu();
    }
}
