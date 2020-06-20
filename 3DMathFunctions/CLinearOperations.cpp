#include "stdafx.h"

namespace LinearOperations {

	void LinOps::buildWorldTransform(Mat4x4& matrix, const Vec3& position, float angleX, float angleY, float angleZ)
	{
		rotation_zAxis(matrix, angleZ);
		rotation_yAxis(matrix, angleY);
		rotation_xAxis(matrix, angleX);
		translate(matrix, position);
	}

	Mat4x4 LinOps::buildRelativeTransform(const Mat4x4& parent, const Mat4x4& child)
	{
		return MatOps::multiply(child, MatOps::inverse(parent));
	}

	Mat4x4 LinOps::composeTransform(const Mat4x4& A, const Mat4x4& B)
	{
		return MatOps::multiply(A,B);
	}

	void LinOps::scale(Mat4x4& A, Vec4& u)
	{
		A.mRight.mI *= u.mI;
		A.mUp.mJ *= u.mJ;
		A.mForward.mK *= u.mK;
	}
	
	void LinOps::translate(Mat4x4& A, const Vec3& u)
	{
		A.mPosition.mI += u.mI;
		A.mPosition.mJ += u.mJ;
		A.mPosition.mK += u.mK;
	}

	void LinOps::rotation_arbitraryAxis(Mat4x4& A, const Vec3& origin, float angle)
	{
		//Expose Euler angles to find current axis rotations
		float angleX = std::atan2(A.mUp.mK, A.mForward.mK);
		float angleY = std::atan2(-(A.mRight.mK), std::sqrt(std::pow(A.mUp.mK, 2) + std::pow(A.mForward.mK, 2)));
		float angleZ = atan2(A.mRight.mJ, A.mRight.mI);

		Vec3 invOrigin(-origin.mI, -origin.mJ, -origin.mK);

		translate(A, origin);

		//Prevent against Gimbal lock without using Quaternions
		if (angleY == 90.f || angleY == -90.f) 
			angleX = 180.f;

		rotation_xAxis(A, angleX);
		rotation_yAxis(A, angleY);
		rotation_zAxis(A, angle);
		rotation_yAxis(A, -angleY);
		rotation_xAxis(A, -angleX);
		translate(A, invOrigin);
	}

	void LinOps::rotation_xAxis(Mat4x4& A, float angle)
	{
		Mat4x4 rotation(
			Vec4(1.f, 0.f, 0.f, 0.f),
			Vec4(0.f, std::cos(angle), -std::sin(angle), 0.f),
			Vec4(0.f, std::sin(angle), std::cos(angle), 0.f),
			Vec4(0.f, 0.f, 0.f, 1.f)
		);
	}

	void LinOps::rotation_yAxis(Mat4x4& A, float angle)
	{
		Mat4x4 rotation(
			Vec4(std::cos(angle), 0.f, std::sin(angle), 0.f),
			Vec4(0.f, 0.f, 0.f, 0.f),
			Vec4(-std::sin(angle), 0.f, std::cos(angle), 0.f),
			Vec4(0.f, 0.f, 0.f, 1.f)
		);
	}

	void LinOps::rotation_zAxis(Mat4x4& A, float angle)
	{
		Mat4x4 rotation(
			Vec4(std::cos(angle), -std::sin(angle), 0.f, 0.f),
			Vec4(std::sin(angle), std::cos(angle), 0.f, 0.f),
			Vec4(0.f, 0.f, 1.f, 0.f),
			Vec4(0.f, 0.f, 0.f, 1.f)
		);
	}
}