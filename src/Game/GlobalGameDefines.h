#pragma once
//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

namespace GameGlobalVar
{
	const int screenWidth = 1280;
	const int screenHeight = 800;

	constexpr int gameplayLeftBorder = 180;
	constexpr int gameplayRightBorder = screenWidth - 270;
	constexpr int gameplayTopBorder = 140;
	constexpr int gameplayBottomBorder = screenHeight - 160;

	#define GREENLIGHT CLITERAL(Color){ 170, 214, 156, 255 }
}

#endif