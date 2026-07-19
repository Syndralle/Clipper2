#include <cstdint>
#include <iostream>
#include <vector>

struct Point {
    bool operator==(const Point &other) {
        return x_ == other.x_ && y_ == other.y_;
    }
    bool operator!=(const Point &other) { return !(*this == other); }
    int64_t x_;
    int64_t y_;
};

#define LEFT 1 << 0
#define RIGHT 1 << 1
#define BOTTOM 1 << 2
#define TOP 1 << 3

bool Collinear(const Point &a, const Point &b, const Point &c) {
    return (b.x_ - a.x_) * (c.y_ - a.y_) == (b.y_ - a.y_) * (c.x_ - a.x_);
}

void print_points(const std::vector<Point> &points) {
    printf("\n");
    for (size_t i = 0; i < points.size(); i++) {
        std::cout << points[i].x_ << " " << points[i].y_ << "\n";
    }
}

// ccw case
std::vector<Point> grow(const std::vector<Point> &geom, int64_t size,
                        char direction) {
    if (geom.empty())
        return {};
    size_t sz = geom.size();
    size_t last_index = sz - 1;
    std::vector<Point> result;
    for (size_t i = 0; i < sz; i++) {
        Point last = geom[last_index];
        Point cur = geom[i];
        Point next = geom[(i + 1) % sz];
        int64_t delta_x = cur.x_ - last.x_;
        int64_t delta_y = cur.y_ - last.y_;
        switch (direction) {
        case (LEFT):
            if (delta_y < 0) {
                last.x_ -= size;
                cur.x_ -= size;
            } else if (!delta_y && delta_x > 0) {
                last.x_ -= size;
            } else if (!delta_y && delta_x < 0) {
                cur.x_ -= size;
            }
            break;
        case (RIGHT):
            if (delta_y > 0) {
                last.x_ += size;
                cur.x_ += size;
            } else if (!delta_y && delta_x > 0) {
                cur.x_ += size;
            } else if (!delta_y && delta_x < 0) {
                last.x_ += size;
            }
            break;
        case (BOTTOM):
            if (delta_x > 0) {
                last.y_ -= size;
                cur.y_ -= size;
            } else if (delta_x == 0 && delta_y > 0) {
                last.y_ -= size;
            } else if (delta_x == 0 && delta_y < 0) {
                cur.y_ -= size;
            }
            break;
        case (TOP):
            if (delta_x < 0) {
                last.y_ += size;
                cur.y_ += size;
            } else if (delta_x == 0 && delta_y > 0) {
                cur.y_ += size;
            } else if (delta_x == 0 && delta_y < 0) {
                last.y_ += size;
            }
        default:
            break;
        }
        if (result.empty() || last != result.back()) {
            result.push_back(last);
        }
        if (result.empty() || (cur != result.front() && cur != last)) {
            result.push_back(cur);
        }
        last_index = i;
    }
    return result;
}

int main() {
    // std::vector<Point> rect = {{0, 0}, {100, 0}, {100, 50}, {0, 50}};
    // std::vector<Point> oct = {{40, 0},   {60, 0},   {100, 40}, {100, 60},
    //                           {60, 100}, {40, 100}, {0, 60},   {0, 40}};
    // std::vector<Point> trapezoid = {{30, 0}, {100, 0}, {100, 50}, {0, 50}};
    std::vector<Point> rect = {{40, 0},   {60, 0},   {100, 40}, {100, 60},
                               {60, 100}, {40, 100}, {0, 60},   {0, 40}};
    auto result = grow(rect, -30, LEFT);
    print_points(result);
    result = grow(rect, -10, RIGHT);
    print_points(result);
    result = grow(rect, -10, BOTTOM);
    print_points(result);
    result = grow(rect, -10, TOP);
    print_points(result);
}
