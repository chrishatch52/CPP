#pragma once

struct Vec {
	float mI;
	float mJ;

	Vec(float i, float j)
		: mI(i), mJ(j) {}
};

struct Vec3 : Vec {

	float mK;

	Vec3(float i, float j, float k) : Vec(i, j), mK(k) {}
};

struct Vec4 : Vec3 {

	float mW;

	Vec4(float i, float j, float k, float w)
		: Vec3(i, j, k), mW(w) {}
};

struct Matrix {};

struct Mat2x2 : Matrix {
	Vec mRight;
	Vec mUp;

	Mat2x2(Vec right, Vec up) : mRight(right), mUp(up) {}

};

struct Mat3x3 : Matrix {
	Vec3 mRight;
	Vec3 mUp;
	Vec3 mForward;

	Mat3x3(Vec3 right, Vec3 up, Vec3 forward)
		: mRight(right), mUp(up), mForward(forward) {}

	Mat3x3(float f_i, float f_j, float f_k,
		float r_i, float r_j, float r_k,
		float u_i, float u_j, float u_k) :
			mForward(Vec3(f_i, f_j, f_k)), mRight(Vec3(r_i, r_j, r_k)), mUp(Vec3(u_i, u_j, u_k)) {}
};

struct Mat4 : Matrix {
	Vec4 mRight;
	Vec4 mUp;
	Vec4 mForward;

	Mat4(Vec4 right, Vec4 up, Vec4 forward)
		: mRight(right), mUp(up), mForward(forward) {}

};

struct Mat4x3 : Mat4 {

	Mat4x3(Vec4 right, Vec4 up, Vec4 forward) : Mat4(right, up, forward) {}
};

struct Mat4x4 : Mat4 {

	Vec4 mPosition;

	Mat4x4(Vec4 right, Vec4 up, Vec4 forward, Vec4 position)
		: Mat4(right, up, forward),
			mPosition(position) {}
	Mat4x4(
		float f_i, float f_j, float f_k, float f_w,
		float r_i, float r_j, float r_k, float r_w,
		float u_i, float u_j, float u_k, float u_w,
		float p_i, float p_j, float p_k, float p_w) :
		Mat4(Vec4(f_i, f_j, f_k, f_w),Vec4(r_i, r_j, r_k, r_w),Vec4(u_i, u_j, u_k, u_w)),
		mPosition(Vec4(p_i, p_j, p_k, p_w)) {}

};
