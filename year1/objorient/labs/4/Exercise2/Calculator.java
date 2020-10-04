class Calculator {
    String one = "";
    String two = "";
    // 53:+ 55:- 52:* 57:/
    char operator;
    Boolean calcState = false;
    Boolean first = true;

    public int value() {
        int out;
        if (this.one == "") {
            out = 0;
        } else if (this.first) {
            out = Integer.parseInt(this.one);
        } else if (this.two == "") {
            out = 0;
        } else {
            out = Integer.parseInt(this.two);
        }
        System.out.println("printing: " + out);
        return out;
    }

    public void press(char key) {
        if (key == 'c' && this.calcState == false) {
            this.calcState = true;
        }

        if (this.calcState == true) {
            if (key == 'P') {
                this.calcState = false;
            } else if (key - '0' < 10 && key - '0' >= 0) {
                this.pressDigit(key);
            } else if (key == '*' || key == '/' || key == '+' || key == '-') {
                this.pressOp(key);
            } else if (key == '=') {
                this.eval();
            } else if (key == 'c') {
                this.one = "";
                this.two = "";
                this.operator = 0;
            } else {
                System.out.println("Yeah no");
            }
        }
    }

    private void pressOp(char key) {
        if (this.two != "") {
            this.eval();
            this.operator = key;
        } else if (this.one != "") {
            this.operator = key;
            this.first = false;
        } else {
            System.out.println("Yup nop");
        }
    }

    private void pressDigit(char key) {
        if (this.first) {
            this.one = this.one + key;
        } else {
            this.two = this.two + key;
        }
    }

    private void eval() {
        int temp = 0;
        int x = Integer.parseInt(this.one);
        int y = Integer.parseInt(this.two);

        if (this.operator == '+') {
            temp = x + y;
        } else if (this.operator == '-') {
            temp = x - y;
        } else if (this.operator == '*') {
            temp = x * y;
        } else if (this.operator == '/') {
            temp = x / y;
        } else {
            System.out.println("None of the above");
        }
        
        this.one = Integer.toString(temp);
        this.two = "";
        this.operator = 0;
        this.first = true;
    }
}