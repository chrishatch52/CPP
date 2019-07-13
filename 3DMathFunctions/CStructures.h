#pragma once

struct Vec3 {
	float mI;
	float mJ;
	float mK;

	Vec3(float i, float j, float k) 
		: mI(i), mJ(j), mK(k) {}
};

struct Vec4 {
	float mI;
	float mJ;
	float mK;
	float mW;

	Vec4(float i, float j, float k, float w) 
		: mI(i), mJ(j), mK(k), mW(w) {}
};

struct Mat3x3 {
	Vec3 mRight;
	Vec3 mUp;
	Vec3 mForward;

	Mat3x3(Vec3 right, Vec3 up, Vec3 forward) 
		: mRight(right), mUp(up), mForward(forward) {}
};

struct Mat4x3 {
	Vec4 mRight;
	Vec4 mUp;
	Vec4 mForward;

	Mat4x3(Vec4 right, Vec4 up, Vec4 forward) 
		: mRight(right), mUp(up), mForward(forward) {}
};

struct Mat4x4 {
	Vec4 mRight;
	Vec4 mUp;
	Vec4 mForward;
	Vec4 mPosition;

	Mat4x4(Vec4 right, Vec4 up, Vec4 forward, Vec4 position) :
		mRight(right), 
		mUp(up), 
		mForward(forward), 
		mPosition(position)
	{}

};