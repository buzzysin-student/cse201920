class Main {
    public static void main(String[] args) {
        System.out.println("started");
        Calculator calcI = new Calculator();
        calcI.press('C');
        calcI.press('1');
        calcI.press('3');
        calcI.press('/');
        calcI.press('2');
        calcI.press('=');
        String out = Integer.toString(calcI.value());
        System.out.println(out);
    }
}