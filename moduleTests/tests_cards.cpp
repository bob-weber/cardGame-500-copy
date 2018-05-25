#include <QtTest>
#include <QSignalSpy>

#include "../gameSrc/data/card.h"
#include "tests_cards.h"


tests_Cards::tests_Cards(QObject *parent) : QObject(parent)
{

}

void tests_Cards::executeAll()
{
	Creation();
	Orientation();
	Rotation();
}

void tests_Cards::Creation()
{
	/* Get a 2 of spades, face down */
	card_2_Spades = new Card(nullptr, Card::PIP_2, Card::SUIT_SPADE, Card::FACE_UP, 0);
	QVERIFY(card_2_Spades->getPip() == Card::PIP_2);
	QVERIFY(card_2_Spades->getSuit() == Card::SUIT_SPADE);
	QVERIFY(card_2_Spades->getOrientation() == Card::FACE_UP);
	QVERIFY(card_2_Spades->getRotation() == 0);

	/* Get a king of hearts, face up */
	card_King_Hearts = new Card(nullptr, Card::PIP_KING, Card::SUIT_HEART, Card::FACE_UP, 0);
	QVERIFY(card_King_Hearts->getPip() == Card::PIP_KING);
	QVERIFY(card_King_Hearts->getSuit() == Card::SUIT_HEART);
	QVERIFY(card_King_Hearts->getOrientation() == Card::FACE_UP);
	QVERIFY(card_King_Hearts->getRotation() == 0);

}

void tests_Cards::Orientation()
{
	// Verify no signals have been emitted for the 2 of spades
	//qRegisterMetaType<Card::Orientation>("Card::Orientation");
	QSignalSpy spyCard_2_spades(card_2_Spades, SIGNAL(orientationChanged(Orientation)));
	QVERIFY(spyCard_2_spades.count() == 0);

	// Set card face down; it should currently be face up. Signal should be emitted.
	card_2_Spades->setOrientation(Card::FACE_DOWN);
	QVERIFY(card_2_Spades->getOrientation() == Card::FACE_DOWN);
	QVERIFY(spyCard_2_spades.count() == 1);

	// Set card face down again. No signal should be emitted.
	card_2_Spades->setOrientation(Card::FACE_DOWN);
	QVERIFY(card_2_Spades->getOrientation() == Card::FACE_DOWN);
	QVERIFY(spyCard_2_spades.count() == 1);

	// Set the card face up again. Another signal should be emitted.
	card_2_Spades->setOrientation(Card::FACE_UP);
	QVERIFY(card_2_Spades->getOrientation() == Card::FACE_UP);
	QVERIFY(spyCard_2_spades.count() == 2);

	/* Flip the king of hears, down and then up.
	 */
	card_King_Hearts->setOrientation(Card::FACE_DOWN);
	QVERIFY(card_King_Hearts->getOrientation() == Card::FACE_DOWN);
	card_King_Hearts->setOrientation(Card::FACE_UP);
	QVERIFY(card_King_Hearts->getOrientation() == Card::FACE_UP);
}

void tests_Cards::Rotation()
{

}
