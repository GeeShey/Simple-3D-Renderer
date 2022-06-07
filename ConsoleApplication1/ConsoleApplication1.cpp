// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "rasterFunctions.h"



void init() {

    //NEEDS TO BE OPTIMIZED

};

void clearBGBuffer(int col = 0x00FFFF00) {
    int offset = 0;
    for (int i = 0; i < RASTER_HEIGHT; i++) {
        for (int j = 0; j < RASTER_WIDTH; j++) {

            //drawPixel(col, i, j);
            bg[i][j] = col;

        }
    }
};

void testDrawLine() {
    std::vector<Vec2> vertices;

    vertices.push_back(getVec2(250, 250));

    vertices.push_back(getVec2(250, 200));
    vertices.push_back(getVec2(250, 300));


    vertices.push_back(getVec2(200, 250));
    vertices.push_back(getVec2(300, 250));

    vertices.push_back(getVec2(275, 275));
    vertices.push_back(getVec2(275, 224));

    vertices.push_back(getVec2(225, 225));
    vertices.push_back(getVec2(225, 275));

    //DrawLine(vertices[0], vertices[1],0x00FFFFF);
    //DrawLine(vertices[0], vertices[2], 0x00FFFFF);
    //DrawLine(vertices[0], vertices[3], 0x00FFFFF);
    //DrawLine(vertices[0], vertices[4], 0x00FFFFF);
    //DrawLine(vertices[0], vertices[5], 0x00FFFFF);
    //DrawLine(vertices[0], vertices[6], 0x00FFFFF);
    //DrawLine(vertices[0], vertices[7], 0x00FFFFF);
    //DrawLine(vertices[0], vertices[8], 0x00FFFFF);

    //DrawLine( vertices[1], vertices[0], 0x00FFFFF);
    //DrawLine(vertices[2], vertices[0], 0x00FFFFF);
    //DrawLine(vertices[3], vertices[0], 0x00FFFFF);
    //DrawLine(vertices[4], vertices[0], 0x00FFFFF);
    //DrawLine(vertices[5], vertices[0], 0x00FFFFF);
    //DrawLine(vertices[6], vertices[0], 0x00FFFFF);//problem
    //DrawLine(vertices[7], vertices[0], 0x00FFFFF);
    //DrawLine(vertices[8], vertices[0], 0x00FFFFF);//problem
};

void DebugPrintVertex(Vec4 vertex) {
    std::cout << "\n-------------Debug Print Vertex:-------------\n";
    std::cout << vertex.element[0] << " , " << vertex.element[1] << " , " << vertex.element[2] << " , " << vertex.element[3] << "\n";
    
};

void DebugPrintVertex(Vec3 vertex) {
    std::cout << "\n-------------Debug Print Vertex:-------------\n";
    std::cout << vertex.element[0] << " , " << vertex.element[1] << " , " << vertex.element[2] << "\n";

};

void DebugPrintMatrix(MATRIX_3X3 mat) {
    std::cout << "\n-------------Debug Print Matrix(3x3):-------------\n";

    for (int i = 0; i < 3; i++) {
        std::cout << mat.element[i][0] << " , " << mat.element[i][1] << " , " << mat.element[i][2] << "\n";  
    }

};

