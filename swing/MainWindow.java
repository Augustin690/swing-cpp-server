import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;

public class MainWindow extends JFrame{
	
	private static final long serialVersionUID = 1L;
	
	private Client client;
	
	
	private JScrollPane scrollPane;
	
	private JMenuBar menuBar;
	private JMenu menu;
	private JToolBar toolBar;
	
	private JTextArea textArea;
	private JTextField textField;
	
	private JPanel buttonPanel;
	
	private JButton searchObjectButton;
	private JButton searchGroupButton;
	private JButton exitButton;
	private JButton playButton;
	
	private JMenuItem deleteItem;
	
	private boolean dataDeleted = false;
	
	public MainWindow(Client client) {
		
		super();
		
		textField = new JTextField("");
		
		this.client = client;	
		
		int rows = 25;
		int col = 40;
		
		setLayout(new BorderLayout());
		setJMenuBar(menuBar = new JMenuBar());
		
		add(textArea = new JTextArea("Server response:" + "\n",rows,col));
		add(buttonPanel = new JPanel(),BorderLayout.SOUTH);
		add(toolBar = new JToolBar(), BorderLayout.NORTH);
		add(scrollPane = new JScrollPane(textArea));
		
		SearchObjectAction searchObjAction = new SearchObjectAction("Search multimedia object ");
		SearchGroupAction searchGrpAction = new SearchGroupAction("Search multimedia group");
		PlayAction playAction = new PlayAction("Play multimedia");
		ExitAction exitAction = new ExitAction("EXIT");
		DeleteAction deleteAction = new DeleteAction("Delete Storage");
		
		buttonPanel.add(searchObjectButton = new JButton(searchObjAction));
		buttonPanel.add(searchGroupButton = new JButton(searchGrpAction));
		buttonPanel.add(playButton = new JButton(playAction));
		buttonPanel.add(exitButton = new JButton(exitAction));
		
		
		
		menuBar.add(textField);
		
		menuBar.add(menu = new JMenu("Delete"));
		menu.add(deleteItem = new JMenuItem(deleteAction));
		
		/*toolBar.add(new TextButton_1("text 1"));
		toolBar.add(new TextButton_2("text 2"));
		toolBar.add(new ExitButton("EXIT"))*/
		
		setDefaultCloseOperation(MainWindow.EXIT_ON_CLOSE);
		setTitle("JAVA GUI");
		pack();
		setVisible(true);
	}
	
	class SearchObjectAction extends AbstractAction{

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;

		public SearchObjectAction(String string) {
			// TODO Auto-generated constructor stub
			super(string);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			
			if(dataDeleted) {
				
				textArea.append("All data has been deleted");
				
			}
			
			else {
				// TODO Auto-generated method stub
				String response = client.send("Afficher l'objet " + textField.getText()).replaceAll("X", "\n");
				textArea.append(response);
				textArea.append("\n");
			}
	  }
	}
		
	class SearchGroupAction extends AbstractAction{

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;

		public SearchGroupAction(String string) {
			// TODO Auto-generated constructor stub
			super(string);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			
			if(dataDeleted) {
				
				textArea.append("All data has been deleted");
				
			}
			else {
				
				String response = client.send("Afficher le groupe " + textField.getText()).replaceAll("X", "\n");
				textArea.append(response);
				textArea.append("\n");
			}
				
		}
			
	}	
		

	
	
	class PlayAction extends AbstractAction{

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;

		public PlayAction(String string) {
			// TODO Auto-generated constructor stub
			super(string);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			
			if(dataDeleted) {
				
				textArea.append("All data has been deleted");
				
			}
			
			else {
				// TODO Auto-generated method stub
				String response = client.send("Play " + textField.getText()).replaceAll("X", "\n");
				textArea.append(response);
				textArea.append("\n");
			}
		}		
		
	}
	
	class ExitAction extends AbstractAction{

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;

		public ExitAction(String string) {
			// TODO Auto-generated constructor stub
			super(string);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			System.exit(0);
		}		
		
	}
	
	class DeleteAction extends AbstractAction{

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;

		public DeleteAction(String string) {
			// TODO Auto-generated constructor stub
			super(string);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			
			if(dataDeleted) {
				
				textArea.append("All data has aldready been deleted");
				
			}
			else {
				// TODO Auto-generated method stub
				String response = client.send("Delete " + textField.getText()).replaceAll("X", "\n");
				textArea.append(response);
				textArea.append("\n");
				dataDeleted = true;
			}
		}		
		
	}


}
