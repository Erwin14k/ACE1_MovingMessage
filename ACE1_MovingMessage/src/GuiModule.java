import panamahitek.Arduino.PanamaHitek_Arduino;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class GuiModule {
    static MessageList messageListHandler = new MessageList();
    static PanamaHitek_Arduino arduinoHandler = new PanamaHitek_Arduino();


    /*public static void loginFrame() throws Exception {
        //Fonts used
        Font font =new Font("Arial",Font.BOLD,50);
        Font font2 =new Font("Helvetica",Font.BOLD,30);
        Font font3 =new Font("Showcard Gothic",Font.BOLD,30);


        //Frame Initialization.
        JFrame loginFrame = new JFrame("Moving Message");
        loginFrame.setLayout(null);
        //Set visible the frame.
        loginFrame.setVisible(true);
        //Not resizable.
        loginFrame.setResizable(false);
        //Background color.
        loginFrame.getContentPane().setBackground(Color.CYAN);
        //On close Behavior of the frame.
        loginFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        //Get screen dimensions.
        Toolkit myScreen= Toolkit.getDefaultToolkit();
        Dimension sizeScreen = myScreen.getScreenSize();
        //Height of the screen.
        int h= sizeScreen.height;
        //Width of the screen.
        int w= sizeScreen.width;
        //Frame size.
        loginFrame.setSize(1080,520);
        //Frame coordinates.
        loginFrame.setLocation(w/4,h/4);









        //Title label
        JLabel titleL = new JLabel("Moving Message");
        titleL.setLayout(null);
        titleL.setVisible(true);
        titleL.setForeground(Color.BLACK);
        titleL.setBounds(350,10,550,60);
        titleL.setFont(font);
        loginFrame.add(titleL);

        //User Label
        JLabel usernameL = new JLabel("User: ");
        usernameL.setLayout(null);
        usernameL.setVisible(true);
        usernameL.setForeground(Color.BLACK);
        usernameL.setBounds(220,150,250,40);
        usernameL.setFont(font3);
        loginFrame.add(usernameL);


        //Password Label
        JLabel passwordL = new JLabel("Password: ");
        passwordL.setLayout(null);
        passwordL.setVisible(true);
        passwordL.setForeground(Color.BLACK);
        passwordL.setBounds(220,250,300,40);
        passwordL.setFont(font3);
        loginFrame.add(passwordL);



        //User text field.
        JTextField usernameTF = new JTextField();
        usernameTF.setLayout(null);
        usernameTF.setVisible(true);
        usernameTF.setBounds(450,145,350,40);
        usernameTF.setFont(font2);
        usernameTF.setBackground(Color.white);
        loginFrame.add(usernameTF);

        //Password text field.
        JPasswordField passwordTF = new JPasswordField();
        passwordTF.setBounds(450,245,350,40);
        passwordTF.setVisible(true);
        passwordTF.setLayout(null);
        passwordTF.setFont(font2);
        passwordTF.setBackground(Color.white);
        loginFrame.add(passwordTF);

        //Login Button.
        JButton loginButton = new JButton("Log In");
        loginButton.setLayout(null);
        loginButton.setVisible(true);
        loginButton.setBounds(380, 350, 300, 60);
        loginButton.setFont(font3);
        loginButton.setBackground(Color.yellow);
        //Login button function
        loginButton.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e){
                if((usernameTF.getText().equals("grupo10"))&&(passwordTF.getText().equals("14k"))){
                    try {
                        JOptionPane.showMessageDialog(null,"<html><p style=\"color:green; font:20px;\">Welcome Again Admin!!</p></html>" );
                        loginFrame.dispose();
                        adminView();
                    } catch (IOException ex) {
                        Logger.getLogger(GuiModule.class.getName()).log(Level.SEVERE, null, ex);
                    } catch (Exception ex) {
                        throw new RuntimeException(ex);
                    }
                }else{
                    JOptionPane.showMessageDialog(null,"<html><p style=\"color:red; font:20px;\">Invalid User/Password, try again!!</p></html>" );
                }
            }
        });
        loginFrame.add(loginButton);
        loginFrame.repaint();
    }*/



    public static void initApp() throws Exception {
        arduinoHandler.arduinoTX("COM1",9600);
        adminView();
    }
    public static void adminView() throws Exception {

        //Fonts Used
        Font font =new Font("Arial",Font.BOLD,36);
        Font font2 =new Font("Helvetica",Font.BOLD,30);
        Font font3 =new Font("Showcard Gothic",Font.BOLD,30);
        Font font4 =new Font("Arial",Font.BOLD,18);

        //Frame Initialization.
        JFrame adminView = new JFrame("Moving Message");
        adminView.setLayout(null);

        //Set visible the frame.
        adminView.setVisible(true);
        //Not resizable.
        adminView.setResizable(false);
        //Background color
        adminView.getContentPane().setBackground(Color.orange);
        //On close behavior.
        adminView.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        //Get screen dimensions.
        Toolkit myScreen= Toolkit.getDefaultToolkit();
        Dimension sizeScreen = myScreen.getScreenSize();
        //screen height.
        int h= sizeScreen.height;
        //screen width.
        int w= sizeScreen.width;
        //Frame size.
        adminView.setSize(860,800);
        //Frame coordinates.
        adminView.setLocation(0,0);

        JLabel titleM = new JLabel("Sent Messages");
        titleM.setLayout(null);
        titleM.setVisible(true);
        titleM.setForeground(Color.BLACK);
        titleM.setBounds(290,20,600,60);
        titleM.setFont(font3);
        adminView.add(titleM);

        //Logout Button
        JButton logOutButton = new JButton("");
        ImageIcon iconobtn4 = new ImageIcon("img/logout.png");
        logOutButton.setLayout(null);
        logOutButton.setVisible(true);
        logOutButton.setBounds(780, 630, 50, 60);
        logOutButton.setBackground(Color.red);
        logOutButton.setIcon(iconobtn4);
        logOutButton.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent ecp){
                adminView.dispose();
            }
        });
        adminView.add(logOutButton);

        /*//Icon Label
        JLabel graphLabel = new JLabel("");
        graphLabel.setLayout(null);
        graphLabel.setVisible(true);
        graphLabel.setForeground(Color.BLACK);
        graphLabel.setBounds(850,20,620,600);
        ImageIcon iconobtn5 = new ImageIcon("img/iconologin.png");
        graphLabel.setIcon(iconobtn5);
        JScrollPane graphScroll= new JScrollPane();
        graphScroll.setBounds(850,20,620,600);
        graphScroll.setViewportView(graphLabel);
        adminView.add(graphScroll);



        JLabel descriptionLabel = new JLabel("Circuit Design");
        descriptionLabel.setLayout(null);
        descriptionLabel.setVisible(true);
        descriptionLabel.setForeground(Color.BLACK);
        descriptionLabel.setBounds(1040,630,600,60);
        descriptionLabel.setFont(font3);
        adminView.add(descriptionLabel);
        */
        //Table creation
        int n=0;
        String[] header = {"Id","Message"};
        JTable messageTable = new JTable(messageListHandler.returnMessagesData(), header);
        JScrollPane messagesDataTableSC= new JScrollPane(messageTable);
        messagesDataTableSC.getViewport().setBackground(Color.white);
        messageTable.getTableHeader().setBackground(Color.decode("#1D2A3B"));
        messageTable.getTableHeader().setForeground(Color.WHITE);
        messageTable.getTableHeader().setFont(font4);
        messageTable.getColumnModel().getColumn(0).setPreferredWidth(100);
        messageTable.getColumnModel().getColumn(1).setPreferredWidth(700);
        messageTable.setRowHeight(40);
        messageTable.setFont(font4);
        messagesDataTableSC.setBounds(20, 100, 800, 500);
        messagesDataTableSC.setViewportView(messageTable);
        adminView.add(messagesDataTableSC);


        //Message text field.
        JTextField messageTF = new JTextField();
        messageTF.setLayout(null);
        messageTF.setVisible(true);
        messageTF.setBounds(30,630,450,40);
        messageTF.setFont(font2);
        messageTF.setBackground(Color.white);
        adminView.add(messageTF);

        //Send Message Button
        JButton sendMessageButton = new JButton("Send Message");
        sendMessageButton.setLayout(null);
        sendMessageButton.setVisible(true);
        sendMessageButton.setBounds(500, 630, 270, 60);
        sendMessageButton.setBackground(Color.yellow);
        sendMessageButton.setFont(font3);
        sendMessageButton.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent ecp){
                messageListHandler.finalInsert(messageTF.getText());
                adminView.dispose();
                try {
                    for(int i=0;i<messageTF.getText().length();i++){
                        char c=messageTF.getText().charAt(i);
                        int charCode=c;
                        arduinoHandler.sendByte(charCode);
                    }
                    adminView();
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }


            }
        });
        adminView.add(sendMessageButton);
    }
}
