#pragma once

namespace  MatrixOperations {

	class MatOps {
	
		public:

		/*2x2 Matrix Ops*/
		
			static signed int determinant2x2(Mat2x2& A);

		/*3x3 Matrix Ops*/
		
			static Mat3x3 add(const Mat3x3 & rhs, const Mat3x3 & lhs);
			//static Mat3x3 addVector(const Mat3x3& A, const Vec3& x);
			static signed int laplace3x3(const Mat3x3& A); //using Laplace Expansion
			static Mat3x3 inverse(const Mat3x3& A);
			static Mat3x3 multiply(const Mat3x3& lhs, const Mat3x3& rhs);	
			static bool orthogonal3x3(const Mat3x3 & A);
			static Mat3x3 transpose(const Mat3x3& A);

		/*Conversion Ops*/

			static Mat3x3 convertTo3x3(const Mat4& A);
			static Mat4x3 convert3x3to4x3(const Mat3x3& A);
			static Mat4x3 convert4x4to4x3(const Mat4x4& A);
			static Mat4x4 convert3x3to4x4(const Mat3x3& A);
			static Mat4x4 convert4x3to4x4(const Mat4x3& A);


		/*4x4 Matrix Ops*/
		
			static Mat4x4 add(const Mat4x4& lhs, const Mat4x4& rhs);
			//static Mat4x4 addVector(const Mat4x4& A, const Vec4& x);
			static signed int determinant4x4(const Mat4x4& A);
			static Mat4x4 inverse(const Mat4x4& A);
			static Mat4x4 multiply(const Mat4x4& lhs, const Mat4x4& rhs);
			static Mat4x4 multiplyVector(const Mat4x4& A, const Vec4& x);
			static bool orthogonal4x4(const Mat4x4& A);
			static Mat4x4 transpose(const Mat4x4& A);
		};
}