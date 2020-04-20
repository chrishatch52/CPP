#include "stdafx.h"


namespace MatrixOperations {

	using namespace VectorOperations;

	Mat3x3 add(const Mat3x3& lhs, const Mat3x3 & rhs)
	{
		return Mat3x3((VecOps::add(lhs.mRight,rhs.mRight)),
						(VecOps::add(lhs.mUp, rhs.mUp)),
						(VecOps::add(lhs.mForward, rhs.mForward)));
	}

	/*Mat3x3 addVector(const Mat3x3 & A, const Vec3 & x)
	{
		return Mat3x3();
	}*/

	Mat3x3 convertTo3x3(const Mat4 & A)
	{
		return Mat3x3(VecOps::toVec3(A.mRight),
						VecOps::toVec3(A.mUp),
						VecOps::toVec3(A.mForward));
	}

	signed int determinant(const Mat3x3 & A)
	{

		return 0;
	}

	Mat3x3 inverse(const Mat3x3 & A)
	{
		return Mat3x3();
	}

	Mat3x3 multiply(const Mat3x3& lhs, const Mat3x3& rhs)
	{
		return Mat3x3();
	}

	Mat3x3 multiplyVector(const Mat3x3 & A, const Vec3 & x)
	{
		return Mat3x3();
	}

	bool orthogonal(const Mat3x3 & A)
	{
		return false;
	}

	Mat3x3 transpose(const Mat3x3 & A)
	{
		return Mat3x3();
	}

	Mat4x3 convert3x3to4x3(const Mat3x3 & A)
	{
		return Mat4x3();
	}

	Mat4x3 convert4x4to4x3(const Mat4x4 & A)
	{
		return Mat4x3();
	}	

	Mat4x4 add(const Mat4x4 & lhs, const Mat4x4& rhs)
	{
		return Mat4x4();
	}

	Mat4x4 addVector(const Mat4x4 & A, const Vec4 & x)
	{
		return Mat4x4();
	}

	Mat4x4 multiply(const Mat4x4 & lhs, const Mat4x4 & rhs)
	{
		// TODO: insert return statement here
	}

	signed int determinant(const Mat4x4 & A)
	{
		return Mat4x4();
	}

	Mat4x4 inverse(const Mat4x4 & A)
	{
		return Mat4x4();
	}

	Mat4x4 multiplyVector(const Mat4x4 & A, const Vec4 & x)
	{
		return Mat4x4();
	}

	bool orthogonal(const Mat4x4 & A)
	{
		return false;
	}

	Mat4x4 transpose(const Mat4x4 & A)
	{
		return Mat4x4();
	}

	Mat4x4 convert3x3to4x4(const Mat3x3 & A)
	{
		return Mat4x4();
	}

	Mat4x4 convert4x3to4x4(const Mat4x3 & A)
	{
		return Mat4x4();
	}

};