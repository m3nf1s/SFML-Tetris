#include "Figure.h"
#include "Gamefield.h"
#include "../GameInstance.h"
#include "../EventSystem/EventManager.h"

Figure::Figure()
    : m_figure_(Matrix_t(0, std::vector<int32_t>(0)))
{
}

Figure::Figure(const Matrix_t& figure)
    : m_figure_(figure)
{
}

void Figure::SetNewPosition(const int32_t new_x, const int32_t new_y)
{
    m_current_position_.X = new_x;
    m_current_position_.Y = new_y;
}

int32_t Figure::Get(const int32_t row_index, const int32_t column_index) const
{
    return m_figure_.at(row_index).at(column_index);
}

const Position& Figure::GetCurrentPosition() const
{
    return m_current_position_;
}

int32_t Figure::GetSize() const
{
    return static_cast<int32_t>(m_figure_.size());
}

bool Figure::HasCollisionGamefield(const Gamefield* gamefield) const
{
    for (int32_t Y = 0; Y < GetSize(); ++Y)
    {
        for (int32_t X = 0; X < GetSize(); ++X)
        {
            if (m_figure_.at(Y).at(X) != 0)
            {
                const int32_t real_position_Y = m_current_position_.Y + Y;
                const int32_t real_position_X = m_current_position_.X + X;
                
                if (real_position_Y > Gamefield::ROWS - 1)
                {
                    return true;
                }

                if (gamefield->GetCell(real_position_Y, real_position_X) != 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Figure::HasCollisionLeftWall() const
{
    for (int32_t X = 0; X < GetSize(); ++X)
    {
        for (int32_t Y = 0; Y < GetSize(); ++Y)
        {
            if (m_figure_.at(Y).at(X) != 0)
            {
                const int32_t real_position_X = m_current_position_.X + X;

                if (real_position_X < 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Figure::HasCollisionRightWall() const
{
    for (int32_t X = 0; X < GetSize(); ++X)
    {
        for (int32_t Y = 0; Y < GetSize(); ++Y)
        {
            if (m_figure_.at(Y).at(X) != 0)
            {
                const int32_t real_position_X = m_current_position_.X + X;

                if (real_position_X > Gamefield::COLUMNS - 1)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Figure::HasCollisionTop() const
{
    for (int32_t Y = 0; Y < GetSize(); ++Y)
    {
        for (int32_t X = 0; X < GetSize(); ++X)
        {
            if (m_figure_.at(Y).at(X) != 0)
            {
                const int32_t real_position_Y = m_current_position_.Y + Y;

                if (real_position_Y < 0)
                {
                    return true;
                }
            }
        }
    }

    return false;

}

void Figure::MoveLeft(const Gamefield* gamefield)
{
    const int32_t previous_position_X = m_current_position_.X;
    m_current_position_.X -= 1;

    if (HasCollisionLeftWall() || HasCollisionGamefield(gamefield))
    {
        m_current_position_.X = previous_position_X;
        return;
    }   
}

void Figure::MoveRight(const Gamefield* gamefield)
{
    const int32_t previous_position_X = m_current_position_.X;
    m_current_position_.X += 1;

    if (HasCollisionRightWall() || HasCollisionGamefield(gamefield))
    {
        m_current_position_.X = previous_position_X;
        return;
    }
}

void Figure::Rotate(const Gamefield* gamefield)
{
    const Matrix_t temp_figure = m_figure_;

    for (int32_t i = 0; i < GetSize(); ++i)
    {
        for (int32_t j = 0; j < GetSize(); ++j)
        {
            //if (temp_figure[i][j] != 0)
            {
                m_figure_[j][GetSize() - 1 - i] = temp_figure[i][j];
            }
        }
    }

    if (HasCollisionLeftWall())
    {
        m_current_position_.X += (0 - m_current_position_.X);
    }

    if (HasCollisionRightWall())
    {
        m_current_position_.X -= (m_current_position_.X + GetSize() - Gamefield::COLUMNS);
    }

    if (HasCollisionTop())
    {
        m_current_position_.Y += (0 - m_current_position_.Y);
    }

    if (HasCollisionGamefield(gamefield))
    {
        m_figure_ = temp_figure;
        return;
    }
}

void Figure::MoveDown(const Gamefield* Gamefield)
{
    const int32_t previous_position_Y = m_current_position_.Y;
    m_current_position_.Y += 1;

    if(HasCollisionGamefield(Gamefield))
    {
        m_current_position_.Y = previous_position_Y;
    }

    //event generate collision
}
