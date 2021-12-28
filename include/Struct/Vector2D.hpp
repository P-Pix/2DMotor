#pragma once

#include <iostream>

namespace Structure {
    template<typename T>
    class Vector2D {
    private:
    protected:
        T m_X;
        T m_Y;

    public:
        Vector2D(void) {
            this->m_X = 0;
            this->m_Y = 0;
        }

        Vector2D(T x, T y) {
            this->m_X = x;
            this->m_Y = y;
        }

        Vector2D(const Vector2D<T> &other) {
            this->m_X = other.m_X;
            this->m_Y = other.m_Y;
        }

        ~Vector2D(void) {
        }

        T getX(void) const {
            return this->m_X;
        }

        T getY(void) const {
            return this->m_Y;
        }

        void setX(T x) {
            this->m_X = x;
        }

        void setY(T y) {
            this->m_Y = y;
        }

        void set(T x, T y) {
            this->setX(x);
            this->setY(y);
        }

        void move(T x, T y) {
            this->setX(this->m_X + x);
            this->setY(this->m_Y + y);
        }

        Vector2D<T> &operator=(const Vector2D<T> &other) {
            this->setX(other.getX());
            this->setY(other.getY());
            return *this;
        }

        Vector2D<T> operator+(const Vector2D<T> &other) const {
            return Vector2D<T>(this->m_X + other.getX(), this->m_Y + other.getY());
        }

        Vector2D<T> operator-(const Vector2D<T> &other) const {
            return Vector2D<T>(this->m_X - other.getX(), this->m_Y - other.getY());
        }

        Vector2D<T> operator*(const Vector2D<T> &other) const {
            return Vector2D<T>(this->m_X * other.getX(), this->m_Y * other.getY());
        }

        Vector2D<T> operator/(const Vector2D<T> &other) const {
            return Vector2D<T>(this->m_X / other.getX(), this->m_Y / other.getY());
        }
    };
}