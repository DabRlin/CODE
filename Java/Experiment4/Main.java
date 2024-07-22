package Experiment4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // 创建一个学生管理系统对象
        StudentManagementSystem system = new StudentManagementSystem();

        // 添加几个示例学生
        Student student1 = new Student("1001", "张三", "男", 20, "ClassA", 85.5);
        Student student2 = new Student("1002", "李四", "女", 22, "ClassB", 78.9);
        system.addStudent(student1);
        system.addStudent(student2);

        // 用户交互示例
        Scanner scanner = new Scanner(System.in);
        boolean isRunning = true;

        while (isRunning) {
            System.out.println("欢迎使用学生管理系统");
            System.out.println("1. 添加学生");
            System.out.println("2. 删除学生");
            System.out.println("3. 查询学生");
            System.out.println("4. 更新学生信息");
            System.out.println("5. 退出系统");
            System.out.print("请选择操作：");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline character

            switch (choice) {
                case 1:
                    // 添加学生信息
                    System.out.print("请输入学号：");
                    String ID = scanner.nextLine();
                    System.out.print("请输入姓名：");
                    String name = scanner.nextLine();
                    System.out.print("请输入性别：");
                    String gender = scanner.nextLine();
                    System.out.print("请输入年龄：");
                    int age = scanner.nextInt();
                    scanner.nextLine(); // Consume newline character
                    System.out.print("请输入班级：");
                    String className = scanner.nextLine();
                    System.out.print("请输入学分绩：");
                    double creditScore = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline character

                    Student newStudent = new Student(ID, name, gender, age, className, creditScore);
                    system.addStudent(newStudent);
                    System.out.println("学生添加成功！");
                    break;

                case 2:
                    // 删除学生信息
                    System.out.print("请输入要删除学生的学号：");
                    String deleteID = scanner.nextLine();
                    system.deleteStudentByID(deleteID);
                    System.out.println("学生删除成功！");
                    break;

                case 3:
                    // 查询学生信息
                    System.out.print("请输入要查询学生的学号：");
                    String searchID = scanner.nextLine();
                    Student searchedStudent = system.searchStudentByID(searchID);
                    if (searchedStudent != null) {
                        System.out.println("查询结果：");
                        System.out.println(searchedStudent.toString()); // Assuming a toString method in Student class
                    } else {
                        System.out.println("未找到该学生！");
                    }
                    break;

                case 4:
                    // 更新学生信息
                    System.out.print("请输入要更新学生的学号：");
                    String updateID = scanner.nextLine();
                    System.out.print("请输入新的姓名：");
                    String newName = scanner.nextLine();
                    System.out.print("请输入新的性别：");
                    String newGender = scanner.nextLine();
                    System.out.print("请输入新的年龄：");
                    int newAge = scanner.nextInt();
                    scanner.nextLine(); // Consume newline character
                    System.out.print("请输入新的班级：");
                    String newClassName = scanner.nextLine();
                    System.out.print("请输入新的学分绩：");
                    double newCreditScore = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline character

                    system.updateStudentInfo(updateID, newName, newGender, newAge, newClassName, newCreditScore);
                    System.out.println("学生信息更新成功！");
                    break;

                case 5:
                    isRunning = false;
                    break;

                default:
                    System.out.println("请输入有效的操作编号！");
                    break;
            }
        }

        // 关闭输入流
        scanner.close();
        System.out.println("感谢使用学生管理系统！");
    }
}
