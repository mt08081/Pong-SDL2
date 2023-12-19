// ball.hpp
class Ball {
public:
    Ball();
    ~Ball();
    void move();
    void render();
private:
    int x, y, speed, direction;
    // SDL related members
};