//* Estratégia
interface NotificationStrategy {
    void send(Message message, String recipient);
}

abstract class Message {
    protected String content;

    public Message(String content) {
        this.content = content;
    }

    public abstract String format(); // Método para formatar a mensagem específica

    public abstract Message createMessage();

    public String getContent() {
        return content;
    }

    public void setContent(String _content){
        this.content = _content;
    }
}

//* Concreto */
class EmailNotificationStrategy implements NotificationStrategy {
    public EmailNotificationStrategy(){
        //? esse construtor sempre é vazio mesmo?
    }

    public void send(Message message, String recipient){
        System.out.println("Preview do email:\n" + message.content + " para " + recipient);
        System.out.println("Email enviado!");

    }
}

//* Concreto */
class SMSNotificationStrategy implements NotificationStrategy {
    public SMSNotificationStrategy(){
        //? esse construtor sempre é vazio mesmo?
    }

    public void send(Message message, String recipient){
        System.out.println("Preview do SMS:\n" + message.content + " para " + recipient);
        System.out.println("SMS enviado!");
    }
    
}

//* Concreto
class SimpleMessage extends Message {
    SimpleMessage(String content){
        super(content);
    }

    public Message createMessage() {
        System.out.println("Criando mensagem simples...");
        String res = format();
        setContent(res);
        return this;
    }

    public String format() {
        return "Nova mensagem:\n" + this.content;
    }
}

//* Concreto
class UrgentMessage extends Message {
    UrgentMessage(String content){
        super(content);
    }

    public Message createMessage(){
        System.out.println("Criando mensagem urgente...");
        String res = format();
        setContent(res);

        return this;
    }

    public String format(){
        return "!!!! URGENTEEEEEEEE !!!!\n" + this.content;
    }
    
}

//* Concreto
class PromotionalMessage extends Message {
    PromotionalMessage(String content){
        super(content);
    }

    public Message createMessage(){
        System.out.println("Criando mensagem promocional...");
        String res = format();
        setContent(res);

        return this;
    }

    public String format(){
        return "<< Promoção >> " + this.content;
    }
}

class MessageFactory {
    public static Message createMessage(String type, String content) {
        if ("SIMPLE".equalsIgnoreCase(type)) {
            return new SimpleMessage(content);
        } else if ("URGENT".equalsIgnoreCase(type)) {
            return new UrgentMessage(content);
        }
        throw new IllegalArgumentException("Tipo de mensagem desconhecido: " + type);
    }
}

// * Context
class NotificationService {
    private NotificationStrategy strategy;

    public NotificationService() {}

    public NotificationService(NotificationStrategy strategy) {
        this.strategy = strategy;
    }

    //* Concreto */
    public void setStrategy(NotificationStrategy strategy) {
        this.strategy = strategy;
    }

    public void sendNotification(Message message, String recipient) {
        if (strategy == null) {
            System.out.println("Erro: Nenhuma estratégia de notificação foi definida.\n");
            return;
        }
        if (message == null) {
            System.out.println("Erro: Mensagem não pode ser nula.\n");
            return;
        }
        strategy.send(message, recipient);
    }
}

public class Main {
    public static void main(String[] args) {
        Message welcomeMessage = MessageFactory.createMessage("SIMPLE", "Bem-vindo(a) ao nosso sistema!");
        Message alertMessage = MessageFactory.createMessage("URGENT", "Falha crítica detectada no servidor XYZ. Ação imediata requerida.");

        NotificationService notificationService = new NotificationService();

        System.out.println("--- Usando Estratégia de Email ---");
        notificationService.setStrategy(new EmailNotificationStrategy());
        notificationService.sendNotification(welcomeMessage, "aluno@exemplo.com");
        notificationService.sendNotification(alertMessage, "admin@exemplo.com");

        System.out.println("--- Mudando para Estratégia de SMS ---");
        notificationService.setStrategy(new SMSNotificationStrategy());
        notificationService.sendNotification(welcomeMessage, "+5511912345678");
        notificationService.sendNotification(alertMessage, "+5521987654321");

    }
}