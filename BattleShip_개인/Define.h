#pragma once

//Board Size
#define BOARD_ROW 8
#define BOARD_COL 8

//Ship Max Number
#define MAX_SHIP 256

//Ship Max Size
#define POS_MAX_SIZE 5

//MainScreen Cursor INTERVAL
#define CURSOR_INTERVAL 4

//MainScreen Input
#define ENTER 13
#define UP 72
#define DOWN 80

//Menu Coordinate
#define MAINMENU_X COL_INTERVAL * BOARD_COL + 18
#define MAINMENU_Y ROW_INTERVAL * BOARD_ROW - 8

#define SETUPMENU_X COL_INTERVAL * BOARD_COL + 15
#define SETUPMENU_Y ROW_INTERVAL * BOARD_ROW - 11

#define ATTACKMENU_X COL_INTERVAL * BOARD_COL + 15
#define ATTACKMENU_Y ROW_INTERVAL * BOARD_ROW - 11

#define ENDMENU_X COL_INTERVAL * BOARD_COL + 16
#define ENDMENU_Y ROW_INTERVAL * BOARD_ROW

#define MENU_INTERVAL 4

//Message Coordinate
#define ATTACKMESSAGE_X COL_INTERVAL * BOARD_COL + 22
#define ATTACKMESSAGE_Y ROW_INTERVAL * BOARD_ROW - 8

#define SETUPMESSAGE_X COL_INTERVAL * BOARD_COL + 14
#define SETUPMESSAGE_Y ROW_INTERVAL * BOARD_ROW - 12

#define PLAYERNAME_X COL_INTERVAL * BOARD_COL - 22
#define PLAYERNAME_Y ROW_INTERVAL * BOARD_ROW + 4

#define DIRECTIONMESSAGE_X COL_INTERVAL * BOARD_COL + 15
#define DIRECTIONMESSAGE_Y ROW_INTERVAL * BOARD_ROW - 2

#define GAMENUMMESSAGE_X COL_INTERVAL * BOARD_COL + 14
#define GAMENUMMESSAGE_Y ROW_INTERVAL * BOARD_ROW - 13

#define ENDMESSAGE_X COL_INTERVAL * BOARD_COL + 22
#define ENDMESSAGE_Y ROW_INTERVAL * BOARD_ROW - 7

#define MESSAGE_INTERVAL 4

//Board Interval
#define COL_INTERVAL 4
#define ROW_INTERVAL 2

//SetupShipsType
#define RANDOM_SET SETUPMENU_Y + MENU_INTERVAL
#define USER_SET SETUPMENU_Y + MENU_INTERVAL * 2

//AttackType
#define RANDOM_ATTACK ATTACKMENU_Y + MENU_INTERVAL
#define USER_ATTACK ATTACKMENU_Y + MENU_INTERVAL * 2

//PlayerBoard Coordinate
#define P1_BOARD_X 4
#define P1_BOARD_Y 0

#define P2_BOARD_X BOARD_COL*COL_INTERVAL + 58
#define P2_BOARD_Y 0	

//Console Size
#define CONSOLE_XSIZE COL_INTERVAL * 2 * BOARD_COL + 64
#define CONSOLE_YSIZE ROW_INTERVAL * 2 * BOARD_ROW + 3

//Color
#define BLACK 0
#define DARKBULE 1
#define DARKGREEN 2
#define DARKSKY 3
#define DARKRED 4
#define DARKPINK 5
#define DARKYELLOW 6
#define DARKWHITE 7
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define SKY 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15