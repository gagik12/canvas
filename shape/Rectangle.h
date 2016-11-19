#pragma once
#include "Point.h"
#include "SolidShape.h"
#include "Color.h"

class CRectangle : public ISolidShape
{
public:
    CRectangle(Point const& leftTop, float width, float height, Color const& outlineColor, Color const& fillColor);
    ~CRectangle() = default;
    float GetArea() const override;
    float GetPerimeter() const override;
    Color GetOutlineColor() const override;
    Color GetFillColor() const override;
    Point const& GetLeftTop() const;
    Point const& GetRightBottom() const;
    float GetWidth() const;
    float GetHeight() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    Point m_leftTop;
    Point m_rightBottom;
    float m_width;
    float m_height;
    Color m_outlineColor;
    Color m_fillColor;
};