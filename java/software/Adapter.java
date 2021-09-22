package software;

import java.util.HashMap;
import java.util.Map;

public class Adapter implements IUserInfo {
    public static void main(String[] args) {
        FacultyMember facultyMember = new FacultyMember("140001", "liyong", "10101010101010101");
        Adapter adapter = new Adapter(facultyMember);
        System.out.println(adapter.getName());
        System.out.println(adapter.getId());
        System.out.println(adapter.getUserTeles().toString());
        System.out.println(adapter.getUserHomeAddress());
    }

    FacultyMember facultyMember;

    public Adapter(FacultyMember facultyMember) {
        this.facultyMember = facultyMember;
    }

    @Override
    public String getNumber() {
        return facultyMember.getIdentification().substring(0, 2);
    }

    @Override
    public String getId() {
        return facultyMember.getIdentification().substring(2, 6);
    }

    @Override
    public String getUserHomeAddress() {
        return null;
    }

    @Override
    public Map<String, String> getUserTeles() {
        Map<String, String> tele = new HashMap<String, String>();
        tele.put("1", facultyMember.contactTelephone);
        return tele;

    }

    @Override
    public String getName() {
        return facultyMember.name;
    }

}

interface IFacultyMember {
    public String getIdentification();

    public String getName();

    public String getContactTelephone();

    public String toString();

    public boolean equals(Object o);
}

class FacultyMember implements IFacultyMember {
    protected String identification;
    protected String name;
    protected String contactTelephone;

    public FacultyMember(String identification, String name, String contactTelephone) {
        this.identification = identification;
        this.name = name;
        this.contactTelephone = contactTelephone;
    }

    @Override
    public String getIdentification() {

        return this.identification;
    }

    @Override
    public String getName() {
        return this.name;
    }

    @Override
    public String getContactTelephone() {
        return this.contactTelephone;
    }

}

interface IUserInfo {
    public String getNumber();

    public String getId();

    public String getUserHomeAddress();

    public Map<String, String> getUserTeles();

    public String getName();

}

class UserInfo implements IUserInfo {
    protected String number;
    protected String name;
    protected String Id;
    protected String homeAddress;
    protected Map<String, String> teles;

    public UserInfo(String number, String name, String Id, String homeAddress, Map<String, String> teles) {
        this.number = number;
        this.name = name;
        this.Id = Id;
        this.homeAddress = homeAddress;
        this.teles = teles;
    }

    @Override
    public String getNumber() {
        return this.number;
    }

    @Override
    public String getId() {
        return this.Id;
    }

    @Override
    public String getUserHomeAddress() {
        return this.homeAddress;
    }

    @Override
    public Map<String, String> getUserTeles() {
        return this.teles;
    }

    @Override
    public String getName() {
        return this.name;
    }

}