#pragma once
#include "defines.h"

float PointFromLineDistance(Vec2 LinePoint1,Vec2 LinePoint2,Vec2 searchPoint) {
	//(Y1 – Y2)x + (X2 – X1)y + X1Y2 – Y1X2 = 0

	/*
	
	Generate cube verts in NdC space
	generate grid vertices from .5 to -.5 on the x and z

	convert to pixel space before drawing

	*/
	return 0;
}

float lerp(float a,float b, float ratio) {
    if (ratio > 1) {
        return b;
    }
    else {
        return a + (b - a) * ratio;
    }
}
Vec4 MultiplyVertexByMatrix4X4(Vec4 vertex, MATRIX_4X4 matrix) {
    Vec4 result = { 0,0,0,0 };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.element[i] += vertex.element[j] * matrix.element[j][i];
        }
    }
    return result;

};
Vec2 CartesianToScreen(Vec4 cartesian) {
	Vec2 screen;

	float xCartesianWorldRatio = (cartesian.element[0] + 1) ;
    screen.x = (RASTER_WIDTH / 2 * xCartesianWorldRatio);

	float yCartesianWorldRatio = (1 - cartesian.element[1]);
	screen.y = (RASTER_HEIGHT  / 2 * yCartesianWorldRatio);

	return screen;
}

MATRIX_4X4 BuildRotationMatrixOnY(float deg) {
    MATRIX_4X4 result = {
    {cos(deg * (3.14 / 180)),0,sin(deg * (3.14 / 180)),0,
    0,1,0,0,
     -sin(deg * (3.14 / 180)),0,cos(deg * (3.14 / 180)),0,
    0,0,0,1}
    };

    return result;
}

MATRIX_4X4 BuildRotationMatrixOnX(float deg) {
    MATRIX_4X4 result = {
        {
            1,0,0,0,
            0,cos(deg * (3.14 / 180)),-sin(deg * (3.14 / 180)),0,
            0,sin(deg * (3.14 / 180)),cos(deg * (3.14 / 180)),0,
            0,0,0,1
        }
    };

    return result;
}

MATRIX_4X4 BuildRotationMatrixOnZ(float deg) {
    MATRIX_4X4 result = {
        {
            cos(deg * (3.14 / 180)),-sin(deg * (3.14 / 180)),0,0,
            sin(deg * (3.14 / 180)),cos(deg * (3.14 / 180)),0,0,
            0,0,1,0,
            0,0,0,1
        }
    };

    return result;
}

MATRIX_3X3 identity(MATRIX_3X3& original) {

    original.element[0][0] = 1;
    original.element[1][1] = 1;
    original.element[2][2] = 1;

    return original;
}

MATRIX_4X4 identity(MATRIX_4X4& original) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            original.element[i][j] = 0;
        }
    }
    original.element[0][0] = 1;
    original.element[1][1] = 1;
    original.element[2][2] = 1;
    original.element[3][3] = 1;

    return original;
}
Vec3 MultiplyVertexByMatrix(Vec3 vertex, MATRIX_3X3 matrix) {
    Vec3 result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.element[i] += vertex.element[j] * matrix.element[j][i];
        }
    }
    return result;

};


MATRIX_4X4 MultiplyMatrixByMatrix(MATRIX_4X4 a, MATRIX_4X4 b) {
    MATRIX_4X4 result;
    int val = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            //get i row element and add it to j column element
            for (int k = 0; k < 4; k++) {
                result.element[i][j] += a.element[i][k] * b.element[k][j];
            }
        }

    }


    return result;

};

MATRIX_4X4 MatrixInverse(MATRIX_4X4 a) {
    MATRIX_4X4 result;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.element[i][j] = a.element[j][i];
        }
    }

    Vec4 pos;
    pos.element[0] = a.element[3][0];
    pos.element[1] = a.element[3][1];
    pos.element[2] = a.element[3][2];

    Vec4 newPos = MultiplyVertexByMatrix4X4(pos, result);
    newPos.element[0] *= -1;
    newPos.element[1] *= -1;
    newPos.element[2] *= -1;

    result.element[3][0] = newPos.element[0];
    result.element[3][1] = newPos.element[1];
    result.element[3][2] = newPos.element[2];
    result.element[3][3] = 1;


    return result;

};

MATRIX_3X3 MultiplyMatrixByMatrix(MATRIX_3X3 a, MATRIX_3X3 b) {
    MATRIX_3X3 result;
    int val = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                //get i row element and add it to j column element
                for (int k = 0; k < 3; k++) {
                    result.element[i][j] += a.element[i][k] * b.element[k][j];
                }
            }
            
        }
    

    return result;

};

