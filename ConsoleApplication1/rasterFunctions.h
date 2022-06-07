#pragma once
#include "Shadders.h"

void DrawLineParametric(Vec2 start, Vec2 end, unsigned int color = 0x00FFFFFF) {

    if (start.x > end.x) {
        Vec2 temp = start;
        start = end;
        end = temp;
    }

    float slope;
    float dy = abs(floorf(end.y - start.y));
    float dx = abs(floorf(end.x - start.x));
    float ratio,currY,currX;
    if (dx == 0) {
        dx = 0.00000001;
    }
    
    if (dx > dy) {
        for (int i = start.x; i < end.x; i++) {
            ratio = (i - start.x) / dx;
            ratio = abs(ratio);
            currY = lerp(start.y, end.y, ratio);
            if (PixelShader)PixelShader(color);
            bg[(int)floor(currY + 0.5)][i] = color;
        }
    }
    else {
        if (start.y > end.y) {
            Vec2 temp = start;
            start = end;
            end = temp;
        }

        for (int i = start.y; i < end.y; i++) {
            ratio = (i - start.y) / dy;
            ratio = abs(ratio);
            currX = lerp(start.x, end.x, ratio);
            if (PixelShader)PixelShader(color);
            bg[i][(int)floor(currX + 0.5)] = color;
        }

    }


}

void DrawLine(Vec2 start, Vec2 end, unsigned int color = 0x00FFFFFF) {


    if (start.y > end.y && start.x > end.x) {
        Vec2 temp = start;
        start = end;
        end = temp;
    }

    if (start.x > end.x) {
        Vec2 temp = start;
        start = end;
        end = temp;
    }
    int curry = start.y;
    int currx = start.x;


    float dx,dy;
    if ((end.x - start.x) != 0) {
        dx = (end.x - start.x);
    }
    else {
        dx = 0.01f;
    }

    //PrintVec2(start);
    //PrintVec2(end);


    dy = end.y - start.y;
    float slope = dy / dx;
    //std::cout << "Slope: " << slope << "\n";
    float error = 0;
    if (abs(dx)>abs(dy)) {


        if (start.x < end.x) {

            for (int i = start.x; i <= end.x; i++) {
                if (PixelShader) PixelShader(color);
                bg[curry][i] = color;
                error += abs(slope);
                //std::cout << "error: " << error <<"\n";

                if (error > 0.5) {
                    curry += 1;
                    error -= 1;
                }
            }
        }
        else {
            for (int i = start.x; i >= end.x; i--) {
                if (PixelShader) PixelShader(color);
                bg[curry][i] = color;
                error += abs(slope);

                //std::cout << "error: " << error << "\n";

                if (error > 0.5) {
                    curry += 1;
                    error -= 1;
                }
            }
        }
    }
    else {
        if (start.y < end.y) {

            for (int i = start.y; i <= end.y; i++) {
                if (PixelShader) PixelShader(color);
                bg[i][currx] = color;
                error += 1 / abs(slope);
                //std::cout << "error: " << error << "\n";

                if (error > 0.5) {
                    currx += 1;
                    error -= 1;
                }
            }
        }
        else {

            for (int i = start.y; i >= end.y; i--) {
                if (PixelShader) PixelShader(color);
                bg[i][currx] = color;
                error += 1 / abs(slope);
                //std::cout << "error: " << error << "\n";

                if (error > 0.5) {
                    currx += 1;
                    error -= 1;
                }
            }
        }
    }

}

void DrawLine(const Vec4& startVertex, const Vec4& endVertex, unsigned int currColor = 0x00FFFFFF) {
    // Copy input data and send through shaders
    Vec4 copy_start = startVertex;
    Vec4 copy_end = endVertex;
    // Use vertex shader to modify incoming copies only.
    if (VertexShader)
    {
        VertexShader(copy_start);
        VertexShader(copy_end);
    }
    // original plotting variables adapted to use new cartesian data
    Vec2 screen_start = CartesianToScreen(copy_start);
    Vec2 screen_end = CartesianToScreen(copy_end);
    // Standard line drawing code follows using integer coordinates...
    DrawLineParametric(screen_start, screen_end, currColor);

}