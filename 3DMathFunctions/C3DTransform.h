#pragma once
#include "CStructures.h"
#include <vector>

class C3DTransform
{

	enum class Type {
		Mat2x2 = 0x00,
		Mat3x3 = 0x01,
		Mat4x3 = 0x10,
		Mat4x4 = 0x11
	};

	const std::vector<std::pair<int, int>> m_dimensions = {
			std::pair<int,int>(2,2),
			std::pair<int,int>(3,3),
			std::pair<int,int>(4,3),
			std::pair<int,int>(4,4)
	};


public:
	C3DTransform();
	~C3DTransform();

	static C3DTransform build_transform() { return C3DTransform(); }

	//std::pair<int, int> m_getDimensions(Type type);
	Mat4x4& get_matrix() { return m_matrix; }

private:

	union {
		float m_data2x2[2][2];
		float m_data3x3[3][3];
		float m_data4x3[4][3];
		float m_data4x4[4][4];
	};

	Mat4x4 m_matrix;
};

