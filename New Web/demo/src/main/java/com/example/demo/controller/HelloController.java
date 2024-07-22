package com.example.demo.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {
//http://localhost:8080/hello?nickname=zhangsan&phone=123
  @RequestMapping(value = "/hello", method= RequestMethod.GET)
  @GetMapping("/hello")
    public String hello( String nickname,String phone){
        System.out.println(phone);
//printlin到终端，return到web界面
        return "hello world" + nickname;
    }
}
