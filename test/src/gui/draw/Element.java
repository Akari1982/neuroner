package gui.draw;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.RenderingHints;
import java.awt.Graphics2D;

public class Element
{
    private Vector pos;
    private final Vector bound_p1;
    private final Vector bound_p2;

    public Element()
    {
        pos = new Vector(0, 0);
        bound_p1 = new Vector(-18, -3);
        bound_p2 = new Vector(36, 21);
    }

    public Vector getPos()
    {
        return pos;
    }

    public Element setPos(Vector pos)
    {
        this.pos = pos;
        return this;
    }

    public void draw(Graphics2D g)
    {
        g.setRenderingHint ( RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON );

        g.translate(pos.x, pos.y);

        g.setColor(Color.BLACK);
        g.setStroke(new BasicStroke(4));
        g.drawLine(0, 0, 0, 7);
        g.drawLine(-15, 7, 15, 7);
        g.drawLine(-10, 7, -10, 15);
        g.drawLine(10, 7, 10, 15);
        g.drawLine(-15, 15, -10, 15);
        g.drawLine(10, 15, 15, 15);

        g.setColor(new Color(178,0,0));
        g.setStroke(new BasicStroke(1));
        g.fillOval( -3, -3, 6, 6 );
        g.fillOval( -18, 12, 6, 6 );
        g.fillOval( 12, 12, 6, 6 );

        g.setColor(Color.GRAY);
        g.setStroke(new BasicStroke(1));
        g.drawLine( -10, 22, -5, 22 );
        g.drawLine( -5, 22, 5, 18 );
        g.drawLine( 5, 22, 10, 22 );
    }

    public boolean matches(Vector p)
    {
        return (pos.x + bound_p1.x <= p.x) && (pos.y + bound_p1.y <= p.y) && (p.x <= pos.x + bound_p2.x) && (p.y <= pos.y + bound_p2.y);
    }

    public void move(Vector delta)
    {
        pos = pos.add(delta);
    }
}