void DebugPrintMatrix(MATRIX_4X4 mat) {
    std::cout << "\n-------------Debug Print Matrix(4x4):-------------\n";

    for (int i = 0; i < 4; i++) {
        std::cout << mat.element[i][0] << " , " << mat.element[i][1] << " , " << mat.element[i][2] << " , " << mat.element[i][3] << "\n";
    }

};
void testMatrixGauntlet() {

    //VECTOR X MATRIX 3X3 TEST
    std::cout << "\nVertex x Matrix Test(3x3)\n";

    Vec3 v = {1,2,3};
    MATRIX_3X3 test;
    float count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            test.element[i][j] = count;
            count++;
        }
    }

    Vec3 result = MultiplyVertexByMatrix(v, test);
    DebugPrintVertex(result);
    

    //VECTOR X MATRIX 4X4 TEST

    std::cout << "\nVertex x Matrix Test(4x4)\n";
    Vec4 vi = { 1,2,3,4 };
    MATRIX_4X4 testi;
    count = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            testi.element[i][j] = count;
            count++;
        }
    }

    Vec4 resulti = MultiplyVertexByMatrix4X4(vi, testi);
    DebugPrintVertex(resulti);

    //MATRIX X MATRIX 3X3 TEST

    std::cout << "\nMatrix x Matrix Test(3x3)\n";

    MATRIX_3X3 resulta = MultiplyMatrixByMatrix(test,test);
    DebugPrintMatrix(resulta);

    //MATRIX X MATRIX 4X4 TEST

    std::cout << "\nMatrix x Matrix Test(4x4)\n";

    MATRIX_4X4 testc;
    count = 17;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            testc.element[i][j] = count;
            count++;
        }
    }

    MATRIX_4X4 resultb = MultiplyMatrixByMatrix(testi, testc);
    DebugPrintMatrix(resultb);

    //MATRIX  INVERSE

    std::cout << "\nMatrix Inverse Test(4x4)\n";

    MATRIX_4X4 testd;
    testd.element[0][0] = 1;
    testd.element[1][1] = 0.309;
    testd.element[1][2] = 0.951;
    testd.element[2][1] = -0.951;
    testd.element[2][2] = 0.309;

    testd.element[3][0] = 7;
    testd.element[3][1] = -2.282;
    testd.element[3][2] = 9.153;
    testd.element[3][3] = 1;




    MATRIX_4X4 resulte  = MatrixInverse(testd);
    DebugPrintMatrix(resulte);

};

