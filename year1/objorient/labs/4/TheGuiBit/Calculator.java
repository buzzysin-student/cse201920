public class Calculator {

    private Integer defaultNum = 42;

    void press(char c) {
        System.out.println("Woaaah you pressed " + c);
    }
    Integer value(){
        return defaultNum;
    }
}

