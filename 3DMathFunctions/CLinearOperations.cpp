#include "stdafx.h"

namespace LinearOperations {

	Mat4x4 LinOps::composeTransform(const Mat4x4 & A, const Mat4x4 & B)
	{
		return A*B;
	}
	void LinOps::findWorldTransform(Mat4x4& matrix, const Vec3 & position, float angleX, float angleY, float angleZ)
	{
		rotate(matrix, angleZ, 2)*rotate(matrix, angleY, 1)*rotate(matrix, angleX, 0);
		translate(matrix, position);
	}
	Mat4x4 LinOps::findRelativeTransform(const Mat4x4 & parent, const Mat4x4 & child)
	{
		return MatrixOperations::inverse(parent) * child;
	}
	Mat4x4 LinOps::rotate(const Mat4x4 & A, const Mat4x4 & rotation)
	{
		return Mat4x4();
	}
	Mat4x4 LinOps::rotate(const Mat4x4 & A, float angle, unsigned int axis)
	{
		return Mat4x4();
	}
	Mat4x4 LinOps::scale(const Mat4x4 & A, unsigned int axis, unsigned int factor)
	{
		return Mat4x4();
	}
	Mat4x4 LinOps::translate(Mat4x4 & A, const Vec3 & u)
	{
		return Mat4x4();
	}
	Mat4x4 LinOps::buildArbitraryRotation(const Mat4x4 & A, const Vec3 & origin, float angle)
	{
		return Mat4x4();
	}
	Mat4x4 LinOps::buildRotation_xAxis(const Mat4x4 & A, float angle)
	{
		return Mat4x4();
	}
	Mat4x4 LinOps::buildRotation_yAxis(const Mat4x4 & A, float angle)
	{
		return Mat4x4();
	}
	Mat4x4 LinOps::buildRotation_zAxis(const Mat4x4 & A, float angle)
	{
		return Mat4x4();
	}
}