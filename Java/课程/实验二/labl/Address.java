package 课程.实验二.labl;

public class Address {
    private String country;
    private String province;
    private String city;
    private String street;
    private String zipcode;

    public Address(String country, String province, String city, String street, String zipcode) {
        this.country = country;
        this.province = province;
        this.city = city;
        this.street = street;
        this.zipcode = zipcode;
    }

    public String getFullAddress() {
        return country + ", " + province + ", " + city + ", " + street + ", " + zipcode;
    }
}
