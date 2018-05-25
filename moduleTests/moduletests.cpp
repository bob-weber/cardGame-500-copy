// #include <QString>
#include <QtTest>
#include "tests_cards.h"

class ModuleTests : public QObject
{
		Q_OBJECT

	public:
		ModuleTests();

	private Q_SLOTS:
		void initTestCase();
		void cleanupTestCase();
		void test_Card();

};

ModuleTests::ModuleTests()
{
}

void ModuleTests::initTestCase()
{
}

void ModuleTests::cleanupTestCase()
{
}

/** Card tests
 */
void ModuleTests::test_Card()
{
	tests_Cards *cardTests = new tests_Cards();
	cardTests->executeAll();
}


QTEST_APPLESS_MAIN(ModuleTests)

#include "moduletests.moc"
