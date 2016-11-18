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

}
void CCanvas::FillCircle(Point const& center, float radius, Color const& fillColor)
{

}