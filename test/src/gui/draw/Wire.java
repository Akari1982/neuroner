package gui.draw;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.RenderingHints;
import java.awt.Graphics2D;

public class Wire
{
    public Vector p1;
    public Vector p2;

    public Wire(Vector p1, Vector p2)
    {
        this.p1 = p1;
        this.p2 = p2;
    }

    public void draw(Graphics2D g)
    {
        g.setRenderingHint( RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON );

        g.setColor(Color.BLACK);
        g.setStroke(new BasicStroke(4));

        g.drawLine(p1.x, p1.y, p2.x, p2.y);
    }

    public void move(Vector delta)
    {
        p1 = p1.add(delta);
        p2 = p2.add(delta);
    }

    public void setP2(Vector p2)
    {
        this.p2 = p2;
    }
}
