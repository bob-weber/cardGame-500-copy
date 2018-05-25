#include "card.h"
#include <QRect>

Card::Card(QObject *parent, Card::Pip pip, Card::Suit suit, Card::Orientation orientation, unsigned int rotation)
{
	this->m_suit = suit;
	this->m_pip = pip;
	this->m_orientation = orientation;
	this->m_rotation = rotation;
}

Card::~Card()
{
}

/** Property functions
 */
Card::Suit Card::getSuit() const {
	return this->m_suit;
}

Card::Pip Card::getPip() const {
	return this->m_pip;
}

Card::Orientation Card::getOrientation() const {
	return this->m_orientation;
}

void Card::setOrientation(Orientation orientation) {
	if (orientation != this->m_orientation) {
		this->m_orientation = orientation;
		emit orientationChanged(orientation);
	}
}

unsigned int Card::getRotation() const {
	return this->m_rotation;
}

/* Only change rotation if it's valid, and different than the current rotation.
 * Requiring the rotation to be different means we only send a notification when the rotation has really changed.
 */
void Card::setRotation(unsigned int rotation) {
	if ((rotation >= MIN_ROTATION) &&
	    (rotation <= MAX_ROTATION) &&
	    (rotation != this->m_rotation))
	{
		this->m_rotation = rotation;
		emit rotationChanged(rotation);
	}
}


void Card::Paint(QRect paintArea, Card::Orientation orientation)
{

}
