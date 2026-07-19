#include <clipper2/clipper.h>

using namespace Clipper2Lib;

int main() {
    // Path64 rect1{{0, 0}, {100, 0}, {100, 100}, {0, 100}};
    // Path64 rect2{{50, 50}, {150, 50}, {150, 150}, {50, 150}};
    // Path64 rect1{{2, 2}, {8, 5}, {4, 10}};
    // Path64 rect2{{5, 1}, {11, 7}, {6, 11}};

    // Path64 rect1{{0, 0}, {0, 1}, {1, 1}, {3, -1}, {5, 1}, {6, 1}, {6, 0}};
    // Path64 rect2{{0, 0}, {0, 1}, {6, 1}, {6, 0}};
    // Path64 rect1{{0, 0}, {2, 2}, {2, 4}, {0, 6}, {2, 6}, {0, 4}, {0, 2}, {2,
    // 0}};
    // Path64 rect1{{30, 40},  {70, 0},   {60, 0},   {100, 40},
    //              {100, 60}, {60, 100}, {70, 100}, {30, 60}};
    // Path64 rect2{{40, 0},   {0, 40},   {0, 60},   {40, 100},
    //              {60, 100}, {100, 60}, {100, 40}, {60, 0}};
    Path64 rect1{{50, 10}, {60, 10}, {60, -20}, {0, -20},
                 {0, 10},  {20, 10}, {40, -10}, {30, -10}};
    Paths64 polys;
    polys.push_back(rect1);
    // polys.push_back(rect2);
    // Paths64 polys1;
    // polys1.push_back(rect2);

    // Merge
    Paths64 result = Union(polys, FillRule::NonZero);
    // Paths64 result = Intersect(polys, polys1, FillRule::NonZero);

    std::cout << "Merged polygon count: " << result.size() << "\n\n";

    for (size_t i = 0; i < result.size(); ++i) {

        std::cout << "Polygon " << i << ":\n";
        for (const auto &p : result[i]) {
            std::cout << "(" << p.x << ", " << p.y << ")\n";
        }
        std::cout << '\n';
    }

    return 0;
}
