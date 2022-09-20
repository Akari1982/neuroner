package gui.draw;

import javax.swing.*;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.RenderingHints;
import java.awt.geom.AffineTransform;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

public final class Canvas extends JComponent
{
    private final ArrayList<Element> elements;
    private final ArrayList<Wire> wires;
    private final Element element;

    private Vector sel_p1;
    private Vector sel_p2;

    public Canvas()
    {
        MyMouseMotionListener l = new MyMouseMotionListener();
        addMouseMotionListener(l);
        addMouseListener(l);

        elements = new ArrayList<>();
        wires = new ArrayList<>();

        element = new Element();
        element.setPos(new Vector(100, 100));

        sel_p1 = new Vector(0, 0);
        sel_p2 = new Vector(0, 0);
    }

    @Override
    protected void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        draw((Graphics2D)g);
    }

    protected void draw(Graphics2D g)
    {
        g.setRenderingHint ( RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON );
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, getWidth(), getHeight());

        for(Wire w : wires)
        {
            w.draw((Graphics2D)g);
        }
        for(Element p : elements)
        {
            p.draw((Graphics2D)g);
        }

        AffineTransform old =g.getTransform();
        element.draw((Graphics2D) g);
        g.setTransform(old);

        // draw selection rect
        g.setColor(Color.BLACK);
        g.setStroke(new BasicStroke(1));
        g.drawLine(sel_p1.x, sel_p1.y, sel_p2.x, sel_p2.y);
    }

    private class MyMouseMotionListener implements MouseMotionListener, MouseListener
    {
        private Vector lastPos;
        private Element partToDrag;

        @Override
        public void mouseDragged(MouseEvent e)
        {
            Vector pos = new Vector(e.getX(), e.getY());

            if(partToDrag != null)
            {
                partToDrag.move(pos.sub(lastPos));
            }
            else
            {
                sel_p2 = pos;
            }

            repaint();
            lastPos = pos;
        }

        @Override
        public void mouseMoved(MouseEvent e)
        {
        }

        @Override
        public void mouseClicked(MouseEvent e)
        {
        }

        @Override
        public void mousePressed(MouseEvent e)
        {
            lastPos = new Vector(e.getX(), e.getY());
            if(element.matches(lastPos))
            {
                partToDrag = element;
            }
            else
            {
                sel_p1 = lastPos;
            }
        }

        @Override
        public void mouseReleased(MouseEvent e)
        {
            if (partToDrag != null)
            {
                partToDrag.setPos(partToDrag.getPos());
                partToDrag = null;
            }
            else
            {
                sel_p2 = new Vector(e.getX(), e.getY());
            }
            repaint();
        }

        @Override
        public void mouseEntered(MouseEvent e)
        {
        }

        @Override
        public void mouseExited(MouseEvent e)
        {
        }
    }
}
