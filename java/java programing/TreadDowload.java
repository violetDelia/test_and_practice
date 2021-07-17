import java.net.URL;
import java.io.*;

public class TreadDowload {
    public static void main(String[] args) throws IOException {
        final URL[] urls = { new URL("A"), new URL("A"), new URL("A"), new URL("A"), };
        final String[] files = { "a", "b", "c", "d" };
        for (int i = 0; i < urls.length; ++i) {
            final int idx = i;
            new Thread(() -> {
                try {
                    System.out.println(urls[idx]);
                    download(urls[idx], files[idx]);
                } catch (Exception e) {
                    // TODO: handle exception
                    e.printStackTrace();
                }
            }).start();
        }
    }

    static void download(URL url, String file) throws IOException {
        try (InputStream input = url.openStream(); OutputStream output = new FileOutputStream(file)) {
            byte[] date = new byte[1024];
            int length;
            while ((length = input.read(date)) != -1) {
                output.write(date, 0, length);
            }
        }
    }

}
