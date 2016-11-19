#include "stdafx.h"
#include "Rectangle.h"
#include "SolidShape.h"
#include "Point.h"
CRectangle::CRectangle(Point const& leftTop, float width, float height, Color const& outlineColor, Color const& fillColor)
    :ISolidShape("Rectangle"), 
    m_leftTop(leftTop),
    m_height(height),
    m_width(width),
    m_fillColor(fillColor),
    m_outlineColor(outlineColor)
{
    m_rightBottom = { leftTop.x + width, leftTop.y + height };
}

float CRectangle::GetWidth() const
{
    return m_width;
};

float CRectangle::GetHeight() const
{
    return m_height;
};


Point const& CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

Point const& CRectangle::GetRightBottom() const
{
    return m_rightBottom;
}

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
    canvas.DrawLine(m_leftTop, { m_leftTop.x + m_width, m_leftTop.y}, m_outlineColor);
    canvas.DrawLine({ m_leftTop.x + m_width, m_leftTop.y }, { m_leftTop.x + m_width, m_leftTop.y + m_height}, m_outlineColor);
    canvas.DrawLine({ m_leftTop.x + m_width, m_leftTop.y + m_height }, { m_leftTop.x, m_leftTop.y + m_height }, m_outlineColor);
    canvas.DrawLine({ m_leftTop.x, m_leftTop.y + m_height }, m_leftTop, m_outlineColor);
    //canvas.FillPolygon(m_vertices, m_fillColor);
}