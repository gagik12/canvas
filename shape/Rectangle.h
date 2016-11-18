#pragma once
#include "Point.h"
#include "SolidShape.h"
#include "Color.h"

class CRectangle : public ISolidShape
{
public:
    CRectangle(Point const& leftTop, GLfloat width, GLfloat height, Color const& outlineColor, Color const& fillColor);
    ~CRectangle() = default;
    double GetArea() const override;
    double GetPerimeter() const override;
    Color GetOutlineColor() const override;
    Color GetFillColor() const override;
    Point const& GetLeftTop() const;
    Point const& GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    Point m_leftTop;
    Point m_rightBottom;
    GLfloat m_width;
    GLfloat m_height;
    Color m_outlineColor;
    Color m_fillColor;
};