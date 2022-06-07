#pragma once
#include "MyMath.h"

// The active vertex shader. Modifies an incoming vertex. Pre-Rasterization. 
void (*VertexShader)(Vec4&) = 0;
// The active pixel shader. Modifies an outgoing pixel. Post-Rasterization.
void (*PixelShader)(unsigned int&) = 0;

// All Shader Variables (Always Pre-fixed by “SV_”)
MATRIX_4X4 SV_WorldMatrix,SV_ViewMatrix, SV_ProjectionMatrix;

// Various custom vertex and pixel shaders, (Pre-fixed by “VS_” & “PS_”)
// Can be swapped using above function pointers as needed for flexibility. 

// Applys the current world matrix to all
void VS_World(Vec4& multiplyMe)
{
    multiplyMe = MultiplyVertexByMatrix4X4(multiplyMe, SV_WorldMatrix);
    multiplyMe = MultiplyVertexByMatrix4X4(multiplyMe, SV_ViewMatrix);
    multiplyMe = MultiplyVertexByMatrix4X4(multiplyMe,SV_ProjectionMatrix);


    //dividing by w
    multiplyMe.element[0] /= multiplyMe.element[3];
    multiplyMe.element[1] /= multiplyMe.element[3];
    multiplyMe.element[2] /= multiplyMe.element[3];
    //multiplyMe = vertexP;



}
// Basic pixel shader returns the color white
void PS_White(unsigned int& makeWhite)
{
    makeWhite = 0xFFFFFFFF;
}

void PS_Green(unsigned int& makeGreen)
{
    makeGreen = 0xFF00FF00;
}
void PS_Red(unsigned int& makeGreen)
{
    makeGreen = 0xFFFF0000;
}
void PS_Blue(unsigned int& makeGreen)
{
    makeGreen = 0xFF0000FF;
}

void PS_Cyan(unsigned int& makeGreen)
{
    makeGreen = 0xFF00FFFF;
}
