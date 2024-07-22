package text;
import java.lang.annotation.*;
import java.lang.reflect.Field;
import java.util.regex.Pattern;

// 自定义注解，用于标记需要进行字符串校验的字段
@Target(ElementType.FIELD)
@Retention(RetentionPolicy.RUNTIME)
@interface StringValidator {
    String regex() default ""; // 正则表达式用于校验
    String message() default "无效的值"; // 错误消息
}

// 校验器类，用于执行字符串校验
class Validator {
    static boolean validate(Object obj) {
        Class<?> clazz = obj.getClass();
        Field[] fields = clazz.getDeclaredFields();
        for (Field field : fields) {
            Annotation annotation = field.getAnnotation(StringValidator.class);
            if (annotation != null) {
                StringValidator validator = (StringValidator) annotation;
                field.setAccessible(true);

                try {
                    String value = (String) field.get(obj);
                    if (!Pattern.matches(validator.regex(), value)) {
                        System.out.println("字段校验失败: " + field.getName());
                        System.out.println("错误消息: " + validator.message());
                        return false;
                    }
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                }
            }
        }
        return true;
    }
}

// 用户类，包含需要校验的字段
class User {
    @StringValidator(regex = "[A-Za-z]+", message = "只允许字母字符")
    private String username;

    public User(String username) {
        this.username = username;
    }
}

public class StringValidationApp {
    public static void main(String[] args) {
        User user = new User("John123");
        User user2= new User("sdkfhkjdsahfjksadhjkh");
        boolean isValid = Validator.validate(user);
        boolean isValid2 = Validator.validate(user2);
        System.out.println("用户是否有效? " + isValid);
        System.out.println("用户是否有效？"+isValid2);
    }
}
