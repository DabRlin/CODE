package com.example.demo.utils;

public class Result {
    private Integer code; // 返回码
    private String message; // 返回信息
    private Object data; // 返回数据

    public Result() {
    }

    public static Result ok() {
        Result result = new Result();
        result.setCode(200);
        result.setMessage("成功");
        return result;
    }

    public static Result error() {
        Result result = new Result();
        result.setCode(500);
        result.setMessage("失败");
        return result;
    }

    public Result code(Integer code) {
        this.code = code;
        return this;
    }

    public Result message(String message) {
        this.message = message;
        return this;
    }

    public Result data(Object data) {
        this.data = data;
        return this;
    }

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }
}
