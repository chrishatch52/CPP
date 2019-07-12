#include "stdafx.h"


namespace MatrixOperations {


	Mat3x3& operator*(const Mat3x3& lhs, const Mat3x3& rhs)
	{
		return Mat3x3();
	}

	Mat3x3& operator+(const Mat3x3 & rhs)
	{
		return Mat3x3();
	}

	Mat3x3 addVector(const Mat3x3 & A, const Vec3 & x)
	{
		return Mat3x3();
	}

	Mat3x3 convert4x3to3x3(const Mat4x3 & A)
	{
		return Mat3x3();
	}

	Mat3x3 convert4x4to3x3(const Mat4x4 & A)
	{
		return Mat3x3();
	}

	Mat3x3 multiplyVector(const Mat3x3 & A, const Vec3 & x)
	{
		return Mat3x3();
	}

	Mat3x3 determinant(const Mat3x3 & A)
	{
		return Mat3x3();
	}

	Mat3x3 inverse(const Mat3x3 & A)
	{
		return Mat3x3();
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

	Mat4x4& operator*(const Mat4x4 & lhs, const Mat4x4 & rhs)
	{
		// TODO: insert return statement here
	}

	Mat4x4& operator+(const Mat4x4& rhs)
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

	Mat4x4 determinant(const Mat4x4 & A)
	{
		return Mat4x4();
	}

	Mat4x4 inverse(const Mat4x4 & A)
	{
		return Mat4x4();
	}

	Mat4x4 transpose(const Mat4x4 & A)
	{
		return Mat4x4();
	}

	Mat4x4 addVector(const Mat4x4 & A, const Vec4 & x)
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