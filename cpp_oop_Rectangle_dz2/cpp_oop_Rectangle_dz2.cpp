#include <iostream>
#include <time.h>
#include<Windows.h>//	Sleep;
#include<conio.h>
using namespace std;
enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получаем дискриптор активного окна
void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27 };
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}


class myRectangle
{
private:
	//Rectangle
	int height = 4;
	int width = 4;
	Color color = Red;
	char symbol = '+';
	COORD startCoords{ 5,5 };

	//Frame
	int frame_height = 40;
	int frame_width = 40;
	Color frame_color_left = Red;
	Color frame_color_right = DarkGray;
	Color frame_color_top = Blue;
	Color frame_color_down = Green;
	COORD frame_start_coords{ 0,0 };

public:

	// Методы Frame

	void setFrameRandomColors()
	{
		Color tempcolor;
		do
		{
			frame_color_left = Color(1 + rand() % 15);
			tempcolor = Color(1 + rand() % 15);
			if (tempcolor != frame_color_left)
			{
				frame_color_right = tempcolor;
			}
			else
			{
				continue;
			}
			tempcolor = Color(1 + rand() % 15);
			if (tempcolor != frame_color_left and tempcolor != frame_color_right)
			{
				frame_color_top = tempcolor;
			}
			else
			{
				continue;
			}
			tempcolor = Color(1 + rand() % 15);
			if (tempcolor != frame_color_left and tempcolor != frame_color_right and tempcolor != frame_color_top)
			{
				frame_color_down = tempcolor;
				break;
			}
			else
			{
				continue;
			}

		} while (true);
	}

	void PrintFrame()
	{
		for (size_t i = 0; i < frame_height; i++)
		{
			SetCursor(frame_start_coords.X, frame_start_coords.Y + i);
			for (size_t j = 0; j < frame_width; j++)
			{
				if(i == 0)
				{
					SetColor(frame_color_top, frame_color_top);
				}
				else if (i == frame_height-1)
				{
					SetColor(frame_color_down, frame_color_down);
				}
				else if (j == 0)
				{
					SetColor(frame_color_left, frame_color_left);
				}
				else if (j == frame_width - 1)
				{
					SetColor(frame_color_right, frame_color_right);
				}
				else
				{
					SetColor(Black, Black);
				}
				cout << '@';
			}
		}
	}
	void setFrameHeight(int func_height)
	{
		if (func_height>10 and func_height < 100)
		{
			frame_height = func_height;
		}
	}
	void setFrameWidth(int func_width)
	{
		if (func_width > 10 and func_width <100)
		{
			frame_width = func_width;
		}
	}
	void setFrameColorLeft(Color func_colorleft)
	{
		frame_color_left = func_colorleft;
	}
	void setFrameColorRight(Color func_colorright)
	{
		frame_color_right = func_colorright;
	}
	void setFrameColorTop(Color func_colortop)
	{
		frame_color_top = func_colortop;
	}
	void setFrameColorDown(Color func_colordown)
	{
		frame_color_down = func_colordown;
	}
	void setCOORDS_Frame(int X, int Y)
	{
		frame_start_coords.X = X;
		frame_start_coords.Y = Y;
	}
	int getFrameX()
	{
		return frame_start_coords.X;
	}
	int getFrameY()
	{
		return frame_start_coords.Y;
	}
	COORD getFrameCOORDS()
	{
		return frame_start_coords;
	}
	Color getFrameColorDown()
	{
		return frame_color_down;
	}
	Color getFrameColorTop()
	{
		return frame_color_top;
	}
	Color getFrameColorRight()
	{
		return frame_color_right;
	}
	Color getFrameColorLeft()
	{
		return frame_color_left;
	}
	int getFrameWidth()
	{
		return frame_width;
	}
	int getFrameHeight()
	{
		return frame_height;
	}
	//Функция исключающая выпадение случайнго цвета равного цвету рамки
	Color setOneSideFrameRandomColor(Color nowcolor)
	{
		Color newcolor;
		do
		{
			newcolor = Color(1 + rand() % 15);
		} while (newcolor == nowcolor);
		return newcolor;
	}

	//Методы Rectangle

	void setRectColor(Color func_color)
	{
		if (func_color != Black)
		{
			color = func_color;
		}
	}

	void setRectSymbol(char func_char)
	{
		symbol = func_char;
	}

	void setCoords(int X, int Y)
	{
		if (X >= 0 and Y >= 0 and X < frame_start_coords.X-width-1 and Y < frame_start_coords.Y-height-1)
		{
			startCoords.X = X;
			startCoords.Y = Y;
		}
	}
	void setWidth(int Width)
	{
		if (Width > 1 && Width < 30)
		{
			width = Width;
		}
	}
	void setHeight(int Height)
	{
		//перед присвоением значения проверяем его
		if (Height > 1 && Height < 30)
		{
			height = Height;
		}
	}

