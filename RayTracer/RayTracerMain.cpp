#include "ray.h"
#include <iostream>
#include <fstream>

using namespace std;

vec3 color(const ray r) {
	vec3 unit_direction = unit_vector(r.direction());
	float t = float(0.5 * (unit_direction.y() + 1.0));
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}
int main()
{
	int nx = 200;
	int ny = 100;
	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);
	ofstream graphicsFile("firstproject.ppm");
	if (graphicsFile.is_open()) {
		graphicsFile << "P3\n" << nx << " " << ny << "\n255\n";
		for (int j = (ny - 1);j >= 0; j--) {
			for (int i = 0; i < nx; i++) {
				float u = float(i) / float(nx);
				float v = float(j) / float(ny);
				ray r(origin, lower_left_corner + u * horizontal + v * vertical);
				vec3 col(color(r));
				int ir = int(255.99 * col[0]);
				int ig = int(255.99 * col[1]);
				int ib = int(255.99 * col[2]);
				graphicsFile << ir << " " << ig << " " << ib << "\n";
			}
		}
		graphicsFile.close();
	}
	else {
		cout << "Unable to open file.";
	}
	return 0;
}