/* @Author: Lloyd Thomas
   @Date: 22/07/2021
*/
#include "PlayerHUDTest.h"


using namespace std;


int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 800;


void Player_HUD_Test::Buffer_HUD(GLFWwindow* graphics_window) {
    // Buffers window & adds new actions & 
    // executes all current pending events
    glfwSwapBuffers(graphics_window);
    glfwPollEvents();
}


void Player_HUD_Test::Show_HUD(GLFWwindow* graphics_window) {
    // Shows window
    glfwShowWindow(graphics_window);
}


void Player_HUD_Test::Hide_HUD(GLFWwindow* graphics_window) {
    // Hides window
    glfwHideWindow(graphics_window);
}

 
void Player_HUD_Test::Draw_HUD(GLFWwindow* graphics_window,
    double bar_location_origin_x,
    double bar_location_origin_y,
    double bar_height, 
    double health,
    double player_health,
    int r,
    int g,
    int b
) { 
    // Config
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Colour
    glColor3d(r, g, b);
    
    // Begin drawing
    glBegin(GL_QUADS);

    // Sets shape coordinates & Draws
    /* Top left */ glVertex2d(bar_location_origin_x, bar_location_origin_y);
    /* Top right */ glVertex2d( /* width = */ player_health, bar_location_origin_y);
    /* Bottom right */ glVertex2d( /* width = */ player_health, /* height = */ bar_height);
    /* Bottom left */ glVertex2d(bar_location_origin_x /* height = */, bar_height);

    // Finish drawing
    glEnd();
}


void Player_HUD_Test::Draw_HUD_Background_Layer(GLFWwindow* graphics_window) {
    unsigned char* data = stbi_load("../Content/Images/HUD.png",
        (int*)30, (int*)6,
        0,
        0
    );


    /* TODO


    unsigned int texture = (int)data;


    */


    // Config
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);


    /*


    // Generates, activates & 
    // binds texture
    glGenTextures(0, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);


    */


    /*


    // Params (texture wrap)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    */


    // Apply image to texture
    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        500, 200,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        (unsigned int*) data
    );


    /*


    // Sets up pointer/s
    glVertexAttribPointer(0, 
        2,
        GL_FLOAT, 
        GL_FALSE,
        1,
        '\0'
    );

    // Enables image/texture drawing, Generates texture & draws
    glEnableVertexAttribArray(0);
    glGenerateMipmap(GL_TEXTURE_2D);
    glDrawElements(GL_TRIANGLES, 4, GL_UNSIGNED_INT, 0);


    */
}


GLFWwindow* Player_HUD_Test::Open_Graphics_Window() {
	std::cout << "Graphics Window Opening..." << std::endl;

    // Initialise
    glfwInit();

    // Parse vals to GLFW vars
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    // Generate Graphics Window
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "Graphics Window Test",
        //glfwGetPrimaryMonitor(), YOU NEED THIS FOR IT TO WORK IN UE...
        '\0',
        '\0'
    );

    return window;
}


Player_HUD_Test::Player_HUD_Test() {
    std::cout << "Player HUD initialising..." << std::endl;
}


Player_HUD_Test::~Player_HUD_Test() {
    std::cout << "Player HUD process finished..." << std::endl;
}