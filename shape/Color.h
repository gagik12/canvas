#pragma once
struct Color
{
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};
bool ConvertHexInRGBColor(std::string const& hexColor, Color & rgbColor);
