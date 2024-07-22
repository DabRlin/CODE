package 课程.实验三;

// 假定的 Book 类
class Book {
    public Book() {
        // 无参构造函数
    }
}

interface IBook {
    // 定义接口
    String SITE = "www.yootk.com";

    void read(); // 抽象方法
}

interface ISpec {
    // 规格信息
    double size(); // 尺寸
}

abstract class Print {
    // 图书刊印的类
    public abstract void batch(); // 批次印刷
}

class MathBook extends Print implements IBook, ISpec {
    // 接口的多实现
    public void read() { // 抽象方法覆写
        System.out.println("&#8203;``【oaicite:1】``&#8203;认真读数学图书，巩固计算机的基础知识");
    }

    public double size() {
        return 7.9;
    }

    public void batch() { // 覆写抽象类中的方法
        System.out.println("&#8203;``【oaicite:0】``&#8203;进行数学图书的批量印刷。");
    }
}

public class YootkDemo {
    public static void main(String args[]) {
        IBook book = new MathBook(); // 向上转型
        ISpec spec = (ISpec) book;
        System.out.println(spec.size());
        Print print = (Print) spec;
        print.batch();
    }
}
