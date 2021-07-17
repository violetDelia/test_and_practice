import java.text.SimpleDateFormat;

import java.util.Calendar;
import java.util.Date;

public class CalendarAndDate {

    public static void main(String[] args) {
        Calendar calender = Calendar.getInstance();
        calender.roll(1,1);
        System.out.println(calender.get(1)+"ÔÂ"+calender.get(1));
        
        Date date = new Date();
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH");
        System.out.println(formatter.format(date));

        
    }
}