package com.example.demo.controller;

import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.example.demo.model.User;
import org.springframework.web.bind.annotation.GetMapping;


@RestController
public class ParamsController {
    
    @RequestMapping(value="/getTest1", method = RequestMethod.GET)
    public String getTest1(){
        return "GET请求";
    }
    @RequestMapping(value="/getTest2", method = RequestMethod.GET)
    public String getTest2(String nickname, String phone){
        System.out.println("nickname:"+nickname);
        System.out.println("phone:"+phone);
        return "GET请求";
    }
    @RequestMapping(value="/getTest3", method = RequestMethod.GET)
    public String getTest3(@RequestParam(value = "nickname", required = false) String name){
        System.out.println("nickname"+name);
        return "GET请求";
    }
    @RequestMapping(value="/PostTest1", method = RequestMethod.POST)
    public String PostTest1(){
        return "POST请求";
    }
    
    @RequestMapping(value="/PostTest2", method = RequestMethod.POST)
    public String PostTest2(String username, String password){
                System.out.println("username:"+username);
        System.out.println("password:"+password);
        return "POST请求";
    }

    @RequestMapping(value="/postTest3", method = RequestMethod.POST)
    public String postText3(User user){
        System.out.println(user);
        return "POST请求";
    }
    @RequestMapping(value="/postTest4", method = RequestMethod.POST)
    public String postText4(@RequestBody User user){
        System.out.println(user);
        return "POST请求";
    }
    @GetMapping(value="/test/**")
    public String test() {
        return "通配符请求";
    }
    
}

