#include "stdafx.h"
#include "Canvas.h"
#include "IShape.h"
#include "const.h"

void CCanvas::DrawShapes(std::vector<std::shared_ptr<IShape>> const& shapes)
{
    for (auto shape : shapes)
    {
        shape->Draw(*this);
    }
}

void CCanvas::DrawLine(Point const& startPoint, Point const& endPoint, Color const& outlineColor)
{
    glColor3f(outlineColor.red, outlineColor.green, outlineColor.blue);
    glEnable(GL_LINE_SMOOTH);
    glBegin(GL_LINES);
        glVertex2f(startPoint.x, startPoint.y);
        glVertex2f(endPoint.x, endPoint.y);
    glEnd();
    glDisable(GL_LINE_SMOOTH);
}

void CCanvas::FillPolygon(Vertices const& vertices, Color const& fillColor)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < vertices.size(); i++)
    {
        glColor3f(fillColor.red, fillColor.green, fillColor.blue);
        glVertex2f(vertices[i].x, vertices[i].y);
    }
    glEnd();
}

void CCanvas::DrawCircle(Point const& center, float radius, Color const& outlineColor)
{
    glColor3f(outlineColor.red, outlineColor.green, outlineColor.blue);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= LINE_AMOUNT; i++)
        {
            float angle = 2.0f * PI * float(i) / float(LINE_AMOUNT);
            glVertex2f(
                center.x + (radius * cos(angle)),
                center.y + (radius* sin(angle))
            );
        }
    glEnd();
}
void CCanvas::FillCircle(Point const& center, float radius, Color const& fillColor)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= LINE_AMOUNT; i++)
    {
        glColor3f(fillColor.red, fillColor.green, fillColor.blue);
        float angle = 2.0f * PI * float(i) / float(LINE_AMOUNT);
        glVertex2f(
            center.x + (radius * cos(angle)),
            center.y + (radius* sin(angle))
        );
    }
    glEnd();
}