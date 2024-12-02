#ifndef ENGINE_MATRIX_MATH
#define ENGINE_MATRIX_MATH

#include <cstdlib>

class Matrix
{
private:
	float** makeMatrix(int rows, int columns)
	{
		if ((rows == 0 || rows < 0) || (columns == 0 || columns < 0))
			return nullptr;

		float** matrix = (float**) malloc(sizeof(float*) * rows);
		
		for (int row = 0; row < rows; row++)
		{
			*(matrix + row) = (float*) malloc(sizeof(float) * columns);
		}

		/* Fill with zeros */
		for (int row = 0; row < rows; row++)
		{
			for (int column = 0; column < columns; column++)
			{
				*(*(matrix + row) + column) = 0.0f;
			}
		}

		return matrix;
	}

public:
	struct Mat2D {
		float** data;
		bool isIdentical;

		float getElementAt(int row, int col)
		{
			return *(*(data + row) + col);
		}

		void setElementAt(int row, int col, float value)
		{
			*(*(data +row) + col) = value;
		}

		void makeIdentity()
		{
			for (int row = 0; row < 2; row++)
			{
				for (int column = 0; column < 2; column++)
				{
					if (row == column)
					{
						setElementAt(row, column, 1.0f);
					}
					else
					{
						setElementAt(row, column, 0.0f);
					}
				}
			}
		}
	};

	struct Mat3D {
		float** data;
		bool isIdentical;

		float getElementAt(int row, int col)
		{
			return *(*(data + row) + col);
		}

		void setElementAt(int row, int col, float value)
		{
			*(*(data + row) + col) = value;
		}

		void makeIdentity()
		{
			for (int row = 0; row < 3; row++)
			{
				for (int column = 0; column < 3; column++)
				{
					if (row == column)
					{
						setElementAt(row, column, 1.0f);
					}
					else
					{
						setElementAt(row, column, 0.0f);
					}
				}
			}
		}
	};

	struct Mat4D {
		float** data;
		bool isIdentical;

		float getElementAt(int row, int col)
		{
			return *(*(data + row) + col);
		}

		void setElementAt(int row, int col, float value)
		{
			*(*(data + row) + col) = value;
		}

		void makeIdentity()
		{
			for (int row = 0; row < 4; row++)
			{
				for (int column = 0; column < 4; column++)
				{
					if (row == column)
					{
						setElementAt(row, column, 1.0f);
					}
					else
					{
						setElementAt(row, column, 0.0f);
					}
				}
			}
		}
	};

	Mat2D get2DMatrix(bool isIdentical)
	{
		Mat2D mat2D;
		mat2D.data = makeMatrix(2, 2);

		if (isIdentical)
		{
			mat2D.makeIdentity();
		}

		return mat2D;
	}

	Mat3D get3DMatrix(bool isIdentical)
	{
		Mat3D mat3D;
		mat3D.data = makeMatrix(3, 3);

		if (isIdentical)
		{
			mat3D.makeIdentity();
		}

		return mat3D;
	}

	Mat4D get4DMatrix(bool isIdentical)
	{
		Mat4D mat4D;
		mat4D.data = makeMatrix(4, 4);

		if (isIdentical)
		{
			mat4D.makeIdentity();
		}

		return mat4D;
	}

	void printMatrix(Mat2D matrix)
	{
		for (int row = 0; row < 2; row++)
		{
			for (int col = 0; col < 2; col++)
			{
				std::cout << " " << matrix.getElementAt(row, col);
			}
			std::cout << std::endl;
		}
	}

	void printMatrix(Mat3D matrix)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				std::cout << " " << matrix.getElementAt(row, col);
			}
			std::cout << std::endl;
		}
	}

	void printMatrix(Mat4D matrix)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				std::cout << " " << matrix.getElementAt(row, col);
			}
			std::cout << std::endl;
		}
	}
};



#endif