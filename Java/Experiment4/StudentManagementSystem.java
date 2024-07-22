package Experiment4;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class StudentManagementSystem {
    private List<Student> studentList;

    public StudentManagementSystem() {
        this.studentList = new ArrayList<>();
    }

    public void addStudent(Student student) {
        studentList.add(student);
    }

    public void deleteStudentByID(String ID) {
        for (Student student : studentList) {
            if (student.getID().equals(ID)) {
                studentList.remove(student);
                break;
            }
        }
    }

    public Student searchStudentByID(String ID) {
        for (Student student : studentList) {
            if (student.getID().equals(ID)) {
                return student;
            }
        }
        return null;
    }

    public void updateStudentInfo(String ID, String newName, String newGender, int newAge, String newClassName, double newCreditScore) {
        for (Student student : studentList) {
            if (student.getID().equals(ID)) {
                student.setName(newName);
                student.setGender(newGender);
                student.setAge(newAge);
                student.setClassName(newClassName);
                student.setCreditScore(newCreditScore);
                break;
            }
        }
    }
    public void loadStudentsFromCSV(String filePath) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            boolean headerSkipped = false; // 跳过CSV文件头部

            while ((line = reader.readLine()) != null) {
                if (!headerSkipped) {
                    headerSkipped = true;
                    continue;
                }

                // 按逗号分割CSV行数据
                String[] data = line.split(",");
                if (data.length == 6) {
                    // 创建学生对象并添加到学生列表中
                    Student student = new Student(data[0], data[1], data[2], Integer.parseInt(data[3]), data[4], Double.parseDouble(data[5]));
                    studentList.add(student);
                }
            }

            System.out.println("学生信息已成功从CSV文件加载！");
        } catch (IOException e) {
            System.out.println("加载CSV文件时出错：" + e.getMessage());
        }
    }

    // Other methods for file I/O, user interaction, etc.
}
