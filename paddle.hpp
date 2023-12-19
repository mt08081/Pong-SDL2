// paddle.hpp
class Paddle {
public:
    Paddle();
    ~Paddle();
    void moveUp();
    void moveDown();
    void render();
private:
    int x, y, speed;
    // SDL related members
};