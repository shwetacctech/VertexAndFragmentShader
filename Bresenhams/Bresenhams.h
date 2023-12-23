#pragma once
#include "pch.h"
#include "Line.h"
#include <vector>

class BRESENHAMS_API Bresenhams
{
public:
    Bresenhams(Line l, std::vector<float>& pixelVertices, std::vector<float>& colors);
    ~Bresenhams();
private:
    void pixelData(Line l, std::vector<float>& pixelVertices, std::vector<float>& colors);
    void drawGrid(std::vector<float>& pixelVertices, std::vector<float>& colors);
};