package 课程.实验一.test2;
import 课程.实验一.labl2.*;
public class YootkDemo { // 主类
    public static void main(String args[]) {
        Book bookA = new Book(); // 无参构造
        Book bookB = new Book("Java从入门到项目实战");
        Book bookC = new Book("Python从入门到项目实战", "大数据2201陈泓源2211650110", 99.8);
        System.out.println(bookA.getInfo());
        System.out.println(bookB.getInfo());
        System.out.println(bookC.getInfo());
        System.out.println("【main()方法】bookA = " + bookA); // 直接进行对象的输出
        bookA.print(); // 调用类中的普通方法
    }
}
