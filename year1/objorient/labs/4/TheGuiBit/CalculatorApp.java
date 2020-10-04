import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.util.List;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;

class CalculatorApp {
    public static void main(String[] args) throws Exception {
        UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        final Calculator calc = new Calculator();
        final JFrame window = new JFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setTitle("Calculator");
        window.setSize(320, 300);
        final JTextField display = new JTextField();
        display.setEditable(false);
        final JPanel keys = new JPanel(new GridLayout(4, 4));
        window.add(display, BorderLayout.NORTH);
        window.add(keys, BorderLayout.CENTER);
        for (char c : List.of(
                '7', '8', '9', '/',
                '4', '5', '6', '*',
                '1', '2', '3', '-',
                '0', '=', 'c', '+')) {
            final var button = new JButton(String.valueOf(c));
            button.addActionListener(ae -> {
                try {
                    calc.press(c);
                    display.setText(String.valueOf(calc.value()));
                } catch (Exception e) {
                    display.setText("Bad input:" +
                            e.getMessage());
                }
            });
            keys.add(button);
        }
        calc.press('c');
        SwingUtilities.updateComponentTreeUI(window);
        window.setVisible(true);
    }
}