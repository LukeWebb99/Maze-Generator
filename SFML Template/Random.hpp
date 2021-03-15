#include <iostream>
#include <random>

class Random
{
public:
	Random(const Random&) = delete;

	static Random& Get() {
		return s_Instance;
	}

	float Float(float min, float max, float precision) {
		std::random_device m_device;
		std::mt19937 generator(m_device());
		std::uniform_int_distribution<int> distribution(min, max);
		return distribution(generator) * precision;

	};

	int Int(int min, int max) {
		std::random_device m_device;
		std::mt19937 generator(m_device());
		std::uniform_int_distribution<int> distribution(min, max);
		return distribution(generator);

	};

private:

	Random() {

	};

	static Random s_Instance;

};

