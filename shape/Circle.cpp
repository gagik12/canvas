#include "stdafx.h"
#include "Circle.h"
#include "SolidShape.h"
#include "Point.h"

CCircle::CCircle(Point const& center, double radius, Color const& outlineColor, Color const& fillColor)
    :ISolidShape("Circle"),
    m_center(center),
    m_radius(radius),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{
}

Point const& CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

Color CCircle::GetOutlineColor() const
{
    return m_outlineColor;
};

Color CCircle::GetFillColor() const
{
    return m_fillColor;
};

double CCircle::GetArea() const
{
    return M_PI * std::pow(m_radius, 2);
};

double CCircle::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
};

void CCircle::AppendProperties(std::ostream & strm) const
{
    strm << "  Radius = " << m_radius;
}

void CCircle::Draw(ICanvas & canvas) const
{
    canvas.FillCircle(m_center, m_radius, m_fillColor);
    canvas.DrawCircle(m_center, m_radius, m_outlineColor);
}