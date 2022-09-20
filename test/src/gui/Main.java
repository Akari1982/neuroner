package gui;

import gui.draw.Canvas;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.SwingUtilities;
import java.awt.Dimension;

public final class Main extends JFrame
{
    private final Canvas canvas;

    public Main()
    {
        super("Editor");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);

        canvas = new Canvas();
        getContentPane().add(canvas);

        setPreferredSize(new Dimension(800, 600));
        pack();
        setLocationRelativeTo(null);

        JMenuBar bar = new JMenuBar();

        JMenu parts = new JMenu("Parts");
        bar.add(parts);

        setJMenuBar(bar);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(() -> new Main().setVisible(true));
    }
}
