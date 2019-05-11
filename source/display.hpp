#pragma once

#include <iostream>
#include <iomanip>
#include <cctype>
#include "setup.hpp"
#include "sevsegdisp.hpp"
#include "colour.hpp"

void dispBanner()
{
    writeBuf << endl;
    writeBuf << endl;
    writeBuf << blue_fg << "  MineSweep" << reset;
}

void dispFlagCounter()
{
    writeBuf << endl;
    writeBuf << reset;

    flagDisp.update("      ");
}

void dispControls()
{
    writeBuf << endl;
    writeBuf << white_fg << "  ↑, ←, ↓, → : " << endl;
    writeBuf << white_fg << "       OR      Movement" << endl;
    writeBuf << white_fg << "  H, J, K, L : " << endl;
    writeBuf << white_fg << "  S or ENTER : Sweep" << endl;
    writeBuf << white_fg << "  F or SPACEBAR : Toggle Flag" << endl;
    writeBuf << white_fg << "  R : Reveal if empty" << endl;
}

void dispVictoryOrDefeat()
{
    writeBuf << endl;
    COLOUR col = gameState == VICTORY ? green_fg : red_fg;

    if (gameState == VICTORY)
    {
        writeBuf << col << R"(  Success!  )" << endl;
    }

    else
    {
        writeBuf << col << R"(  Try again..  )" << endl;
    }
}

void setGameMode()
{
    int ch = 2;

    gameMode = (GAME_MODE)ch;
}

void getQuickClearSettings()
{
  QUICKCLEAR = true;
}
