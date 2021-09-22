package software;

public class NpuInfo {

    private String name = "西北工业大学";
    private String address = "西安市友谊西路127号";
    private String telephone = "029-88494433";

    private static NpuInfo instance = new NpuInfo();

    private NpuInfo() {
    };

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return this.address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getTelephone() {
        return this.telephone;
    }

    public void setTelephone(String telephone) {
        this.telephone = telephone;
    }

    public static NpuInfo getInstance() {
        return instance;
    }
}
