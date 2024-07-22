package lab;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class FileIO {
    public static void loadStudent(List<Student> studentList) throws Exception  {
        Scanner input = new Scanner(new File("Students.csv"));
        input.nextLine();
        while (input.hasNextLine()) {
            String text = input.nextLine();
            Scanner data = new Scanner(text).useDelimiter(",");
            int id = data.nextInt();
            String name = data.next();
            int age = data.nextInt();
            String gender = data.next();
            int class_id = data.nextInt();
            double gpa = data.nextDouble();
            studentList.add(new Student(id, age, name, gender, class_id, gpa));
        }
        input.close();
    }

    public static void saveStudent(List<Student> studentList) throws Exception {
        Writer out = new FileWriter("Students.csv");
        Iterator<Student> iter = studentList.iterator();
        out.write("学号,姓名,年龄,性别,班级,成绩\r\n");
        while(iter.hasNext())
        {
            Student stu = iter.next();
            out.write(String.format("%d,%s,%d,%s,%d,%f\r\n",stu.getId(),stu.getName(),stu.getAge(),stu.getGender(),stu.getClassId(),stu.getGPA()));
        }
        out.flush();
        out.close();
    }
}
