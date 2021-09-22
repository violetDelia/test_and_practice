package software;

public class FactoryCreator {
    public static Factory getFactory(String choice) {
        if (choice.equals("Mobile")) {
            return new MobileFactory();
        }
        return null;
    }
}

abstract class Factory {
    public abstract Mobile getMobile(String brand);

    public abstract void func();
}

class MobileFactory extends Factory {

    @Override
    public Mobile getMobile(String brand) {
        if (brand == null)
            return null;
        if (brand == "vivo")
            return new Vivo();
        if (brand == "oppo")
            return new Oppo();
        return null;
    }

    @Override
    public void func() {
        // TODO Auto-generated method stub

    };

}

interface Mobile {
    void func();
}

class Vivo implements Mobile {

    @Override
    public void func() {
        // TODO Auto-generated method stub

    }

}

class Oppo implements Mobile {

    @Override
    public void func() {
        // TODO Auto-generated method stub

    }

}
