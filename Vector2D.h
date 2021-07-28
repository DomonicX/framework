#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <cmath>
template<class T>
class Vector2D
{
public:
    T x, y;
    Vector2D() :x(0), y(0) {}
    Vector2D( T _x,  T _y) :x(_x), y(_y) {}
    Vector2D(const Vector2D& _v) :x(_v.x), y(_v.y) {}
    Vector2D& operator=(const Vector2D& _v)
    {
        x = _v.x;
        y = _v.y;
        return *this;
    }

    Vector2D operator+(Vector2D& _v)
    {
        return Vector2D(x + _v.x, y + _v.y);
    }
    Vector2D operator-(Vector2D& _v)
    {
        return Vector2D(x - _v.x, y - _v.y);
    }
    Vector2D& operator+=(Vector2D _v)
    {
        x += _v.x;
        y += _v.y;
        return *this;
    }
    Vector2D& operator-=(Vector2D _v)
    {
        x -= _v.x;

        y -= _v.y;
        return *this;
    }
    Vector2D operator+(float _s)
    {
        return Vector2D(x + _s,y +_s);
    }
    Vector2D operator-(float _s)
    {
        return Vector2D(x - (double)_s,y - (double)_s);
    }
  Vector2D operator*(double s) {
		return Vector2D(x * s, y * s);
	}
    Vector2D operator/(float _s)
    {
        return Vector2D(x /(float) _s,y / (float)_s);
    }
    Vector2D& operator+=(float _s)
    {
        x += (float)_s;
        y += (float)_s;
        return *this;
    }

    bool operator==(Vector2D _v)
    {
       if(x == (float)_v.x)
       {

       if( y == (float)_v.y)
       {

        return true;
       }
       }
       return false;
    }
    Vector2D& operator-=(float _s)
    {
        x -= _s;
        y -= _s;
        return *this;
    }
    Vector2D& operator*=(float _s)
    {
        x *= _s;
        y *= _s;
        return *this;
    }
    Vector2D& operator/=(float _s)
    {
        x /= _s;
        y /= _s;
        return *this;
    }
    void  Roatate(float deg)
    {
        double theta = deg / 180 * M_PI;
        double c = cos(theta);
        double s = sin(theta);
        double tx = x * c - y * s;
        double ty = x *s +y *c;
        x = tx;
        y = ty;
    }
    void Set(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    Vector2D Normalise()
    {
        if(Length() == 0)
            return *this;
        *this *= (1.0 / Length());
        return *this;
    }
    float Dist(Vector2D _v) const
    {
        Vector2D d(_v.x - x, _v.y - y);
        return d.Length();
    }
    float Length() const
    {
        return std::sqrt( x * x + y * y);

    }
    void Truncate(double _length)
    {
        double angle = atan2f(y,x);
        x = _length * cos(angle);
        y = _length * sin(angle);
    }
    Vector2D Ortho() const
    {
        return(y,-x);
    }
    static  float Dot( Vector2D & _v1,Vector2D & _v2)
    {
        return _v1.x * _v2.x + _v1.y * _v2.y;
    }
    float Cross( Vector2D & _v1,Vector2D & _v2)
    {
        return (_v1.x * _v2.y )- ( _v1.y * _v2.x);
    }

void Limit(float Max)
{
    if(Length() > Max)
    {
       Vector2D s = Vector2D(x,y);
        s.Normalise();
        s*=Max;
        x = s.x;
        y = s.y;
    }

}


    int GetArrayIndex(int Size_of_Rows){ return x/25 + ((y/25)*25); }
protected:

private:
};

typedef Vector2D<float>vec2f;
typedef Vector2D<double>vec2d;

#endif // VECTOR2D_H
