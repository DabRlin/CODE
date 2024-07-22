package 课程.实验三;

public class YootkDemo5 {
    public static void main(String[] args) {
        Foo[] pity = {new Baz(), new Bar(), new Mumble(), new Foo()};
        for (int i = 0; i < pity.length; i++) {
            System.out.println(pity[i]);
            pity[i].method1();
            pity[i].method2();
            System.out.println();
        }
    }
}

class Foo {
    public void method1() {
        System.out.println("foo 1");
    }

    public void method2() {
        System.out.println("foo 2");
    }

    public String toString() {
        return "foo";
    }
}

class Bar extends Foo {
    public void method2() {
        System.out.println("bar 2");
    }
}

class Baz extends Foo {
    public void method1() {
        System.out.println("baz 1");
    }

    public String toString() {
        return "baz";
    }
}

class Mumble extends Baz {
    public void method2() {
        System.out.println("mumble 2");
    }
}