int main()
{
    clearBGBuffer(0x00);
    RS_Initialize("Shekhar Sai", RASTER_WIDTH, RASTER_HEIGHT);
    //testMatrixGauntlet();

    //Vec2 UnEditableOriginalLine[2] =
    //{
    //     { -0.2, +0.2 }, { +0.2, -0.5 } // Defines a fixed diagonal line crossing the origin.    
    //};
    Vec4 test = { 1,2,3,4 };
    MATRIX_4X4 testb = { {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16} };
    Vec4 resul = MultiplyVertexByMatrix4X4(test, testb);

    float radius = 0.5;

    std::vector<Vec4> cubeVerts;

    for (float i = -1*(radius/2); i < radius; i+=radius) {
        for (float j = -1 * (radius / 2); j < radius; j += radius) {
            for (float k = -1 * (radius / 2); k < radius; k += radius) {
                Vec4 vert; //lil uzi
                vert.element[0] = i ;
                vert.element[1] = j ;
                vert.element[2] = k ;

                
                cubeVerts.push_back(vert);

            }
        }
    }
    std::vector<Vec2> cubeVertsInScreenSpace;

    for (int i = 0; i < cubeVerts.size(); i++) {
        cubeVertsInScreenSpace.push_back(CartesianToScreen(cubeVerts[i]));
    }


    //CREATING THE GRID
    std::vector<Vec4> gridVerts;

    //changing the x 
    for (float i = -.5; i <= 0.5; i+=.1) {
        Vec4 vert; //lil uzi
        vert.element[0] = i;
        vert.element[2] = -.5;
        gridVerts.push_back(vert);

        vert.element[2] = .5;
        gridVerts.push_back(vert);

    }

    //changing the z
    for (float i = -0.5; i <= 0.5; i+=.1) {
        Vec4 vert; //lil uzi
        vert.element[0] = -.5;
        vert.element[2] = i;
        gridVerts.push_back(vert);

        vert.element[0] = .5;
        gridVerts.push_back(vert);


    }

    std::vector<Vec2> gridVertsInScreenSpace;
    MATRIX_4X4 gridWorldMatrix = identity(gridWorldMatrix);
    
    for (int i = 0; i < gridVerts.size(); i++) {
        gridVertsInScreenSpace.push_back(CartesianToScreen(gridVerts[i]));

    }

    Vec4 cubeTranslation = {0,1,0,0};

    MATRIX_4X4 cubeWorldTranslationMatrix = {
        {1,0,0,0,
            0,1,0,0,
            0,0,1,0
        ,0,radius/2,0,1}
    };

    //y 18
    /*MATRIX_4X4 viewMatrix = {
        {cos(18 * (3.14 / 180)),0,sin(18 * (3.14 / 180)),0,
            0,1,0,0,
            -sin(18 * (3.14 / 180)),0,cos(18 * (3.14 / 180)),0
        ,0,0,-1,1}
    };*/

    ////x 18
    MATRIX_4X4 rotMatrix = BuildRotationMatrixOnX(-18);
    MATRIX_4X4 viewTranslationMatrix = {
        {   1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,-1,1
        }
    };

    MATRIX_4X4 viewMatrixTranslated = MultiplyMatrixByMatrix( viewTranslationMatrix,rotMatrix);

    MATRIX_4X4 inverseViewMatrix = MatrixInverse(viewMatrixTranslated);
    float aspectRatio = RASTER_HEIGHT/ RASTER_WIDTH;
    float yScale = 1 / tan(0.5 * 90 * 3.14/180);
    float xScale = yScale * aspectRatio;
    float zFar = 10;
    float zNear = 0.1;


    MATRIX_4X4 projectionMatrix = {
        {xScale,0,0,0,
            0,yScale,0,0,
            0,0,zFar / (zFar - zNear),1
        ,0,0,(-(zFar * zNear) / (zFar - zNear)),0}
    };
    SV_ViewMatrix = inverseViewMatrix;
    SV_ProjectionMatrix = projectionMatrix;

    XTime s;
    s.Restart();
    //DrawLine();
    std::cout << "Hello World!\n";
    double angle = 0;
    int speed = 15;
    while (RS_Update(*bg, RASTER_PIXEL_COUNT)) {

        clearBGBuffer(0x00);

        SV_WorldMatrix = gridWorldMatrix;
        VertexShader = VS_World; // I choose a shader that will multiply by a single matrix that I control.  
        PixelShader = PS_White; // Regardless of the original color I want all pixels to be shown white. 

        for (int i = 0; i < gridVertsInScreenSpace.size(); i+=2) {

            if (i == 10 ) {
                PixelShader = PS_Blue ;
            }
            else if (i == 30) {
                PixelShader = PS_Red;

            }
            else {
                PixelShader = PS_White;
            }
            DrawLine(gridVerts[i+1], gridVerts[i], 0x00FFFFFF);//bottom
        }
        angle += s.Delta();

        MATRIX_4X4 rot = BuildRotationMatrixOnY(angle * speed);

        //UNCOMMENT THESE LINES TO ROTATE ON ALL THE AXIS
        //rot = MultiplyMatrixByMatrix(BuildRotationMatrixOnY(angle * speed), BuildRotationMatrixOnX(angle * speed));
        //rot = MultiplyMatrixByMatrix(rot, BuildRotationMatrixOnZ(angle * speed));
        
        

        if (angle >= 360) {
            angle = 0;
        }

        s.Signal();
        //SV_WorldMatrix = cubeWorldTranslationMatrix;
        SV_WorldMatrix = MultiplyMatrixByMatrix(cubeWorldTranslationMatrix,rot);
        VertexShader = VS_World;  
        PixelShader = PS_Green; 


        //0,1,2,3
        DrawLine(cubeVerts[0], cubeVerts[2], 0x0000FF00);//Left
        DrawLine(cubeVerts[2], cubeVerts[6], 0x0000FF00);//top
        DrawLine(cubeVerts[4], cubeVerts[6], 0x0000FF00);//right
        DrawLine(cubeVerts[0], cubeVerts[4], 0x0000FF00);//bottom

        //back face
        DrawLine(cubeVerts[1], cubeVerts[3], 0x0000FF00);//Left
        DrawLine(cubeVerts[3], cubeVerts[7], 0x0000FF00);//top
        DrawLine(cubeVerts[5], cubeVerts[7], 0x0000FF00);//right
        DrawLine(cubeVerts[1], cubeVerts[5], 0x0000FF00);//bottom

        //brdging the two faces
        DrawLine(cubeVerts[0], cubeVerts[1], 0x0000FF00);
        DrawLine(cubeVerts[2], cubeVerts[3], 0x0000FF00);
        DrawLine(cubeVerts[5], cubeVerts[4], 0x0000FF00);
        DrawLine(cubeVerts[6], cubeVerts[7], 0x0000FF00);

        //testDrawLine();


    }

    RS_Shutdown();


}
