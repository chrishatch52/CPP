#pragma once
#include "CMatrixOperations.h"
#include "CVectorOperations.h"

using namespace MatrixOperations;

namespace LinearOperations {

	class LinOps {

	public:
		static void buildWorldTransform(Mat4x4& matrix, const Vec3& position, float angleX, float angleY, float angleZ);
		static Mat4x4 buildRelativeTransform(const Mat4x4& parent, const Mat4x4& child);
		static Mat4x4 composeTransform(const Mat4x4& A, const Mat4x4& B);

		static void rotation_arbitraryAxis(Mat4x4& A, const Vec3& origin, float angle);
		static void rotation_xAxis(Mat4x4& A, float angle);
		static void rotation_yAxis(Mat4x4& A, float angle);
		static void rotation_zAxis(Mat4x4& A, float angle);

		static void scale(Mat4x4& A, Vec4& u);
		static void translate(Mat4x4& A, const Vec3& u);

		const Mat4x4 m_Identity4x4 = Mat4x4(Vec4(1, 0, 0, 0), Vec4(0, 1, 0, 0), Vec4(0, 0, 1, 0), Vec4(0, 0, 0, 1));
		
	};

}