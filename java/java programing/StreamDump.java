import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class StreamDump{
    public static void main(String[] args) {
        try {
            dump(new FileInputStream("aaa.bmp"),new FileOutputStream("bbb.bmp"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    public static void dump(InputStream src, OutputStream dest) throws IOException{
        InputStream input = new BufferedInputStream(src);
        OutputStream output = new BufferedOutputStream(dest);
        byte[] date = new byte[1024];
        int length = -1;
        while((length = input.read(date))!=-1){
            output.write(date,0,length);
        }
        input.close();
        output.close();
    }
}
