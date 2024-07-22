package 课程.实验一.labl2;

 public class Book {
    private String title;
    private String author;
    private double price;

    public Book() { // 无参构造方法
        this("李兴华编程训练营", "沐言优拓", 9988.66);
    }

    public Book(String title) { // 单参构造方法
        this(title, "小李老师", 5566.88);
    }

    public Book(String title, String author, double price) { // 多参构造方法
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public String getInfo() {
        return "图书名称：" + this.title + "、图书作者：" + this.author + "、图书价格：" + this.price;
    }

    public void setTitle(String t) {
        title = t;
    }

    public void setAuthor(String a) {
        author = a;
    }

    public void setPrice(double p) {
        if (p > 0) { // 设置了一个判断条件
            price = p;
        }
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public double getPrice() {
        return price;
    }

    // 类中的普通方法如果要想被调用，那么一定要通过实例化对象的形式完成
    public void print() { // 类中的普通方法
        System.out.println("【Book类-print()方法】" + this); // 直接输出this关键字的信息
    }
}