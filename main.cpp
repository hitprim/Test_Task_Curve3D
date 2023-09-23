
//#include "Curves.h"
#include "bin/library.h"
#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <algorithm>
#include <cmath>
#include <random>


double RandomNum(double min, double max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    std::vector<std::shared_ptr<Curve3D>> curves;

    for (int i = 0; i < 3; ++i) {
        double radius = RandomNum(1.0, 5.0);
        double param = RandomNum(0.1, 2.0);
        if (i % 3 == 0){
            curves.push_back(std::make_shared<Circle3D>(radius));
        } else if (i % 3 == 1){
            curves.push_back(std::make_shared<Ellipse>(radius, param));
        } else{
            curves.push_back(std::make_shared<Helix>(radius, param));
        }
    }

    double t = M_PI / 4;
    for (auto &curve : curves){
        auto point =  curve->CalculatePoint(t);
        auto  derivative = curve->CalculateDerivative(t);

        std::cout << "Point: (" << std::get<0>(point) << ", " << std::get<1>(point) << ", " << std::get<2>(point) << ")\n";
        std::cout << "Derivative: (" << std::get<0>(derivative) << ", " << std::get<1>(derivative) << ", " << std::get<2>(derivative) << ")\n";
    }

    std::vector<std::shared_ptr<Circle3D>> circles;
    for (auto& curve : curves){
        if (auto circle = std::dynamic_pointer_cast<Circle3D>(curve)){
            circles.push_back(circle);
        }
    }

    std::sort(circles.begin(), circles.end(), [](auto a, auto b){
        double x_a = std::get<0>(a->CalculatePoint(0));
        double x_b = std::get<0>(a->CalculatePoint(0));
        return x_a < x_b;
    });

    double sumOfRadii = 0.0;
    for(auto &circle : circles){
        sumOfRadii += std::get<0>(circle->CalculatePoint(0));
    }

    std::cout << "Total sum: " << sumOfRadii << '\n';

    std::cin.get();
    return EXIT_SUCCESS;
}
