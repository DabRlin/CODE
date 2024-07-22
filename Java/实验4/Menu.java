// package 实验4;

// import java.util.Scanner;

// public class Menu {
// 	private Scanner input = null;


	
// 	public Menu() {
// 		this.input = new Scanner(System.in);
	
// 		while (true) {
// 			this.showStudent();
// 		}
// 	}

	
// 	// 显示学生操作的菜单
// 	public void showStudent() {
		
// 		System.out.println("            学生信息管理                 ");
// 		System.out.println("           1、增加学生信息               ");
// 		System.out.println("           2、列出全部学生信息           ");
// 		System.out.println("           3、查询学生信息               ");
// 		System.out.println("           4、删除学生信息               ");
// 		System.out.println("           5、修改学生信息               ");
// 		System.out.println("           6、返回上一级菜单             ");
// 		System.out.println("\n\n请选择具体的操作：");
// 		switch (this.input.nextInt()) {
// 		case 1: {
//             System.out.print("输入学生学号：");
//             int id = this.input.nextInt();
//             System.out.print("输入学生姓名：");
//             String name = this.input.next();
//             System.out.print("输入学生年龄：");
//             int age = this.input.nextInt();
//             System.out.print("输入学生班级：");
//             String className = this.input.next();
//             System.out.print("输入学生学分绩：");
//             double creditScore = this.input.nextDouble();
            
//             Student newStudent = new Student(id, name, "Male/Female", age, className, creditScore);
//             // 将 newStudent 添加到你的学生列表中
//             // studentsList.add(newStudent);
//             break;
// 		}
// 		case 2: {
//     // 列出全部学生信息
//     // 循环遍历学生列表并打印每个学生的信息
//     for (Student student : studentsList) {
//         System.out.println(student.toString());
//     }
//     break;
// 		}
// 		case 3: {
// 			//find by id
			
// 		}
// 		case 4: {
// 			//delete
			
// 		}
// 		case 5: {
// 			//update
			
// 			break;
// 		}

// 		default: {
// 			System.out.println("      选择错误，请重新选择！");
// 			break;
// 		}
// 		}
// 	}

	
// 	public static void main(String[] args) {
// 		new Menu();
// 	}
// }
