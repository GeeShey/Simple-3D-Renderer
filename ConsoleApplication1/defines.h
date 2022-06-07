#pragma once
#include "XTime.h"
#include <iostream>
#include <vector>
#include "RasterSurface.h"
#include <vector>
#include <math.h>


#define RASTER_WIDTH 500.0f
#define RASTER_HEIGHT 500.0f
#define RASTER_PIXEL_COUNT (RASTER_HEIGHT*RASTER_WIDTH)

unsigned int bg[(int)RASTER_HEIGHT][(int)RASTER_WIDTH];

struct Vec2 {
	float x = 0, y = 0;
};

struct Vec3 {
    float element[3] = {0,0,0};

};

struct Vec4{
    float element[4] = { 0,0,0,1 };

};


struct MATRIX_3X3 {
    float element[3][3] = { 
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };
};

struct MATRIX_4X4 {
    float element[4][4] = {
        { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }
    };
};

Vec2 getVec2(float x, float y) {
    Vec2 ret;
    ret.x = x;
    ret.y = y;
    return ret;
};
//all the includes
//defines