#include <memory>

#include "Enemy.hpp"
#include "DiscreteMap.hpp"

Enemy::Enemy(const std::vector<sf::Vector2u>& l_translation, size_t l_attackRadius)
: m_translation(l_translation)
, m_attackRadius(l_attackRadius)
, m_translationStep(0)
{
    UpdateLocationByNextStepOfTranslation();
}

Enemy::~Enemy()
{}

void Enemy::Update(sf::Time dt)
{
    UpdateLocationByNextStepOfTranslation();
}

void Enemy::UpdateLocationOnMap(DiscreteMap* l_map) const
{
    // 1. Update radius attack range
    UpdateAttackRangeOnMap(l_map);

    // 2. Update enemy location
    l_map->SetCellWithPositionAndState(m_location, Cell::OCCUPY_BY_ENEMY);
}

void Enemy::UpdateAttackRangeOnMap(DiscreteMap* l_map) const
{
    // ...
}

Object::ObjectType Enemy::GetObjectType() const
{
    return MoveableObject::GetObjectType();
}

void Enemy::UpdateLocationByNextStepOfTranslation()
{
    m_location = m_translation[m_translationStep++ % m_translation.size()];
}
