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

struct Mat2x2 {
	Vec mRight;
	Vec mUp;

	Mat2x2(Vec right, Vec up) : mRight(right), mUp(up) {}
	
};

struct Mat3x3 {
	Vec3 mRight;
	Vec3 mUp;
	Vec3 mForward;

	Mat3x3(Vec3 right, Vec3 up, Vec3 forward) 
		: mRight(right), mUp(up), mForward(forward) {}
};

struct Mat4 {
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
			mPosition(position) 	{}

};