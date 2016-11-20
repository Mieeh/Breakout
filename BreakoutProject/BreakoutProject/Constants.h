#pragma once

#ifndef CONSANTS_H
#define CONSTANTS_H

/*
* Default constant values used my more than one class 
*/

/*
#define FPS 60
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Classic Breakout"
#define DEG2RAD 3.14159f / 180.0f
*/
static const int FPS = 60;
static const int WINDOW_WIDTH = 590;
static const int WINDOW_HEIGHT = 600;
static const std::string WINDOW_TITLE = "Classic Breakout";
static const double DEG2RAD = 3.14159 / 180.0;

// Paddle values
static const double PADDLE_WIDTH = 70;
static const double PADDLE_HEIGHT = 7.5;
static const double PADDLE_SPEED = 0.7;

// Ball values
static const double BALL_RADIUS = 10;

#endif