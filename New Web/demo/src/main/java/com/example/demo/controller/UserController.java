package com.example.demo.controller;

import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.PutMapping;


@RestController
public class UserController{
    @GetMapping("/user/{id}")
    public String getUserByIdString(@PathVariable String id){
        System.out.println(id);
        return "根据ID获取用户";
    }
    @PostMapping(value = "/user/")
    public String save(){
        return "添加用户";
    }
    @PutMapping(value="/user/{id}")
    public String update(){
        return "更新用户";
    }
    @DeleteMapping(value = "/user/{id}")
        public String  deleteByIdString(@PathVariable String id){
        System.out.println(id);
        return "根据id删除用户";
        }
    }





// package com.example.demo.controller;



// import org.springframework.web.bind.annotation.CrossOrigin;
// import org.springframework.web.bind.annotation.GetMapping;
// import org.springframework.web.bind.annotation.PostMapping;
// import org.springframework.web.bind.annotation.RequestMapping;
// import org.springframework.web.bind.annotation.RestController;

// import com.example.demo.model.User;
// import com.example.demo.utils.JwtUtils;
// import com.example.demo.utils.Result;

// import io.swagger.v3.oas.annotations.parameters.RequestBody;

// @RestController
// @RequestMapping("/user")
// @CrossOrigin
// public class UserController {
//     @PostMapping("/login")
//     public Result login(@RequestBody User user ){
//         String username =JwtUtils.generateToken(user.getUsername());
//         return Result.ok().data("token",token);
//     }
//     @GetMapping("/info")
//     public Result info(String token){
//         String username =JwtUtils.getClaimsByToken(token).getSubject;
//         String url = "null";
//         return Result.ok().data("username",username).data("avatar",url);
//     }
//     @PostMapping("/logout")
//      public Result logout(String token){
//         return Result.ok();
// }
// }