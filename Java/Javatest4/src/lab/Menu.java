package lab;
import java.util.Scanner;

import java.util.*;

public class Menu {
    private Scanner input = null;
    private boolean flag = true;
    private boolean flag2;

    StudentManagementSystem SMS = new StudentManagementSystem(new ArrayList<>());

    public Menu() {
        this.input = new Scanner(System.in);

        while (this.flag) {
            this.showStudent();
        }
    }

    public void showStream() {
        System.out.println("            学生信息管理                 ");
        System.out.println("           1、根据班级排序               ");
        System.out.println("           2、根据学分绩排序              ");
        System.out.println("           3、根据年龄排序               ");
        System.out.println("           4、所有姓？的学生列表           ");
        System.out.println("           5、GPA低于2.0的学生列表        ");
        System.out.println("           6、每个班级的平均GPA           ");
        System.out.println("           7、每个班级GPA最高的学生信息     ");
        System.out.println("           8、返回上一层                 ");
        System.out.println("\n\n请选择具体的操作：");
        switch (this.input.nextInt()) {
            case 1: {
                System.out.println("是否取代原表？(Y/N)");
                String ok = this.input.next();
                SMS.SortByClass((Objects.equals(ok, "Y")) | (Objects.equals(ok, "y")));
                break;
            }
            case 2: {
                System.out.println("是否取代原表？(Y/N)");
                String ok = this.input.next();
                SMS.SortByGpa((Objects.equals(ok, "Y")) | (Objects.equals(ok, "y")));
                break;
            }
            case 3: {
                System.out.println("是否取代原表？(Y/N)");
                String ok = this.input.next();
                SMS.SortByAge((Objects.equals(ok, "Y")) | (Objects.equals(ok, "y")));
                break;
            }
            case 4: {
                System.out.println("请输入姓氏：");
                String S = this.input.next();
                SMS.FindSecondName(S);
                break;
            }
            case 5: {
                SMS.FindGPALowThan2();
                break;
            }
            case 6: {
                SMS.CalcAveGpaByClass();
                break;
            }
            case 7: {
                SMS.FindMaxGpaByClass();
                break;
            }
            case 8: {
                flag2 = false;
                break;
            }
            default: {
                System.out.println("      选择错误，请重新选择！");
                break;
            }
        }
    }


    // 显示学生操作的菜单
    public void showStudent() {

        System.out.println("            学生信息管理                 ");
        System.out.println("           1、增加学生信息               ");
        System.out.println("           2、列出全部学生信息           ");
        System.out.println("           3、查询学生信息               ");
        System.out.println("           4、删除学生信息               ");
        System.out.println("           5、修改学生信息               ");
        System.out.println("           6、更多查看操作(streamApi)    ");
        System.out.println("           7、从本地csv文件导入学生信息    ");
        System.out.println("           8、将学生信息导出到本地        ");
        System.out.println("           9、退出                     ");
        System.out.println("\n\n请选择具体的操作：");
        switch (this.input.nextInt()) {
            case 1: {
                //add
                System.out.print("输入学生学号：");
                int id = this.input.nextInt();
                System.out.print("输入学生姓名：");
                String name = this.input.next();
                System.out.print("输入学生年龄：");
                int age = this.input.nextInt();
                System.out.print("输入学生成绩：");
                double score = this.input.nextDouble();
                System.out.print("输入学生班级：");
                int classId = this.input.nextInt();
                System.out.print("输入学生性别(M/F)：");
                String gender = this.input.next();
                if(!Objects.equals(gender, "M") | !Objects.equals(gender, "F")) gender = "M";
                Student student = new Student(id, age, name, gender, classId, score);
                SMS.addStudent(student);
                System.out.println("添加成功");
                break;
            }
            case 2: {
                //find all
                for(Student i : SMS.findAll()){
                    System.out.println(i);
                }
                break;
            }
            case 3: {
                //find by id
                System.out.print("输入学生学号：");
                int id = this.input.nextInt();
                Optional<Student> stu = SMS.findStudentById(id);
                System.out.println(stu);
                break;
            }
            case 4: {
                //delete
                System.out.print("输入学生学号：");
                int id = this.input.nextInt();
                SMS.deleteStudent(id);
                System.out.println("已删除");
                break;
            }
            case 5: {
                //update
                System.out.print("输入学生学号：");
                int id = this.input.nextInt();
                System.out.println("当前学生为："+SMS.findStudentById(id));

                System.out.print("输入修改后的学生姓名：");
                String name = this.input.next();
                System.out.print("输入修改后的学生年龄：");
                int age = this.input.nextInt();
                System.out.print("输入修改后的学生性别：");
                String gender = this.input.next();
                System.out.print("输入修改后的学生班级：");
                int classId = this.input.nextInt();
                System.out.print("输入修改后的学生成绩：");
                double score = this.input.nextDouble();

                SMS.updateStudent(id, name, age, gender, classId, score);
                System.out.println("修改成功");
                break;
            }
            case 6: {
                //stream Api
                flag2 = true;
                while(flag2){
                    showStream();
                }
                break;
            }
            case 7: {
                //file in
                List<Student> studentList = new ArrayList<>();
                try {
                    FileIO.loadStudent(studentList);
                } catch (Exception e) {
                    System.out.println("导入失败");
                    throw new RuntimeException(e);
                }
                SMS = new StudentManagementSystem(studentList);
                System.out.println("导入成功");
                break;
            }
            case 8: {
                //file out
                try {
                    FileIO.saveStudent(SMS.findAll());
                } catch (Exception e) {
                    System.out.println("导出失败");
                    throw new RuntimeException(e);
                }
                System.out.println("导出成功");
                break;
            }
            case 9: {
                this.flag = false;
                break;
            }
            default: {
                System.out.println("      选择错误，请重新选择！");
                break;
            }
        }
    }


    public static void main(String[] args) {
        new Menu();
    }
}
