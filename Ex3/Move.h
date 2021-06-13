#pragma once
class Move 
{
public:
	Move(int r, int c)
	{
		_row = r;
		_col = c;
	}
	int getX() const { return _row; }
	int getY() const { return _col; }
private:
	int _row, _col;
};