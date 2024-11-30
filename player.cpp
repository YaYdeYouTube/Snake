#include "player.hpp"

enum Direction {up = 0, down = 1, left = 2, right = 3};

Player::Player()
{
    Init();
}

void Player::Draw()
{
    for (int i = 0; i < body.size(); i++)
        DrawRectangle(body[i].x * 15 + 30, body[i].y * 15 + 30, 15, 15, WHITE);
}

void Player::Update()
{
    float deltaTime = GetFrameTime();
    time += deltaTime;

    if (time >= delay)
    {
        switch (direction)
        {
        case 0:
            body.pop_back();
            body.push_front({ body[0].x, body[0].y - 1 });
            break;
        case 1:
            body.pop_back();
            body.push_front({ body[0].x, body[0].y + 1 });
            break;
        case 2:
            body.pop_back();
            body.push_front({ body[0].x - 1, body[0].y  });
            break;
        case 3:
            body.pop_back();
            body.push_front({ body[0].x + 1, body[0].y });
            break;
        }
        time = 0.0f;
    }

    if (body[0].x <= 0)
    {
        active = false;
    }
    else if (body[0].x >= 39)
    {
        active = false;
    }
    else if (body[0].y <= 0)
    {
        active = false;
    }
    else if (body[0].y >= 39)
    {
        active = false;
    }
}

void Player::MoveUp()
{
    direction = up;
}

void Player::MoveDown()
{
    direction = down;
}

void Player::MoveLeft()
{
    direction = left;
}

void Player::MoveRight()
{
    direction = right;
}

void Player::GetLonger()
{
    switch (direction)
    {
    case 0:
        body.push_front({ body[0].x, body[0].y - 1 });
        break;
    case 1:
        body.push_front({ body[0].x, body[0].y + 1 });
        break;
    case 2:
        body.push_front({ body[0].x - 1, body[0].y });
        break;
    case 3:
        body.push_front({ body[0].x + 1, body[0].y });
        break;
    }
}

void Player::Init()
{
    headPosition = { 19, 19 };
    direction = left;
    delay = 0.5f;
    time = 0.0f;
    body = { headPosition, {headPosition.x + 1, headPosition.y}, {headPosition.x + 2, headPosition.y} };
    active = true;
}

Rectangle Player::GetRect()
{
	return { body[0].x * 15 + 30, body[0].y * 15 + 30, 15, 15};
}
