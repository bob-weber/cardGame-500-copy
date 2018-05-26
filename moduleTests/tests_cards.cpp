#include <QtTest>
#include <QSignalSpy>
#include <QMetaType>

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
	unsigned int signalCount;
	QList<QVariant> arguments;

	// Verify no signals have been emitted for the 2 of spades
	qRegisterMetaType<Card::Orientation>();
	QSignalSpy spyCard_2_spades(card_2_Spades, &Card::orientationChanged);
	signalCount = spyCard_2_spades.count();
	QVERIFY(signalCount == 0);

	// Set card face down; it should currently be face up. Signal should be emitted.
	card_2_Spades->setOrientation(Card::FACE_DOWN);
	signalCount = spyCard_2_spades.count();
	// Arguments for this signal event are 0 based, so the 1st signal event's arguments are at QList[0].
	arguments = spyCard_2_spades.takeAt(signalCount-1);
	QVERIFY(card_2_Spades->getOrientation() == Card::FACE_DOWN);
	QVERIFY(signalCount == 1);
	QVERIFY(arguments.at(0) == Card::FACE_DOWN);

	// Set card face down again. They're already face down, so no signal should be emitted.
	card_2_Spades->setOrientation(Card::FACE_DOWN);
	signalCount = spyCard_2_spades.count();
	// ERROR HERE. count returns 0. I didn't expect the counter to get reset.
	// This causes the next call to seg fault.
	arguments = spyCard_2_spades.takeAt(signalCount-1);;
	QVERIFY(card_2_Spades->getOrientation() == Card::FACE_DOWN);
	QVERIFY(spyCard_2_spades.count() == 1);
	QVERIFY(arguments.at(0) == Card::FACE_DOWN);

	// Set the card face up again. Another signal should be emitted.
	card_2_Spades->setOrientation(Card::FACE_UP);
	signalCount = spyCard_2_spades.count();
	arguments = spyCard_2_spades.takeAt(signalCount-1);;
	QVERIFY(card_2_Spades->getOrientation() == Card::FACE_UP);
	QVERIFY(spyCard_2_spades.count() == 2);
	QVERIFY(arguments.at(0) == Card::FACE_UP);
}

void tests_Cards::Rotation()
{

}
