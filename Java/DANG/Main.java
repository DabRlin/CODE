package DANG;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

import experiment.StudentInfo;

public class Main {
    //从文件导入数据 
    public static void loadStudent(List<StudentInfo> studentList) throws Exception  {
        Scanner input = new Scanner(new File("Students.csv"));
        while (input.hasNextLine()) {
            String text = input.nextLine();
            //processLine(text);
            Scanner data = new Scanner(text).useDelimiter(",");
            String name = data.next();
            Boolean gender = data.nextBoolean();
            Integer age = data.nextInt();
            double height = data.nextDouble();
            double gpa = data.nextDouble();
            studentList.add(new StudentInfo(name,gender,age,height,gpa));
        }
        input.close();
    }
    
//导出到文件
    public static void saveStudent(List<StudentInfo> studentList) throws Exception {
        Writer out = new FileWriter(new File("Students.csv"));
        Iterator<StudentInfo> iter = studentList.iterator();
        while(iter.hasNext())
        {
            StudentInfo stu = (StudentInfo)iter.next();
            out.write(stu.getName()+","+stu.getGender()+","+stu.getAge()+","+stu.getHeight()+","+stu.getGpa()+"\r\n");
        }
        out.flush();// 强制刷新缓冲区
        out.close();

    }
    
    
}
