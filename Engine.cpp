// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "Engine.h"

using namespace std;

int main()
{
	StandardMath* math = new StandardMath();
	Matrix* matrix = new Matrix();

	Matrix::Mat2D mat2D = matrix->get2DMatrix(true);
	mat2D.makeIdentity();
	matrix->printMatrix(mat2D);

	std::cout << "\n" << std::endl;

	Matrix::Mat3D mat3D = matrix->get3DMatrix(true);
	mat3D.makeIdentity();
	matrix->printMatrix(mat3D);

	std::cout << "\n" << std::endl;

	Matrix::Mat4D mat4D = matrix->get4DMatrix(true);
	mat4D.makeIdentity();
	matrix->printMatrix(mat4D);

	return 0;
}
