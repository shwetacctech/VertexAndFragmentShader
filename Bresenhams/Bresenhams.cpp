#include "pch.h"
#include "Bresenhams.h"
#include <vector>


Bresenhams::Bresenhams(Line l, std::vector<float>& pixelVertices, std::vector<float>& colors)
{
   pixelData(l, pixelVertices,colors);
   //drawGrid(pixelVertices,colors);
}

Bresenhams::~Bresenhams()
{
}
void Bresenhams::drawGrid(std::vector<float>& pixelVertices, std::vector<float>& colors) {
    const float gridSize = 10.0f;
    const float step = 1.0f;

    // Code to draw horizontal lines
    for (float y = -gridSize / 2.0f; y <= gridSize / 2.0f; y += step)
    {
        pixelVertices.push_back(-gridSize / 2.0f);
        pixelVertices.push_back(y);
        pixelVertices.push_back(0);
        pixelVertices.push_back(gridSize / 2.0f);
        pixelVertices.push_back(y);
        pixelVertices.push_back(0);

        colors.push_back(1.0f);
        colors.push_back(0.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(0.0f);
        colors.push_back(1.0f);

    }

    // Code to draw Vertical lines
    for (float x = -gridSize / 2.0f; x <= gridSize / 2.0f; x += step)
    {
        pixelVertices.push_back(x);
        pixelVertices.push_back(-gridSize / 2.0f);
        pixelVertices.push_back(0);
        pixelVertices.push_back(x);
        pixelVertices.push_back(gridSize / 2.0f);
        pixelVertices.push_back(0);
        colors.push_back(1.0f);
        colors.push_back(0.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(0.0f);
        colors.push_back(1.0f);

    }
}
void Bresenhams::pixelData(Line l, std::vector<float>& pixelVertices, std::vector<float>& colors)
{
    // Bresenham's line drawing algorithm
    float x1 = l.getP1().getX();
    float y1 = l.getP1().getY();
    float x2 = l.getP2().getX();
    float y2 = l.getP2().getY();

    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float sx = (x1 < x2) ? 1.0f : -1.0f;
    float sy = (y1 < y2) ? 1.0f : -1.0f;
    float err = dx - dy;

    while (x1 < x2 || y1 < y2) {
        pixelVertices.push_back(round(x1));
        pixelVertices.push_back(round(y1));
        pixelVertices.push_back(0);
        
        pixelVertices.push_back(round(x1) + 1);
        pixelVertices.push_back(round(y1));
        pixelVertices.push_back(0);
        
        pixelVertices.push_back(round(x1) + 1);
        pixelVertices.push_back(round(y1) + 1);
        pixelVertices.push_back(0);
        
        pixelVertices.push_back(round(x1));
        pixelVertices.push_back(round(y1) + 1);
        pixelVertices.push_back(0);
        

        float e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
            x1 = round(x1);
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
            y1 = round(y1);
        }
    }
}
