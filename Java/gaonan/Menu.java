package gaonan;
import java.util.Scanner;

public class Menu {
    private Scanner scanner;
    private StudentManagementSystem system;

    public Menu(StudentManagementSystem system) {
        this.system = system;
        this.scanner = new Scanner(System.in);
    }

    public void showMenu() {
        while (true) {
            System.out.println("学生信息管理\n");
            System.out.println("1、增加学生信息 \n2、列出全部学生信息 \n3、查询学生信息 \n4、删除学生信息 \n5、修改学生信息 \n6、返回上一级菜单 \n");
            System.out.println("7、根据班级排序 \n8、根据学分绩排序 \n9、根据年龄排序 \n");
            System.out.println("10、所有姓李的学生列表GPA低于2.0的学生列表 \n11、每个班级的平均GPA \n12、每个班级GPA最高的学生信息 \n");
            System.out.println("13、支持数据导入 \n14、支持数据导出 \n");

            System.out.println("请选择具体的操作:\n");

            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    system.listAllStudents();
                    break;
                case 3:
                    findStudent();
                    break;
                case 4:
                    deleteStudent();
                    break;
                case 5:
                    updateStudent();
                    break;
                case 6:
                    return;
                case 7:
                    sortByClassName();
                    break;
                case 8:
                    sortByGpa();
                    break;
                case 9:
                    sortByAge();
                    break;
                case 10:
                    filterLiAndLowGpa();
                    break;
                case 11:
                    averageGpaByClassName();
                    break;
                case 12:
                    topGpaByClassName();
                    break;
                case 13:
                    importFromCSV();
                    break;
                case 14:
                    exportToCSV();
                    break;
                default:
                    System.out.println("选择错误，请重新选择！");
            }
        }
    }


    private void addStudent() {
        System.out.println("输入学生姓名:");
        String name = scanner.nextLine();

        System.out.println("输入学生性别:");
        String gender = scanner.nextLine();

        System.out.println("输入学生年龄:");
        int age = scanner.nextInt();

        System.out.println("输入学生班级:");
        scanner.nextLine(); // Consume the newline character
        String className = scanner.nextLine();

        System.out.println("输入学生学分绩:");
        double gpa = scanner.nextDouble();

        System.out.println("输入学生ID:");
        double id = scanner.nextDouble();

        Student student = new Student((int) id, name, gender, age, className, gpa);
        system.addStudent(student);

        System.out.println("学生信息添加成功！");
    }

    private void findStudent() {
        System.out.println("输入要查询的学生ID:");
        int id = scanner.nextInt();

        Student student = system.findStudentById(id);
        if (student != null) {
            System.out.println("找到学生：" + student.getName());
        } else {
            System.out.println("未找到该学生");
        }
    }

    private void deleteStudent() {
        System.out.println("输入要删除的学生ID:");
        int id = scanner.nextInt();

        if (system.deleteStudent(id)) {
            System.out.println("学生删除成功！");
        } else {
            System.out.println("未找到该学生");
        }
    }

    private void updateStudent() {
        System.out.println("输入要更新的学生ID:");
        int id = scanner.nextInt();

        Student student = system.findStudentById(id);
        if (student != null) {
            System.out.println("输入新的学生姓名:");
            String name = scanner.nextLine();

            System.out.println("输入新的学生性别:");
            String gender = scanner.nextLine();

            System.out.println("输入新的学生年龄:");
            int age = scanner.nextInt();

            System.out.println("输入新的学生班级:");
            scanner.nextLine();
            String className = scanner.nextLine();

            System.out.println("输入新的学生学分绩:");
            double gpa = scanner.nextDouble();

            system.updateStudent(id, name, gender, age, className, gpa);
            System.out.println("学生信息更新成功！");
        } else {
            System.out.println("未找到该学生");
        }
    }

    private void sortByClassName() {
        system.sortByClassName().forEach(student -> System.out.println(student.getId() + " " + student.getName()));
    }

    private void sortByGpa() {
        system.sortByGpa().forEach(student -> System.out.println(student.getId() + " " + student.getName()));
    }

    private void sortByAge() {
        system.sortByAge().forEach(student -> System.out.println(student.getId() + " " + student.getName()));
    }

    private void filterLiAndLowGpa() {
        system.filterLiAndLowGpa().forEach(student -> System.out.println(student.getId() + " " + student.getName()));
    }

    private void averageGpaByClassName() {
        system.averageGpaByClassName().forEach((className, avgGpa) ->
                System.out.println(className + ": " + avgGpa));
    }

    private void topGpaByClassName() {
        system.topGpaByClassName().forEach((className, student) ->
                System.out.println(className + ": " + student.getId() + " " + student.getName()));
    }

    private void exportToCSV() {
        System.out.println("输入导出文件路径:");
        String filePath = scanner.nextLine();
        system.exportToCSV(filePath);
        System.out.println("导出成功！");
    }

    private void importFromCSV() {
        System.out.println("输入导入文件路径:");
        String filePath = scanner.nextLine();
        system.importFromCSV(filePath);
        System.out.println("导入成功！");
    }
}

