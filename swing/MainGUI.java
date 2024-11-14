import java.io.*;
import java.net.*;


public class MainGUI {

	public static void main(String[] args) throws UnknownHostException, IOException {
		// TODO Auto-generated method stub
		
		Client client = new Client(Client.DEFAULT_HOST,Client.DEFAULT_PORT);
		
		
		MainWindow window = new MainWindow(client);
		

	}

}
