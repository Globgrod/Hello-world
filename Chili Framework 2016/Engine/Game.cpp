/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}



void Game::UpdateModel()
{
	
	x_fixed4 = Width(x_fixed4);
	y_fixed4 = Height(y_fixed4);
	

		X_Right(x_fixed0);

	colliding = 
		Overlaptest(x_fixed0, y_fixed0, x_fixed4, y_fixed4) ||
		Overlaptest(x_fixed1, y_fixed1, x_fixed4, y_fixed4) ||
		Overlaptest(x_fixed2, y_fixed2, x_fixed4, y_fixed4) ||
		Overlaptest(x_fixed3, y_fixed3, x_fixed4, y_fixed4);

	
	
	
	
}	



void Game::ComposeFrame()
{
	
	DrawBox(x_fixed0, y_fixed0, 0, 255, 0);
	DrawBox(x_fixed1, y_fixed1, 0, 255, 0);
	DrawBox(x_fixed2, y_fixed2, 0, 255, 0);
	DrawBox(x_fixed3, y_fixed3, 0, 255, 0);

	

	if (colliding)
	{
		DrawBox(x_fixed4, y_fixed4, 255, 0, 0);
	}
	else
	{
		DrawBox(x_fixed4, y_fixed4, 255, 255, 255);
	}
}

void Game::DrawBox( int x,int y,int r,int g,int b )
{
	gfx.PutPixel(-5 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, -4 + y, r, g, b);
	gfx.PutPixel(-5 + x, -3 + y, r, g, b);
	gfx.PutPixel(-4 + x, -5 + y, r, g, b);
	gfx.PutPixel(-3 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 4 + y, r, g, b);
	gfx.PutPixel(-5 + x, 3 + y, r, g, b);
	gfx.PutPixel(-4 + x, 5 + y, r, g, b);
	gfx.PutPixel(-3 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, -4 + y, r, g, b);
	gfx.PutPixel(5 + x, -3 + y, r, g, b);
	gfx.PutPixel(4 + x, -5 + y, r, g, b);
	gfx.PutPixel(3 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, 4 + y, r, g, b);
	gfx.PutPixel(5 + x, 3 + y, r, g, b);
	gfx.PutPixel(4 + x, 5 + y, r, g, b);
	gfx.PutPixel(3 + x, 5 + y, r, g, b);
}

int Game::X_Right(int x)
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT));
		return x + 1;
	
}

bool Game::Overlaptest(int box0x, int box0y, int box1x, int box1y)
{
	const int left_box0 = box0x - 5;
	const int right_box0 = box0x + 5;
	const int bottom_box0 = box0y + 5;
	const int top_box0 = box0y - 5;

	const int left_box1 = box1x - 5;
	const int right_box1 = box1x + 5;
	const int bottom_box1 = box1y + 5;
	const int top_box1 = box1y - 5;

	return left_box0 <= right_box1 &&
		right_box0 >= left_box1 &&
		top_box0 <= bottom_box1 &&
		bottom_box0 >= top_box1;
}

int Game::Width(int x)
{
	const int left = x - 5;
	const int right = x + 5;
		if (left < 0)
		{
			return 5;
		}
		else if (right >= gfx.ScreenWidth)
		{
			return gfx.ScreenWidth - 6;
		}
		else 
		{
			return x;
		}
}

int Game::Height(int y)
{
	const int top = y - 5;
	const int bottom = y + 5;
	if (top < 0)
	{
		return 5;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		return gfx.ScreenHeight - 6;
	}
	else
	{
		return y;
	}
}