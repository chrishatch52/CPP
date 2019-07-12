#pragma once
#include <cmath>

namespace VectorOperations {

	class VecOps {

	public:
	/*3 Dimensional Vectors*/
		static Vec3 add(const Vec3& u, const Vec3& v);
		static Vec3 subtract(const Vec3& u, const Vec3& v);

		static Vec3 crossProduct(const Vec3& u, const Vec3& v);
		static int dotProduct(const Vec3& u, const Vec3& v);

		static float findAngle_cosine(const Vec3& u, const Vec3& v);
		static float findAngle_sine(const Vec3& u, const Vec3& v);

		static Vec3 normalize(const Vec3& u);
		static float magnitude(const Vec3& u);
		static Vec3 multiplyMatrix(const Vec3& u, const Mat3x3& A);

	/*4 Dimensional Vectors*/
		static Vec4 add(const Vec4& u, const Vec4& v);
		static Vec4 subtract(const Vec4& u, const Vec4& v);
	};

}