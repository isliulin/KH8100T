#include "RandomOperateDb.h"
#include "FastdbTableDefine.h"
#include "FastdbManager.h"


RandomOperateDb::RandomOperateDb()
	: m_operInfo(QStringLiteral(""))
{
	m_fastdbManager = FastdbManagerInstance::getFastdbManagerInstance();
}

RandomOperateDb::~RandomOperateDb()
{

}

void RandomOperateDb::startOperate(OperateMode mode)
{
	dbDatabase* m_dbPtr = m_fastdbManager->getDbDatabase();
	if (!m_dbPtr)
	{
		m_operInfo += QStringLiteral("线程ID( ") + getThreadId() + QStringLiteral(" )");
		m_operInfo += QStringLiteral("实时库指针为空，无法操作实时库");
		return;
	}
	if (!m_dbPtr->isAttached())
	{
		m_dbPtr->attach();
	}

	mode = (mode != ModeCount) ? mode : (OperateMode)(getRandValue() % ModeCount);
	switch(mode)
	{
	case InsertMode:
		insertData();
		break;
	case UpdateMode:
		updateData();
		break;
	case DeleteMode:
		deleteData();
		break;
	case SelectMode:
		selectData();
		break;
	default:
		break;
	}

	if (m_dbPtr->isAttached())
	{
		m_dbPtr->detach();
	}
	return;
}

QString RandomOperateDb::getOperateInfo() const
{
	return m_operInfo;
}

void RandomOperateDb::setThreadId( const QString& threadId )
{
	m_threadId = threadId;
}

QString RandomOperateDb::getThreadId() const
{
	return m_threadId;
}

void RandomOperateDb::insertData()
{
	QMutexLocker locker(&m_mutex);

	// 每次插入指定条目的数据
	const int count = 20;
	m_operInfo += QStringLiteral("线程ID( ") + getThreadId() + QStringLiteral(" )");
	m_operInfo += QStringLiteral("插入数据：\n");
	for (int i = 0; i < count; ++i)
	{
		Record record;
		record.id = QUuid::createUuid().toString().toStdString();
		record.iValue = getRandValue();
		record.dValue = getRandValue() / 5.0;
		insert(record);

		QString text = QString().fromStdString(record.output());
		m_operInfo += text + QStringLiteral("\n");

		QThread::msleep(2);
	}
	m_fastdbManager->commit();
}

void RandomOperateDb::updateData()
{
	QMutexLocker locker(&m_mutex);

	dbCursor<Record> cursor(dbCursorForUpdate);
	int count = cursor.select();
	m_operInfo += QStringLiteral("线程ID( ") + getThreadId() + QStringLiteral(" )");
	m_operInfo += QStringLiteral("更新数据： \n");
	if (count > 0)
	{
		int value = getRandValue() % 5;
		do 
		{
			cursor->iValue += value;
			cursor->dValue *= value;
			cursor.update();

			QString text = QString().fromStdString(cursor->output());
			m_operInfo += text + QStringLiteral("\n");
		} while (cursor.next());
	}
	else
	{
		m_operInfo += QStringLiteral("无数据");
	}
	m_fastdbManager->commit();
}

void RandomOperateDb::deleteData()
{
	QMutexLocker locker(&m_mutex);

	// 删除iValue为偶数的记录
	dbCursor<Record> cursor(dbCursorForUpdate);
	int count = cursor.select();
	m_operInfo += QStringLiteral("线程ID( ") + getThreadId() + QStringLiteral(" )");
	m_operInfo += QStringLiteral("删除数据： \n");
	if (count > 0)
	{
		do 
		{
			if (cursor->iValue % 2 == 0)
			{
				QString text = QString().fromStdString(cursor->output());
				m_operInfo += text + QStringLiteral("\n");
			
				cursor.remove();
			}
		} while (cursor.next());
	}
	else
	{
		m_operInfo += QStringLiteral("无数据");
	}
	m_fastdbManager->commit();
}

void RandomOperateDb::selectData()
{
	QMutexLocker locker(&m_mutex);

	dbCursor<Record> cursor(dbCursorViewOnly);
	int count = cursor.select();
	m_operInfo += QStringLiteral("线程ID( ") + getThreadId() + QStringLiteral(" )");
	QString text = QString(QStringLiteral("个数(%1)\n")).arg(count);
	m_operInfo += QStringLiteral("查询数据：") + text;
	if (count > 0)
	{
		do 
		{
			text = QString().fromStdString(cursor->output());
			m_operInfo += text + QStringLiteral("\n");
		} while (cursor.next());
	}
	else
	{
		m_operInfo += QStringLiteral("无数据");
	}
}

int RandomOperateDb::getRandValue()
{
	qsrand(QDateTime::currentDateTime().toTime_t()); 
	return qrand();
}
