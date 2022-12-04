public class MessageList {
    private MessageListNode first;
    private int messagesCounter=0;
    public String allCodes;

    public boolean isEmpty(){
        return first==null;
    }

    public void finalInsert(String message){
        Message newMessage=new Message(messagesCounter,message);
        MessageListNode node= new MessageListNode(newMessage);
        if(first==null){
            first=node;
        }else{
            MessageListNode pointer= first;
            while(pointer.next!=null){
                pointer=pointer.next;
            }
            pointer.next=node;
        }
        messagesCounter++;
    }

    public  Object[][] returnMessagesData(){
        int rows = 0;
        Object[][] messagesMatrix;
        if(first!=null){


            MessageListNode temp = first;
            do{
                rows++;
                temp = temp.next;
            }while(temp != null);

            messagesMatrix = new Object[rows][2];
            MessageListNode aux = first;
            int counter =0;
            do{
                messagesMatrix[counter][0] = aux.message.getId();
                messagesMatrix[counter][1] = aux.message.getMessage();
                counter++;
                aux = aux.next;
            }while(aux != null);

            return messagesMatrix;

        }
        messagesMatrix = new Object[rows][2];
        return messagesMatrix;
    }
}
