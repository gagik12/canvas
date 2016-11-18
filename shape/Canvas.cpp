#include "stdafx.h"
#include "Canvas.h"
#include "IShape.h"

void CCanvas::DrawShapes(std::vector<std::shared_ptr<IShape>> const& shapes)
{
    for (auto shape : shapes)
    {
        shape->Draw(*this);
    }
}

void CCanvas::DrawLine(Point const& startPoint, Point const& endPoint, Color const& outlineColor)
{
    glColor3i(outlineColor.red, outlineColor.blue, outlineColor.green);
    glBegin(GL_LINES);
        glVertex2f(startPoint.x, startPoint.y);
        glVertex2f(endPoint.x, endPoint.y);
    glEnd();
}

void CCanvas::FillPolygon(Vertices const& vertices, Color const& fillColor)
{

}

void CCanvas::DrawCircle(Point const& center, float radius, Color const& outlineColor)
{
    const int lineAmount = 100; 
    glColor3i(outlineColor.red, outlineColor.blue, outlineColor.green);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= lineAmount; i++) 
        {
            float angle = 2.0f * 3.1415926f * float(i) / float(lineAmount);
            glVertex2f(
                center.x + (radius * cos(angle)),
                center.y + (radius* sin(angle))
            );
        }
    glEnd();
}
void CCanvas::FillCircle(Point const& center, float radius, Color const& fillColor)
{
    const int lineAmount = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= lineAmount; i++)
    {
        glColor3i(fillColor.red, fillColor.blue, fillColor.green);
        float angle = 2.0f * 3.1415926f * float(i) / float(lineAmount);
        glVertex2f(
            center.x + (radius * cos(angle)),
            center.y + (radius* sin(angle))
        );
    }
    glEnd();
}