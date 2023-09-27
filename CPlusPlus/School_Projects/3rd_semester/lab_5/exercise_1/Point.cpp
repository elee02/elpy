
bool Point::InitMembers(int xpos, int ypos) {
    if (!isInRange(xpos) || !isInRange(ypos))
        return false;

    m_x = xpos;
    m_y = ypos;
    return true;
}

int Point::GetX() const {
    return m_x;
}

int Point::GetY() const {
    return m_y;
}

bool Point::SetX(int xpos) {
    if (!isInRange(xpos))
        return false;

    m_x = xpos;
    return true;
}

bool Point::SetY(int ypos) {
    if (!isInRange(ypos))
        return false;

    m_y = ypos;
    return true;
}

bool Point::isInRange(int pos) {
    if (pos >= POSMIN && pos <= POSMAX)
        return true;

    return false;
}