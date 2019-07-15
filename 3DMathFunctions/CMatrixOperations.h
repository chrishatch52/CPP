#pragma once

namespace  MatrixOperations {

	/*3x3 Matrix Ops*/
		
		static Mat3x3 add(const Mat3x3 & rhs);
		static Mat3x3 addVector(const Mat3x3& A, const Vec3& x);
		static Mat3x3 determinant(const Mat3x3& A);
		static Mat3x3 inverse(const Mat3x3& A);
		static Mat3x3 multiply(const Mat3x3& lhs, const Mat3x3& rhs);
		static Mat3x3 multiplyVector(const Mat3x3& A, const Vec3& x);	
		static bool orthogonal(const Mat3x3 & A);
		static Mat3x3 transpose(const Mat3x3& A);

	/*Conversion Ops*/

		static Mat3x3 convert4x3to3x3(const Mat4x3& A);
		static Mat3x3 convert4x4to3x3(const Mat4x4& A);
		static Mat4x3 convert3x3to4x3(const Mat3x3& A);
		static Mat4x3 convert4x4to4x3(const Mat4x4& A);
		static Mat4x4 convert3x3to4x4(const Mat3x3& A);
		static Mat4x4 convert4x3to4x4(const Mat4x3& A);


	/*4x4 Matrix Ops*/
		
		static Mat4x4 add(const Mat4x4& lhs, const Mat4x4& rhs);
		static Mat4x4 addVector(const Mat4x4& A, const Vec4& x);
		static Mat4x4 determinant(const Mat4x4& A);
		static Mat4x4 inverse(const Mat4x4& A);
		static Mat4x4 multiply(const Mat4x4& lhs, const Mat4x4& rhs);
		static Mat4x4 multiplyVector(const Mat4x4& A, const Vec4& x);
		static bool orthogonal(const Mat4x4& A);
		static Mat4x4 transpose(const Mat4x4& A);

}