	//блок методов, которые возвращают значения каждого поля
	int getHeight()
	{
		return height;
	}
	int getWidth()
	{
		return width;
	}
	Color getColor()
	{
		return color;
	}
	char getChar()
	{
		return symbol;
	}

	COORD getCOORD()
	{
		return startCoords;
	}

	int getX()
	{
		return startCoords.X;
	}
	int getY()
	{
		return startCoords.Y;
	}
	int getSquare()
	{
		return height * width;
	}
	void printRectangle()
	{
		SetColor(color, Black);
		for (size_t i = 0; i < height; i++)
		{
			SetCursor(startCoords.X, startCoords.Y + i);
			for (size_t j = 0; j < width; j++)
			{
				cout << symbol;
			}
		}
		SetColor(White, Black);
	}

	//метод для перемещения прямоугольника по нажатию клавиши
	int moveRect(/*int maxRight, int maxDown*/)
	{
		int key;
		printRectangle();
		key = _getch();
		clearRectangle();

		if (key == Up and startCoords.Y > 1)
		{
			startCoords.Y--;
		}
		if (key == Down and startCoords.Y < frame_height - height-1)
		{
			startCoords.Y++;
		}
		if (key == Left and startCoords.X > 1)
		{
			startCoords.X--;
		}
		if (key == Right and startCoords.X < frame_width- width -1)
		{
			startCoords.X++;
		}
		return key;
	}
	//метод для затирания прямоугольника
	void clearRectangle()
	{
		SetColor(Black, Black);
		for (size_t i = 0; i < height; i++)
		{
			SetCursor(startCoords.X, startCoords.Y + i);
			for (size_t j = 0; j < width; j++)
			{
				cout << symbol;
			}
		}
		SetColor(White, Black);
	}
};

void MainLoop(myRectangle Rinf)
{
	int button;
	bool top_y_test = false;
	bool down_y_test = false;
	bool left_x_test = false;
	bool right_x_test = false;
	do
	{
		SetColor(White, Black);
		SetCursor(45, 0);
		cout << "                            ";
		SetCursor(45, 0);
		cout << "Нач. X прям.уг.: " << Rinf.getX();
		SetCursor(45, 1);
		cout << "                            ";
		SetCursor(45, 1);
		cout << "Нач. Y прям.уг.: " << Rinf.getY();
		button = Rinf.moveRect();
		//Касание верха рамки
		// Если координаты прямоугольника за 1 позицию до координат рамки - срабатывает ключ, в противном случае ключ = false
		if (Rinf.getY()-2 == Rinf.getFrameY() )
		{
			top_y_test = true;
		}
		if (Rinf.getY()-1 == Rinf.getFrameY() and top_y_test)
		{
			Rinf.setRectColor(Rinf.getFrameColorTop());
			Rinf.setFrameColorTop(Rinf.setOneSideFrameRandomColor(Rinf.getFrameColorTop()));
			Rinf.PrintFrame();
			top_y_test = false;
		}
		//Касание низа рамки
		if (Rinf.getY()+Rinf.getHeight() == Rinf.getFrameY() + Rinf.getFrameHeight() - 2)
		{
			down_y_test = true;
		}
		if (Rinf.getY()+Rinf.getHeight() == Rinf.getFrameY() + Rinf.getFrameHeight()-1 and down_y_test)
		{
			Rinf.setRectColor(Rinf.getFrameColorDown());
			Rinf.setFrameColorDown(Rinf.setOneSideFrameRandomColor(Rinf.getFrameColorDown()));
			Rinf.PrintFrame();
			down_y_test = false;
		}
		//Касание левого края рамки
		if (Rinf.getX() - 2 == Rinf.getFrameX())
		{
			left_x_test = true;
		}
		if (Rinf.getX() - 1 == Rinf.getFrameX() and left_x_test)
		{
			Rinf.setRectColor(Rinf.getFrameColorLeft());
			Rinf.setFrameColorLeft(Rinf.setOneSideFrameRandomColor(Rinf.getFrameColorLeft()));
			Rinf.PrintFrame();
			left_x_test = false;
		}
		//Касание правого края рамки
		if (Rinf.getX() + Rinf.getWidth() == Rinf.getFrameX() + Rinf.getFrameWidth() - 2)
		{
			right_x_test = true;
		}
		if (Rinf.getX() + Rinf.getWidth() == Rinf.getFrameX() + Rinf.getFrameWidth() - 1 and right_x_test)
		{
			Rinf.setRectColor(Rinf.getFrameColorRight());
			Rinf.setFrameColorRight(Rinf.setOneSideFrameRandomColor(Rinf.getFrameColorRight()));
			Rinf.PrintFrame();
			right_x_test = false;
		}
	} while (button != esc);
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	myRectangle Rinf;

	//Начальные параметры прямоугольника и рамки
	Rinf.setRectColor(Yellow);
	Rinf.setRectSymbol('*');
	Rinf.setFrameHeight(25);
	Rinf.setFrameRandomColors();
	Rinf.PrintFrame();
	//Функция перемещения прямоугольника в рамке
	MainLoop(Rinf);
	return 0;
}