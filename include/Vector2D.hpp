#include <cmath>

struct Vector2D {
    float x;
    float y;

    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& p) const {
        return Vector2D(x + p.x, y + p.y);
    }

    Vector2D operator-(const Vector2D &p) const {
        return Vector2D(x - p.x, y - p.y);
    }

    Vector2D operator*(const float s) const {
        return Vector2D(x * s, y * s);
    }

    Vector2D operator/(const float s) const {
        return Vector2D(x / s, y / s);
    }

    Vector2D& operator+=(const Vector2D &p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Vector2D& operator-=(const Vector2D &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Vector2D& operator*=(const float s) {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2D& operator/=(const float s) {
        if (s != 0) {
            x /= s;
            y /= s;
        }
        return *this;
    }

    float magnitude() const {
        return std::sqrt(x*x + y*y);
    }

    void normalize() {
        float mag = magnitude();
        if (mag > 0) 
            *this /= mag;
        else {
            *this = Vector2D(0, 0);
        }
    }

    void limit(float max) {
        float mag = magnitude();
        if (mag > max)
            *this = (Vector2D(x, y) / mag) * max;
    }

    float distance(const Vector2D& p) const {
        return std::sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
    }
};