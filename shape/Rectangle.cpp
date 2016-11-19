#include "stdafx.h"
#include "Rectangle.h"
#include "SolidShape.h"
#include "Point.h"
CRectangle::CRectangle(Point const& leftTop, float width, float height, Color const& outlineColor, Color const& fillColor)
    :ISolidShape("Rectangle"), 
    m_height(height),
    m_width(width),
    m_fillColor(fillColor),
    m_outlineColor(outlineColor)
{
    m_vertices.push_back(leftTop);
    m_vertices.push_back({ leftTop.x + m_width, leftTop.y });
    m_vertices.push_back({ leftTop.x + m_width, leftTop.y + m_height });
    m_vertices.push_back({ leftTop.x, leftTop.y + m_height });
}

float CRectangle::GetWidth() const
{
    return m_width;
};

float CRectangle::GetHeight() const
{
    return m_height;
};

Color CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
};

Color CRectangle::GetFillColor() const
{
    return m_fillColor;
};

float CRectangle::GetArea() const
{
    return m_width * m_height;
};

float CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
};

void CRectangle::AppendProperties(std::ostream & strm) const
{
    strm << "  Width = " << m_width
        << "  Height = " << m_height;
}

void CRectangle::Draw(ICanvas & canvas) const
{
    canvas.DrawLine(m_vertices[0], m_vertices[1], m_outlineColor);
    canvas.DrawLine(m_vertices[1], m_vertices[2], m_outlineColor);
    canvas.DrawLine(m_vertices[2], m_vertices[3], m_outlineColor);
    canvas.DrawLine(m_vertices[3], m_vertices[0], m_outlineColor);
    canvas.FillPolygon(m_vertices, m_fillColor);
}