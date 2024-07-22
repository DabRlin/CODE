package experiment;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;
import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.Collectors.toList;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        //Stream API 举例
List<StudentInfo> studentList = new ArrayList<>();
        
        studentList.add(new StudentInfo("李小明",true,18,1.76,3.1));
        studentList.add(new StudentInfo("张小丽",false,20,1.61,4.0));
        studentList.add(new StudentInfo("王大朋",true,19,1.82,3.9));
        studentList.add(new StudentInfo("陈小跑",false,17,1.67,3.6));

//根据年龄从大到小排序，再根据身高从小到大排序
        List<StudentInfo> studentsSortName = studentList.stream()
                .sorted(Comparator.comparing(StudentInfo::getAge).reversed().thenComparing(StudentInfo::getHeight))
                .collect(toList());
                
//统计男生和女生的平均身高，结果存储在Map中
Map<Boolean,Double> m1 = studentList.stream().collect(groupingBy(StudentInfo::getGender,Collectors.averagingDouble(StudentInfo::getHeight)));

//根据姓名分组
Map<Boolean,List<StudentInfo>> m2 = studentList.stream().collect(groupingBy(StudentInfo::getGender));

//分别返回男生和女生中最高的学生
 Map<Boolean,Optional<StudentInfo>> m3= studentList.stream().collect(groupingBy(StudentInfo::getGender,Collectors.maxBy(Comparator.comparingDouble(StudentInfo::getHeight))));         
    

    
//男生和女生中学分绩最高的学生姓名
        System.out.println("[性别]\t\t[姓名]");
        studentList.stream().collect(groupingBy(StudentInfo::getGender,Collectors.collectingAndThen(Collectors.maxBy(Comparator.comparingDouble(StudentInfo::getGpa)),Optional::get))).forEach((k, v) -> System.out.println(k + "\t\t" + v.getName() ));            
                
//修改姓名为王大朋的学生年龄和学分绩
     studentList.stream()
                .filter(student -> student.getName().equals("王大朋"))
                .findFirst()
                .ifPresent(student -> {
                    student.setAge(30);
                    student.setGpa(4.1);
                });
    }
//     public static void main(String[] args) {
//         // 创建学生列表
//         List<Student> studentsList = // 初始化学生列表...

//         // 创建学生管理系统
//         StudentManagementSystem studentSystem = new StudentManagementSystem(studentsList);

//         // 添加学生
//         studentSystem.addStudent(new Student("David", 23, 78.9));

//         // 删除学生
//         studentSystem.deleteStudent("Alice");

//         // 更新学生信息
//         studentSystem.updateStudent("Bob", 23, 95.5);

//         // 查找学生
//         Optional<Student> foundStudent = studentSystem.findStudentByName("Charlie");
//         foundStudent.ifPresent(student -> System.out.println("Found student: " + student));
//     }
// }
}
