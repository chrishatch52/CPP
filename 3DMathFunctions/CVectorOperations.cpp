#include "CVectorOperations.h"



namespace VecOps {

	Vec3 add(const Vec3& u, const Vec3& v)
	{
		return Vec3(
			(u.mI + v.mI),
			(u.mJ + v.mJ),
			(u.mK + v.mK)
		);
	}

	Vec3 crossProduct(const Vec3& u, const Vec3& v)
	{
		return Vec3(
			((u.mJ * v.mK) - (u.mK * v.mJ)), 
			((u.mK * v.mI) - (u.mI * v.mK)),
			((u.mI * v.mJ) - (u.mJ * v.mI))
		);
	}

	int dotProduct(const Vec3& u, const Vec3& v)
	{
		return ((u.mI * v.mI) + (u.mJ * v.mJ) + (u.mK * v.mK));
	}

	float findAngle_cosine(const Vec3& u, const Vec3& v)
	{
		return std::acos((dotProduct(u,v))/((magnitude(u) * magnitude(v))));
	}

	float findAngle_sine(const Vec3& u, const Vec3& v)
	{
		return std::asin(magnitude((crossProduct(u, v))) / ((magnitude(u) * magnitude(v))));
	}

	Vec3 normalize(const Vec3& u)
	{
		float mag = magnitude(u);

		return Vec3(
			(u.mI / mag), 
			(u.mJ / mag),
			(u.mK / mag)
		);
	}

	float magnitude(const Vec3& u)
	{
		return std::sqrt(std::pow(u.mI, 2) + std::pow(u.mJ, 2) + std::pow(u.mK, 2));
	}

	Vec3 multiplyMatrix(Vec3& u, const Mat3x3& A)
	{
		return Vec3(
			((A.mRight.mI * u.mI) + (A.mUp.mI * u.mI) + (A.mForward.mI * u.mI)),
			((A.mRight.mJ * u.mJ) + (A.mUp.mJ * u.mJ) + (A.mForward.mJ * u.mJ)),
			((A.mRight.mK * u.mK) + (A.mUp.mK * u.mK) + (A.mForward.mK * u.mK))
		);
	}

	Vec3 scalar(float f, Vec3 & u)
	{
		return Vec3((f*u.mI),(f*u.mJ),(f*u.mK));
	}

	Vec3 subtract(const Vec3& u, const Vec3& v)
	{
		return Vec3(
			(u.mI - v.mI),
			(u.mJ - v.mJ),
			(u.mK - v.mK)
		);
	}

	Vec4 add(const Vec4& u, const Vec4& v)
	{
		return Vec4(
			(u.mI + v.mI),
			(u.mJ + v.mJ),
			(u.mK + v.mK),
			(u.mW + v.mW)
		);
	}

	Vec4 subtract(const Vec4& u, const Vec4& v)
	{
		return Vec4(
			(u.mI - v.mI),
			(u.mJ - v.mJ),
			(u.mK - v.mK),
			(u.mW - v.mW)
		);
	}
	Vec3 toVec3(const Vec4 & A)
	{
		return Vec3(std::move(A.mI), std::move(A.mJ), std::move(A.mK));
	}
}


