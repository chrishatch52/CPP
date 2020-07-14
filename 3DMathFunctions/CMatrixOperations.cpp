#include "stdafx.h"


namespace MatOps {

	signed int determinant2x2(Mat2x2 & A)
	{
		return ((A.mUp.mI * A.mRight.mJ) - (A.mUp.mJ * A.mRight.mI));
	}

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

	signed int determinant3x3(const Mat3x3 & A)
	{
		Vec tmp0 = Vec(A.mForward.mJ, A.mForward.mK);
		Vec tmp1 = Vec(A.mRight.mJ, A.mRight.mK);
		Vec tmp2 = Vec(A.mUp.mJ, A.mUp.mK);

		float tmpForward_i = A.mForward.mI;
		float tmpRight_i = A.mRight.mI;
		float tmpUp_i = A.mUp.mI;

		Mat2x2 tmp3(tmp1, tmp2);
		Mat2x2 tmp4(tmp0, tmp2);
		Mat2x2 tmp5(tmp0, tmp1);

		return ( (tmpForward_i * (determinant2x2(tmp3))))
			- (tmpRight_i * (determinant2x2(tmp4)))
			+ (tmpUp_i * (determinant2x2(tmp5)) );
	}

	bool equals3x3(const Mat3x3 & rhs, const Mat3x3 & lhs)
	{
		return false;
	}

	Mat3x3 inverse(const Mat3x3 & A)
	{
		Mat3x3 temp = transpose(A);

		float scalar = 1/ determinant3x3(A);

		return Mat3x3(VecOps::scalar(scalar, temp.mRight),
						VecOps::scalar(scalar, temp.mUp),
						VecOps::scalar(scalar, temp.mForward));
	}

	Mat3x3 multiply(const Mat3x3& lhs, const Mat3x3& rhs)
	{
		Mat3x3 temp = inverse(lhs);
		
		Vec3 tempRight = VecOps::multiplyMatrix(temp.mRight, rhs);
		Vec3 tempUp = VecOps::multiplyMatrix(temp.mUp, rhs);
		Vec3 tempForward = VecOps::multiplyMatrix(temp.mForward, rhs);

		return Mat3x3(tempRight, tempUp, tempForward);
	}

	bool orthogonal3x3(const Mat3x3 & A)
	{
		Mat3x3 identity = Mat3x3(1.f,0.f,0.f,
							0.f,1.f,0.f,
							0.f,0.f,1.f);

		return (equals3x3(multiply(A, A), identity));
	}

	Mat3x3 transpose(const Mat3x3 & A)
	{
		Vec3 i_forward(A.mRight.mI, A.mUp.mI, A.mForward.mI);
		Vec3 i_right(A.mRight.mJ, A.mUp.mJ, A.mForward.mJ);
		Vec3 i_up(A.mRight.mK, A.mUp.mK, A.mForward.mK);

		return Mat3x3(i_right, i_up, i_forward);
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

	signed int determinant4x4(const Mat4x4 & A)
	{

		return 0;
	}

	bool equals4x4(const Mat4x4 & rhs, const Mat4x4 & lhs)
	{
		
	}

	Mat4x4 inverse(const Mat4x4 & A)
	{
		return Mat4x4();
	}

	Mat4x4 multiplyVector(const Mat4x4 & A, const Vec4 & x)
	{
		return Mat4x4();
	}

	bool orthogonal4x4(const Mat4x4 & A)
	{
		Mat4x4 identity = Mat4x4(
			1.f, 0.f, 0.f, 0.f,
			0.f, 1.f, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f);

		return (equals4x4(multiply(A, A), identity));
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