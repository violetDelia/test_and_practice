public class ExpectionAndCause {
    public static void main(String[] args) {
        try {
            BankAtm.GetbalanceInfo(12345L);
        } catch (Exception e) {
            System.out.println("something wrong:" + e);
            System.out.println("cause:" + e.getCause());
        }
    }
}

class DateHouse {
    public static void FindDate(long ID) throws DateHouseException {
        {
            if(ID >0 && ID <1000)
            System.out.println("id"+ID);
            else
             throw new DateHouseException("cannot find the id");
        }
    }
}

class BankAtm{
    public static void GetbalanceInfo(long ID) throws MyAppException{
        try{
            DateHouse.FindDate(ID);
        }catch(DateHouseException e){
            throw new MyAppException("invilid id",e);
        }
    }
}

class DateHouseException extends Exception{
    public DateHouseException(String message){
        super(message);
    }
}

class MyAppException extends Exception{
    public MyAppException(String message) {
        super(message);
    }
    public MyAppException(String massage, Exception cause){
        super(massage, cause);
    }
}