#pragma once
#include "SolidShape.h"
#include "Point.h"
#include "Color.h"

class CCircle : public ISolidShape
{
public:
    CCircle(Point const& center, double radius, Color const& outlineColor, Color const& fillColor);
    ~CCircle() = default;
    double GetArea() const override;
    double GetPerimeter() const override;
    Color GetOutlineColor() const override;
    Color GetFillColor() const override;
    double GetRadius() const;
    Point const& GetCenter() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    Point m_center;
    double m_radius;
    Color m_outlineColor;
    Color m_fillColor;
};