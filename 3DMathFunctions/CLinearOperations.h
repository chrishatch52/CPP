#pragma once
#include "CMatrixOperations.h"
#include "CVectorOperations.h"

using namespace MatrixOperations;

namespace LinearOperations {

	class LinOps {

	public:
		static Mat4x4 composeTransform(const Mat4x4& A, const Mat4x4& B);
		static void findWorldTransform(Mat4x4& matrix, const Vec3& position, float angleX, float angleY, float angleZ);
		static Mat4x4 findRelativeTransform(const Mat4x4& parent, const Mat4x4& child);

		static Mat4x4 rotate(Mat4x4& A, const Mat4x4& rotation);
		static Mat4x4 rotate(Mat4x4& A, float angle, unsigned int axis);

		static Mat4x4 scale(Mat4x4& A, unsigned int axis, unsigned int factor);
		
		static Mat4x4 translate(Mat4x4& A, const Vec3& u);

	private:
		static Mat4x4 buildArbitraryRotation(const Mat4x4& A, const Vec3& origin, float angle);
		static Mat4x4 buildRotation_xAxis(const Mat4x4& A, float angle);
		static Mat4x4 buildRotation_yAxis(const Mat4x4& A, float angle);
		static Mat4x4 buildRotation_zAxis(const Mat4x4& A, float angle);

		const Mat4x4 _mIdentity4x4 = Mat4x4(Vec4(1, 0, 0, 0), Vec4(0, 1, 0, 0), Vec4(0, 0, 1, 0), Vec4(0, 0, 0, 1));
	};

}